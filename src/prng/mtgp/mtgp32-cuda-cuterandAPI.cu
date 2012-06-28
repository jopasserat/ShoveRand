/**
 * Sample Program for CUDA 2.3
 * written by M.Saito (saito@math.sci.hiroshima-u.ac.jp)
 *
 * This sample uses texture reference.
 * The generation speed of PRNG using texture is faster than using
 * constant tabel on Geforce GTX 260.
 *
 * MTGP32-11213
 * This program generates 32-bit unsigned integers.
 * The period of generated integers is 2<sup>11213</sup>-1.
 * This also generates single precision floating point numbers.
 */
#define __STDC_FORMAT_MACROS 1
#define __STDC_CONSTANT_MACROS 1
#include <stdio.h>
#include <cuda.h>
#include <shoverand/util/myCutil.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>
#include <stdlib.h>

#include "mtgp32-cuda-cuterandAPI.h"

//#include "mtgp-cuda-tex.h"
#include "mtgp-cuda-common.h"
#include "mtgp32-cuda-hostCalled.h"
extern "C" {
   #include "mtgp32-fast.h"
}




/********************************************************/
/********** begin of intialization functions ************/
/********************************************************/

/**
 * This function sets constants in device memory.
 * @param[in] params input, MTGP32 parameters.
 */
void make_constant(const mtgp32_params_fast_t params[],
    int block_num) {
    const int size1 = sizeof(uint32_t) * block_num;
    const int size2 = sizeof(uint32_t) * block_num * TBL_SIZE;
    uint32_t *h_pos_tbl;
    uint32_t *h_sh1_tbl;
    uint32_t *h_sh2_tbl;
    uint32_t *h_param_tbl;
    uint32_t *h_temper_tbl;
    uint32_t *h_single_temper_tbl;
#if 0
    uint32_t *h_mask;
#endif
    h_pos_tbl = (uint32_t *)malloc(size1);
    h_sh1_tbl = (uint32_t *)malloc(size1);
    h_sh2_tbl = (uint32_t *)malloc(size1);
    h_param_tbl = (uint32_t *)malloc(size2);
    h_temper_tbl = (uint32_t *)malloc(size2);
    h_single_temper_tbl = (uint32_t *)malloc(size2);
#if 0
    h_mask = (uint32_t *)malloc(sizeof(uint32_t));
#endif
    if (h_pos_tbl == NULL
	|| h_sh1_tbl == NULL
	|| h_sh2_tbl == NULL
	|| h_param_tbl == NULL
	|| h_temper_tbl == NULL
	|| h_single_temper_tbl == NULL
#if 0
	|| h_mask == NULL
#endif
	) {
	printf("failure in allocating host memory for constant table.\n");
	exit(1);
    }
#if 0
    h_mask = params[0].mask;
#endif
    for (int i = 0; i < block_num; i++) {
	h_pos_tbl[i] = params[i].pos;
	h_sh1_tbl[i] = params[i].sh1;
	h_sh2_tbl[i] = params[i].sh2;
	for (int j = 0; j < TBL_SIZE; j++) {
	    h_param_tbl[i * TBL_SIZE + j] = params[i].tbl[j];
	    h_temper_tbl[i * TBL_SIZE + j] = params[i].tmp_tbl[j];
	    h_single_temper_tbl[i * TBL_SIZE + j] = params[i].flt_tmp_tbl[j];
	}
    }
    // copy from malloc area only
    myCutilSafeCall(cudaMemcpyToSymbol(pos_tbl, h_pos_tbl, size1));
    myCutilSafeCall(cudaMemcpyToSymbol(sh1_tbl, h_sh1_tbl, size1));
    myCutilSafeCall(cudaMemcpyToSymbol(sh2_tbl, h_sh2_tbl, size1));
    myCutilSafeCall(cudaMemcpyToSymbol(param_tbl, h_param_tbl, size2));
    myCutilSafeCall(cudaMemcpyToSymbol(temper_tbl, h_temper_tbl, size2));
    myCutilSafeCall(cudaMemcpyToSymbol(single_temper_tbl,
				      h_single_temper_tbl, size2));
#if 0
    myCutilSafeCall(cudaMemcpyToSymbol(&mask,
				      &h_mask, sizeof(uint32_t)));
#endif
    free(h_pos_tbl);
    free(h_sh1_tbl);
    free(h_sh2_tbl);
    free(h_param_tbl);
    free(h_temper_tbl);
    free(h_single_temper_tbl);
#if 0
    free(h_mask);
#endif
}


/**
 * This function sets texture lookup table.
 * @param params input, MTGP32 parameters.
 * @param d_texture_tbl device memory used for texture bind
 * @param block_num block number used for kernel call
 */
/*void make_texture(const mtgp32_params_fast_t params[],
                  uint32_t *d_texture_tbl[3],
                  int block_num) {
   const int count = block_num * TBL_SIZE;
   const int size = sizeof(uint32_t) * count;
   uint32_t *h_texture_tbl[3];
   int i, j;
   for (i = 0; i < 3; i++) {
      h_texture_tbl[i] = (uint32_t *)malloc(size);
      if (h_texture_tbl[i] == NULL) {
         for (j = 0; j < i; j++) {
            free(h_texture_tbl[i]);
         }
         printf("failure in allocating host memory for constant table.\n");
         exit(1);
      }
   }
   for (int i = 0; i < block_num; i++) {
      for (int j = 0; j < TBL_SIZE; j++) {
         h_texture_tbl[0][i * TBL_SIZE + j] = params[i].tbl[j];
         h_texture_tbl[1][i * TBL_SIZE + j] = params[i].tmp_tbl[j];
         h_texture_tbl[2][i * TBL_SIZE + j] = params[i].flt_tmp_tbl[j];
      }
   }
   myCutilSafeCall(cudaMemcpy(d_texture_tbl[0], h_texture_tbl[0], size,
                             cudaMemcpyHostToDevice));
   myCutilSafeCall(cudaMemcpy(d_texture_tbl[1], h_texture_tbl[1], size,
                             cudaMemcpyHostToDevice));
   myCutilSafeCall(cudaMemcpy(d_texture_tbl[2], h_texture_tbl[2], size,
                             cudaMemcpyHostToDevice));
   tex_param_ref.filterMode = cudaFilterModePoint;
   tex_temper_ref.filterMode = cudaFilterModePoint;
   tex_single_ref.filterMode = cudaFilterModePoint;
   myCutilSafeCall(cudaBindTexture(0, tex_param_ref, d_texture_tbl[0], size));
   myCutilSafeCall(cudaBindTexture(0, tex_temper_ref, d_texture_tbl[1], size));
   myCutilSafeCall(cudaBindTexture(0, tex_single_ref, d_texture_tbl[2], size));
   free(h_texture_tbl[0]);
   free(h_texture_tbl[1]);
   free(h_texture_tbl[2]);
}
*/
/********************************************************/
/************ end of intialization functions ************/
/********************************************************/


/********************************************************/
/************************ DEVICE API ********************/
/********************************************************/


