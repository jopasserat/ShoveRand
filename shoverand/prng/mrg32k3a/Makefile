
# compilers variables 
STD = -std=c99
CC = gcc
CPP = g++
ARCH = -arch=compute_11
NVCC = nvcc

# includes and libraries directories
CUTILINC = /Developer/GPU\ Computing/C/common/inc/
CUTILLIB= /Developer/GPU\ Computing/C/lib/libcutil_i386.a
CUDALIB = /usr/local/cuda/lib
CUDALINK= -lcuda -lcudart

CORE_INCLUDES= ../src/core
MRG32K3A_INCLUDES= ../src/prng/mrg32k3a

# compilers flags
WARN = -Wmissing-prototypes -Wall -Wextra
OPTI = -m32 -O3
CPPFLAGS= $(WARN) $(OPTI)
CFLAGS= $(OPTI) $(WARN) $(STD)
NVCC_FLAGS= -g -G -m32 $(ARCH) --compiler-options '-Wall -Wextra -ansi -posix'
NVCC_FLAGS_13= -arch=compute_13 --compiler-options '-Wall'

EXEC= test-mrg32k3a

.SUFFIXES:	.cu .cubin .ptx .bin

all: $(EXEC)

test-mrg32k3a:	Stream.o SubStream.o test_mrg32k3a_cuda.o 
	${CPP} -m32 $^ -o $@ ${CUTILLIB} -L${CUDALIB}  ${CUDALINK}

%.cpp: %.cu
	${NVCC} -Xptxas -v $(NVCC_FLAGS) -I . -I ${CORE_INCLUDES} -I ${MRG32K3A_INCLUDES} -I ~/programming/boost_1_44_0 -I ${CUTILINC} -cuda $<
	
%.o: %.cu
	${NVCC} -Xptxas -v $(NVCC_FLAGS) -I . -I ${CORE_INCLUDES} -I ${MRG32K3A_INCLUDES} -I ~/programming/boost_1_44_0 -I ${CUTILINC} -c $<
	
	
%.o: %.c
	${CC} ${CFLAGS} -c $<	

%.o: %.cpp
	${CPP} ${CPPFLAGS} -c $<
	
clean:
	rm -f *.o *~

mrproper: clean
	rm -f $(EXEC)
