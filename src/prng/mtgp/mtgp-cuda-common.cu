/*
 * Sample Program for CUDA 2.3
 * written by M.Saito (saito@math.sci.hiroshima-u.ac.jp)
 *
 * This sample uses texture reference.
 * The generation speed of PRNG using texture is faster than using
 * constant tabel on Geforce GTX 260.
 *
 * MTGP32-11213
 * This program generates 32-bit unsigned integers.
 * The period of generated integers is 2<sup>23209</sup>-1.
 * This also generates single precision floating point numbers.
 */


#include <stdio.h>
#include <cuda.h>
#include <cutil.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>
#include <stdlib.h>

#include "mtgp-cuda-common.h"

void printParams(mtgp32_params_fast_t* params);

/*
int get_suitable_block_num(int word_size, int thread_num, int large_size) {
    cudaDeviceProp dev;
    CUdevice cuDevice;
    int max_thread_dev;
    int max_block, max_block_mem, max_block_dev;
    int major, minor, ver;

    CUDA_SAFE_CALL(cudaGetDeviceProperties(&dev, 0));
    cuDeviceGet(&cuDevice, 0);
    cuDeviceComputeCapability(&major, &minor, cuDevice);
    max_block_mem = dev.sharedMemPerBlock / (large_size * word_size);
    if (major == 9999 && minor == 9999) {
	return -1;
    }
    ver = major * 100 + minor;
    if (ver <= 101) {
	max_thread_dev = 768;
    } else if (ver <= 103) {
	max_thread_dev = 1024;
    } else {
	max_thread_dev = 1024;
    }
    max_block_dev = max_thread_dev / thread_num;
    if (max_block_mem < max_block_dev) {
	max_block = max_block_mem;
    } else {
	max_block = max_block_dev;
    }
    return max_block * dev.multiProcessorCount;
}
*/

/**
 * This function initializes kernel I/O data.
 * @param d_status output kernel I/O data.
 * @param params MTGP32 parameters. needed for the initialization.
 */
void make_kernel_data(mtgp32_kernel_status_t *d_status,
                      mtgp32_params_fast_t params[],
                      int block_num) {
   mtgp32_kernel_status_t* h_status = (mtgp32_kernel_status_t *) malloc(block_num *
                                                                        sizeof(mtgp32_kernel_status_t));
   
   if (h_status == NULL) {
      printf("failure in allocating host memory for kernel I/O data.\n");
      exit(8);
   }
   for (int i = 0; i < block_num; i++) {
   
   //   printParams(&params[i]);
      mtgp32_init_state(&(h_status[i].status[0]), &params[i], i + 1);
   }
#if defined(DEBUG)
   
   printf("h_status[0].status[0]:%08x\n", h_status[0].status[0]);
   printf("h_status[0].status[1]:%08x\n", h_status[0].status[1]);
   printf("h_status[0].status[2]:%08x\n", h_status[0].status[2]);
   printf("h_status[0].status[3]:%08x\n\n", h_status[0].status[3]);
   
   printf("h_status[1].status[0]:%08x\n", h_status[1].status[0]);
   printf("h_status[1].status[1]:%08x\n", h_status[1].status[1]);
   printf("h_status[1].status[2]:%08x\n", h_status[1].status[2]);
   printf("h_status[1].status[3]:%08x\n\n", h_status[1].status[3]);
   
   printf("h_status[2].status[0]:%08x\n", h_status[2].status[0]);
   printf("h_status[2].status[1]:%08x\n", h_status[2].status[1]);
   printf("h_status[2].status[2]:%08x\n", h_status[2].status[2]);
   printf("h_status[2].status[3]:%08x\n\n", h_status[2].status[3]);
#endif
   CUDA_SAFE_CALL(cudaMemcpy(d_status,
                             h_status,
                             sizeof(mtgp32_kernel_status_t) * block_num,
                             cudaMemcpyHostToDevice));
   free(h_status);
}


void printParams(mtgp32_params_fast_t* params) {

      printf ("Printing parameters:\n \
            mexp: %d\n\
            pos: %d\n\
            sh1: %d\n\
            sh2: %d\n", params->mexp, params->pos, params->sh1, params->sh2);
  
      for (int i = 0; i < 16; ++i)     printf ("tbl[%d]= %u\n", i, params->tbl[i]);
      for (int i = 0; i < 16; ++i)     printf ("tmp_tbl[%d]= %u\n", i, params->tmp_tbl[i]);
      for (int i = 0; i < 16; ++i)     printf ("flt_tmp_tbl[%d]= %u\n", i, params->flt_tmp_tbl[i]);
      printf("mask: %u\n", params->mask);
      for (int i = 0; i < 21; ++i)     printf ("poly_sha1[%d]= %d\n", i, params->poly_sha1[i]);
}
