/*
 *  MRG32k3a.hxx
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 1/31/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef MRG32k3a_HXX
#define MRG32k3a_HXX

#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>
#include <stdexcept>
#include <vector>
#include <numeric>


#include <shoverand/core/ParameterizedStatus.hxx>
#include <shoverand/core/SeedStatus.hxx>

#include "ParameterizedStatus.h"
#include "SeedStatus.h"
#include "utils.h"

namespace shoverand {
	namespace prng {	
		namespace MRG32k3a {

			/** Stores the address of the array containing all the ParameterizedStatuses.
			 *  DO NOT USE IT directly!
			 * */
			__device__
			ParameterizedStatusMRG32k3a* ps_;
			
			
			__constant__ __device__
			int kernelCount;
			
			__device__
			int kernelIdOffset;
			
			__device__
			ParameterizedStatusMRG32k3a** array;
			
			/** This kernel is a hack to avoid the user to pass ParameterizedStatus 
			 * as parameter of his own kernels. 
			 * @param inStatus Address of the PREVIOUSLY ALLOCATED ParameterizedStatus array to store
			 * 					 in global variable ps_
			 */
			__global__
			static void fillParameterizedStatus(ParameterizedStatusMRG32k3a* inStatus) {
				if (threadIdx.x == 0) {
					ps_ = inStatus;
				}
			}
			
			/** This kernel is a hack to avoid the user to pass their kernel's 
			 * assigned ParameterizedStatus as a parameter of the said kernel. 
			 * @param inArray   Address of the PREVIOUSLY ALLOCATED ParameterizedStatus array to store
			 * 					 in global variable array
			 */
			__global__
			static void fillParameterizedStatusArray(ParameterizedStatusMRG32k3a** inArray) {
				if (threadIdx.x == 0) {
					array = inArray;
				}
			}
			
			/** Class statically checking the RNGAlgorithm policy's interface.
			Most of this class' methods are marked as __host__ so that BCCL
			can check their presence. 
			You should use them in device code only, when nothing precised.
			*/
			// TODO force people to use it through RNG<>
			template < class T >
			class MRG32k3a {
				
				
			public:
				
				// TODO insert in core namespace
				typedef SeedStatusMRG32k3a 			SeedStatusType;
				typedef ParameterizedStatusMRG32k3a ParameterizedStatusType;

				
				// TODO add to Concept Checking
				typedef T result_type;
				typedef T input_type;
				
				
			private:
				static ParameterizedStatusType* status_host__;
				static ParameterizedStatusType* status_device__;
				SeedStatusType ss_;
				
				static ParameterizedStatusType** array_host__;
				static ParameterizedStatusType** array_device__;
									
				long k;
				double p1, p2, u;

			public:
				
				/** __host__ constructor is here for concept checking purpose only */
				__host__
				MRG32k3a(int foo) {}
				
				__device__
				MRG32k3a() {
					uint id;
					asm("mov.u32 %0, %gridid;" : "=r"(id) );
					
					int kernelID = (id % shoverand::prng::MRG32k3a::kernelCount);
					
// 					ss_.setUp(ps_);

					ss_.setUp(array[kernelID]);
				}
				
				// NOTE it seems that this *** CUDA won't generate any code for
				//		  destructor. screw it!
// 				__device__
// 				~MRG32k3a() {
// 					delete ss_;
// 				}
				
				/** Initialize the device so that a ParameterizedStatus status is created and copied
				 *  in device memory for every block used in the application.
				*   MUST BE CALLED before any call to ShoveRand's features in device code.
				*   @param block_num Number of CUDA blocks used in the application.
				* 	 @throw std::runtime_error
				*/
				__host__
				static void init(unsigned int block_num) throw (std::runtime_error) {
					// ParameterizedStatus initialization on both sides
					status_host__ = new ParameterizedStatusType();
					status_host__->setUp(block_num);

					cutilSafeCall( cudaMalloc((void**) &status_device__, sizeof(ParameterizedStatusType)) );  
					cutilSafeCall( cudaMemcpy(status_device__, status_host__, sizeof(ParameterizedStatusType), cudaMemcpyHostToDevice) );
										
					// call the hack kernel with only one thread to copy the array's address
					fillParameterizedStatus<<<1,1>>> (status_device__);
					
					cudaError_t err;
					if ( (err = cudaGetLastError()) != cudaSuccess ) {
						throw std::runtime_error(cudaGetErrorString(err));
					}
					
					// wait until preceeding kernel to complete
					cutilSafeCall( cudaDeviceSynchronize() );
				}
				
				
				/** TODO doc me! */
				__host__
				static void init(const std::vector< int >& inKernelRandomConfiguration) throw (std::runtime_error) {
					
					int kernelCount = inKernelRandomConfiguration.size();
					cutilSafeCall ( cudaMemcpyToSymbol ( shoverand::prng::MRG32k3a::kernelCount, &kernelCount, sizeof(int) ) );
					
					int block_num = std::accumulate ( inKernelRandomConfiguration.begin(), inKernelRandomConfiguration.end(), 0 );
					init(block_num); // call classic init
					
					cutilSafeCall ( cudaMalloc ( (void**) &array_device__, sizeof (ParameterizedStatusType*) * kernelCount) );

               array_host__ = new ParameterizedStatusType* [ kernelCount ];
					// init PS pointers array with offset according to input vector
					for (int i = 0, acc = 0; i < kernelCount; acc += inKernelRandomConfiguration[i], ++i) {
				          array_host__[i] = status_device__ + acc;
					}
					
               cutilSafeCall ( cudaMemcpy ( array_device__, array_host__, sizeof(ParameterizedStatusType*) * kernelCount, cudaMemcpyHostToDevice ) );
					fillParameterizedStatusArray <<<1, 1>>> (array_device__);
					
					cudaError_t err;
					if ( (err = cudaGetLastError()) != cudaSuccess ) {
						throw std::runtime_error(cudaGetErrorString(err));
					}
					
					// wait until preceeding kernel to complete
					cutilSafeCall( cudaDeviceSynchronize() );
				}
				
				
				/** Release resources allocated by init */
				__host__
				static void release() {
					if (status_host__ != NULL) {
						status_host__->shutdown();
						delete status_host__;
					}
					
					if (status_device__ != NULL) {
						cutilSafeCall(cudaFree(status_device__));
					}
					
					if (array_device__ != NULL) {
						cutilSafeCall(cudaFree(array_device__));
					}
					
					if (array_host__ != NULL) {
						delete [] array_host__;
					}
				}
				
				__host__ __device__
				T next() {
					
					// Component 1
					p1 = a12 * ss_.Cg_[1] - a13n * ss_.Cg_[0];
					k = static_cast<long> (p1 / m1);
					p1 -= k * m1;
					
					if (p1 < 0.0)  p1 += m1;
					
					ss_.Cg_[0] = ss_.Cg_[1]; ss_.Cg_[1] = ss_.Cg_[2]; ss_.Cg_[2] = p1;
					
					// Component 2
					p2 = a21 * ss_.Cg_[5] - a23n * ss_.Cg_[3];
					k = static_cast<long> (p2 / m2);
					p2 -= k * m2;
					
					if (p2 < 0.0) p2 += m2;
					
					ss_.Cg_[3] = ss_.Cg_[4]; ss_.Cg_[4] = ss_.Cg_[5]; ss_.Cg_[5] = p2;
					
					// Combination
					u = ((p1 > p2) ? (p1 - p2) * norm : (p1 - p2 + m1) * norm);
					
					return u;
				}
				
				//TODO The two following methods need to be tuned according to MRG32k3a's characteristics
				// 	and also to its result type.
				__host__ __device__ inline
				result_type min() const { return result_type(0); }


				// TODO specialize according to internal data type
				__host__ __device__ inline
				result_type max() const { return result_type(1); }
				

				__host__ __device__ inline
				result_type operator() () { return this->next(); }

				// concept checking class 
				// (friend allows to expose private methods to this class only)
				template <class U, template <typename> class Algo>
				friend class RNGAlgorithm;

			};

			template <class T>
			ParameterizedStatusMRG32k3a* MRG32k3a<T>::status_host__ = NULL;
			
			template <class T>
			ParameterizedStatusMRG32k3a* MRG32k3a<T>::status_device__ = NULL;

			template <class T>
			ParameterizedStatusMRG32k3a** MRG32k3a<T>::array_device__ = NULL;

			template <class T>
			ParameterizedStatusMRG32k3a** MRG32k3a<T>::array_host__ = NULL;
		} // end of namespace MRG32k3a
	} // end of namespace prng
	
	// shortcut to MRG32k3a
	using prng::MRG32k3a::MRG32k3a;

	
} // end of namespace shoverand

#endif // MRG32k3a_HXX
