/*
 *  mtgp32-cuda-hostCalled.h
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 12/8/10.
 *  Copyright 2010 ISIMA/LIMOS. All rights reserved.
 *
 */


#ifndef MTGP32_CUDA_HOSTCALLED
#define MTGP32_CUDA_HOSTCALLED

#include "mtgp-cuda-common.h"


/**
 * Read the internal state vector from kernel I/O data, and
 * put them into shared memory.
 *
 * @param[out] status shared memory.
 * @param[in] d_status kernel I/O data
 * @param[in] bid block id
 * @param[in] tid thread id
 */
inline __device__ void status_read(uint32_t status[LARGE_SIZE],
                            const mtgp32_kernel_status_t *d_status,
                            int bid,
                            int tid) {
   status[LARGE_SIZE - N + tid] = d_status[bid].status[tid];
   if (tid < N - THREAD_NUM) {
      status[LARGE_SIZE - N + THREAD_NUM + tid]
      = d_status[bid].status[THREAD_NUM + tid];
   }
   __syncthreads();
}

/**
 * Read the internal state vector from shared memory, and
 * write them into kernel I/O data.
 *
 * @param[out] d_status kernel I/O data
 * @param[in] status shared memory.
 * @param[in] bid block id
 * @param[in] tid thread id
 */
inline __device__ void status_write(mtgp32_kernel_status_t *d_status,
                             const uint32_t status[LARGE_SIZE],
                             int bid,
                             int tid) {
   
   d_status[bid].status[tid] = status[LARGE_SIZE - N + tid];
   if (tid < N - THREAD_NUM) {
      d_status[bid].status[THREAD_NUM + tid]
      = status[4 * THREAD_NUM - N + tid];
   }
   __syncthreads();
}

#endif // MTGP32_CUDA_HOSTCALLED
