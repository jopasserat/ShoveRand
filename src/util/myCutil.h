#pragma once

#define myCutilSafeCall(err)           __myCudaSafeCall      (err, __FILE__, __LINE__)

#include <iostream>
inline void __myCudaSafeCall( cudaError err, const char *file, const int line )
{
    if (err != cudaSuccess)
    {
        std::cerr << file << "(" << line << ") : cudaSafeCall() Runtime API error " << (int)err << ": " << cudaGetErrorString( err ) << "." << std::endl;
        exit(-1);
    }
}
