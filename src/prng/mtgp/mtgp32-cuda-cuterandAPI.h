/*
 *  mtgp32-cuda-cuterandAPI.h
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 12/8/10.
 *  Copyright 2010 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef MTGP32_CUDA_CUTERANDAPI_H
#define MTGP32_CUDA_CUTERANDAPI_H

#include "mtgp-cuda-common.h"
#include "mtgp32-cuda-hostCalled.h"

/*
 * Generator Parameters.
 */
__constant__ uint32_t param_tbl[BLOCK_NUM_MAX][TBL_SIZE];
__constant__ uint32_t temper_tbl[BLOCK_NUM_MAX][TBL_SIZE];
//__constant__ uint32_t single_temper_tbl[BLOCK_NUM_MAX][TBL_SIZE];
__constant__ uint32_t pos_tbl[BLOCK_NUM_MAX];
__constant__ uint32_t sh1_tbl[BLOCK_NUM_MAX];
__constant__ uint32_t sh2_tbl[BLOCK_NUM_MAX];


/* high_mask and low_mask should be set by make_constant(), but
 * did not work.
 * (mask 0xff800000 only valid with exponent 11213)
 */
__constant__ uint32_t mask = 0xff800000;

/**
 * Shared memory
 * The generator's internal status vector.
 */
__shared__ uint32_t status[LARGE_SIZE];

/** Step of the generation. From 0 to 2.
 Used by each thread to generate the correct 
 number of the sequence. 
 */
__shared__ uint32_t step[1024]; // size is here the maximum number of threads within a block


/********************************************************/
/************** begin of device called functions ********/
/************** implied in random numbers generation ****/
/********************************************************/


void make_constant(const mtgp32_params_fast_t params[],
                   int block_num);

/**
 * The function of the recursion formula calculation.
 *
 * @param[in] X1 the farthest part of state array.
 * @param[in] X2 the second farthest part of state array.
 * @param[in] Y a part of state array.
 * @param[in] bid block id.
 * @return output
 */
inline __device__ uint32_t para_rec(uint32_t X1, uint32_t X2, uint32_t Y, int bid) {
   uint32_t X = (X1 & mask) ^ X2;
   uint32_t MAT;
   
   X ^= X << sh1_tbl[bid];
   Y = X ^ (Y >> sh2_tbl[bid]);
   MAT = param_tbl[bid][Y & 0x0f];
   return Y ^ MAT;
}

/**
 * The tempering function.
 *
 * @param[in] V the output value should be tempered.
 * @param[in] T the tempering helper value.
 * @param[in] bid block id.
 * @return the tempered value.
 */
inline __device__ uint32_t temper(uint32_t V, uint32_t T, int bid) {
   uint32_t MAT;
   
   T ^= T >> 16;
   T ^= T >> 8;
   MAT = temper_tbl[bid][T & 0x0f];
   return V ^ MAT;
}



/********************************************************/
/************** end of device called functions **********/
/************** implied in random numbers generation ****/
/********************************************************/




/* Device API */
inline __device__ void mtgp32_init_shared_memory(mtgp32_kernel_status_t* d_status) {

   // set to first step
   step[threadIdx.x] = 0;
   // fill in status for each block
   

   status[threadIdx.x] = 0;
   status[threadIdx.x+blockDim.x] = 0;
   status[threadIdx.x + 2*blockDim.x] = 0;
   status_read(status, d_status, blockIdx.x, threadIdx.x);
   
/*   status[LARGE_SIZE - N + tid] = 7;
   if (tid < N - THREAD_NUM) {
      status[LARGE_SIZE - N + THREAD_NUM + tid]
      = 8;
   }*/
   __syncthreads();
   
}

/**
 * device function.
 * This function generates 32-bit unsigned integers in d_data
 *
 * @params[in,out] d_status kernel I/O data
 * @params[out] d_data output
 * @params[in] size number of output data requested.
 *
 */
inline __device__ uint32_t mtgp32_uint32_device() {
   const int bid = blockIdx.x;
   const int tid = threadIdx.x;
   int pos = pos_tbl[bid];
   uint32_t r;
   uint32_t o;
   
   // keep up an history of previous generation formulas 
   // in order to use the 3 different ones below

   // each thread is gonna take the same path!
   switch (step[tid]) {
         
         ////////// first step
      case 0:
         // next_state
         r = para_rec(status[LARGE_SIZE - N + tid],
                      status[LARGE_SIZE - N + tid + 1],
                      status[LARGE_SIZE - N + tid + pos],
                      bid);
         status[tid] = r;
         
         // get the random number
         o = temper(r, status[tid - N + LARGE_SIZE + pos - 1], bid);
         
         __syncthreads();
         break;
         
         ////////// second step
      case 1:  
         r = para_rec(status[(4 * THREAD_NUM - N + tid) % LARGE_SIZE],
                      status[(4 * THREAD_NUM - N + tid + 1) % LARGE_SIZE],
                      status[(4 * THREAD_NUM - N + tid + pos) % LARGE_SIZE],
                      bid);
         status[tid + THREAD_NUM] = r;
         
         o = temper(r,
                    status[(tid - N + 4 * THREAD_NUM + pos - 1) % LARGE_SIZE],
                    bid);
         
         __syncthreads();
         break;
         
         ////////// third step
      case 2:
         r = para_rec(status[2 * THREAD_NUM - N + tid],
                      status[2 * THREAD_NUM - N + tid + 1],
                      status[2 * THREAD_NUM - N + tid + pos],
                      bid);
         
         status[tid + 2 * THREAD_NUM] = r;
         
         o = temper(r, status[tid - N + 2 * THREAD_NUM + pos - 1], bid);
         __syncthreads();
         break;
   }
   __syncthreads();

   step[tid] = (step[tid] + 1) % 3;
   return o; // TODO change to o
}





#endif // MTGP32_CUDA_CUTERANDAPI_H
