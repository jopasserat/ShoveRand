################################################################################
#
# Build script for project
#
################################################################################

# Add source files here
EXECUTABLE	:= libor
# CUDA source files (compiled with cudacc)
CUFILES		:= libor.cu
# CUDA dependency files
CU_DEPS		:= \
		libor_kernels.cu \
		Makefile \

# C/C++ source files (compiled with gcc / c++)
CCFILES		:= \
		libor_gold.cpp \
		mrg32k3a_gold.cpp \

################################################################################
# Rules and targets

include ../../common/common.mk


# NVCCFLAGS += -arch sm_13

# NVCCFLAGS += -keep -clean

# NVCCFLAGS += -keep

NVCCFLAGS += -Xptxas -v
