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
#include <stdexcept>

#include <shoverand/util/myCutil.h>
#include <shoverand/core/ParameterizedStatus.hxx>
#include <shoverand/core/SeedStatus.hxx>

#include "ParameterizedStatus.h"
#include "SeedStatus.h"
#include <shoverand/util/mrg32k3a/util.h>

namespace shoverand {
	namespace prng {	
		namespace MRG32k3a {

			/** Stores the address of the array containing all the ParameterizedStatuses.
			 *  DO NOT USE IT directly!
			 * */
			__device__
			ParameterizedStatusMRG32k3a* ps_;
			
			
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
									
				long k;
				double p1, p2, u;

			public:
				
				/** __host__ constructor is here for concept checking purpose only */
				__host__
				MRG32k3a(int foo) {}
				
				__device__
				MRG32k3a() {
					//ss_ = new SeedStatusMRG32k3a(ps_);
					ss_.setUp(ps_);
				}
				
				// NOTE it seems that this CUDA sonofabitch won't generate any code for
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

					myCutilSafeCall( cudaMalloc((void**) &status_device__, sizeof(ParameterizedStatusType)) );  
					myCutilSafeCall( cudaMemcpy(status_device__, status_host__, sizeof(ParameterizedStatusType), cudaMemcpyHostToDevice) );
										
					// call the hack kernel with only one thread to copy the array's address
					fillParameterizedStatus<<<1,1>>> (status_device__);
					
					cudaError_t err;
					if ( (err = cudaGetLastError()) != cudaSuccess ) {
						throw std::runtime_error(cudaGetErrorString(err));
					}
					
					// wait until preceeding kernel to complete
					myCutilSafeCall( cudaDeviceSynchronize() );
				}
				
				/** Release resources allocated by init */
				__host__
				static void release() {
					status_host__->shutdown();
					delete status_host__;
					
					myCutilSafeCall(cudaFree(status_device__));
					
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
			ParameterizedStatusMRG32k3a* MRG32k3a<T>::status_host__;
			
			template <class T>
			ParameterizedStatusMRG32k3a* MRG32k3a<T>::status_device__;
			
		} // end of namespace MRG32k3a
	} // end of namespace prng
	
	// shortcut to MRG32k3a
	using prng::MRG32k3a::MRG32k3a;

	
} // end of namespace shoverand

#endif // MRG32k3a_HXX
