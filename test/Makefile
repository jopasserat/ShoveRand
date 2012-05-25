
# Compilers
CPP   = g++
CXX   = g++
NVCC  = nvcc

ARCH  = -arch=compute_20

# Flags
CPP_FLAGS = -Wall -ansi -pedantic -O3
NVCC_FLAGS = -g -G --compiler-options '-Wall -Wextra -posix'

# Includes
#CUDAINCL    = -I/opt/cuda/include
CUDASDKINCL = -I/opt/cuda/C/common/inc

# Libs
CUDASDKLIB  = -L/opt/cuda/C/common/lib/linux/
CUTILLIB    = /opt/cuda/C/lib/libcutil_x86_64.a
#CUDALIB	    = /opt/cuda/lib64

EXEC= test-shoverand

.SUFFIXES:	.cu .cubin .ptx .bin

OBJS_MRG32k3a = $(patsubst %.cu,%.o,$(wildcard ../src/prng/mrg32k3a/*.cu))
OBJS_MRG32k3a_basenamed = $(patsubst ../src/prng/mrg32k3a/%.cu,%.o, $(OBJS_MRG32k3a))
OBJS_TEST = $(patsubst %.cu,%.o, $(wildcard *.cu))

OBJS= $(OBJS_MRG32k3a_basenamed) $(OBJS_TEST)

all: $(EXEC)

test-shoverand:	mrg32k3a $(OBJS) 
	${CPP} $(OBJS) -o $@ ${CUTILLIB} -L ${CUDALIB} -lcuda -lcudart

test-cpu: testRngStream2.o RngStream.o 
	$(CPP) $^ -o $@

mrg32k3a: $(wildcard ../src/prng/mrg32k3a/*.cu)
	$(MAKE) -C ../src/prng/mrg32k3a

# Compilation rules
%o: %cpp
	$(CPP) -c $< $(CPP_FLAGS)

%.o: %.cu
	$(NVCC) -c -I. -I../ $< $(NVCC_FLAGS) $(ARCH) $(CUDAINCL) $(CUDASDKINCL) 

clean:
	rm -f *~ *.o 

mrproper: clean
	$(MAKE) -C ../src/prng/mrg32k3a/ clean
