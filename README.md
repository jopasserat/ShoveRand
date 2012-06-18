# Shoverand #

## *A Pseudo-Random Number Generation library for GPGPU* ##

ShoveRand provides implementations of both Pseudo-Random Number Generators (PRNGs) for CUDA-enabled GPUs and also a framework allowing developers to easily add their own PRNGs to ShoveRand.

Its API is quite similar to what can be encountered when using high-level CPU languages like C++ or Java. Shoverand's main goal is to handle the distribution of stochastic streams automatically without any intervention from the user.

Shoverand also targets PRNG developers: indeed, Shoverand only integrates third-party PRNGs and focuses on unifying their interface. To do so, we integrate compile-time constraints that check whether the algorithm meets our guidelines.

## Requirements ##
  * git
  * cmake
  * CUDA

## Setting up Shoverand ##

Shoverand is mainly based upon header files to be included directly in your source code. Indeed, Shoverand highly relies on
the C++ template mechanism to provide its random number generation facilities. However, some parts need to be compiled using the
following cmake process.

    mkdir build_<build_type>
    cd build_<build_type>
    cmake -D <path_to_cuda_sdk> -D CMAKE_BUILD_TYPE=<None | Debug | Release | RelWithDebInfo | MinSizeRel>
    make

## Usage ##

A simple example of how to use Shoverand can be found in `test/test-shoverand.cu`.  
When using Shoverand in your own project, **do not forget to link against the `libshoverand.so`** library that is built in the `lib/` directory.
