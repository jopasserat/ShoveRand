
cmake_minimum_required( VERSION 2.6.2 )

project ( SHOVERAND )

SET ( EXECUTABLE_OUTPUT_PATH ${SHOVERAND_BINARY_DIR}/bin )
SET ( LIBRARY_OUTPUT_PATH ${SHOVERAND_BINARY_DIR}/lib )
message ( "root path: " ${SHOVERAND_BINARY_DIR} )
message ( "bin dir: " ${EXECUTABLE_OUTPUT_PATH} )
message ( "lib dir: " ${LIBRARY_OUTPUT_PATH} )
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

# include shoverand's self directory
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
#     Source and header files                        #
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

set( SHOVERAND_TEST_SOURCES
   test/test-shoverand.cu
)

# -------------------------------------- #
#         Binaries creation              #
# -------------------------------------- #

CUDA_ADD_LIBRARY( shoverand
                     ${SHOVERAND_SOURCES}
                     ${SHOVERAND_HEADERS}
                     SHARED
                   )

CUDA_ADD_EXECUTABLE( test-shoverand
                     ${SHOVERAND_TEST_SOURCES}
                  )

target_link_libraries ( test-shoverand shoverand )
