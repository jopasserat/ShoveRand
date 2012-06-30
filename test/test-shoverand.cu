#include <shoverand/prng/mrg32k3a/MRG32k3a.hxx>
#include <shoverand/prng/tinymt/TinyMT.hxx>
#include <shoverand/core/RNG.hxx>

#include <shoverand/distribution/variate_generator.hpp>
#include <shoverand/distribution/uniform_01.hpp>

#include <cstdlib>

#include <cuda.h>
#include <shoverand/util/myCutil.h>

#include <iostream> // debug purposes


// shortcuts :)
using shoverand::RNG;
using shoverand::MRG32k3a;
using shoverand::TinyMT;

typedef RNG < float, MRG32k3a > rng_type;


/** Kernel testing PRNG implementations */
__global__ void testPRNG(double* ddata) {

	// this call might not work with devices of
	// compute capability < 2.x
	rng_type 	rng;

	// TODO old devices compliant version

	ddata[blockDim.x * blockIdx.x + threadIdx.x] = rng.next();
	__syncthreads();
}


/** Kernel testing variate_generator facility */
//__global__ void testVariateGenerator(double* ddata,  ParameterizedStatusType* param) {
__global__ void testVariateGenerator(double* ddata) {

	// this call might not work with devices of
	// compute capability < 2.x
	typedef rng_type				    				 randomengine;
	typedef shoverand::uniform_01< float, float>         distribution;

	randomengine 	rng;

	distribution myDistribution;

	shoverand::variate_generator
	<
	randomengine,
	distribution
	>
	myVariateGenerator(rng, myDistribution);

	ddata[blockDim.x * blockIdx.x + threadIdx.x] = myVariateGenerator();
}


int main(int, char **) {

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
	myCutilSafeCall( cudaMalloc((void**) &d_data, data_size) );
	myCutilSafeCall( cudaMemset(d_data, 0, data_size) );


	if (cudaGetLastError() != cudaSuccess) {
		std::cerr << "error has occured before kernel call." << std::endl;
		exit(1);
	}

	// init step from host side
	rng_type ::init(block_num);

	cudaEventRecord(start, 0);


	// --- kernel calls ---
	//	testVariateGenerator<<< block_num, thread_num >>>(d_data);
	testPRNG<<< block_num, thread_num >>>(d_data);

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

	myCutilSafeCall(
			cudaMemcpy(h_data,
					d_data,
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

	// release memory allocated on device from host
	rng_type :: release();

	delete [] h_data;
	myCutilSafeCall(cudaFree(d_data));

	cudaMemGetInfo(&memFree, &memTotal);
	std :: cerr << "Available device memory at the end: " << memFree << "/" << memTotal << std::endl;
}
