
cmake_minimum_required( VERSION 2.6.2 )

project ( SHOVERAND )

SET ( EXECUTABLE_OUTPUT_PATH ${SHOVERAND_BINARY_DIR}/bin )
message ( "exe: " ${EXECUTABLE_OUTPUT_PATH} )
message ( "bin dir: " ${SHOVERAND_BINARY_DIR} )
# -------------------------------------- #
#                  CUDA                  #
# -------------------------------------- #

message ( " ----  CUDA  ---- " )


find_package( CUDA QUIET REQUIRED )

set( CUDA_VERBOSE_BUILD ON )

message ( "CUDA_VERSION_STRING: " ${CUDA_VERSION_STRING} )
message ( "CUDA_TOOLKIT_ROOT_DIR: " ${CUDA_TOOLKIT_ROOT_DIR} )
message ( "CUDA_SDK_ROOT_DIR: " ${CUDA_SDK_ROOT_DIR} )
message ( "CUDA_INCLUDE_DIRS: " "${CUDA_INCLUDE_DIRS}" )
message ( "CUDA_LIBRARIES: " "${CUDA_LIBRARIES}" )

include_directories ( ${CUDA_SDK_ROOT_DIR}/inc )
include_directories( ${CUDA_SDK_ROOT_DIR}/common/inc )

# include shoverand's directory
include_directories( "." )

# 1.0
#SET( CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} "-arch=sm_10" )
# 1.3
#SET( CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} "-arch=sm_13" )
# 2.0
SET( CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} "-arch=sm_20" )

option ( PTXAS_OPTION "Activate --ptxas-options=-v option." OFF )
if ( PTXAS_OPTION )
   SET( CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} "--ptxas-options=-v" )
endif()

# -------------------------------------- #
#               Boost                    #
# -------------------------------------- #

include( boost.cmake )

# -------------------------------------------------- #
#     Definition des fichiers sources et headers     #
# -------------------------------------------------- #

set( SHOVERAND_SOURCES
   src/prng/mrg32k3a/Stream.cu
   src/prng/mrg32k3a/ParameterizedStatus.cu
)

set( SHOVERAND_HEADERS
# Template files
   src/core/SeedStatus.hxx
   src/core/RNGAlgorithm.hxx
   src/core/ParameterizedStatus.hxx
   src/core/RNG.hxx
   src/prng/tinymt/TinyMT.hxx
   src/prng/tinymt/utils.hxx
   src/prng/mrg32k3a/MRG32k3a.hxx
#
#  Headers (template specializations)
   src/prng/tinymt/ParameterizedStatus.h
   src/prng/tinymt/SeedStatus.h
   src/prng/mrg32k3a/Stream.h
   src/prng/mrg32k3a/ParameterizedStatus.h
   src/prng/mrg32k3a/SeedStatus.h
   src/prng/mrg32k3a/utils.h
)

set( SHOVERAND_SOURCES_TEST
   test/test-shoverand.cu
)

# -------------------------------------- #
#         Creation des projets           #
# -------------------------------------- #

CUDA_ADD_LIBRARY( shoverand
                     ${SHOVERAND_SOURCES}
                     ${SHOVERAND_HEADERS}
                     SHARED
                   )

