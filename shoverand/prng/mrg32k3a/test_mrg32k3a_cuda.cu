#include <SubStream.h>
#include <Stream.h>

#include <cstdio>
#include <cstdlib>
#include <cerrno>


#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>


__global__ void testMRG32k3a(double* ddata, MRG32k3a::Stream allStreams[]) {
   
  // MRG32k3a::SubStream s(allStreams);4
  // __syncthreads();
   
   
   ddata[blockDim.x * blockIdx.x + threadIdx.x] = 23;
   __syncthreads();
}


int main(int, char **) {

   int block_num = 1;
   int thread_num = 32;
   int data_size = block_num * thread_num * sizeof(double);
   
   double* d_data;
   double* h_data;
   cudaError_t e;
   float gputime;
   
   
   // create Streams for all threads
   // MRG32k3a::Stream* allStreamslocal = new MRG32k3a::Stream[block_num];
   //MRG32k3a::Stream::init(block_num);
   
   // create timers 
   cudaEvent_t start;
   cudaEvent_t stop;
   cudaEventCreate(&start);
   cudaEventCreate(&stop);
   
   
   // allocate memory for data on device
   cutilSafeCall( cudaMalloc((void**) &d_data, data_size) );
   cutilSafeCall( cudaMemset(d_data, 42, data_size) );
   
   if (cudaGetLastError() != cudaSuccess) {
      fprintf(stderr, "error has occured before kernel call.\n");
      exit(1);
   }
   
   cudaEventRecord(start, 0);
   
   // kernel call
   testMRG32k3a<<< block_num, thread_num>>>(d_data, MRG32k3a::Stream::allStreams);
   
   cudaEventRecord(stop, 0);
   cudaEventSynchronize(stop);
   
   e = cudaGetLastError();
   if (e != cudaSuccess) {
      fprintf(stderr, "failure in kernel call.\n%s\n", cudaGetErrorString(e));
      exit(2);
   }
   
   // allocate memory to get results back on the host
   h_data = (double *) malloc(data_size);
   
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
      printf ("h_data[%d] = %lf\n", i, h_data[i]);
   }
   
   
   printf("generated numbers: %d\n", thread_num * block_num);
   printf("Processing time: %f (ms)\n", gputime);
   printf("Samples per second: %E \n", (thread_num * block_num) / (gputime * 0.001));
   
   //free memories
   cudaEventDestroy(start);
   cudaEventDestroy(stop);
   
   free(h_data);
   cutilSafeCall(cudaFree(d_data));
   
}
