#include <Stream.cu>
#include <ParameterizedStatus.h>
#include <SubStream.h>

#include <cstdio>
#include <cstdlib>
#include <cerrno>


#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>


// __global__ void testMRG32k3a(double* ddata,  MRG32k3a::SubStream allSubStreams[], MRG32k3a::Stream allStreams[]) {
__global__ void testMRG32k3a(double* ddata,  MRG32k3a::ParameterizedStatus* param) {

	// this call could not work with devices of
	// compute capability < 2.x
	MRG32k3a::SubStream s(param);

   // old devices compliant version
//    MRG32k3a::SubStream* s = allSubStreams + (blockDim.x * blockIdx.x + threadIdx.x);
//    s->init(allStreams);
   
   ddata[blockDim.x * blockIdx.x + threadIdx.x] = s.next(); // IT WORKS!!!!!
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
   
   
   // create Streams for all threads
//    MRG32k3a::Stream::init(block_num);
//    MRG32k3a::SubStream* allSubStreams_host = new MRG32k3a::SubStream[thread_num * block_num];
//    MRG32k3a::SubStream* allSubStreams_device;
//    
   // create timers 
   cudaEvent_t start;
   cudaEvent_t stop;
   cudaEventCreate(&start);
   cudaEventCreate(&stop);
   
   
   // allocate memory for data on device
   cutilSafeCall( cudaMalloc((void**) &d_data, data_size) );
   cutilSafeCall( cudaMemset(d_data, 0, data_size) );
 

//   allSubStreams_host = (MRG32k3a::SubStream*)malloc(thread_num * block_num * sizeof(MRG32k3a::SubStream));

//    cutilSafeCall( cudaMalloc((void**) &allSubStreams_device, thread_num * block_num * sizeof(MRG32k3a::SubStream)) );
//    cutilSafeCall( cudaMemcpy(allSubStreams_device, allSubStreams_host, thread_num * block_num * sizeof(MRG32k3a::SubStream), cudaMemcpyHostToDevice) );

   MRG32k3a::ParameterizedStatus*   status_host = new MRG32k3a::ParameterizedStatus(block_num);
   MRG32k3a::ParameterizedStatus*   status_device;
   cutilSafeCall( cudaMalloc((void**) &status_device, sizeof(MRG32k3a::ParameterizedStatus)) );  
   cutilSafeCall( cudaMemcpy(status_device, status_host, sizeof(MRG32k3a::ParameterizedStatus), cudaMemcpyHostToDevice) );


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
