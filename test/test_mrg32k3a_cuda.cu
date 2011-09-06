// #include <Stream.cu> // already included by ParameterizedStatus.h
#include <ParameterizedStatus.h>
#include <SubStream.h>
#include <MRG32k3a.hxx>

#include <cstdlib>

#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>


#include <iostream> // debug purposes

// shortcuts :)
using shoverand::prng::core::RNG;
typedef RNG< float, MRG32k3a::MRG32k3a > ::ParameterizedStatusType ParameterizedStatusType;



__global__ void testMRG32k3a(double* ddata,  ParameterizedStatusType* param) {

	// this call could not work with devices of
	// compute capability < 2.x
	//MRG32k3a::SubStream s(param);

	RNG < float, MRG32k3a::MRG32k3a > 	rng(param);
	rng.init();

   // old devices compliant version
//    MRG32k3a::SubStream* s = allSubStreams + (blockDim.x * blockIdx.x + threadIdx.x);
//    s->init(allStreams);
   
	ddata[blockDim.x * blockIdx.x + threadIdx.x] = rng.next(); // IT WORKS!!!!!
   __syncthreads();
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



	ParameterizedStatusType* 	 status_host = new MRG32k3a::ParameterizedStatusMRG32k3a(); // TODO change to builder method
	status_host->setUp(block_num);
   ParameterizedStatusType*    status_device;
   cutilSafeCall( cudaMalloc((void**) &status_device, sizeof(ParameterizedStatusType)) );  
   cutilSafeCall( cudaMemcpy(status_device, status_host, sizeof(ParameterizedStatusType), cudaMemcpyHostToDevice) );


   if (cudaGetLastError() != cudaSuccess) {
      std::cerr << "error has occured before kernel call." << std::endl;
      exit(1);
   }
   
   cudaEventRecord(start, 0);
   

   // kernel call
   testMRG32k3a<<< block_num, thread_num >>>(d_data, status_device);
   
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
   
   //free memories
   cudaEventDestroy(start);
   cudaEventDestroy(stop);
   
   delete [] h_data;
   cutilSafeCall(cudaFree(d_data));

	cutilSafeCall(cudaFree(status_device));
	delete status_host;
   
}
