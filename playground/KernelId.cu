#include <cuda.h>
#include <iostream>

#define ARRAY_SIZE (64 * 64)

__global__
void myKernel2 (uint* array) {
   uint id;

   asm("mov.u32 %0, %gridid;" : "=r"(id) );

   array [ threadIdx.x + blockIdx.x * blockDim.x ] = id;
}

__global__
void myKernel (uint* array) {
   uint id;

   asm("mov.u32 %0, %gridid;" : "=r"(id) );

   array [ threadIdx.x + blockIdx.x * blockDim.x ] = id;
}

int main() {
   uint array[ARRAY_SIZE] = { 0 };
   uint* d_array;

   cudaMalloc( (void**) &d_array, sizeof(uint) * ARRAY_SIZE);

   for (int j = 0; j < 10; ++j) {
      myKernel <<< 64, 64 >>> ( d_array );
      myKernel2 <<< 64, 64 >>> ( d_array );

      cudaMemcpy( array, d_array, sizeof(uint) * ARRAY_SIZE, cudaMemcpyDeviceToHost);

      for (int i = 0; i < ARRAY_SIZE; ++i) {
         std::cout << array[i] << "\n";
      }
      std::cout << std::endl;
   }
   cudaFree (d_array);
   return 0;
}

