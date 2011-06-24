# @file  Makefile
# @brief Makefile
#
# @author Mutsuo Saito (Hiroshima University)
# @author Makoto Matsumoto (Hiroshima University)
#
# Copyright (C) 2009, 2010 Mutsuo Saito, Makoto Matsumoto and
# Hiroshima University. All rights reserved.
#
# The new BSD License is applied to this software.
# see LICENSE.txt
#


# compilers variables 
STD = -std=c99
CC = gcc
CPP = g++
ARCH = -arch=compute_20
NVCC = nvcc


# includes and libraries directories
CUDA_HOME = /opt/cuda
CUTILINC = ${CUDA_HOME}/C/common/inc/
CUTILLIB= ${CUDA_HOME}/C/lib/libcutil_x86_64.a
CUDALIB = ${CUDA_HOME}/lib64
CUDALINK= -lcuda -lcudart

CORE_INCLUDES= ../src/core
MRG32K3A_INCLUDES= ../src/prng/mrg32k3a

# compilers flags
WARN = -Wmissing-prototypes -Wall -Wextra
OPTI = -g -G
CPPFLAGS= $(WARN) $(OPTI)
CFLAGS= $(OPTI) $(WARN) $(STD)
NVCC_FLAGS= $(ARCH) --compiler-options '-Wall'

EXEC= test-shoverand

.SUFFIXES:	.cu .cubin .ptx .bin

all: $(EXEC)

test-shoverand:	main.o 
	${CPP} $^ -o $@ ${CUTILLIB} -L${CUDALIB}  ${CUDALINK}

%.cpp: %.cu
	${NVCC} -Xptxas -v $(NVCC_FLAGS) -I . -I ${CORE_INCLUDES} -I ${MRG32K3A_INCLUDES} -I ~/programming/boost_1_44_0 -I ${CUTILINC} -cuda $<
	
%.o: %.cu
	${NVCC} -Xptxas -v $(NVCC_FLAGS) -I . -I ${CORE_INCLUDES} -I ${MRG32K3A_INCLUDES} -I ~/programming/boost_1_44_0 -I ${CUTILINC} -c $<
	
	
%.o: %.c
	${CC} ${CFLAGS} -c $<	
	
clean:
	rm -f *.o *~

mrproper: clean
	rm -f $(EXEC)
		
# unused rules	
.cu.ptx:
	${NVCC} ${CUTILINC} -ptx $<

.cu.cubin:
	${NVCC} ${CUTILINC} -cubin $<

.cu.bin:
	${NVCC} $(NVCC_FLAGS) ${CUTILINC} -o $@ $< ${CUTILLIB} ${CUDALINK}

.c.o:
	${CC} ${CCFLAGS} -c $<
