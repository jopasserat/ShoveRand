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
NVCC_FLAGS= -m32 $(ARCH) --compiler-options '-Wall'
NVCC_FLAGS_13= -arch=compute_13 --compiler-options '-Wall'

EXEC= test-shoverand

.SUFFIXES:	.cu .cubin .ptx .bin

all: $(EXEC)

test-shoverand:	main.o 
	${NVCC} -m32 $^ -o $@ -Xptxas -v -I ${CORE_INCLUDES} -I ${MRG32K3A_INCLUDES} ${CUTILLIB} -L${CUDALIB}  ${CUDALINK}

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
