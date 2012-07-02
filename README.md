# Shoverand #

## *A Pseudorandom Number Generation library for GPU* ##

ShoveRand provides implementations of both Pseudorandom Number Generators (PRNGs) for CUDA-enabled GPUs and also a framework allowing developers to easily add their own PRNGs to ShoveRand.

Its API is quite similar to what can be encountered when using high-level CPU languages like C++ or Java. Shoverand's main goal is to handle the distribution of stochastic streams automatically without any intervention from the user.

Shoverand also targets PRNG developers: indeed, Shoverand only integrates third-party PRNGs and focuses on unifying their interface. To do so, we integrate compile-time constraints that check whether the algorithm meets our guidelines.

## Requirements ##
  * git
  * CMake
  * CUDA

## Setting up Shoverand ##

Shoverand is mainly based upon header files to be included directly in your source code. Indeed, Shoverand highly relies on
the C++ template mechanism to provide its random number generation facilities. However, some parts need to be compiled using the
following cmake process.

    mkdir build_<build_type>
    cd build_<build_type>
    cmake -D CUDA_SDK_ROOT_DIR=<path_to_cuda_sdk> -D CMAKE_BUILD_TYPE=<None | Debug | Release | RelWithDebInfo | MinSizeRel>
    make

## Usage ##

A simple example of how to use Shoverand can be found in `example/montecarlo/montecarlo_pi.cu` and `test/test-shoverand.cu`.
When using Shoverand in your own project, **do not forget to link against the `libshoverand.so`** library that is built in the `lib/` directory.

You can also find an example showing how to integrate a PRNG in shoverand in `example/dummy_generator/dummy_generator.hxx`.

These examples were presented as a tutorial at the HPCS 2012 conference, in Madrid (http://hpcs2012.cisedu.info/4-program/tutorials  ==> T4). 
