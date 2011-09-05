#include <Stream.cu>
#include <ParameterizedStatus.h>
#include <SubStream.h>

#include <MRG32k3a.hxx>

#include <cstdio>
#include <cstdlib>
#include <cerrno>


#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>


// shortcut :)
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
   
  // ddata[blockDim.x * blockIdx.x + threadIdx.x] = s.next(); // IT WORKS!!!!!
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



	ParameterizedStatusType* 	 status_host = new MRG32k3a::ParameterizedStatusMRG32k3a(); // TODO change by builder method
	status_host->setUp(block_num);
   ParameterizedStatusType*    status_device;
   cutilSafeCall( cudaMalloc((void**) &status_device, sizeof(ParameterizedStatusType)) );  
   cutilSafeCall( cudaMemcpy(status_device, status_host, sizeof(ParameterizedStatusType), cudaMemcpyHostToDevice) );


   if (cudaGetLastError() != cudaSuccess) {
      fprintf(stderr, "error has occured before kernel call.\n");
      exit(1);
   }
   
   cudaEventRecord(start, 0);
   

   // kernel call
   testMRG32k3a<<< block_num, thread_num >>>(d_data, status_device);
   
   cudaEventRecord(stop, 0);
   cudaEventSynchronize(stop);
   
   e = cudaGetLastError();
   if (e != cudaSuccess) {
      fprintf(stderr, "failure in kernel call.\n%s\n", cudaGetErrorString(e));
      exit(2);
   }
   
   // allocate memory to get results back on the host
   h_data = new double[data_size];
   
   if (h_data == NULL) {
      fprintf(stderr, "failure in allocating host memory for output data.\n");
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
   
   
   printf("generated numbers: %d\n", thread_num * block_num);
   printf("Processing time: %f (ms)\n", gputime);
   printf("Samples per second: %E \n", (thread_num * block_num) / (gputime * 0.001));
   
   //free memories
   cudaEventDestroy(start);
   cudaEventDestroy(stop);
   
   delete [] h_data;
   cutilSafeCall(cudaFree(d_data));

	cutilSafeCall(cudaFree(status_device));
	delete status_host;
   
}
