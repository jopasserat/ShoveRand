/*
 *  \file mtgp-cuda-common.h Common functions prototypes.
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 12/7/10.
 *  Copyright 2010 ISIMA/LIMOS. All rights reserved.
 *  
 */


#ifndef MTGP_CUDA_COMMON_H
#define MTGP_CUDA_COMMON_H


extern "C" {
   #include "mtgp32-fast.h"
}

// previously in mtgp32dc-param-11213.c
#define MTGPDC_MEXP 11213
#define MTGPDC_N 351
#define MTGPDC_FLOOR_2P 256
#define MTGPDC_CEIL_2P 512
#define MTGPDC_PARAM_TABLE mtgp32dc_params_fast_11213
/*
#define MTGPDC_MEXP 3217
#define MTGPDC_N 101
#define MTGPDC_FLOOR_2P 64
#define MTGPDC_CEIL_2P 128
#define MTGPDC_PARAM_TABLE mtgp32dc_params_fast_3217
*/
#define MEXP 11213
#define N MTGPDC_N
#define THREAD_NUM MTGPDC_FLOOR_2P
#define LARGE_SIZE (THREAD_NUM * 3)
//#define BLOCK_NUM 32
#define BLOCK_NUM_MAX 200
#define TBL_SIZE 16



extern mtgp32_params_fast_t mtgp32dc_params_fast_11213[]; 
//extern mtgp32_params_fast_t mtgp32dc_params_fast_3217[]; 
// end


/**
 * kernel I/O
 * This structure must be initialized before first use.
 */
struct mtgp32_kernel_status_t {
   uint32_t status[N];
};


/**
 * This function sets constants in device memory.
 * @param params input, MTGP32 parameters.
 */
void make_constant_param(const mtgp32_params_fast_t params[],
                         int block_num);

/**
 * This function sets texture lookup table.
 * @param params input, MTGP32 parameters.
 * @param d_texture_tbl device memory used for texture bind
 * @param block_num block number used for kernel call
 */
void make_texture(const mtgp32_params_fast_t params[],
                  uint32_t *d_texture_tbl[3],
                  int block_num);


int get_suitable_block_num(int word_size, int thread_num, int large_size);


/**
 * This function initializes kernel I/O data.
 * @param d_status output kernel I/O data.
 * @param params MTGP32 parameters. needed for the initialization.
 */
void make_kernel_data(mtgp32_kernel_status_t *d_status,
                      mtgp32_params_fast_t params[],
                      int block_num);




#endif // MTGP_CUDA_COMMON_H
