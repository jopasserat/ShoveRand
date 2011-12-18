#include <shoverand/prng/mrg32k3a/MRG32k3a.hxx>
#include <shoverand/core/RNG.hxx>


#include <shoverand/prng/tinymt/utils.hxx>

#include <shoverand/distribution/variate_generator.hpp>
#include <shoverand/distribution/uniform_01.hpp>

#include <cstdlib>

#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>


#include <iostream> // debug purposes

// shortcuts :)
using shoverand::RNG;
using shoverand::MRG32k3a;

__global__ void testMultiple1(float* ddata) {

	RNG < float, MRG32k3a > 	rng;
   
	ddata[blockDim.x * blockIdx.x + threadIdx.x] = rng.next();
}

__global__ void testMultiple2(float* ddata) {

	RNG < float, MRG32k3a > 	rng;

	ddata[blockDim.x * blockIdx.x + threadIdx.x] = rng.next();
}

__global__ void testMultiple3(float* ddata) {

	RNG < float, MRG32k3a > 	rng;

	ddata[blockDim.x * blockIdx.x + threadIdx.x] = rng.next();
}

void testMultipleInitializations() {

	size_t memFree;
	size_t memTotal;

	cudaMemGetInfo(&memFree, &memTotal);
	std :: cerr << "Available device memory at the beginning: " << memFree << "/" << memTotal << std::endl;

   int block_num = 3;
   int thread_num = 512;
   int data_size = block_num * thread_num * sizeof(double);
   
   double* d_data;
   double* h_data;
   cudaError_t e;
   float gputime;

   
   // create timers 
   cudaEvent_t start;
   cudaEvent_t stop;
   cudaEventCreate(&start);
   cudaEventCreate(&stop);
   
   
   // allocate memory for data on device
   cutilSafeCall( cudaMalloc((void**) &d_data, data_size) );
   cutilSafeCall( cudaMemset(d_data, 0, data_size) );


   if (cudaGetLastError() != cudaSuccess) {
      std::cerr << "error has occured before kernel call." << std::endl;
      exit(1);
   }
   
	
   cudaEventRecord(start, 0);
   

   float* d_bigdata;
	cutilSafeCall( cudaMalloc( (void**) &d_bigdata, sizeof(float) * 1024*1024) );
	
	std::vector<int> paramVector;
	paramVector.push_back(20);
	paramVector.push_back(60);
	paramVector.push_back(10);

	RNG< float, MRG32k3a > ::init ( paramVector );
	//for (int i = 0; i < 10; ++i) {
	
		testMultiple1<<< 20, 64 >>>  ( d_bigdata );
		cudaDeviceSynchronize();
// 		testMultiple2<<< 60, 128 >>> ( d_bigdata );
// 		cudaDeviceSynchronize();
// 		testMultiple3<<< 10, 256 >>> ( d_bigdata );
// 		cudaDeviceSynchronize();
//    }


   cudaEventRecord(stop, 0);
   cudaEventSynchronize(stop);
   
   e = cudaGetLastError();
   if (e != cudaSuccess) {
      std::cerr << "failure in kernel call.\n" << cudaGetErrorString(e) << std::endl;
      exit(2);
   }
   
   // allocate memory to get results back on the host
   h_data = new double[data_size];
   
   if (h_data == NULL) {
      std::cerr << "failure in allocating host memory for output data." << std::endl;
      exit(3);
   }
   
   cutilSafeCall(
                 cudaMemcpy(h_data,
                            d_bigdata,
                            data_size,
                            cudaMemcpyDeviceToHost));
   cudaEventElapsedTime(&gputime, start, stop);
   
   
   for (int i = 0; i < block_num * thread_num; ++i) {
		std::cout << "h_data[" << i << "] = " << h_data[i] << std::endl;
   }

   std::cout << "generated numbers: " << thread_num * block_num << std::endl;
   std::cout << "Processing time: " << gputime << " (ms)" << std::endl;
   std::cout << "Samples per second: " << (thread_num * block_num) / (gputime * 0.001) << std::endl; 
   
   //free memory
   cudaEventDestroy(start);
   cudaEventDestroy(stop);

	RNG< float, MRG32k3a > :: release();
	
   delete [] h_data;
   cutilSafeCall(cudaFree(d_data));   

	cudaMemGetInfo(&memFree, &memTotal);
	std :: cerr << "Available device memory at the end: " << memFree << "/" << memTotal << std::endl;
}
