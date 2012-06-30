/**
 *  @file TinyMT.hxx
 *  @author jH@CKtheRipper
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 1/31/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef TINYMT_HXX
#define TINYMT_HXX

#include <shoverand/core/ParameterizedStatus.hxx>
#include <shoverand/core/SeedStatus.hxx>

#include <cuda.h>
#include <shoverand/util/myCutil.h>
#include "ParameterizedStatus.h"
#include "SeedStatus.h"
#include <shoverand/util/tinymt/util.hxx>

namespace shoverand {
	namespace prng {	
		namespace TinyMT {
                        
			__device__ const int TINYMT32_SHIFT0 = 1;
			__device__ const int TINYMT32_SHIFT1 = 10;
			__device__ const int TINYMT32_MIN_LOOP = 8;
			__device__ const int TINYMT32_PRE_LOOP = 8;
			__device__ const int TINYMT32_MASK = 0x7fffffffU;
			__device__ const int TINYMT32_SINGLE_MASK = 0x3f800000U;

			__device__ 
			ParameterizedStatusTinyMT* paramArray;
			
			/** This kernel is a hack to avoid the user to pass ParameterizedStatus 
			 * as parameter of his own kernels. 
			 * @param inStatus Address of the PREVIOUSLY ALLOCATED ParameterizedStatus array to store
			 * 					 in global variable ps_
			 */
			__global__
			static void fillParameterizedStatus(ParameterizedStatusTinyMT* inStatus) {
				if (0 == threadIdx.x) {
					paramArray = inStatus;
				}
			}
			
			
			/** Class statically checking the RNGAlgorithm policy's interface.
						Most of this class' methods are marked as __host__ so that BCCL
						can check their presence.
						You should use them in device code only, when nothing is specified.
			 */
			// TODO force people to use it through RNG<>
			template < class T >
			class TinyMT {

			public:

				// TODO insert in core namespace
				typedef SeedStatusTinyMT 			 SeedStatusType;
				typedef ParameterizedStatusTinyMT 	 ParameterizedStatusType;


				// TODO add to Concept Checking
				typedef T result_type;
				typedef T input_type;


			private:
				ParameterizedStatusType* ps_;
				SeedStatusType ss_;

				// parameters array memento
				static ParameterizedStatusType* status_host_;
				static ParameterizedStatusType* status_device_;

			private:
				__host__ __device__ void nextRN() {
					unsigned int y = ss_.status3_;
					unsigned int x = (ss_.status0_ & TINYMT32_MASK)
								^ ss_.status1_ ^ ss_.status2_;

					x ^= (x << TINYMT32_SHIFT0);
					y ^= (y >> TINYMT32_SHIFT0) ^ x;
					ss_.status0_ = ss_.status1_;
					ss_.status1_ = ss_.status2_;
					ss_.status2_ = x ^ (y << TINYMT32_SHIFT1);
					ss_.status3_ = y;
					if (y & 1) {
						ss_.status1_ ^= ps_->mat1_;
						ss_.status2_ ^= ps_->mat2_;
					}
				}

				__host__ __device__ T temper() {
					unsigned int t0, t1;
					t0 = ss_.status3_;
					t1 = ss_.status0_ + (ss_.status2_ >> 8);
					t0 ^= t1;
					if (t1 & 1) {
						t0 ^= ps_->tmat_;
					}
					return t0;

				}

			public:

				/**TinyMT's default constructor.
				 * Initialize ParameterizedStatus according to global blockId.
				 * ParameterizedStatuses array must have been transfered to device
				 * memory before.
				 * @see init
								@note  __host__ tag is here for concept check purpose only
				 */
				 __host__ __device__
				 TinyMT()
				 	 :ps_(paramArray + (blockIdx.x * blockDim.y + blockIdx.y) )
				{
					 //ss_.setUp(ps_); // not needed yet
				}


				/** Initialize the device so that a ParameterizedStatus status is created and copied
				 *  in device memory for every block used in the application.
				 *   MUST BE CALLED before any call to ShoveRand's features in device code.
				 *   @param block_num Number of CUDA blocks used in the application.
				 */
				 __host__
				 static void init(unsigned int block_num) {

					 // ParameterizedStatus initialization on both sides
					 status_host_ = new ParameterizedStatusType[block_num];

					 for (int i = 0; i < block_num; ++i) {
						 status_host_[i].setUp(i);
					 }

					 myCutilSafeCall( cudaMalloc((void**) &status_device_, sizeof(ParameterizedStatusType) * block_num) );
					 myCutilSafeCall( cudaMemcpy(status_device_, status_host_, sizeof(ParameterizedStatusType) * block_num, cudaMemcpyHostToDevice) );

					 // call the hack kernel with only one thread to copy the array's address
					 fillParameterizedStatus<<<1,1>>> (status_device_);

					 // wait until preceeding kernel to complete
					 myCutilSafeCall( cudaDeviceSynchronize() );
				 }

				 /** Release resources allocated by init */
				 __host__
				 static void release() {
					 status_host_->shutdown();
					 delete [] status_host_;

					 myCutilSafeCall( cudaFree( status_device_ ));
				 }

				 __host__ __device__
				 T next() {
					 nextRN();
					 return temper();
				 }

				 //TODO The two following methods need to be tuned according to TinyMT's characteristics
				 // 	and also to its result type.
				 __host__ __device__ inline
				 result_type min() const { return result_type(0); }


				 // TODO specialize according to internal data type
				 __host__ __device__ inline
				 result_type max() const { return result_type(1); }

				 // TODO factor upwards
				 __host__ __device__ inline
				 result_type operator() () { return this->next(); }

				 // concept checking class
				 // (friend allows to expose private methods to this class only)
				 template <class U, template <typename> class Algo>
				 friend class RNGAlgorithm;

			};

			template <class T>
			ParameterizedStatusTinyMT* TinyMT<T>::status_host_;

			template <class T>
			ParameterizedStatusTinyMT* TinyMT<T>::status_device_;

		} // end of namespace TinyMT
	} // end of namespace prng

	// shortcut to TinyMT
	using prng::TinyMT::TinyMT;

} // end of namespace shoverand

#endif // TINYMT_HXX
