
# Compilers
CPP   = g++
CXX   = g++
NVCC  = nvcc

ARCH  = -arch=compute_20

# Flags
CPP_FLAGS = -Wall -ansi -pedantic -O3
NVCC_FLAGS = -g -G --compiler-options '-Wall -Wextra -posix'

# Includes
CUDAINCL    = -I/opt/cuda/include
CUDASDKINCL = -I/opt/cuda/C/common/inc

# Libs
CUDASDKLIB  = -L/opt/cuda/C/common/lib/linux/
CUTILLIB    = /opt/cuda/C/lib/libcutil_x86_64.a
CUDALIB	    = /opt/cuda/lib64

EXEC= test-mrg32k3a

.SUFFIXES:	.cu .cubin .ptx .bin

all: *.o

# Compilation rules
%.o: %cpp
	$(CPP) -c $< $(CPP_FLAGS)

%.o: %.cu
	$(NVCC) -c -I. -I ../../.. $< $(NVCC_FLAGS) $(ARCH) $(CUDAINCL) $(CUDASDKINCL)

clean:
	rm -f *~ *.o

