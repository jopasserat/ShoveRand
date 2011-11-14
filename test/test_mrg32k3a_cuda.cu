//#include <shoverand/prng/mrg32k3a/ParameterizedStatus.h>
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
//typedef RNG< float, MRG32k3a > ::ParameterizedStatusType ParameterizedStatusType;


/** Kernel testing MRG32k3a implementation */
//__global__ void testMRG32k3a(double* ddata,  ParameterizedStatusType* param) {
__global__ void testMRG32k3a(double* ddata) {

	// this call might not work with devices of
	// compute capability < 2.x
	RNG < float, MRG32k3a > 	rng;
	//rng.init();

   // TODO old devices compliant version
   
	ddata[blockDim.x * blockIdx.x + threadIdx.x] = rng.next();
   __syncthreads();
}


/** Kernel testing variate_generator facility */
//__global__ void testVariateGenerator(double* ddata,  ParameterizedStatusType* param) {
__global__ void testVariateGenerator(double* ddata) {

	// this call might not work with devices of
	// compute capability < 2.x
	typedef RNG < float, MRG32k3a >  				 randomengine;
	typedef boost::uniform_01< float, float>      distribution;

	randomengine 	rng;
	//rng.init();

	distribution myDistribution;

	boost::variate_generator
         <
         randomengine,
         distribution
         >
         myVariateGenerator(rng, myDistribution);
   
	ddata[blockDim.x * blockIdx.x + threadIdx.x] = myVariateGenerator();
}


int main(int, char **) {

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
   
	RNG< float, MRG32k3a > ::init(block_num);

   cudaEventRecord(start, 0);
   

   // kernel call
   //testMRG32k3a<<< block_num, thread_num >>>(d_data, status_device);
	//testVariateGenerator<<< block_num, thread_num >>>(d_data, status_device);
	testMRG32k3a<<< block_num, thread_num >>>(d_data);
	//testVariateGenerator<<< block_num, thread_num >>>(d_data);
   
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
   
	RNG< float, MRG32k3a > :: release();
   delete [] h_data;
   cutilSafeCall(cudaFree(d_data));   
}
