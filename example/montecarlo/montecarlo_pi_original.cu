#include <iostream>
#include <cuda.h>

#include "dummy_generator/dummy_generator_original.hxx"

typedef float float_type;

__global__ void kernelMonteCarloPi( float_type * outArray )
{

   DummyGenerator<float_type>    rng;
   float_type x, y;
   long pointsInsideCircle = 0;
   int indiceThd     = threadIdx.x;  // thread identifier

   for (int i = 0; i < 5000; i++)
   {
       x = rng.next();
       y = rng.next();

       if (sqrt (x*x + y*y) <= 1.0) {
           pointsInsideCircle += 1;
       }
   }

   outArray[indiceThd] = (pointsInsideCircle * 4.0) / 5000.0;
}

int main( int argc, char * argv[] )
{
   const int   arraySize  = 200;   // array size

   float_type *     array_host;           // array on the host
   float_type *     array_device;         // array on the device
   float_type       estimated_pi = 0.0;

   cudaError_t error;             // error code 

   // memory allocation for the host array
   array_host    = new float_type[ arraySize ];
   // memory allocation for the device array
   error = cudaMalloc( (void **) &array_device, arraySize * sizeof( float_type ) );
   std::cout << "Error during memory allocation: " << cudaGetErrorString(error) << std::endl;

   // -------------------------------------------//
   // Kernel call (1 block, arraySize threads)  //
   // ----------------------------------------- //
   kernelMonteCarloPi<<< 1, arraySize >>>( array_device );
   error = cudaGetLastError();
   std::cout << "Error during kernel call: " << cudaGetErrorString(error) << std::endl;

   // copy back resulting data from device's array to host's
   error = cudaMemcpy( array_host, array_device, arraySize * sizeof( float_type ), cudaMemcpyDeviceToHost );
   std::cout << "Error in copy from device to host: " << cudaGetErrorString(error) << std::endl;

   std::cout << "Received results" << std::endl;
   for ( int i = 0; i < arraySize; ++i )
   {
      std::cout << array_host[ i ] << " ";
      estimated_pi += array_host[ i ];
   }
   std::cout << std::endl;

   estimated_pi /= (float_type)arraySize;
   std::cout << "Estimated PI " << estimated_pi << std::endl;

   // free device's memory
   cudaFree( array_device );
   // free host's memory
   delete array_host;

   return 0;
}

