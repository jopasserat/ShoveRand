#include <shoverand/prng/mrg32k3a/MRG32k3a.hxx>
#include <shoverand/core/RNG.hxx>


#include <shoverand/prng/tinymt/utils.hxx>

#include <shoverand/distribution/variate_generator.hpp>
#include <shoverand/distribution/uniform_01.hpp>

#include <cstdlib>

#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>

#include <algorithm> // std::accumulate

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

	std::vector<int> blocksInKernels;
	blocksInKernels.push_back(20);
	blocksInKernels.push_back(60);
	blocksInKernels.push_back(10);

	std::vector<int> threadsPerBlocksInKernels;
	threadsPerBlocksInKernels.push_back(64);
	threadsPerBlocksInKernels.push_back(128);
	threadsPerBlocksInKernels.push_back(256);

	int block_num = std::accumulate ( blocksInKernels.begin(), blocksInKernels.end(), 0 );
	int thread_num = std::accumulate ( threadsPerBlocksInKernels.begin(), threadsPerBlocksInKernels.end(), 0 );
	int data_size = block_num * thread_num * sizeof(float);



	if (cudaGetLastError() != cudaSuccess) {
		std::cerr << "error has occurred before kernel call." << std::endl;
		exit(1);
	}



	// allocate memory to get results back on the host
	float* h_data = new float[1024*1024];
	if (h_data == NULL) {
		std::cerr << "failure in allocating host memory for output data." << std::endl;
		exit(3);
	}
	bzero(h_data, 1024*1024*sizeof(float));

	float* d_bigdata;
	cutilSafeCall( cudaMalloc( (void**) &d_bigdata, sizeof(float) * 1024 * 1024) );
	cutilSafeCall( cudaMemset( d_bigdata, 0, sizeof(float) * 1024 * 1024));



	RNG< float, MRG32k3a > ::init ( blocksInKernels );
	//for (int i = 0; i < 10; ++i) {

	testMultiple1<<< blocksInKernels[0], threadsPerBlocksInKernels[0] >>>  ( d_bigdata );
	cudaError_t e = cudaGetLastError();
	if (e != cudaSuccess) {
		std::cerr << "failure in kernel call.\n" << cudaGetErrorString(e) << std::endl;
		exit(2);
	}
	cudaDeviceSynchronize();

	cutilSafeCall(
			cudaMemcpy(h_data,
					d_bigdata,
					1024*1024,
					cudaMemcpyDeviceToHost));

	for (int i = 0; i < blocksInKernels[0] * threadsPerBlocksInKernels[0]; ++i) {
		std::cout << "h_data[" << i << "] = " << h_data[i] << std::endl;
	}

	// 		testMultiple2<<< blocksInKernels[1], threadsPerBlocksInKernels[1] >>> ( d_bigdata );
	// 		cudaDeviceSynchronize();
	// 		testMultiple3<<< blocksInKernels[2], threadsPerBlocksInKernels[2] >>> ( d_bigdata );
	// 		cudaDeviceSynchronize();
	//    }




	// release memory
	RNG< float, MRG32k3a > :: release();
	delete [] h_data;
	cutilSafeCall(cudaFree(d_bigdata));

	cudaMemGetInfo(&memFree, &memTotal);
	std :: cerr << "Available device memory at the end: " << memFree << "/" << memTotal << std::endl;
}
