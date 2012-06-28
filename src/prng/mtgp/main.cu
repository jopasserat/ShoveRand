/*
 *  main.cpp
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 12/7/10.
 *  Copyright 2010 ISIMA/LIMOS. All rights reserved.
 *
 */


//#include <RNG.hxx>
//#include <MTGP.hxx>




extern "C" {
   #include <stdio.h>
   #include <stdlib.h>
   #include <errno.h>
}

#include <shoverand/util/myCutil.h>
#include "mtgp-cuda-common.h"
#include "mtgp32-cuda-cuterandAPI.h"



#define DATA_SIZE LARGE_SIZE

//typedef RNG<int, MTGP> MyRNG;

/*
__global__ void testShoveRand(uint32_t* ddata, MyRNG* rngTab) {
   
   MyRNG rng; // = rngTab + threadIdx.x;
   
   //rng->next(threadIdx.x);
   ddata[threadIdx.x] = rng.foo();
   
//   ddata[blockDim.x * blockIdx.x + threadIdx.x] = status[threadIdx.x + blockDim.x*blockIdx.x];
//   ddata[threadIdx.x] = status[threadIdx.x];
}*/


__global__ void testMTGP(uint32_t* ddata, mtgp32_kernel_status_t* dstatus) {
   mtgp32_init_shared_memory(dstatus);
   __syncthreads();

	for (int i = 0; i < 100; ++i)   mtgp32_uint32_device();
   
   ddata[blockDim.x * blockIdx.x + threadIdx.x] = mtgp32_uint32_device();
//   ddata[blockDim.x * blockIdx.x + threadIdx.x] = status[threadIdx.x + blockDim.x*blockIdx.x];
//   ddata[threadIdx.x] = status[threadIdx.x];

   __syncthreads();
}


int main(int argc, char *argv[])
{
   // LARGE_SIZE is a multiple of 16
   int num_data = 10000000;
   int block_num = 200;
   int num_unit;
   int r;
   mtgp32_kernel_status_t *d_status;
   uint32_t* d_texture[3];
   uint32_t* d_data;
   unsigned int timer = 0;
   uint32_t* h_data;
   cudaError_t e;
   float gputime;
   
   CUT_DEVICE_INIT(argc, argv);
   
   myCutilSafeCall(cudaMalloc((void**)&d_status,
                             sizeof(mtgp32_kernel_status_t) * block_num));
   myCutilSafeCall(cudaMalloc((void**)&d_texture[0],
                             sizeof(uint32_t) * block_num * TBL_SIZE));
   myCutilSafeCall(cudaMalloc((void**)&d_texture[1],
                             sizeof(uint32_t) * block_num * TBL_SIZE));
   myCutilSafeCall(cudaMalloc((void**)&d_texture[2],
                             sizeof(uint32_t) * block_num * TBL_SIZE));

   make_constant(MTGPDC_PARAM_TABLE, block_num);
  // make_texture(MTGPDC_PARAM_TABLE, d_texture, block_num);
   make_kernel_data(d_status, MTGPDC_PARAM_TABLE, block_num);
   
   


    printf("generating 32-bit unsigned random numbers.\n");
    myCutilSafeCall(cudaMalloc((void**)&d_data, sizeof(uint32_t) * block_num * THREAD_NUM));
    myCutilSafeCall(cudaMemset(d_data, 0, block_num * THREAD_NUM));
    CUT_SAFE_CALL(cutCreateTimer(&timer));
    h_data = (uint32_t *) malloc(sizeof(uint32_t) * block_num * THREAD_NUM);
    if (h_data == NULL) {
    printf("failure in allocating host memory for output data.\n");
    exit(1);
    }
    CUT_SAFE_CALL(cutStartTimer(timer));
    if (cudaGetLastError() != cudaSuccess) {
	printf("error has been occured before kernel call.\n");
	exit(1);
    }

/*
 	MyRNG rng_host;
   MyRNG* rng_device;
   
   rng_host.init();
   
   myCutilSafeCall(cudaMalloc((void**)&rng_device, sizeof(MyRNG) * THREAD_NUM));
   testShoveRand<<< block_num, THREAD_NUM >>>(d_data, rng_device);
*/

    /* kernel call */
//    testMTGP<<< block_num, THREAD_NUM >>>(d_data, d_status);
    
    
   // cudaThreadSynchronize();

    e = cudaGetLastError();
    if (e != cudaSuccess) {
	printf("failure in kernel call.\n%s\n", cudaGetErrorString(e));
	exit(1);
    }
    CUT_SAFE_CALL(cutStopTimer(timer));
    myCutilSafeCall(
	cudaMemcpy(h_data,
		   d_data,
		   sizeof(uint32_t) * block_num * THREAD_NUM,
		   cudaMemcpyDeviceToHost));
    gputime = cutGetTimerValue(timer);


    for (int i = 0; i < block_num * THREAD_NUM; ++i) {
       printf ("h_data[%d] = %u\n", i, h_data[i]);
    }
      
   
    printf("generated numbers: %d\n", THREAD_NUM * block_num);
    printf("Processing time: %f (ms)\n", gputime);
    printf("Samples per second: %E \n", (THREAD_NUM * block_num) / (gputime * 0.001));
    CUT_SAFE_CALL(cutDeleteTimer(timer));
    //free memories
    free(h_data);
    myCutilSafeCall(cudaFree(d_data));

   
   
   
   
   //finalize
   myCutilSafeCall(cudaFree(d_status));
   myCutilSafeCall(cudaFree(d_texture[0]));
   myCutilSafeCall(cudaFree(d_texture[1]));
   myCutilSafeCall(cudaFree(d_texture[2]));
#ifdef NEED_PROMPT
   CUT_EXIT(argc, argv);
#endif
}
