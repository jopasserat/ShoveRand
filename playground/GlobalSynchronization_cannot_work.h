#ifndef GLOBAL_SYNCHRONIZATION
#define GLOBAL_SYNCHRONIZATION

#include <cuda.h>


namespace shoverand {
	namespace utils {

		/** Integer stored in device's global memory to implement
		 *  a barrier between all the threads of a kernel.
		 */
		__device__ int globalBarrier;
		
		/** A call to this function will synchronize every thread
		*  within the current kernel.
		*
		* @see __syncthreads
		* @author Tadashi Yamazaki (original author)
		* @author jH@CKtheRipper (modifications)
		*/
		__device__ void __syncAllThreads() {
			
			// select a representative thread for each block
			if (threadIdx.x == 0) {
				atomicAdd(&globalBarrier, 1);
				
				// now enable the representative thread of the representative block only
				if (blockIdx.x == 0) {
						// wait until the value of the barrier becomes equal to the number of block]
						// in the kernel...
						while (atomicAdd(&globalBarrier, 0) < (gridDim.x * gridDim.y) );
						// ... and clear it!
						atomicExch(&globalBarrier, 0);
				} else {
						// every thread that is not representative waits until
						// the barrier is cleared
						while (atomicAdd(&globalBarrier, 0) > 0);
				}
			}
			__syncthreads();
		}
		
	} // end of namespace utils
} // end of namespace shoverand

#endif // GLOBAL_SYNCHRONIZATION
