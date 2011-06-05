# 1 "/tmp/tmpxft_00000cb2_00000000-1_mtgp32-cuda-cuterandAPI.cudafe1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/tmp/tmpxft_00000cb2_00000000-1_mtgp32-cuda-cuterandAPI.cudafe1.cpp"
# 1 "mtgp32-cuda-cuterandAPI.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 152 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stddef.h" 3
typedef int ptrdiff_t;
# 214 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1 3
# 69 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/builtin_types.h" 1 3
# 42 "/usr/local/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda/bin/../include/device_types.h" 1 3
# 46 "/usr/local/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/driver_types.h" 1 3
# 96 "/usr/local/cuda/bin/../include/driver_types.h" 3
enum cudaError
{





  cudaSuccess = 0,





  cudaErrorMissingConfiguration = 1,





  cudaErrorMemoryAllocation = 2,





  cudaErrorInitializationError = 3,
# 131 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchFailure = 4,
# 140 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorPriorLaunchFailure = 5,
# 150 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchTimeout = 6,
# 159 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorLaunchOutOfResources = 7,





  cudaErrorInvalidDeviceFunction = 8,
# 174 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorInvalidConfiguration = 9,





  cudaErrorInvalidDevice = 10,





  cudaErrorInvalidValue = 11,





  cudaErrorInvalidPitchValue = 12,





  cudaErrorInvalidSymbol = 13,




  cudaErrorMapBufferObjectFailed = 14,




  cudaErrorUnmapBufferObjectFailed = 15,





  cudaErrorInvalidHostPointer = 16,





  cudaErrorInvalidDevicePointer = 17,





  cudaErrorInvalidTexture = 18,





  cudaErrorInvalidTextureBinding = 19,






  cudaErrorInvalidChannelDescriptor = 20,





  cudaErrorInvalidMemcpyDirection = 21,
# 255 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorAddressOfConstant = 22,
# 264 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorTextureFetchFailed = 23,
# 273 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorTextureNotBound = 24,
# 282 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorSynchronizationError = 25,





  cudaErrorInvalidFilterSetting = 26,





  cudaErrorInvalidNormSetting = 27,







  cudaErrorMixedDeviceExecution = 28,







  cudaErrorCudartUnloading = 29,




  cudaErrorUnknown = 30,





  cudaErrorNotYetImplemented = 31,
# 330 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorMemoryValueTooLarge = 32,






  cudaErrorInvalidResourceHandle = 33,







  cudaErrorNotReady = 34,






  cudaErrorInsufficientDriver = 35,
# 365 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorSetOnActiveProcess = 36,





  cudaErrorInvalidSurface = 37,





  cudaErrorNoDevice = 38,





  cudaErrorECCUncorrectable = 39,




  cudaErrorSharedObjectSymbolNotFound = 40,




  cudaErrorSharedObjectInitFailed = 41,





  cudaErrorUnsupportedLimit = 42,





  cudaErrorDuplicateVariableName = 43,





  cudaErrorDuplicateTextureName = 44,





  cudaErrorDuplicateSurfaceName = 45,
# 426 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorDevicesUnavailable = 46,




  cudaErrorInvalidKernelImage = 47,







  cudaErrorNoKernelImageForDevice = 48,
# 448 "/usr/local/cuda/bin/../include/driver_types.h" 3
  cudaErrorIncompatibleDriverContext = 49,




  cudaErrorStartupFailure = 0x7f,





  cudaErrorApiFailureBase = 10000
};





enum cudaChannelFormatKind
{
  cudaChannelFormatKindSigned = 0,
  cudaChannelFormatKindUnsigned = 1,
  cudaChannelFormatKindFloat = 2,
  cudaChannelFormatKindNone = 3
};





struct cudaChannelFormatDesc
{
  int x;
  int y;
  int z;
  int w;
  enum cudaChannelFormatKind f;
};





struct cudaArray;





enum cudaMemcpyKind
{
  cudaMemcpyHostToHost = 0,
  cudaMemcpyHostToDevice = 1,
  cudaMemcpyDeviceToHost = 2,
  cudaMemcpyDeviceToDevice = 3
};






struct cudaPitchedPtr
{
  void *ptr;
  size_t pitch;
  size_t xsize;
  size_t ysize;
};






struct cudaExtent
{
  size_t width;
  size_t height;
  size_t depth;
};






struct cudaPos
{
  size_t x;
  size_t y;
  size_t z;
};





struct cudaMemcpy3DParms
{
  struct cudaArray *srcArray;
  struct cudaPos srcPos;
  struct cudaPitchedPtr srcPtr;

  struct cudaArray *dstArray;
  struct cudaPos dstPos;
  struct cudaPitchedPtr dstPtr;

  struct cudaExtent extent;
  enum cudaMemcpyKind kind;
};





struct cudaGraphicsResource;





enum cudaGraphicsRegisterFlags
{
  cudaGraphicsRegisterFlagsNone = 0
};





enum cudaGraphicsMapFlags
{
  cudaGraphicsMapFlagsNone = 0,
  cudaGraphicsMapFlagsReadOnly = 1,
  cudaGraphicsMapFlagsWriteDiscard = 2
};





enum cudaGraphicsCubeFace {
  cudaGraphicsCubeFacePositiveX = 0x00,
  cudaGraphicsCubeFaceNegativeX = 0x01,
  cudaGraphicsCubeFacePositiveY = 0x02,
  cudaGraphicsCubeFaceNegativeY = 0x03,
  cudaGraphicsCubeFacePositiveZ = 0x04,
  cudaGraphicsCubeFaceNegativeZ = 0x05
};





struct cudaFuncAttributes
{





   size_t sharedSizeBytes;





   size_t constSizeBytes;




   size_t localSizeBytes;






   int maxThreadsPerBlock;




   int numRegs;






   int ptxVersion;






   int binaryVersion;

   int __cudaReserved[6];
};





enum cudaFuncCache
{
  cudaFuncCachePreferNone = 0,
  cudaFuncCachePreferShared = 1,
  cudaFuncCachePreferL1 = 2
};





enum cudaComputeMode
{
  cudaComputeModeDefault = 0,
  cudaComputeModeExclusive = 1,
  cudaComputeModeProhibited = 2
};





enum cudaLimit
{
    cudaLimitStackSize = 0x00,
    cudaLimitPrintfFifoSize = 0x01,
    cudaLimitMallocHeapSize = 0x02
};





struct cudaDeviceProp
{
  char name[256];
  size_t totalGlobalMem;
  size_t sharedMemPerBlock;
  int regsPerBlock;
  int warpSize;
  size_t memPitch;
  int maxThreadsPerBlock;
  int maxThreadsDim[3];
  int maxGridSize[3];
  int clockRate;
  size_t totalConstMem;
  int major;
  int minor;
  size_t textureAlignment;
  int deviceOverlap;
  int multiProcessorCount;
  int kernelExecTimeoutEnabled;
  int integrated;
  int canMapHostMemory;
  int computeMode;
  int maxTexture1D;
  int maxTexture2D[2];
  int maxTexture3D[3];
  int maxTexture2DArray[3];
  size_t surfaceAlignment;
  int concurrentKernels;
  int ECCEnabled;
  int pciBusID;
  int pciDeviceID;
  int tccDriver;
  int __cudaReserved[21];
};
# 768 "/usr/local/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef struct CUstream_st *cudaStream_t;





typedef struct CUevent_st *cudaEvent_t;





typedef struct cudaGraphicsResource *cudaGraphicsResource_t;





typedef struct CUuuid_st cudaUUID_t;
# 44 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/surface_types.h" 1 3
# 63 "/usr/local/cuda/bin/../include/surface_types.h" 3
enum cudaSurfaceBoundaryMode
{
  cudaBoundaryModeZero = 0,
  cudaBoundaryModeClamp = 1,
  cudaBoundaryModeTrap = 2
};





enum cudaSurfaceFormatMode
{
  cudaFormatModeForced = 0,
  cudaFormatModeAuto = 1
};





struct surfaceReference
{



  struct cudaChannelFormatDesc channelDesc;
};
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_types.h" 1 3
# 63 "/usr/local/cuda/bin/../include/texture_types.h" 3
enum cudaTextureAddressMode
{
  cudaAddressModeWrap = 0,
  cudaAddressModeClamp = 1,
  cudaAddressModeMirror = 2,
  cudaAddressModeBorder = 3
};





enum cudaTextureFilterMode
{
  cudaFilterModePoint = 0,
  cudaFilterModeLinear = 1
};





enum cudaTextureReadMode
{
  cudaReadModeElementType = 0,
  cudaReadModeNormalizedFloat = 1
};





struct textureReference
{



  int normalized;



  enum cudaTextureFilterMode filterMode;



  enum cudaTextureAddressMode addressMode[3];



  struct cudaChannelFormatDesc channelDesc;
  int __cudaReserved[16];
};
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/vector_types.h" 1 3
# 45 "/usr/local/cuda/bin/../include/vector_types.h" 3
# 1 "/usr/local/cuda/bin/../include/builtin_types.h" 1 3
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda/bin/../include/vector_types.h" 1 3
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 46 "/usr/local/cuda/bin/../include/vector_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 47 "/usr/local/cuda/bin/../include/vector_types.h" 2 3
# 75 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct char1
{
  signed char x;
};


struct uchar1
{
  unsigned char x;
};


struct __attribute__((aligned(2))) char2
{
  signed char x, y;
};


struct __attribute__((aligned(2))) uchar2
{
  unsigned char x, y;
};


struct char3
{
  signed char x, y, z;
};


struct uchar3
{
  unsigned char x, y, z;
};


struct __attribute__((aligned(4))) char4
{
  signed char x, y, z, w;
};


struct __attribute__((aligned(4))) uchar4
{
  unsigned char x, y, z, w;
};


struct short1
{
  short x;
};


struct ushort1
{
  unsigned short x;
};


struct __attribute__((aligned(4))) short2
{
  short x, y;
};


struct __attribute__((aligned(4))) ushort2
{
  unsigned short x, y;
};


struct short3
{
  short x, y, z;
};


struct ushort3
{
  unsigned short x, y, z;
};


struct __attribute__((aligned(8))) short4 { short x; short y; short z; short w; };


struct __attribute__((aligned(8))) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; };


struct int1
{
  int x;
};


struct uint1
{
  unsigned int x;
};


struct __attribute__((aligned(8))) int2 { int x; int y; };


struct __attribute__((aligned(8))) uint2 { unsigned int x; unsigned int y; };


struct int3
{
  int x, y, z;
};


struct uint3
{
  unsigned int x, y, z;
};


struct __attribute__((aligned(16))) int4
{
  int x, y, z, w;
};


struct __attribute__((aligned(16))) uint4
{
  unsigned int x, y, z, w;
};


struct long1
{
  long int x;
};


struct ulong1
{
  unsigned long x;
};
# 229 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct __attribute__((aligned(2*sizeof(long int)))) long2
{
  long int x, y;
};


struct __attribute__((aligned(2*sizeof(unsigned long int)))) ulong2
{
  unsigned long int x, y;
};




struct long3
{
  long int x, y, z;
};


struct ulong3
{
  unsigned long int x, y, z;
};


struct __attribute__((aligned(16))) long4
{
  long int x, y, z, w;
};


struct __attribute__((aligned(16))) ulong4
{
  unsigned long int x, y, z, w;
};


struct float1
{
  float x;
};


struct __attribute__((aligned(8))) float2 { float x; float y; };


struct float3
{
  float x, y, z;
};


struct __attribute__((aligned(16))) float4
{
  float x, y, z, w;
};


struct longlong1
{
  long long int x;
};


struct ulonglong1
{
  unsigned long long int x;
};


struct __attribute__((aligned(16))) longlong2
{
  long long int x, y;
};


struct __attribute__((aligned(16))) ulonglong2
{
  unsigned long long int x, y;
};


struct longlong3
{
  long long int x, y, z;
};


struct ulonglong3
{
  unsigned long long int x, y, z;
};


struct __attribute__((aligned(16))) longlong4
{
  long long int x, y, z ,w;
};


struct __attribute__((aligned(16))) ulonglong4
{
  unsigned long long int x, y, z, w;
};


struct double1
{
  double x;
};


struct __attribute__((aligned(16))) double2
{
  double x, y;
};


struct double3
{
  double x, y, z;
};


struct __attribute__((aligned(16))) double4
{
  double x, y, z, w;
};
# 366 "/usr/local/cuda/bin/../include/vector_types.h" 3
typedef struct char1 char1;

typedef struct uchar1 uchar1;

typedef struct char2 char2;

typedef struct uchar2 uchar2;

typedef struct char3 char3;

typedef struct uchar3 uchar3;

typedef struct char4 char4;

typedef struct uchar4 uchar4;

typedef struct short1 short1;

typedef struct ushort1 ushort1;

typedef struct short2 short2;

typedef struct ushort2 ushort2;

typedef struct short3 short3;

typedef struct ushort3 ushort3;

typedef struct short4 short4;

typedef struct ushort4 ushort4;

typedef struct int1 int1;

typedef struct uint1 uint1;

typedef struct int2 int2;

typedef struct uint2 uint2;

typedef struct int3 int3;

typedef struct uint3 uint3;

typedef struct int4 int4;

typedef struct uint4 uint4;

typedef struct long1 long1;

typedef struct ulong1 ulong1;

typedef struct long2 long2;

typedef struct ulong2 ulong2;

typedef struct long3 long3;

typedef struct ulong3 ulong3;

typedef struct long4 long4;

typedef struct ulong4 ulong4;

typedef struct float1 float1;

typedef struct float2 float2;

typedef struct float3 float3;

typedef struct float4 float4;

typedef struct longlong1 longlong1;

typedef struct ulonglong1 ulonglong1;

typedef struct longlong2 longlong2;

typedef struct ulonglong2 ulonglong2;

typedef struct longlong3 longlong3;

typedef struct ulonglong3 ulonglong3;

typedef struct longlong4 longlong4;

typedef struct ulonglong4 ulonglong4;

typedef struct double1 double1;

typedef struct double2 double2;

typedef struct double3 double3;

typedef struct double4 double4;
# 469 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;

    dim3(unsigned int vx = 1, unsigned int vy = 1, unsigned int vz = 1) : x(vx), y(vy), z(vz) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 46 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 70 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/storage_class.h" 1 3
# 71 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 216 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stddef.h" 2 3
# 96 "/usr/local/cuda/bin/../include/driver_types.h"
# 466 "/usr/local/cuda/bin/../include/driver_types.h"
# 478 "/usr/local/cuda/bin/../include/driver_types.h"
# 491 "/usr/local/cuda/bin/../include/driver_types.h"
# 497 "/usr/local/cuda/bin/../include/driver_types.h"
# 510 "/usr/local/cuda/bin/../include/driver_types.h"
# 523 "/usr/local/cuda/bin/../include/driver_types.h"
# 535 "/usr/local/cuda/bin/../include/driver_types.h"
# 546 "/usr/local/cuda/bin/../include/driver_types.h"
# 564 "/usr/local/cuda/bin/../include/driver_types.h"
# 570 "/usr/local/cuda/bin/../include/driver_types.h"
# 579 "/usr/local/cuda/bin/../include/driver_types.h"
# 590 "/usr/local/cuda/bin/../include/driver_types.h"
# 603 "/usr/local/cuda/bin/../include/driver_types.h"
# 656 "/usr/local/cuda/bin/../include/driver_types.h"
# 667 "/usr/local/cuda/bin/../include/driver_types.h"
# 678 "/usr/local/cuda/bin/../include/driver_types.h"
# 689 "/usr/local/cuda/bin/../include/driver_types.h"
# 768 "/usr/local/cuda/bin/../include/driver_types.h"
# 774 "/usr/local/cuda/bin/../include/driver_types.h"
# 780 "/usr/local/cuda/bin/../include/driver_types.h"
# 786 "/usr/local/cuda/bin/../include/driver_types.h"
# 792 "/usr/local/cuda/bin/../include/driver_types.h"
# 63 "/usr/local/cuda/bin/../include/surface_types.h"
# 74 "/usr/local/cuda/bin/../include/surface_types.h"
# 84 "/usr/local/cuda/bin/../include/surface_types.h"
# 63 "/usr/local/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda/bin/../include/texture_types.h"
# 85 "/usr/local/cuda/bin/../include/texture_types.h"
# 95 "/usr/local/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda/bin/../include/vector_types.h"
# 81 "/usr/local/cuda/bin/../include/vector_types.h"
# 87 "/usr/local/cuda/bin/../include/vector_types.h"
# 93 "/usr/local/cuda/bin/../include/vector_types.h"
# 99 "/usr/local/cuda/bin/../include/vector_types.h"
# 105 "/usr/local/cuda/bin/../include/vector_types.h"
# 111 "/usr/local/cuda/bin/../include/vector_types.h"
# 117 "/usr/local/cuda/bin/../include/vector_types.h"
# 123 "/usr/local/cuda/bin/../include/vector_types.h"
# 129 "/usr/local/cuda/bin/../include/vector_types.h"
# 135 "/usr/local/cuda/bin/../include/vector_types.h"
# 141 "/usr/local/cuda/bin/../include/vector_types.h"
# 147 "/usr/local/cuda/bin/../include/vector_types.h"
# 153 "/usr/local/cuda/bin/../include/vector_types.h"
# 159 "/usr/local/cuda/bin/../include/vector_types.h"
# 162 "/usr/local/cuda/bin/../include/vector_types.h"
# 165 "/usr/local/cuda/bin/../include/vector_types.h"
# 171 "/usr/local/cuda/bin/../include/vector_types.h"
# 177 "/usr/local/cuda/bin/../include/vector_types.h"
# 180 "/usr/local/cuda/bin/../include/vector_types.h"
# 183 "/usr/local/cuda/bin/../include/vector_types.h"
# 189 "/usr/local/cuda/bin/../include/vector_types.h"
# 195 "/usr/local/cuda/bin/../include/vector_types.h"
# 201 "/usr/local/cuda/bin/../include/vector_types.h"
# 207 "/usr/local/cuda/bin/../include/vector_types.h"
# 213 "/usr/local/cuda/bin/../include/vector_types.h"
# 229 "/usr/local/cuda/bin/../include/vector_types.h"
# 235 "/usr/local/cuda/bin/../include/vector_types.h"
# 243 "/usr/local/cuda/bin/../include/vector_types.h"
# 249 "/usr/local/cuda/bin/../include/vector_types.h"
# 255 "/usr/local/cuda/bin/../include/vector_types.h"
# 261 "/usr/local/cuda/bin/../include/vector_types.h"
# 267 "/usr/local/cuda/bin/../include/vector_types.h"
# 273 "/usr/local/cuda/bin/../include/vector_types.h"
# 276 "/usr/local/cuda/bin/../include/vector_types.h"
# 282 "/usr/local/cuda/bin/../include/vector_types.h"
# 288 "/usr/local/cuda/bin/../include/vector_types.h"
# 294 "/usr/local/cuda/bin/../include/vector_types.h"
# 300 "/usr/local/cuda/bin/../include/vector_types.h"
# 306 "/usr/local/cuda/bin/../include/vector_types.h"
# 312 "/usr/local/cuda/bin/../include/vector_types.h"
# 318 "/usr/local/cuda/bin/../include/vector_types.h"
# 324 "/usr/local/cuda/bin/../include/vector_types.h"
# 330 "/usr/local/cuda/bin/../include/vector_types.h"
# 336 "/usr/local/cuda/bin/../include/vector_types.h"
# 342 "/usr/local/cuda/bin/../include/vector_types.h"
# 348 "/usr/local/cuda/bin/../include/vector_types.h"
# 354 "/usr/local/cuda/bin/../include/vector_types.h"
# 366 "/usr/local/cuda/bin/../include/vector_types.h"
# 368 "/usr/local/cuda/bin/../include/vector_types.h"
# 370 "/usr/local/cuda/bin/../include/vector_types.h"
# 372 "/usr/local/cuda/bin/../include/vector_types.h"
# 374 "/usr/local/cuda/bin/../include/vector_types.h"
# 376 "/usr/local/cuda/bin/../include/vector_types.h"
# 378 "/usr/local/cuda/bin/../include/vector_types.h"
# 380 "/usr/local/cuda/bin/../include/vector_types.h"
# 382 "/usr/local/cuda/bin/../include/vector_types.h"
# 384 "/usr/local/cuda/bin/../include/vector_types.h"
# 386 "/usr/local/cuda/bin/../include/vector_types.h"
# 388 "/usr/local/cuda/bin/../include/vector_types.h"
# 390 "/usr/local/cuda/bin/../include/vector_types.h"
# 392 "/usr/local/cuda/bin/../include/vector_types.h"
# 394 "/usr/local/cuda/bin/../include/vector_types.h"
# 396 "/usr/local/cuda/bin/../include/vector_types.h"
# 398 "/usr/local/cuda/bin/../include/vector_types.h"
# 400 "/usr/local/cuda/bin/../include/vector_types.h"
# 402 "/usr/local/cuda/bin/../include/vector_types.h"
# 404 "/usr/local/cuda/bin/../include/vector_types.h"
# 406 "/usr/local/cuda/bin/../include/vector_types.h"
# 408 "/usr/local/cuda/bin/../include/vector_types.h"
# 410 "/usr/local/cuda/bin/../include/vector_types.h"
# 412 "/usr/local/cuda/bin/../include/vector_types.h"
# 414 "/usr/local/cuda/bin/../include/vector_types.h"
# 416 "/usr/local/cuda/bin/../include/vector_types.h"
# 418 "/usr/local/cuda/bin/../include/vector_types.h"
# 420 "/usr/local/cuda/bin/../include/vector_types.h"
# 422 "/usr/local/cuda/bin/../include/vector_types.h"
# 424 "/usr/local/cuda/bin/../include/vector_types.h"
# 426 "/usr/local/cuda/bin/../include/vector_types.h"
# 428 "/usr/local/cuda/bin/../include/vector_types.h"
# 430 "/usr/local/cuda/bin/../include/vector_types.h"
# 432 "/usr/local/cuda/bin/../include/vector_types.h"
# 434 "/usr/local/cuda/bin/../include/vector_types.h"
# 436 "/usr/local/cuda/bin/../include/vector_types.h"
# 438 "/usr/local/cuda/bin/../include/vector_types.h"
# 440 "/usr/local/cuda/bin/../include/vector_types.h"
# 442 "/usr/local/cuda/bin/../include/vector_types.h"
# 444 "/usr/local/cuda/bin/../include/vector_types.h"
# 446 "/usr/local/cuda/bin/../include/vector_types.h"
# 448 "/usr/local/cuda/bin/../include/vector_types.h"
# 450 "/usr/local/cuda/bin/../include/vector_types.h"
# 452 "/usr/local/cuda/bin/../include/vector_types.h"
# 454 "/usr/local/cuda/bin/../include/vector_types.h"
# 456 "/usr/local/cuda/bin/../include/vector_types.h"
# 458 "/usr/local/cuda/bin/../include/vector_types.h"
# 460 "/usr/local/cuda/bin/../include/vector_types.h"
# 469 "/usr/local/cuda/bin/../include/vector_types.h"
# 480 "/usr/local/cuda/bin/../include/vector_types.h"
# 115 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
# 131 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSynchronize();
# 183 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetLimit(cudaLimit, size_t);
# 207 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetLimit(size_t *, cudaLimit);
# 237 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadGetCacheConfig(cudaFuncCache *);
# 278 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadSetCacheConfig(cudaFuncCache);
# 330 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
# 373 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaPeekAtLastError();
# 387 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" const char *cudaGetErrorString(cudaError_t);
# 418 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
# 536 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
# 555 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
# 579 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDevice(int);
# 597 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDevice(int *);
# 626 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetValidDevices(int *, int);
# 677 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDeviceFlags(unsigned);
# 703 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
# 719 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
# 753 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamWaitEvent(cudaStream_t, cudaEvent_t, unsigned);
# 771 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
# 789 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 821 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
# 852 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, unsigned);
# 885 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t = 0);
# 914 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
# 946 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
# 966 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
# 1007 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 1046 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = 0);
# 1073 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
# 1119 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncSetCacheConfig(const char *, cudaFuncCache);
# 1154 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaLaunch(const char *);
# 1187 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 1209 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
# 1231 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 1263 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
# 1292 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocHost(void **, size_t);
# 1331 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
# 1370 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (0), unsigned = (0));
# 1394 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFree(void *);
# 1414 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeHost(void *);
# 1436 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaFreeArray(cudaArray *);
# 1495 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
# 1522 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
# 1541 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 1576 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
# 1626 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent, unsigned = (0));
# 1723 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
# 1828 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t = 0);
# 1847 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemGetInfo(size_t *, size_t *);
# 1880 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
# 1913 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
# 1946 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
# 1981 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2023 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 2064 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
# 2105 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
# 2144 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
# 2179 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
# 2213 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 2256 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2298 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2340 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2391 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2441 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2491 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2535 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2578 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0);
# 2600 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
# 2626 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 2665 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
# 2692 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemsetAsync(void *, int, size_t, cudaStream_t = 0);
# 2724 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset2DAsync(void *, size_t, int, size_t, size_t, cudaStream_t = 0);
# 2769 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset3DAsync(cudaPitchedPtr, int, cudaExtent, cudaStream_t = 0);
# 2796 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
# 2819 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 2865 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t);
# 2897 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t, unsigned);
# 2932 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsMapResources(int, cudaGraphicsResource_t *, cudaStream_t = 0);
# 2963 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsUnmapResources(int, cudaGraphicsResource_t *, cudaStream_t = 0);
# 2992 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void **, size_t *, cudaGraphicsResource_t);
# 3026 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray **, cudaGraphicsResource_t, unsigned, unsigned);
# 3059 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
# 3094 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 3136 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
# 3179 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
# 3207 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 3228 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
# 3253 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
# 3277 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 3310 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference *, const cudaArray *, const cudaChannelFormatDesc *);
# 3328 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference **, const char *);
# 3355 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
# 3372 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 3377 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetExportTable(const void **, const cudaUUID_t *);
# 93 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template< class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
# 94 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 95 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
# 96 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 98 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf()
# 99 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 100 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 102 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 103 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 105 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1()
# 106 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 107 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 109 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 110 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 112 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2()
# 113 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 114 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 116 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 117 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 119 "/usr/local/cuda/bin/../include/channel_descriptor.h"
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4()
# 120 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 121 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 123 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 124 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 126 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
# 127 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 128 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(char)) * 8);
# 133 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 135 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 137 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
# 138 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 139 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 141 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 142 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 144 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
# 145 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 146 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 148 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 149 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 151 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
# 152 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 153 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 155 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 156 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 158 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
# 159 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 160 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 162 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 163 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 165 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
# 166 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 167 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 169 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 170 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 172 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
# 173 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 174 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 176 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 177 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 179 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
# 180 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 181 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(signed char)) * 8);
# 183 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 184 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 186 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
# 187 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 188 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned char)) * 8);
# 190 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 191 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 193 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
# 194 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 195 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 197 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 198 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 200 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
# 201 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 202 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 204 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 205 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 207 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
# 208 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 209 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 211 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 212 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 214 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
# 215 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 216 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 218 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 219 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 221 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
# 222 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 223 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 225 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 226 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 228 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
# 229 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 230 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 232 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 233 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 235 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
# 236 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 237 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(short)) * 8);
# 239 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 240 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 242 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
# 243 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 244 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned short)) * 8);
# 246 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 247 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 249 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
# 250 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 251 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 253 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 254 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 256 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
# 257 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 258 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 260 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 261 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 263 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
# 264 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 265 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 267 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 268 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 270 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
# 271 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 272 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 274 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 275 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 277 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
# 278 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 279 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 281 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 282 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 284 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
# 285 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 286 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 288 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 289 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 291 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
# 292 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 293 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(int)) * 8);
# 295 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 296 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 298 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
# 299 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 300 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned)) * 8);
# 302 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 303 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 307 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long> ()
# 308 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 309 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(long)) * 8);
# 311 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 312 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 314 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned long> ()
# 315 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 316 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned long)) * 8);
# 318 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 319 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 321 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long1> ()
# 322 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 323 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(long)) * 8);
# 325 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
# 326 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 328 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong1> ()
# 329 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 330 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned long)) * 8);
# 332 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
# 333 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 335 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long2> ()
# 336 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 337 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(long)) * 8);
# 339 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
# 340 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 342 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong2> ()
# 343 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 344 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned long)) * 8);
# 346 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
# 347 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 349 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long4> ()
# 350 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 351 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(long)) * 8);
# 353 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
# 354 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 356 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong4> ()
# 357 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 358 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(unsigned long)) * 8);
# 360 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
# 361 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 365 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
# 366 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 367 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 369 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 370 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 372 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
# 373 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 374 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 376 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
# 377 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 379 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
# 380 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 381 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 383 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
# 384 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 386 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
# 387 "/usr/local/cuda/bin/../include/channel_descriptor.h"
{
# 388 "/usr/local/cuda/bin/../include/channel_descriptor.h"
int e = (((int)sizeof(float)) * 8);
# 390 "/usr/local/cuda/bin/../include/channel_descriptor.h"
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
# 391 "/usr/local/cuda/bin/../include/channel_descriptor.h"
}
# 65 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
# 66 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 67 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPitchedPtr s;
# 69 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ptr) = d;
# 70 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.pitch) = p;
# 71 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.xsize) = xsz;
# 72 "/usr/local/cuda/bin/../include/driver_functions.h"
(s.ysize) = ysz;
# 74 "/usr/local/cuda/bin/../include/driver_functions.h"
return s;
# 75 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 92 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
# 93 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 94 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaPos p;
# 96 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.x) = x;
# 97 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.y) = y;
# 98 "/usr/local/cuda/bin/../include/driver_functions.h"
(p.z) = z;
# 100 "/usr/local/cuda/bin/../include/driver_functions.h"
return p;
# 101 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 118 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
# 119 "/usr/local/cuda/bin/../include/driver_functions.h"
{
# 120 "/usr/local/cuda/bin/../include/driver_functions.h"
cudaExtent e;
# 122 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.width) = w;
# 123 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.height) = h;
# 124 "/usr/local/cuda/bin/../include/driver_functions.h"
(e.depth) = d;
# 126 "/usr/local/cuda/bin/../include/driver_functions.h"
return e;
# 127 "/usr/local/cuda/bin/../include/driver_functions.h"
}
# 55 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
# 56 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 57 "/usr/local/cuda/bin/../include/vector_functions.h"
char1 t; (t.x) = x; return t;
# 58 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 60 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar1 make_uchar1(unsigned char x)
# 61 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 62 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar1 t; (t.x) = x; return t;
# 63 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 65 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char2 make_char2(signed char x, signed char y)
# 66 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 67 "/usr/local/cuda/bin/../include/vector_functions.h"
char2 t; (t.x) = x; (t.y) = y; return t;
# 68 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 70 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
# 71 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 72 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar2 t; (t.x) = x; (t.y) = y; return t;
# 73 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 75 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char3 make_char3(signed char x, signed char y, signed char z)
# 76 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 77 "/usr/local/cuda/bin/../include/vector_functions.h"
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 78 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 80 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
# 81 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 82 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 83 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 85 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
# 86 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 87 "/usr/local/cuda/bin/../include/vector_functions.h"
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 88 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 90 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
# 91 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 92 "/usr/local/cuda/bin/../include/vector_functions.h"
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 93 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 95 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short1 make_short1(short x)
# 96 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 97 "/usr/local/cuda/bin/../include/vector_functions.h"
short1 t; (t.x) = x; return t;
# 98 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 100 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort1 make_ushort1(unsigned short x)
# 101 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 102 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort1 t; (t.x) = x; return t;
# 103 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 105 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short2 make_short2(short x, short y)
# 106 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 107 "/usr/local/cuda/bin/../include/vector_functions.h"
short2 t; (t.x) = x; (t.y) = y; return t;
# 108 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 110 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
# 111 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 112 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort2 t; (t.x) = x; (t.y) = y; return t;
# 113 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 115 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short3 make_short3(short x, short y, short z)
# 116 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 117 "/usr/local/cuda/bin/../include/vector_functions.h"
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 118 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 120 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
# 121 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 122 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 123 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 125 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline short4 make_short4(short x, short y, short z, short w)
# 126 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 127 "/usr/local/cuda/bin/../include/vector_functions.h"
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 128 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 130 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
# 131 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 132 "/usr/local/cuda/bin/../include/vector_functions.h"
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 133 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 135 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int1 make_int1(int x)
# 136 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 137 "/usr/local/cuda/bin/../include/vector_functions.h"
int1 t; (t.x) = x; return t;
# 138 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 140 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint1 make_uint1(unsigned x)
# 141 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 142 "/usr/local/cuda/bin/../include/vector_functions.h"
uint1 t; (t.x) = x; return t;
# 143 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 145 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int2 make_int2(int x, int y)
# 146 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 147 "/usr/local/cuda/bin/../include/vector_functions.h"
int2 t; (t.x) = x; (t.y) = y; return t;
# 148 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 150 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint2 make_uint2(unsigned x, unsigned y)
# 151 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 152 "/usr/local/cuda/bin/../include/vector_functions.h"
uint2 t; (t.x) = x; (t.y) = y; return t;
# 153 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 155 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int3 make_int3(int x, int y, int z)
# 156 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 157 "/usr/local/cuda/bin/../include/vector_functions.h"
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 158 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 160 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
# 161 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 162 "/usr/local/cuda/bin/../include/vector_functions.h"
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 163 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 165 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline int4 make_int4(int x, int y, int z, int w)
# 166 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 167 "/usr/local/cuda/bin/../include/vector_functions.h"
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 168 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 170 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
# 171 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 172 "/usr/local/cuda/bin/../include/vector_functions.h"
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 173 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 175 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long1 make_long1(long x)
# 176 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 177 "/usr/local/cuda/bin/../include/vector_functions.h"
long1 t; (t.x) = x; return t;
# 178 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 180 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong1 make_ulong1(unsigned long x)
# 181 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 182 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong1 t; (t.x) = x; return t;
# 183 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 185 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long2 make_long2(long x, long y)
# 186 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 187 "/usr/local/cuda/bin/../include/vector_functions.h"
long2 t; (t.x) = x; (t.y) = y; return t;
# 188 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 190 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
# 191 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 192 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong2 t; (t.x) = x; (t.y) = y; return t;
# 193 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 195 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long3 make_long3(long x, long y, long z)
# 196 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 197 "/usr/local/cuda/bin/../include/vector_functions.h"
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 198 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 200 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z)
# 201 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 202 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 203 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 205 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline long4 make_long4(long x, long y, long z, long w)
# 206 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 207 "/usr/local/cuda/bin/../include/vector_functions.h"
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 208 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 210 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w)
# 211 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 212 "/usr/local/cuda/bin/../include/vector_functions.h"
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 213 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 215 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float1 make_float1(float x)
# 216 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 217 "/usr/local/cuda/bin/../include/vector_functions.h"
float1 t; (t.x) = x; return t;
# 218 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 220 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float2 make_float2(float x, float y)
# 221 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 222 "/usr/local/cuda/bin/../include/vector_functions.h"
float2 t; (t.x) = x; (t.y) = y; return t;
# 223 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 225 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float3 make_float3(float x, float y, float z)
# 226 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 227 "/usr/local/cuda/bin/../include/vector_functions.h"
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 228 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 230 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline float4 make_float4(float x, float y, float z, float w)
# 231 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 232 "/usr/local/cuda/bin/../include/vector_functions.h"
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 233 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 235 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong1 make_longlong1(long long x)
# 236 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 237 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong1 t; (t.x) = x; return t;
# 238 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 240 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong1 make_ulonglong1(unsigned long long x)
# 241 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 242 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong1 t; (t.x) = x; return t;
# 243 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 245 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong2 make_longlong2(long long x, long long y)
# 246 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 247 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong2 t; (t.x) = x; (t.y) = y; return t;
# 248 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 250 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
# 251 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 252 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong2 t; (t.x) = x; (t.y) = y; return t;
# 253 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 255 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong3 make_longlong3(long long x, long long y, long long z)
# 256 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 257 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 258 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 260 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z)
# 261 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 262 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 263 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 265 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w)
# 266 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 267 "/usr/local/cuda/bin/../include/vector_functions.h"
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 268 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 270 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w)
# 271 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 272 "/usr/local/cuda/bin/../include/vector_functions.h"
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 273 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 275 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double1 make_double1(double x)
# 276 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 277 "/usr/local/cuda/bin/../include/vector_functions.h"
double1 t; (t.x) = x; return t;
# 278 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 280 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double2 make_double2(double x, double y)
# 281 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 282 "/usr/local/cuda/bin/../include/vector_functions.h"
double2 t; (t.x) = x; (t.y) = y; return t;
# 283 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 285 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double3 make_double3(double x, double y, double z)
# 286 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 287 "/usr/local/cuda/bin/../include/vector_functions.h"
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
# 288 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 290 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline double4 make_double4(double x, double y, double z, double w)
# 291 "/usr/local/cuda/bin/../include/vector_functions.h"
{
# 292 "/usr/local/cuda/bin/../include/vector_functions.h"
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
# 293 "/usr/local/cuda/bin/../include/vector_functions.h"
}
# 37 "/usr/include/i386/_types.h" 3
typedef signed char __int8_t;
# 41 "/usr/include/i386/_types.h" 3
typedef unsigned char __uint8_t;
# 42 "/usr/include/i386/_types.h" 3
typedef short __int16_t;
# 43 "/usr/include/i386/_types.h" 3
typedef unsigned short __uint16_t;
# 44 "/usr/include/i386/_types.h" 3
typedef int __int32_t;
# 45 "/usr/include/i386/_types.h" 3
typedef unsigned __uint32_t;
# 46 "/usr/include/i386/_types.h" 3
typedef long long __int64_t;
# 47 "/usr/include/i386/_types.h" 3
typedef unsigned long long __uint64_t;
# 49 "/usr/include/i386/_types.h" 3
typedef long __darwin_intptr_t;
# 50 "/usr/include/i386/_types.h" 3
typedef unsigned __darwin_natural_t;
# 70 "/usr/include/i386/_types.h" 3
typedef int __darwin_ct_rune_t;
# 79 "/usr/include/i386/_types.h" 3
typedef
# 76 "/usr/include/i386/_types.h" 3
union {
# 77 "/usr/include/i386/_types.h" 3
char __mbstate8[128];
# 78 "/usr/include/i386/_types.h" 3
long long _mbstateL;
# 79 "/usr/include/i386/_types.h" 3
} __mbstate_t;
# 81 "/usr/include/i386/_types.h" 3
typedef __mbstate_t __darwin_mbstate_t;
# 84 "/usr/include/i386/_types.h" 3
typedef int __darwin_ptrdiff_t;
# 90 "/usr/include/i386/_types.h" 3
typedef unsigned long __darwin_size_t;
# 96 "/usr/include/i386/_types.h" 3
typedef __builtin_va_list __darwin_va_list;
# 102 "/usr/include/i386/_types.h" 3
typedef int __darwin_wchar_t;
# 107 "/usr/include/i386/_types.h" 3
typedef __darwin_wchar_t __darwin_rune_t;
# 110 "/usr/include/i386/_types.h" 3
typedef int __darwin_wint_t;
# 115 "/usr/include/i386/_types.h" 3
typedef unsigned long __darwin_clock_t;
# 116 "/usr/include/i386/_types.h" 3
typedef __uint32_t __darwin_socklen_t;
# 117 "/usr/include/i386/_types.h" 3
typedef long __darwin_ssize_t;
# 118 "/usr/include/i386/_types.h" 3
typedef long __darwin_time_t;
# 58 "/usr/include/sys/_types.h" 3
struct __darwin_pthread_handler_rec {
# 60 "/usr/include/sys/_types.h" 3
void (*__routine)(void *);
# 61 "/usr/include/sys/_types.h" 3
void *__arg;
# 62 "/usr/include/sys/_types.h" 3
__darwin_pthread_handler_rec *__next;
# 63 "/usr/include/sys/_types.h" 3
};
# 64 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_attr_t { long __sig; char __opaque[36]; };
# 65 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_cond_t { long __sig; char __opaque[24]; };
# 66 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_condattr_t { long __sig; char __opaque[4]; };
# 67 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_mutex_t { long __sig; char __opaque[40]; };
# 68 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_mutexattr_t { long __sig; char __opaque[8]; };
# 69 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_once_t { long __sig; char __opaque[4]; };
# 70 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_rwlock_t { long __sig; char __opaque[124]; };
# 71 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_rwlockattr_t { long __sig; char __opaque[12]; };
# 72 "/usr/include/sys/_types.h" 3
struct _opaque_pthread_t { long __sig; __darwin_pthread_handler_rec *__cleanup_stack; char __opaque[596]; };
# 94 "/usr/include/sys/_types.h" 3
typedef __int64_t __darwin_blkcnt_t;
# 95 "/usr/include/sys/_types.h" 3
typedef __int32_t __darwin_blksize_t;
# 96 "/usr/include/sys/_types.h" 3
typedef __int32_t __darwin_dev_t;
# 97 "/usr/include/sys/_types.h" 3
typedef unsigned __darwin_fsblkcnt_t;
# 98 "/usr/include/sys/_types.h" 3
typedef unsigned __darwin_fsfilcnt_t;
# 99 "/usr/include/sys/_types.h" 3
typedef __uint32_t __darwin_gid_t;
# 100 "/usr/include/sys/_types.h" 3
typedef __uint32_t __darwin_id_t;
# 101 "/usr/include/sys/_types.h" 3
typedef __uint64_t __darwin_ino64_t;
# 103 "/usr/include/sys/_types.h" 3
typedef __darwin_ino64_t __darwin_ino_t;
# 107 "/usr/include/sys/_types.h" 3
typedef __darwin_natural_t __darwin_mach_port_name_t;
# 108 "/usr/include/sys/_types.h" 3
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
# 109 "/usr/include/sys/_types.h" 3
typedef __uint16_t __darwin_mode_t;
# 110 "/usr/include/sys/_types.h" 3
typedef __int64_t __darwin_off_t;
# 111 "/usr/include/sys/_types.h" 3
typedef __int32_t __darwin_pid_t;
# 113 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_attr_t __darwin_pthread_attr_t;
# 115 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_cond_t __darwin_pthread_cond_t;
# 117 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
# 118 "/usr/include/sys/_types.h" 3
typedef unsigned long __darwin_pthread_key_t;
# 120 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
# 122 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
# 124 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_once_t __darwin_pthread_once_t;
# 126 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
# 128 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
# 130 "/usr/include/sys/_types.h" 3
typedef _opaque_pthread_t *__darwin_pthread_t;
# 131 "/usr/include/sys/_types.h" 3
typedef __uint32_t __darwin_sigset_t;
# 132 "/usr/include/sys/_types.h" 3
typedef __int32_t __darwin_suseconds_t;
# 133 "/usr/include/sys/_types.h" 3
typedef __uint32_t __darwin_uid_t;
# 134 "/usr/include/sys/_types.h" 3
typedef __uint32_t __darwin_useconds_t;
# 135 "/usr/include/sys/_types.h" 3
typedef unsigned char __darwin_uuid_t[16];
# 136 "/usr/include/sys/_types.h" 3
typedef char __darwin_uuid_string_t[37];
# 39 "/usr/include/_types.h" 3
typedef int __darwin_nl_item;
# 40 "/usr/include/_types.h" 3
typedef int __darwin_wctrans_t;
# 44 "/usr/include/_types.h" 3
typedef unsigned long __darwin_wctype_t;
# 70 "/usr/include/string.h" 3
typedef __darwin_ssize_t ssize_t;
# 81 "/usr/include/string.h" 3
extern "C" void *memchr(const void *, int, size_t);
# 82 "/usr/include/string.h" 3
extern "C" int memcmp(const void *, const void *, size_t);
# 83 "/usr/include/string.h" 3
extern "C" __attribute__((weak)) void *memcpy(void *, const void *, size_t);
# 84 "/usr/include/string.h" 3
extern "C" void *memmove(void *, const void *, size_t);
# 85 "/usr/include/string.h" 3
extern "C" __attribute__((weak)) void *memset(void *, int, size_t);
# 87 "/usr/include/string.h" 3
extern "C" char *stpcpy(char *, const char *);
# 88 "/usr/include/string.h" 3
extern "C" char *strcasestr(const char *, const char *);
# 90 "/usr/include/string.h" 3
extern "C" char *strcat(char *, const char *);
# 91 "/usr/include/string.h" 3
extern "C" char *strchr(const char *, int);
# 92 "/usr/include/string.h" 3
extern "C" int strcmp(const char *, const char *);
# 93 "/usr/include/string.h" 3
extern "C" int strcoll(const char *, const char *);
# 94 "/usr/include/string.h" 3
extern "C" char *strcpy(char *, const char *);
# 95 "/usr/include/string.h" 3
extern "C" size_t strcspn(const char *, const char *);
# 96 "/usr/include/string.h" 3
extern "C" char *strerror(int) __asm__("_strerror$UNIX2003");
# 97 "/usr/include/string.h" 3
extern "C" int strerror_r(int, char *, size_t);
# 98 "/usr/include/string.h" 3
extern "C" size_t strlen(const char *);
# 99 "/usr/include/string.h" 3
extern "C" char *strncat(char *, const char *, size_t);
# 100 "/usr/include/string.h" 3
extern "C" int strncmp(const char *, const char *, size_t);
# 101 "/usr/include/string.h" 3
extern "C" char *strncpy(char *, const char *, size_t);
# 103 "/usr/include/string.h" 3
extern "C" char *strnstr(const char *, const char *, size_t);
# 105 "/usr/include/string.h" 3
extern "C" char *strpbrk(const char *, const char *);
# 106 "/usr/include/string.h" 3
extern "C" char *strrchr(const char *, int);
# 107 "/usr/include/string.h" 3
extern "C" size_t strspn(const char *, const char *);
# 108 "/usr/include/string.h" 3
extern "C" char *strstr(const char *, const char *);
# 109 "/usr/include/string.h" 3
extern "C" char *strtok(char *, const char *);
# 110 "/usr/include/string.h" 3
extern "C" size_t strxfrm(char *, const char *, size_t);
# 114 "/usr/include/string.h" 3
extern "C" void *memccpy(void *, const void *, int, size_t);
# 115 "/usr/include/string.h" 3
extern "C" char *strtok_r(char *, const char *, char **);
# 116 "/usr/include/string.h" 3
extern "C" char *strdup(const char *);
# 118 "/usr/include/string.h" 3
extern "C" int bcmp(const void *, const void *, size_t);
# 119 "/usr/include/string.h" 3
extern "C" void bcopy(const void *, void *, size_t);
# 120 "/usr/include/string.h" 3
extern "C" void bzero(void *, size_t);
# 121 "/usr/include/string.h" 3
extern "C" int ffs(int);
# 122 "/usr/include/string.h" 3
extern "C" int ffsl(long);
# 123 "/usr/include/string.h" 3
extern "C" int fls(int);
# 124 "/usr/include/string.h" 3
extern "C" int flsl(long);
# 125 "/usr/include/string.h" 3
extern "C" char *index(const char *, int);
# 126 "/usr/include/string.h" 3
extern "C" void memset_pattern4(void *, const void *, size_t);
# 127 "/usr/include/string.h" 3
extern "C" void memset_pattern8(void *, const void *, size_t);
# 128 "/usr/include/string.h" 3
extern "C" void memset_pattern16(void *, const void *, size_t);
# 129 "/usr/include/string.h" 3
extern "C" char *rindex(const char *, int);
# 130 "/usr/include/string.h" 3
extern "C" int strcasecmp(const char *, const char *);
# 131 "/usr/include/string.h" 3
extern "C" size_t strlcat(char *, const char *, size_t);
# 132 "/usr/include/string.h" 3
extern "C" size_t strlcpy(char *, const char *, size_t);
# 133 "/usr/include/string.h" 3
extern "C" void strmode(int, char *);
# 134 "/usr/include/string.h" 3
extern "C" int strncasecmp(const char *, const char *, size_t);
# 135 "/usr/include/string.h" 3
extern "C" char *strsep(char **, const char *);
# 136 "/usr/include/string.h" 3
extern "C" char *strsignal(int);
# 137 "/usr/include/string.h" 3
extern "C" void swab(const void *, void *, ssize_t);
# 88 "/usr/include/sys/_structs.h" 3
struct timespec {
# 90 "/usr/include/sys/_structs.h" 3
__darwin_time_t tv_sec;
# 91 "/usr/include/sys/_structs.h" 3
long tv_nsec;
# 92 "/usr/include/sys/_structs.h" 3
};
# 77 "/usr/include/time.h" 3
typedef __darwin_clock_t clock_t;
# 87 "/usr/include/time.h" 3
typedef __darwin_time_t time_t;
# 90 "/usr/include/time.h" 3
struct tm {
# 91 "/usr/include/time.h" 3
int tm_sec;
# 92 "/usr/include/time.h" 3
int tm_min;
# 93 "/usr/include/time.h" 3
int tm_hour;
# 94 "/usr/include/time.h" 3
int tm_mday;
# 95 "/usr/include/time.h" 3
int tm_mon;
# 96 "/usr/include/time.h" 3
int tm_year;
# 97 "/usr/include/time.h" 3
int tm_wday;
# 98 "/usr/include/time.h" 3
int tm_yday;
# 99 "/usr/include/time.h" 3
int tm_isdst;
# 100 "/usr/include/time.h" 3
long tm_gmtoff;
# 101 "/usr/include/time.h" 3
char *tm_zone;
# 102 "/usr/include/time.h" 3
};
# 113 "/usr/include/time.h" 3
extern char *tzname[];
# 116 "/usr/include/time.h" 3
extern int getdate_err;
# 118 "/usr/include/time.h" 3
extern long timezone __asm__("_timezone$UNIX2003");
# 120 "/usr/include/time.h" 3
extern int daylight;
# 123 "/usr/include/time.h" 3
extern "C" char *asctime(const tm *);
# 124 "/usr/include/time.h" 3
extern "C" __attribute__((weak)) clock_t clock() __asm__("_clock$UNIX2003");
# 125 "/usr/include/time.h" 3
extern "C" char *ctime(const time_t *);
# 126 "/usr/include/time.h" 3
extern "C" double difftime(time_t, time_t);
# 127 "/usr/include/time.h" 3
extern "C" tm *getdate(const char *);
# 128 "/usr/include/time.h" 3
extern "C" tm *gmtime(const time_t *);
# 129 "/usr/include/time.h" 3
extern "C" tm *localtime(const time_t *);
# 130 "/usr/include/time.h" 3
extern "C" time_t mktime(tm *) __asm__("_mktime$UNIX2003");
# 131 "/usr/include/time.h" 3
extern "C" size_t strftime(char *, size_t, const char *, const tm *) __asm__("_strftime$UNIX2003");
# 132 "/usr/include/time.h" 3
extern "C" char *strptime(const char *, const char *, tm *) __asm__("_strptime$UNIX2003");
# 133 "/usr/include/time.h" 3
extern "C" time_t time(time_t *);
# 136 "/usr/include/time.h" 3
extern "C" void tzset();
# 140 "/usr/include/time.h" 3
extern "C" char *asctime_r(const tm *, char *);
# 141 "/usr/include/time.h" 3
extern "C" char *ctime_r(const time_t *, char *);
# 142 "/usr/include/time.h" 3
extern "C" tm *gmtime_r(const time_t *, tm *);
# 143 "/usr/include/time.h" 3
extern "C" tm *localtime_r(const time_t *, tm *);
# 146 "/usr/include/time.h" 3
extern "C" time_t posix2time(time_t);
# 150 "/usr/include/time.h" 3
extern "C" void tzsetwall();
# 151 "/usr/include/time.h" 3
extern "C" time_t time2posix(time_t);
# 152 "/usr/include/time.h" 3
extern "C" time_t timelocal(tm *const);
# 153 "/usr/include/time.h" 3
extern "C" time_t timegm(tm *const);
# 157 "/usr/include/time.h" 3
extern "C" int nanosleep(const timespec *, timespec *) __asm__("_nanosleep$UNIX2003");
# 57 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) clock_t clock() __asm__("_clock$UNIX2003");
# 59 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) void *memset(void *, int, size_t);
# 61 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((weak)) void *memcpy(void *, const void *, size_t);
# 66 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int abs(int) __attribute__((__const__));
# 68 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long labs(long) __attribute__((__const__));
# 70 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llabs(long long);
# 72 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fabs(double);
# 74 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fabsf(float);
# 77 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int min(int, int);
# 79 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned umin(unsigned, unsigned);
# 81 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llmin(long long, long long);
# 83 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned long long ullmin(unsigned long long, unsigned long long);
# 85 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fminf(float, float);
# 87 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmin(double, double);
# 90 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int max(int, int);
# 92 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned umax(unsigned, unsigned);
# 94 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llmax(long long, long long);
# 96 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) unsigned long long ullmax(unsigned long long, unsigned long long);
# 98 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmaxf(float, float);
# 100 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmax(double, double);
# 103 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sin(double);
# 105 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinf(float);
# 108 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cos(double);
# 110 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float cosf(float);
# 113 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) void sincos(double, double *, double *);
# 115 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) void sincosf(float, float *, float *);
# 118 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tan(double);
# 120 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tanf(float);
# 123 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sqrt(double);
# 125 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sqrtf(float);
# 128 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rsqrt(double);
# 130 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rsqrtf(float);
# 133 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp2(double);
# 135 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float exp2f(float);
# 138 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp10(double);
# 140 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float exp10f(float);
# 143 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double expm1(double);
# 145 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float expm1f(float);
# 148 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log2(double);
# 150 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log2f(float);
# 153 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log10(double);
# 155 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log10f(float);
# 158 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log(double);
# 160 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float logf(float);
# 163 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double log1p(double);
# 165 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float log1pf(float);
# 168 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double floor(double);
# 170 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float floorf(float);
# 173 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double exp(double);
# 175 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float expf(float);
# 178 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cosh(double);
# 180 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float coshf(float);
# 183 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sinh(double);
# 185 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinhf(float);
# 188 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tanh(double);
# 190 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tanhf(float);
# 193 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double acosh(double);
# 195 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float acoshf(float);
# 198 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double asinh(double);
# 200 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float asinhf(float);
# 203 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atanh(double);
# 205 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atanhf(float);
# 208 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double ldexp(double, int);
# 210 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float ldexpf(float, int);
# 213 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double logb(double);
# 215 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float logbf(float);
# 218 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int ilogb(double);
# 220 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int ilogbf(float);
# 223 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double scalbn(double, int);
# 225 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float scalbnf(float, int);
# 228 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double scalbln(double, long);
# 230 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float scalblnf(float, long);
# 233 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double frexp(double, int *);
# 235 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float frexpf(float, int *);
# 238 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double round(double);
# 240 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float roundf(float);
# 243 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lround(double);
# 245 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lroundf(float);
# 248 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llround(double);
# 250 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llroundf(float);
# 253 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rint(double);
# 255 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rintf(float);
# 258 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lrint(double);
# 260 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long lrintf(float);
# 263 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llrint(double);
# 265 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) long long llrintf(float);
# 268 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nearbyint(double);
# 270 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nearbyintf(float);
# 273 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double ceil(double);
# 275 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float ceilf(float);
# 278 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double trunc(double);
# 280 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float truncf(float);
# 283 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fdim(double, double);
# 285 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fdimf(float, float);
# 288 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atan2(double, double);
# 290 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atan2f(float, float);
# 293 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double atan(double);
# 295 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float atanf(float);
# 298 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double asin(double);
# 300 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float asinf(float);
# 303 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double acos(double);
# 305 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float acosf(float);
# 308 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double hypot(double, double);
# 310 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float hypotf(float, float);
# 313 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double cbrt(double);
# 315 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float cbrtf(float);
# 318 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double rcbrt(double);
# 320 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float rcbrtf(float);
# 323 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double sinpi(double);
# 325 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float sinpif(float);
# 328 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double pow(double, double);
# 330 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float powf(float, float);
# 333 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double modf(double, double *);
# 335 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float modff(float, float *);
# 338 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fmod(double, double);
# 340 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmodf(float, float);
# 343 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double remainder(double, double);
# 345 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float remainderf(float, float);
# 348 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double remquo(double, double, int *);
# 350 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float remquof(float, float, int *);
# 353 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erf(double);
# 355 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erff(float);
# 358 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfinv(double);
# 360 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfinvf(float);
# 363 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfc(double);
# 365 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfcf(float);
# 368 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double erfcinv(double);
# 370 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float erfcinvf(float);
# 373 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double lgamma(double);
# 375 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float lgammaf(float);
# 378 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double tgamma(double);
# 380 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float tgammaf(float);
# 383 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double copysign(double, double);
# 385 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float copysignf(float, float);
# 388 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nextafter(double, double);
# 390 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nextafterf(float, float);
# 393 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double nan(const char *);
# 395 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float nanf(const char *);
# 398 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinf(double);
# 400 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinff(float);
# 403 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnan(double);
# 405 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnanf(float);
# 410 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isfinited(double);
# 412 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isfinitef(float);
# 414 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitd(double);
# 428 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitf(float);
# 431 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) double fma(double, double, double);
# 433 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) float fmaf(float, float, float);
# 441 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __signbitl(long double);
# 443 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isinfl(long double);
# 445 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isnanl(long double);
# 450 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((weak)) int __isfinite(long double);
# 49 "/usr/include/architecture/i386/math.h" 3
extern "C" { typedef float float_t; }
# 50 "/usr/include/architecture/i386/math.h" 3
extern "C" { typedef double double_t; }
# 108 "/usr/include/architecture/i386/math.h" 3
extern "C" unsigned __math_errhandling();
# 128 "/usr/include/architecture/i386/math.h" 3
extern "C" int __fpclassifyf(float);
# 129 "/usr/include/architecture/i386/math.h" 3
extern "C" int __fpclassifyd(double);
# 130 "/usr/include/architecture/i386/math.h" 3
extern "C" int __fpclassify(long double);
# 163 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isfinitef(float) __attribute__((__always_inline__)); }
# 164 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isfinited(double) __attribute__((__always_inline__)); }
# 165 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isfinite(long double) __attribute__((__always_inline__)); }
# 166 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isinff(float) __attribute__((__always_inline__)); }
# 167 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isinfd(double) __attribute__((__always_inline__)); }
# 168 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isinf(long double) __attribute__((__always_inline__)); }
# 169 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isnanf(float) __attribute__((__always_inline__)); }
# 170 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isnand(double) __attribute__((__always_inline__)); }
# 171 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isnan(long double) __attribute__((__always_inline__)); }
# 172 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isnormalf(float) __attribute__((__always_inline__)); }
# 173 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isnormald(double) __attribute__((__always_inline__)); }
# 174 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_isnormal(long double) __attribute__((__always_inline__)); }
# 175 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_signbitf(float) __attribute__((__always_inline__)); }
# 176 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_signbitd(double) __attribute__((__always_inline__)); }
# 177 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline int __inline_signbit(long double) __attribute__((__always_inline__)); }
# 179 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isinff(float __x) { return __builtin_fabsf(__x) == __builtin_inff(); } }
# 180 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isinfd(double __x) { return __builtin_fabs(__x) == __builtin_inf(); } }
# 181 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isinf(long double __x) { return __builtin_fabsl(__x) == __builtin_infl(); } }
# 182 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isfinitef(float __x) { return (__x == __x) && (__builtin_fabsf(__x) != __builtin_inff()); } }
# 183 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isfinited(double __x) { return (__x == __x) && (__builtin_fabs(__x) != __builtin_inf()); } }
# 184 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isfinite(long double __x) { return (__x == __x) && (__builtin_fabsl(__x) != __builtin_infl()); } }
# 185 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isnanf(float __x) { return __x != __x; } }
# 186 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isnand(double __x) { return __x != __x; } }
# 187 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isnan(long double __x) { return __x != __x; } }
# 188 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_signbitf(float __x) { union { float __f; unsigned __u; } __u; (__u.__f) = __x; return (int)((__u.__u) >> 31); } }
# 189 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_signbitd(double __x) { union { double __f; unsigned __u[2]; } __u; (__u.__f) = __x; return (int)(((__u.__u)[1]) >> 31); } }
# 190 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_signbit(long double __x) { union { long double __ld; struct { unsigned __m[2]; short __sexp; } __p; } __u; (__u.__ld) = __x; return (int)(((unsigned short)((__u.__p).__sexp)) >> 15); } }
# 191 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isnormalf(float __x) { float fabsf = __builtin_fabsf(__x); if (__x != __x) { return 0; } return (fabsf < __builtin_inff()) && (fabsf >= (1.175494351e-38F)); } }
# 192 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isnormald(double __x) { double fabsf = __builtin_fabs(__x); if (__x != __x) { return 0; } return (fabsf < __builtin_inf()) && (fabsf >= (2.225073858507201383e-308)); } }
# 193 "/usr/include/architecture/i386/math.h" 3
extern "C" { static inline __attribute__((__always_inline__)) int __inline_isnormal(long double __x) { long double fabsf = __builtin_fabsl(__x); if (__x != __x) { return 0; } return (fabsf < __builtin_infl()) && (fabsf >= (0.0L)); } }
# 253 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double acos(double);
# 254 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float acosf(float);
# 256 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double asin(double);
# 257 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float asinf(float);
# 259 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double atan(double);
# 260 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float atanf(float);
# 262 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double atan2(double, double);
# 263 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float atan2f(float, float);
# 265 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double cos(double);
# 266 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float cosf(float);
# 268 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double sin(double);
# 269 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float sinf(float);
# 271 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double tan(double);
# 272 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float tanf(float);
# 274 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double acosh(double);
# 275 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float acoshf(float);
# 277 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double asinh(double);
# 278 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float asinhf(float);
# 280 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double atanh(double);
# 281 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float atanhf(float);
# 283 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double cosh(double);
# 284 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float coshf(float);
# 286 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double sinh(double);
# 287 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float sinhf(float);
# 289 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double tanh(double);
# 290 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float tanhf(float);
# 292 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double exp(double);
# 293 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float expf(float);
# 295 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double exp2(double);
# 296 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float exp2f(float);
# 298 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double expm1(double);
# 299 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float expm1f(float);
# 301 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double log(double);
# 302 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float logf(float);
# 304 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double log10(double);
# 305 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float log10f(float);
# 307 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double log2(double);
# 308 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float log2f(float);
# 310 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double log1p(double);
# 311 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float log1pf(float);
# 313 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double logb(double);
# 314 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float logbf(float);
# 316 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double modf(double, double *);
# 317 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float modff(float, float *);
# 319 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double ldexp(double, int);
# 320 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float ldexpf(float, int);
# 322 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double frexp(double, int *);
# 323 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float frexpf(float, int *);
# 325 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) int ilogb(double);
# 326 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) int ilogbf(float);
# 328 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double scalbn(double, int);
# 329 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float scalbnf(float, int);
# 331 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double scalbln(double, long);
# 332 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float scalblnf(float, long);
# 334 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double fabs(double);
# 335 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float fabsf(float);
# 337 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double cbrt(double);
# 338 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float cbrtf(float);
# 340 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double hypot(double, double);
# 341 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float hypotf(float, float);
# 343 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double pow(double, double);
# 344 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float powf(float, float);
# 346 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double sqrt(double);
# 347 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float sqrtf(float);
# 349 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double erf(double);
# 350 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float erff(float);
# 352 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double erfc(double);
# 353 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float erfcf(float);
# 360 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double lgamma(double);
# 361 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float lgammaf(float);
# 363 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double tgamma(double);
# 364 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float tgammaf(float);
# 366 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double ceil(double);
# 367 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float ceilf(float);
# 369 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double floor(double);
# 370 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float floorf(float);
# 372 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double nearbyint(double);
# 373 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float nearbyintf(float);
# 375 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double rint(double);
# 376 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float rintf(float);
# 378 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) long lrint(double);
# 379 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) long lrintf(float);
# 381 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double round(double);
# 382 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float roundf(float);
# 384 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) long lround(double);
# 385 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) long lroundf(float);
# 390 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) long long llrint(double);
# 391 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) long long llrintf(float);
# 393 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) long long llround(double);
# 394 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) long long llroundf(float);
# 398 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double trunc(double);
# 399 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float truncf(float);
# 401 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double fmod(double, double);
# 402 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float fmodf(float, float);
# 404 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double remainder(double, double);
# 405 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float remainderf(float, float);
# 407 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double remquo(double, double, int *);
# 408 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float remquof(float, float, int *);
# 410 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double copysign(double, double);
# 411 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float copysignf(float, float);
# 413 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double nan(const char *);
# 414 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float nanf(const char *);
# 416 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double nextafter(double, double);
# 417 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float nextafterf(float, float);
# 419 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double fdim(double, double);
# 420 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float fdimf(float, float);
# 422 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double fmax(double, double);
# 423 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float fmaxf(float, float);
# 425 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double fmin(double, double);
# 426 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float fminf(float, float);
# 428 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) double fma(double, double, double);
# 429 "/usr/include/architecture/i386/math.h" 3
extern "C" __attribute__((weak)) float fmaf(float, float, float);
# 431 "/usr/include/architecture/i386/math.h" 3
extern "C" long double acosl(long double);
# 432 "/usr/include/architecture/i386/math.h" 3
extern "C" long double asinl(long double);
# 433 "/usr/include/architecture/i386/math.h" 3
extern "C" long double atanl(long double);
# 434 "/usr/include/architecture/i386/math.h" 3
extern "C" long double atan2l(long double, long double);
# 435 "/usr/include/architecture/i386/math.h" 3
extern "C" long double cosl(long double);
# 436 "/usr/include/architecture/i386/math.h" 3
extern "C" long double sinl(long double);
# 437 "/usr/include/architecture/i386/math.h" 3
extern "C" long double tanl(long double);
# 438 "/usr/include/architecture/i386/math.h" 3
extern "C" long double acoshl(long double);
# 439 "/usr/include/architecture/i386/math.h" 3
extern "C" long double asinhl(long double);
# 440 "/usr/include/architecture/i386/math.h" 3
extern "C" long double atanhl(long double);
# 441 "/usr/include/architecture/i386/math.h" 3
extern "C" long double coshl(long double);
# 442 "/usr/include/architecture/i386/math.h" 3
extern "C" long double sinhl(long double);
# 443 "/usr/include/architecture/i386/math.h" 3
extern "C" long double tanhl(long double);
# 444 "/usr/include/architecture/i386/math.h" 3
extern "C" long double expl(long double);
# 445 "/usr/include/architecture/i386/math.h" 3
extern "C" long double exp2l(long double);
# 446 "/usr/include/architecture/i386/math.h" 3
extern "C" long double expm1l(long double);
# 447 "/usr/include/architecture/i386/math.h" 3
extern "C" long double logl(long double);
# 448 "/usr/include/architecture/i386/math.h" 3
extern "C" long double log10l(long double);
# 449 "/usr/include/architecture/i386/math.h" 3
extern "C" long double log2l(long double);
# 450 "/usr/include/architecture/i386/math.h" 3
extern "C" long double log1pl(long double);
# 451 "/usr/include/architecture/i386/math.h" 3
extern "C" long double logbl(long double);
# 452 "/usr/include/architecture/i386/math.h" 3
extern "C" long double modfl(long double, long double *);
# 453 "/usr/include/architecture/i386/math.h" 3
extern "C" long double ldexpl(long double, int);
# 454 "/usr/include/architecture/i386/math.h" 3
extern "C" long double frexpl(long double, int *);
# 455 "/usr/include/architecture/i386/math.h" 3
extern "C" int ilogbl(long double);
# 456 "/usr/include/architecture/i386/math.h" 3
extern "C" long double scalbnl(long double, int);
# 457 "/usr/include/architecture/i386/math.h" 3
extern "C" long double scalblnl(long double, long);
# 458 "/usr/include/architecture/i386/math.h" 3
extern "C" long double fabsl(long double);
# 459 "/usr/include/architecture/i386/math.h" 3
extern "C" long double cbrtl(long double);
# 460 "/usr/include/architecture/i386/math.h" 3
extern "C" long double hypotl(long double, long double);
# 461 "/usr/include/architecture/i386/math.h" 3
extern "C" long double powl(long double, long double);
# 462 "/usr/include/architecture/i386/math.h" 3
extern "C" long double sqrtl(long double);
# 463 "/usr/include/architecture/i386/math.h" 3
extern "C" long double erfl(long double);
# 464 "/usr/include/architecture/i386/math.h" 3
extern "C" long double erfcl(long double);
# 471 "/usr/include/architecture/i386/math.h" 3
extern "C" long double lgammal(long double);
# 473 "/usr/include/architecture/i386/math.h" 3
extern "C" long double tgammal(long double);
# 474 "/usr/include/architecture/i386/math.h" 3
extern "C" long double ceill(long double);
# 475 "/usr/include/architecture/i386/math.h" 3
extern "C" long double floorl(long double);
# 476 "/usr/include/architecture/i386/math.h" 3
extern "C" long double nearbyintl(long double);
# 477 "/usr/include/architecture/i386/math.h" 3
extern "C" long double rintl(long double);
# 478 "/usr/include/architecture/i386/math.h" 3
extern "C" long lrintl(long double);
# 479 "/usr/include/architecture/i386/math.h" 3
extern "C" long double roundl(long double);
# 480 "/usr/include/architecture/i386/math.h" 3
extern "C" long lroundl(long double);
# 484 "/usr/include/architecture/i386/math.h" 3
extern "C" long long llrintl(long double);
# 485 "/usr/include/architecture/i386/math.h" 3
extern "C" long long llroundl(long double);
# 488 "/usr/include/architecture/i386/math.h" 3
extern "C" long double truncl(long double);
# 489 "/usr/include/architecture/i386/math.h" 3
extern "C" long double fmodl(long double, long double);
# 490 "/usr/include/architecture/i386/math.h" 3
extern "C" long double remainderl(long double, long double);
# 491 "/usr/include/architecture/i386/math.h" 3
extern "C" long double remquol(long double, long double, int *);
# 492 "/usr/include/architecture/i386/math.h" 3
extern "C" long double copysignl(long double, long double);
# 493 "/usr/include/architecture/i386/math.h" 3
extern "C" long double nanl(const char *);
# 494 "/usr/include/architecture/i386/math.h" 3
extern "C" long double nextafterl(long double, long double);
# 495 "/usr/include/architecture/i386/math.h" 3
extern "C" double nexttoward(double, long double);
# 496 "/usr/include/architecture/i386/math.h" 3
extern "C" float nexttowardf(float, long double);
# 497 "/usr/include/architecture/i386/math.h" 3
extern "C" long double nexttowardl(long double, long double);
# 498 "/usr/include/architecture/i386/math.h" 3
extern "C" long double fdiml(long double, long double);
# 499 "/usr/include/architecture/i386/math.h" 3
extern "C" long double fmaxl(long double, long double);
# 500 "/usr/include/architecture/i386/math.h" 3
extern "C" long double fminl(long double, long double);
# 501 "/usr/include/architecture/i386/math.h" 3
extern "C" long double fmal(long double, long double, long double);
# 510 "/usr/include/architecture/i386/math.h" 3
extern "C" double __inf();
# 511 "/usr/include/architecture/i386/math.h" 3
extern "C" float __inff();
# 512 "/usr/include/architecture/i386/math.h" 3
extern "C" long double __infl();
# 513 "/usr/include/architecture/i386/math.h" 3
extern "C" float __nan();
# 516 "/usr/include/architecture/i386/math.h" 3
extern "C" double j0(double);
# 518 "/usr/include/architecture/i386/math.h" 3
extern "C" double j1(double);
# 520 "/usr/include/architecture/i386/math.h" 3
extern "C" double jn(int, double);
# 522 "/usr/include/architecture/i386/math.h" 3
extern "C" double y0(double);
# 524 "/usr/include/architecture/i386/math.h" 3
extern "C" double y1(double);
# 526 "/usr/include/architecture/i386/math.h" 3
extern "C" double yn(int, double);
# 528 "/usr/include/architecture/i386/math.h" 3
extern "C" double scalb(double, double);
# 546 "/usr/include/architecture/i386/math.h" 3
extern "C" { extern int signgam; }
# 560 "/usr/include/architecture/i386/math.h" 3
extern "C" long rinttol(double);
# 562 "/usr/include/architecture/i386/math.h" 3
extern "C" long roundtol(double);
# 600 "/usr/include/architecture/i386/math.h" 3
extern "C" int finite(double);
# 602 "/usr/include/architecture/i386/math.h" 3
extern "C" double gamma(double);
# 613 "/usr/include/architecture/i386/math.h" 3
extern "C" double significand(double);
# 618 "/usr/include/architecture/i386/math.h" 3
extern "C" double drem(double, double);
# 83 "/usr/include/sys/wait.h" 3
typedef
# 79 "/usr/include/sys/wait.h" 3
enum {
# 80 "/usr/include/sys/wait.h" 3
P_ALL,
# 81 "/usr/include/sys/wait.h" 3
P_PID,
# 82 "/usr/include/sys/wait.h" 3
P_PGID
# 83 "/usr/include/sys/wait.h" 3
} idtype_t;
# 90 "/usr/include/sys/wait.h" 3
typedef __darwin_pid_t pid_t;
# 95 "/usr/include/sys/wait.h" 3
typedef __darwin_id_t id_t;
# 39 "/usr/include/i386/signal.h" 3
typedef int sig_atomic_t;
# 43 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_i386_thread_state {
# 45 "/usr/include/mach/i386/_structs.h" 3
unsigned __eax;
# 46 "/usr/include/mach/i386/_structs.h" 3
unsigned __ebx;
# 47 "/usr/include/mach/i386/_structs.h" 3
unsigned __ecx;
# 48 "/usr/include/mach/i386/_structs.h" 3
unsigned __edx;
# 49 "/usr/include/mach/i386/_structs.h" 3
unsigned __edi;
# 50 "/usr/include/mach/i386/_structs.h" 3
unsigned __esi;
# 51 "/usr/include/mach/i386/_structs.h" 3
unsigned __ebp;
# 52 "/usr/include/mach/i386/_structs.h" 3
unsigned __esp;
# 53 "/usr/include/mach/i386/_structs.h" 3
unsigned __ss;
# 54 "/usr/include/mach/i386/_structs.h" 3
unsigned __eflags;
# 55 "/usr/include/mach/i386/_structs.h" 3
unsigned __eip;
# 56 "/usr/include/mach/i386/_structs.h" 3
unsigned __cs;
# 57 "/usr/include/mach/i386/_structs.h" 3
unsigned __ds;
# 58 "/usr/include/mach/i386/_structs.h" 3
unsigned __es;
# 59 "/usr/include/mach/i386/_structs.h" 3
unsigned __fs;
# 60 "/usr/include/mach/i386/_structs.h" 3
unsigned __gs;
# 61 "/usr/include/mach/i386/_structs.h" 3
};
# 89 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_fp_control {
# 91 "/usr/include/mach/i386/_structs.h" 3
unsigned short __invalid:1,
# 92 "/usr/include/mach/i386/_structs.h" 3
__denorm:1,
# 93 "/usr/include/mach/i386/_structs.h" 3
__zdiv:1,
# 94 "/usr/include/mach/i386/_structs.h" 3
__ovrfl:1,
# 95 "/usr/include/mach/i386/_structs.h" 3
__undfl:1,
# 96 "/usr/include/mach/i386/_structs.h" 3
__precis:1;
# 97 "/usr/include/mach/i386/_structs.h" 3
unsigned short:2,
# 98 "/usr/include/mach/i386/_structs.h" 3
__pc:2,
# 104 "/usr/include/mach/i386/_structs.h" 3
__rc:2;
# 111 "/usr/include/mach/i386/_structs.h" 3
unsigned short:1;
# 112 "/usr/include/mach/i386/_structs.h" 3
unsigned short:3;
# 113 "/usr/include/mach/i386/_structs.h" 3
};
# 114 "/usr/include/mach/i386/_structs.h" 3
typedef __darwin_fp_control __darwin_fp_control_t;
# 147 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_fp_status {
# 149 "/usr/include/mach/i386/_structs.h" 3
unsigned short __invalid:1,
# 150 "/usr/include/mach/i386/_structs.h" 3
__denorm:1,
# 151 "/usr/include/mach/i386/_structs.h" 3
__zdiv:1,
# 152 "/usr/include/mach/i386/_structs.h" 3
__ovrfl:1,
# 153 "/usr/include/mach/i386/_structs.h" 3
__undfl:1,
# 154 "/usr/include/mach/i386/_structs.h" 3
__precis:1,
# 155 "/usr/include/mach/i386/_structs.h" 3
__stkflt:1,
# 156 "/usr/include/mach/i386/_structs.h" 3
__errsumm:1,
# 157 "/usr/include/mach/i386/_structs.h" 3
__c0:1,
# 158 "/usr/include/mach/i386/_structs.h" 3
__c1:1,
# 159 "/usr/include/mach/i386/_structs.h" 3
__c2:1,
# 160 "/usr/include/mach/i386/_structs.h" 3
__tos:3,
# 161 "/usr/include/mach/i386/_structs.h" 3
__c3:1,
# 162 "/usr/include/mach/i386/_structs.h" 3
__busy:1;
# 163 "/usr/include/mach/i386/_structs.h" 3
};
# 164 "/usr/include/mach/i386/_structs.h" 3
typedef __darwin_fp_status __darwin_fp_status_t;
# 191 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_mmst_reg {
# 193 "/usr/include/mach/i386/_structs.h" 3
char __mmst_reg[10];
# 194 "/usr/include/mach/i386/_structs.h" 3
char __mmst_rsrv[6];
# 195 "/usr/include/mach/i386/_structs.h" 3
};
# 210 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_xmm_reg {
# 212 "/usr/include/mach/i386/_structs.h" 3
char __xmm_reg[16];
# 213 "/usr/include/mach/i386/_structs.h" 3
};
# 232 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_i386_float_state {
# 234 "/usr/include/mach/i386/_structs.h" 3
int __fpu_reserved[2];
# 235 "/usr/include/mach/i386/_structs.h" 3
__darwin_fp_control __fpu_fcw;
# 236 "/usr/include/mach/i386/_structs.h" 3
__darwin_fp_status __fpu_fsw;
# 237 "/usr/include/mach/i386/_structs.h" 3
__uint8_t __fpu_ftw;
# 238 "/usr/include/mach/i386/_structs.h" 3
__uint8_t __fpu_rsrv1;
# 239 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_fop;
# 240 "/usr/include/mach/i386/_structs.h" 3
__uint32_t __fpu_ip;
# 241 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_cs;
# 242 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_rsrv2;
# 243 "/usr/include/mach/i386/_structs.h" 3
__uint32_t __fpu_dp;
# 244 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_ds;
# 245 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_rsrv3;
# 246 "/usr/include/mach/i386/_structs.h" 3
__uint32_t __fpu_mxcsr;
# 247 "/usr/include/mach/i386/_structs.h" 3
__uint32_t __fpu_mxcsrmask;
# 248 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm0;
# 249 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm1;
# 250 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm2;
# 251 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm3;
# 252 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm4;
# 253 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm5;
# 254 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm6;
# 255 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm7;
# 256 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm0;
# 257 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm1;
# 258 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm2;
# 259 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm3;
# 260 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm4;
# 261 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm5;
# 262 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm6;
# 263 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm7;
# 264 "/usr/include/mach/i386/_structs.h" 3
char __fpu_rsrv4[(14 * 16)];
# 265 "/usr/include/mach/i386/_structs.h" 3
int __fpu_reserved1;
# 266 "/usr/include/mach/i386/_structs.h" 3
};
# 308 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_i386_exception_state {
# 310 "/usr/include/mach/i386/_structs.h" 3
unsigned __trapno;
# 311 "/usr/include/mach/i386/_structs.h" 3
unsigned __err;
# 312 "/usr/include/mach/i386/_structs.h" 3
unsigned __faultvaddr;
# 313 "/usr/include/mach/i386/_structs.h" 3
};
# 326 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_x86_debug_state32 {
# 328 "/usr/include/mach/i386/_structs.h" 3
unsigned __dr0;
# 329 "/usr/include/mach/i386/_structs.h" 3
unsigned __dr1;
# 330 "/usr/include/mach/i386/_structs.h" 3
unsigned __dr2;
# 331 "/usr/include/mach/i386/_structs.h" 3
unsigned __dr3;
# 332 "/usr/include/mach/i386/_structs.h" 3
unsigned __dr4;
# 333 "/usr/include/mach/i386/_structs.h" 3
unsigned __dr5;
# 334 "/usr/include/mach/i386/_structs.h" 3
unsigned __dr6;
# 335 "/usr/include/mach/i386/_structs.h" 3
unsigned __dr7;
# 336 "/usr/include/mach/i386/_structs.h" 3
};
# 358 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_x86_thread_state64 {
# 360 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rax;
# 361 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rbx;
# 362 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rcx;
# 363 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rdx;
# 364 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rdi;
# 365 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rsi;
# 366 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rbp;
# 367 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rsp;
# 368 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __r8;
# 369 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __r9;
# 370 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __r10;
# 371 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __r11;
# 372 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __r12;
# 373 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __r13;
# 374 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __r14;
# 375 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __r15;
# 376 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rip;
# 377 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __rflags;
# 378 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __cs;
# 379 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __fs;
# 380 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __gs;
# 381 "/usr/include/mach/i386/_structs.h" 3
};
# 413 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_x86_float_state64 {
# 415 "/usr/include/mach/i386/_structs.h" 3
int __fpu_reserved[2];
# 416 "/usr/include/mach/i386/_structs.h" 3
__darwin_fp_control __fpu_fcw;
# 417 "/usr/include/mach/i386/_structs.h" 3
__darwin_fp_status __fpu_fsw;
# 418 "/usr/include/mach/i386/_structs.h" 3
__uint8_t __fpu_ftw;
# 419 "/usr/include/mach/i386/_structs.h" 3
__uint8_t __fpu_rsrv1;
# 420 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_fop;
# 423 "/usr/include/mach/i386/_structs.h" 3
__uint32_t __fpu_ip;
# 424 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_cs;
# 426 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_rsrv2;
# 429 "/usr/include/mach/i386/_structs.h" 3
__uint32_t __fpu_dp;
# 430 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_ds;
# 432 "/usr/include/mach/i386/_structs.h" 3
__uint16_t __fpu_rsrv3;
# 433 "/usr/include/mach/i386/_structs.h" 3
__uint32_t __fpu_mxcsr;
# 434 "/usr/include/mach/i386/_structs.h" 3
__uint32_t __fpu_mxcsrmask;
# 435 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm0;
# 436 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm1;
# 437 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm2;
# 438 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm3;
# 439 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm4;
# 440 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm5;
# 441 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm6;
# 442 "/usr/include/mach/i386/_structs.h" 3
__darwin_mmst_reg __fpu_stmm7;
# 443 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm0;
# 444 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm1;
# 445 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm2;
# 446 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm3;
# 447 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm4;
# 448 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm5;
# 449 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm6;
# 450 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm7;
# 451 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm8;
# 452 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm9;
# 453 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm10;
# 454 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm11;
# 455 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm12;
# 456 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm13;
# 457 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm14;
# 458 "/usr/include/mach/i386/_structs.h" 3
__darwin_xmm_reg __fpu_xmm15;
# 459 "/usr/include/mach/i386/_structs.h" 3
char __fpu_rsrv4[(6 * 16)];
# 460 "/usr/include/mach/i386/_structs.h" 3
int __fpu_reserved1;
# 461 "/usr/include/mach/i386/_structs.h" 3
};
# 517 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_x86_exception_state64 {
# 519 "/usr/include/mach/i386/_structs.h" 3
unsigned __trapno;
# 520 "/usr/include/mach/i386/_structs.h" 3
unsigned __err;
# 521 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __faultvaddr;
# 522 "/usr/include/mach/i386/_structs.h" 3
};
# 535 "/usr/include/mach/i386/_structs.h" 3
struct __darwin_x86_debug_state64 {
# 537 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __dr0;
# 538 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __dr1;
# 539 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __dr2;
# 540 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __dr3;
# 541 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __dr4;
# 542 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __dr5;
# 543 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __dr6;
# 544 "/usr/include/mach/i386/_structs.h" 3
__uint64_t __dr7;
# 545 "/usr/include/mach/i386/_structs.h" 3
};
# 48 "/usr/include/i386/_structs.h" 3
struct __darwin_mcontext32 {
# 50 "/usr/include/i386/_structs.h" 3
__darwin_i386_exception_state __es;
# 51 "/usr/include/i386/_structs.h" 3
__darwin_i386_thread_state __ss;
# 52 "/usr/include/i386/_structs.h" 3
__darwin_i386_float_state __fs;
# 53 "/usr/include/i386/_structs.h" 3
};
# 68 "/usr/include/i386/_structs.h" 3
struct __darwin_mcontext64 {
# 70 "/usr/include/i386/_structs.h" 3
__darwin_x86_exception_state64 __es;
# 71 "/usr/include/i386/_structs.h" 3
__darwin_x86_thread_state64 __ss;
# 72 "/usr/include/i386/_structs.h" 3
__darwin_x86_float_state64 __fs;
# 73 "/usr/include/i386/_structs.h" 3
};
# 94 "/usr/include/i386/_structs.h" 3
typedef __darwin_mcontext32 *mcontext_t;
# 75 "/usr/include/sys/_structs.h" 3
struct __darwin_sigaltstack {
# 77 "/usr/include/sys/_structs.h" 3
void *ss_sp;
# 78 "/usr/include/sys/_structs.h" 3
__darwin_size_t ss_size;
# 79 "/usr/include/sys/_structs.h" 3
int ss_flags;
# 80 "/usr/include/sys/_structs.h" 3
};
# 128 "/usr/include/sys/_structs.h" 3
struct __darwin_ucontext {
# 130 "/usr/include/sys/_structs.h" 3
int uc_onstack;
# 131 "/usr/include/sys/_structs.h" 3
__darwin_sigset_t uc_sigmask;
# 132 "/usr/include/sys/_structs.h" 3
__darwin_sigaltstack uc_stack;
# 133 "/usr/include/sys/_structs.h" 3
__darwin_ucontext *uc_link;
# 134 "/usr/include/sys/_structs.h" 3
__darwin_size_t uc_mcsize;
# 135 "/usr/include/sys/_structs.h" 3
__darwin_mcontext32 *uc_mcontext;
# 139 "/usr/include/sys/_structs.h" 3
};
# 218 "/usr/include/sys/_structs.h" 3
typedef __darwin_sigaltstack stack_t;
# 227 "/usr/include/sys/_structs.h" 3
typedef __darwin_ucontext ucontext_t;
# 163 "/usr/include/sys/signal.h" 3
typedef __darwin_pthread_attr_t pthread_attr_t;
# 168 "/usr/include/sys/signal.h" 3
typedef __darwin_sigset_t sigset_t;
# 178 "/usr/include/sys/signal.h" 3
typedef __darwin_uid_t uid_t;
# 181 "/usr/include/sys/signal.h" 3
union sigval {
# 183 "/usr/include/sys/signal.h" 3
int sival_int;
# 184 "/usr/include/sys/signal.h" 3
void *sival_ptr;
# 185 "/usr/include/sys/signal.h" 3
};
# 191 "/usr/include/sys/signal.h" 3
struct sigevent {
# 192 "/usr/include/sys/signal.h" 3
int sigev_notify;
# 193 "/usr/include/sys/signal.h" 3
int sigev_signo;
# 194 "/usr/include/sys/signal.h" 3
sigval sigev_value;
# 195 "/usr/include/sys/signal.h" 3
void (*sigev_notify_function)(sigval);
# 196 "/usr/include/sys/signal.h" 3
pthread_attr_t *sigev_notify_attributes;
# 197 "/usr/include/sys/signal.h" 3
};
# 211 "/usr/include/sys/signal.h" 3
typedef
# 200 "/usr/include/sys/signal.h" 3
struct __siginfo {
# 201 "/usr/include/sys/signal.h" 3
int si_signo;
# 202 "/usr/include/sys/signal.h" 3
int si_errno;
# 203 "/usr/include/sys/signal.h" 3
int si_code;
# 204 "/usr/include/sys/signal.h" 3
pid_t si_pid;
# 205 "/usr/include/sys/signal.h" 3
uid_t si_uid;
# 206 "/usr/include/sys/signal.h" 3
int si_status;
# 207 "/usr/include/sys/signal.h" 3
void *si_addr;
# 208 "/usr/include/sys/signal.h" 3
sigval si_value;
# 209 "/usr/include/sys/signal.h" 3
long si_band;
# 210 "/usr/include/sys/signal.h" 3
unsigned long __pad[7];
# 211 "/usr/include/sys/signal.h" 3
} siginfo_t;
# 292 "/usr/include/sys/signal.h" 3
union __sigaction_u {
# 293 "/usr/include/sys/signal.h" 3
void (*__sa_handler)(int);
# 294 "/usr/include/sys/signal.h" 3
void (*__sa_sigaction)(int, __siginfo *, void *);
# 296 "/usr/include/sys/signal.h" 3
};
# 299 "/usr/include/sys/signal.h" 3
struct __sigaction {
# 300 "/usr/include/sys/signal.h" 3
::__sigaction_u __sigaction_u;
# 301 "/usr/include/sys/signal.h" 3
void (*sa_tramp)(void *, int, int, siginfo_t *, void *);
# 302 "/usr/include/sys/signal.h" 3
sigset_t sa_mask;
# 303 "/usr/include/sys/signal.h" 3
int sa_flags;
# 304 "/usr/include/sys/signal.h" 3
};
# 309 "/usr/include/sys/signal.h" 3
struct sigaction {
# 310 "/usr/include/sys/signal.h" 3
::__sigaction_u __sigaction_u;
# 311 "/usr/include/sys/signal.h" 3
sigset_t sa_mask;
# 312 "/usr/include/sys/signal.h" 3
int sa_flags;
# 313 "/usr/include/sys/signal.h" 3
};
# 354 "/usr/include/sys/signal.h" 3
typedef void (*sig_t)(int);
# 371 "/usr/include/sys/signal.h" 3
struct sigvec {
# 372 "/usr/include/sys/signal.h" 3
void (*sv_handler)(int);
# 373 "/usr/include/sys/signal.h" 3
int sv_mask;
# 374 "/usr/include/sys/signal.h" 3
int sv_flags;
# 375 "/usr/include/sys/signal.h" 3
};
# 390 "/usr/include/sys/signal.h" 3
struct sigstack {
# 391 "/usr/include/sys/signal.h" 3
char *ss_sp;
# 392 "/usr/include/sys/signal.h" 3
int ss_onstack;
# 393 "/usr/include/sys/signal.h" 3
};
# 413 "/usr/include/sys/signal.h" 3
extern "C" void (*signal(int, void (*)(int)))(int);
# 100 "/usr/include/sys/_structs.h" 3
struct timeval {
# 102 "/usr/include/sys/_structs.h" 3
__darwin_time_t tv_sec;
# 103 "/usr/include/sys/_structs.h" 3
__darwin_suseconds_t tv_usec;
# 104 "/usr/include/sys/_structs.h" 3
};
# 88 "/usr/include/sys/resource.h" 3
typedef __uint64_t rlim_t;
# 144 "/usr/include/sys/resource.h" 3
struct rusage {
# 145 "/usr/include/sys/resource.h" 3
timeval ru_utime;
# 146 "/usr/include/sys/resource.h" 3
timeval ru_stime;
# 155 "/usr/include/sys/resource.h" 3
long ru_maxrss;
# 157 "/usr/include/sys/resource.h" 3
long ru_ixrss;
# 158 "/usr/include/sys/resource.h" 3
long ru_idrss;
# 159 "/usr/include/sys/resource.h" 3
long ru_isrss;
# 160 "/usr/include/sys/resource.h" 3
long ru_minflt;
# 161 "/usr/include/sys/resource.h" 3
long ru_majflt;
# 162 "/usr/include/sys/resource.h" 3
long ru_nswap;
# 163 "/usr/include/sys/resource.h" 3
long ru_inblock;
# 164 "/usr/include/sys/resource.h" 3
long ru_oublock;
# 165 "/usr/include/sys/resource.h" 3
long ru_msgsnd;
# 166 "/usr/include/sys/resource.h" 3
long ru_msgrcv;
# 167 "/usr/include/sys/resource.h" 3
long ru_nsignals;
# 168 "/usr/include/sys/resource.h" 3
long ru_nvcsw;
# 169 "/usr/include/sys/resource.h" 3
long ru_nivcsw;
# 172 "/usr/include/sys/resource.h" 3
};
# 215 "/usr/include/sys/resource.h" 3
struct rlimit {
# 216 "/usr/include/sys/resource.h" 3
rlim_t rlim_cur;
# 217 "/usr/include/sys/resource.h" 3
rlim_t rlim_max;
# 218 "/usr/include/sys/resource.h" 3
};
# 238 "/usr/include/sys/resource.h" 3
extern "C" int getpriority(int, id_t);
# 240 "/usr/include/sys/resource.h" 3
extern "C" int getiopolicy_np(int, int);
# 242 "/usr/include/sys/resource.h" 3
extern "C" int getrlimit(int, rlimit *) __asm__("_getrlimit$UNIX2003");
# 243 "/usr/include/sys/resource.h" 3
extern "C" int getrusage(int, rusage *);
# 244 "/usr/include/sys/resource.h" 3
extern "C" int setpriority(int, id_t, int);
# 246 "/usr/include/sys/resource.h" 3
extern "C" int setiopolicy_np(int, int, int);
# 248 "/usr/include/sys/resource.h" 3
extern "C" int setrlimit(int, const rlimit *) __asm__("_setrlimit$UNIX2003");
# 46 "/usr/include/libkern/i386/_OSByteOrder.h" 3
static inline __uint16_t _OSSwapInt16(__uint16_t
# 47 "/usr/include/libkern/i386/_OSByteOrder.h" 3
_data)
# 49 "/usr/include/libkern/i386/_OSByteOrder.h" 3
{
# 50 "/usr/include/libkern/i386/_OSByteOrder.h" 3
return (_data << 8) | (_data >> 8);
# 51 "/usr/include/libkern/i386/_OSByteOrder.h" 3
}
# 55 "/usr/include/libkern/i386/_OSByteOrder.h" 3
static inline __uint32_t _OSSwapInt32(__uint32_t
# 56 "/usr/include/libkern/i386/_OSByteOrder.h" 3
_data)
# 58 "/usr/include/libkern/i386/_OSByteOrder.h" 3
{
# 62 "/usr/include/libkern/i386/_OSByteOrder.h" 3
__asm__("bswap   %0" : "+r" (_data));
# 63 "/usr/include/libkern/i386/_OSByteOrder.h" 3
return _data;
# 65 "/usr/include/libkern/i386/_OSByteOrder.h" 3
}
# 80 "/usr/include/libkern/i386/_OSByteOrder.h" 3
static inline __uint64_t _OSSwapInt64(__uint64_t
# 81 "/usr/include/libkern/i386/_OSByteOrder.h" 3
_data)
# 83 "/usr/include/libkern/i386/_OSByteOrder.h" 3
{
# 84 "/usr/include/libkern/i386/_OSByteOrder.h" 3
__asm__("bswap   %%eax\n\tbswap   %%edx\n\txchgl   %%eax, %%edx" : "+A" (_data));
# 88 "/usr/include/libkern/i386/_OSByteOrder.h" 3
return _data;
# 89 "/usr/include/libkern/i386/_OSByteOrder.h" 3
}
# 201 "/usr/include/sys/wait.h" 3
union wait {
# 202 "/usr/include/sys/wait.h" 3
int w_status;
# 206 "/usr/include/sys/wait.h" 3
struct {
# 208 "/usr/include/sys/wait.h" 3
unsigned w_Termsig:7,
# 209 "/usr/include/sys/wait.h" 3
w_Coredump:1,
# 210 "/usr/include/sys/wait.h" 3
w_Retcode:8,
# 211 "/usr/include/sys/wait.h" 3
w_Filler:16;
# 219 "/usr/include/sys/wait.h" 3
} w_T;
# 225 "/usr/include/sys/wait.h" 3
struct {
# 227 "/usr/include/sys/wait.h" 3
unsigned w_Stopval:8,
# 228 "/usr/include/sys/wait.h" 3
w_Stopsig:8,
# 229 "/usr/include/sys/wait.h" 3
w_Filler:16;
# 236 "/usr/include/sys/wait.h" 3
} w_S;
# 237 "/usr/include/sys/wait.h" 3
};
# 255 "/usr/include/sys/wait.h" 3
extern "C" pid_t wait(int *) __asm__("_wait$UNIX2003");
# 256 "/usr/include/sys/wait.h" 3
extern "C" pid_t waitpid(pid_t, int *, int) __asm__("_waitpid$UNIX2003");
# 258 "/usr/include/sys/wait.h" 3
extern "C" int waitid(idtype_t, id_t, siginfo_t *, int) __asm__("_waitid$UNIX2003");
# 261 "/usr/include/sys/wait.h" 3
extern "C" pid_t wait3(int *, int, rusage *);
# 262 "/usr/include/sys/wait.h" 3
extern "C" pid_t wait4(pid_t, int *, int, rusage *);
# 36 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t);
# 81 "/usr/include/stdlib.h" 3
typedef __darwin_ct_rune_t ct_rune_t;
# 86 "/usr/include/stdlib.h" 3
typedef __darwin_rune_t rune_t;
# 100 "/usr/include/stdlib.h" 3
typedef
# 97 "/usr/include/stdlib.h" 3
struct {
# 98 "/usr/include/stdlib.h" 3
int quot;
# 99 "/usr/include/stdlib.h" 3
int rem;
# 100 "/usr/include/stdlib.h" 3
} div_t;
# 105 "/usr/include/stdlib.h" 3
typedef
# 102 "/usr/include/stdlib.h" 3
struct {
# 103 "/usr/include/stdlib.h" 3
long quot;
# 104 "/usr/include/stdlib.h" 3
long rem;
# 105 "/usr/include/stdlib.h" 3
} ldiv_t;
# 111 "/usr/include/stdlib.h" 3
typedef
# 108 "/usr/include/stdlib.h" 3
struct {
# 109 "/usr/include/stdlib.h" 3
long long quot;
# 110 "/usr/include/stdlib.h" 3
long long rem;
# 111 "/usr/include/stdlib.h" 3
} lldiv_t;
# 134 "/usr/include/stdlib.h" 3
extern int __mb_cur_max;
# 145 "/usr/include/stdlib.h" 3
extern "C" void abort() __attribute__((__noreturn__));
# 146 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) int abs(int) __attribute__((__const__));
# 147 "/usr/include/stdlib.h" 3
extern "C" int atexit(void (*)(void));
# 148 "/usr/include/stdlib.h" 3
extern "C" double atof(const char *);
# 149 "/usr/include/stdlib.h" 3
extern "C" int atoi(const char *);
# 150 "/usr/include/stdlib.h" 3
extern "C" long atol(const char *);
# 153 "/usr/include/stdlib.h" 3
extern "C" long long atoll(const char *);
# 155 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
# 157 "/usr/include/stdlib.h" 3
extern "C" void *calloc(size_t, size_t);
# 158 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) __attribute__((__const__));
# 159 "/usr/include/stdlib.h" 3
extern "C" void exit(int) __attribute__((__noreturn__));
# 160 "/usr/include/stdlib.h" 3
extern "C" void free(void *);
# 161 "/usr/include/stdlib.h" 3
extern "C" char *getenv(const char *);
# 162 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) long labs(long) __attribute__((__const__));
# 163 "/usr/include/stdlib.h" 3
extern "C" ldiv_t ldiv(long, long) __attribute__((__const__));
# 166 "/usr/include/stdlib.h" 3
extern "C" __attribute__((weak)) long long llabs(long long);
# 167 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long, long long);
# 169 "/usr/include/stdlib.h" 3
extern "C" void *malloc(size_t);
# 170 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t);
# 171 "/usr/include/stdlib.h" 3
extern "C" size_t mbstowcs(wchar_t *, const char *, size_t);
# 172 "/usr/include/stdlib.h" 3
extern "C" int mbtowc(wchar_t *, const char *, size_t);
# 173 "/usr/include/stdlib.h" 3
extern "C" int posix_memalign(void **, size_t, size_t);
# 174 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
# 176 "/usr/include/stdlib.h" 3
extern "C" int rand();
# 177 "/usr/include/stdlib.h" 3
extern "C" void *realloc(void *, size_t);
# 178 "/usr/include/stdlib.h" 3
extern "C" void srand(unsigned);
# 179 "/usr/include/stdlib.h" 3
extern "C" double strtod(const char *, char **) __asm__("_strtod$UNIX2003");
# 180 "/usr/include/stdlib.h" 3
extern "C" float strtof(const char *, char **) __asm__("_strtof$UNIX2003");
# 181 "/usr/include/stdlib.h" 3
extern "C" long strtol(const char *, char **, int);
# 183 "/usr/include/stdlib.h" 3
extern "C" long double strtold(const char *, char **);
# 186 "/usr/include/stdlib.h" 3
extern "C" long long strtoll(const char *, char **, int);
# 189 "/usr/include/stdlib.h" 3
extern "C" unsigned long strtoul(const char *, char **, int);
# 192 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull(const char *, char **, int);
# 194 "/usr/include/stdlib.h" 3
extern "C" int system(const char *) __asm__("_system$UNIX2003");
# 195 "/usr/include/stdlib.h" 3
extern "C" size_t wcstombs(char *, const wchar_t *, size_t);
# 196 "/usr/include/stdlib.h" 3
extern "C" int wctomb(char *, wchar_t);
# 199 "/usr/include/stdlib.h" 3
extern "C" void _Exit(int) __attribute__((__noreturn__));
# 200 "/usr/include/stdlib.h" 3
extern "C" long a64l(const char *);
# 201 "/usr/include/stdlib.h" 3
extern "C" double drand48();
# 202 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double, int, int *, int *);
# 203 "/usr/include/stdlib.h" 3
extern "C" double erand48(unsigned short [3]);
# 204 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double, int, int *, int *);
# 205 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double, int, char *);
# 206 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **, char *const *, char **);
# 207 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int);
# 209 "/usr/include/stdlib.h" 3
extern "C" char *initstate(unsigned, char *, size_t);
# 213 "/usr/include/stdlib.h" 3
extern "C" long jrand48(unsigned short [3]);
# 214 "/usr/include/stdlib.h" 3
extern "C" char *l64a(long);
# 215 "/usr/include/stdlib.h" 3
extern "C" void lcong48(unsigned short [7]);
# 216 "/usr/include/stdlib.h" 3
extern "C" long lrand48();
# 217 "/usr/include/stdlib.h" 3
extern "C" char *mktemp(char *);
# 218 "/usr/include/stdlib.h" 3
extern "C" int mkstemp(char *);
# 219 "/usr/include/stdlib.h" 3
extern "C" long mrand48();
# 220 "/usr/include/stdlib.h" 3
extern "C" long nrand48(unsigned short [3]);
# 221 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int);
# 222 "/usr/include/stdlib.h" 3
extern "C" char *ptsname(int);
# 223 "/usr/include/stdlib.h" 3
extern "C" int putenv(char *) __asm__("_putenv$UNIX2003");
# 224 "/usr/include/stdlib.h" 3
extern "C" long random();
# 225 "/usr/include/stdlib.h" 3
extern "C" int rand_r(unsigned *);
# 227 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *, char *) __asm__("_realpath$DARWIN_EXTSN");
# 232 "/usr/include/stdlib.h" 3
extern "C" unsigned short *seed48(unsigned short [3]);
# 233 "/usr/include/stdlib.h" 3
extern "C" int setenv(const char *, const char *, int) __asm__("_setenv$UNIX2003");
# 235 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char *) __asm__("_setkey$UNIX2003");
# 239 "/usr/include/stdlib.h" 3
extern "C" char *setstate(const char *);
# 240 "/usr/include/stdlib.h" 3
extern "C" void srand48(long);
# 242 "/usr/include/stdlib.h" 3
extern "C" void srandom(unsigned);
# 246 "/usr/include/stdlib.h" 3
extern "C" int unlockpt(int);
# 248 "/usr/include/stdlib.h" 3
extern "C" int unsetenv(const char *) __asm__("_unsetenv$UNIX2003");
# 78 "/usr/include/i386/types.h" 3
extern "C" { typedef signed char int8_t; }
# 80 "/usr/include/i386/types.h" 3
extern "C" { typedef unsigned char u_int8_t; }
# 83 "/usr/include/i386/types.h" 3
extern "C" { typedef short int16_t; }
# 85 "/usr/include/i386/types.h" 3
extern "C" { typedef unsigned short u_int16_t; }
# 88 "/usr/include/i386/types.h" 3
extern "C" { typedef int int32_t; }
# 90 "/usr/include/i386/types.h" 3
extern "C" { typedef unsigned u_int32_t; }
# 93 "/usr/include/i386/types.h" 3
extern "C" { typedef long long int64_t; }
# 95 "/usr/include/i386/types.h" 3
extern "C" { typedef unsigned long long u_int64_t; }
# 100 "/usr/include/i386/types.h" 3
extern "C" { typedef int32_t register_t; }
# 105 "/usr/include/i386/types.h" 3
extern "C" { typedef __darwin_intptr_t intptr_t; }
# 109 "/usr/include/i386/types.h" 3
extern "C" { typedef unsigned long uintptr_t; }
# 114 "/usr/include/i386/types.h" 3
extern "C" { typedef u_int64_t user_addr_t; }
# 115 "/usr/include/i386/types.h" 3
extern "C" { typedef u_int64_t user_size_t; }
# 116 "/usr/include/i386/types.h" 3
extern "C" { typedef int64_t user_ssize_t; }
# 117 "/usr/include/i386/types.h" 3
extern "C" { typedef int64_t user_long_t; }
# 118 "/usr/include/i386/types.h" 3
extern "C" { typedef u_int64_t user_ulong_t; }
# 119 "/usr/include/i386/types.h" 3
extern "C" { typedef int64_t user_time_t; }
# 120 "/usr/include/i386/types.h" 3
extern "C" { typedef int64_t user_off_t; }
# 128 "/usr/include/i386/types.h" 3
extern "C" { typedef u_int64_t syscall_arg_t; }
# 258 "/usr/include/stdlib.h" 3
extern "C" { typedef __darwin_dev_t dev_t; }
# 263 "/usr/include/stdlib.h" 3
extern "C" { typedef __darwin_mode_t mode_t; }
# 268 "/usr/include/stdlib.h" 3
extern "C" u_int32_t arc4random();
# 269 "/usr/include/stdlib.h" 3
extern "C" void arc4random_addrandom(unsigned char *, int);
# 270 "/usr/include/stdlib.h" 3
extern "C" void arc4random_stir();
# 278 "/usr/include/stdlib.h" 3
extern "C" char *cgetcap(char *, const char *, int);
# 279 "/usr/include/stdlib.h" 3
extern "C" int cgetclose();
# 280 "/usr/include/stdlib.h" 3
extern "C" int cgetent(char **, char **, const char *);
# 281 "/usr/include/stdlib.h" 3
extern "C" int cgetfirst(char **, char **);
# 282 "/usr/include/stdlib.h" 3
extern "C" int cgetmatch(const char *, const char *);
# 283 "/usr/include/stdlib.h" 3
extern "C" int cgetnext(char **, char **);
# 284 "/usr/include/stdlib.h" 3
extern "C" int cgetnum(char *, const char *, long *);
# 285 "/usr/include/stdlib.h" 3
extern "C" int cgetset(const char *);
# 286 "/usr/include/stdlib.h" 3
extern "C" int cgetstr(char *, const char *, char **);
# 287 "/usr/include/stdlib.h" 3
extern "C" int cgetustr(char *, const char *, char **);
# 289 "/usr/include/stdlib.h" 3
extern "C" int daemon(int, int) __asm__("_daemon$1050") __attribute__((__deprecated__)) __attribute__((visibility("default")));
# 290 "/usr/include/stdlib.h" 3
extern "C" char *devname(dev_t, mode_t);
# 291 "/usr/include/stdlib.h" 3
extern "C" char *devname_r(dev_t, mode_t, char *, int);
# 292 "/usr/include/stdlib.h" 3
extern "C" char *getbsize(int *, long *);
# 293 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int);
# 295 "/usr/include/stdlib.h" 3
extern "C" const char *getprogname();
# 297 "/usr/include/stdlib.h" 3
extern "C" int heapsort(void *, size_t, size_t, int (*)(const void *, const void *));
# 303 "/usr/include/stdlib.h" 3
extern "C" int mergesort(void *, size_t, size_t, int (*)(const void *, const void *));
# 309 "/usr/include/stdlib.h" 3
extern "C" void psort(void *, size_t, size_t, int (*)(const void *, const void *));
# 315 "/usr/include/stdlib.h" 3
extern "C" void psort_r(void *, size_t, size_t, void *, int (*)(void *, const void *, const void *));
# 321 "/usr/include/stdlib.h" 3
extern "C" void qsort_r(void *, size_t, size_t, void *, int (*)(void *, const void *, const void *));
# 323 "/usr/include/stdlib.h" 3
extern "C" int radixsort(const unsigned char **, int, const unsigned char *, unsigned);
# 325 "/usr/include/stdlib.h" 3
extern "C" void setprogname(const char *);
# 326 "/usr/include/stdlib.h" 3
extern "C" int sradixsort(const unsigned char **, int, const unsigned char *, unsigned);
# 328 "/usr/include/stdlib.h" 3
extern "C" void sranddev();
# 329 "/usr/include/stdlib.h" 3
extern "C" void srandomdev();
# 330 "/usr/include/stdlib.h" 3
extern "C" void *reallocf(void *, size_t);
# 333 "/usr/include/stdlib.h" 3
extern "C" long long strtoq(const char *, char **, int);
# 335 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtouq(const char *, char **, int);
# 337 "/usr/include/stdlib.h" 3
extern "C" { extern char *suboptarg; }
# 338 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t);
# 138 "/usr/include/sys/unistd.h" 3
struct accessx_descriptor {
# 139 "/usr/include/sys/unistd.h" 3
unsigned ad_name_offset;
# 140 "/usr/include/sys/unistd.h" 3
int ad_flags;
# 141 "/usr/include/sys/unistd.h" 3
int ad_pad[2];
# 142 "/usr/include/sys/unistd.h" 3
};
# 83 "/usr/include/unistd.h" 3
typedef __darwin_gid_t gid_t;
# 100 "/usr/include/unistd.h" 3
typedef __darwin_off_t off_t;
# 127 "/usr/include/unistd.h" 3
typedef __darwin_useconds_t useconds_t;
# 133 "/usr/include/unistd.h" 3
typedef __darwin_uuid_t uuid_t;
# 416 "/usr/include/unistd.h" 3
extern "C" void _exit(int) __attribute__((__noreturn__));
# 417 "/usr/include/unistd.h" 3
extern "C" int access(const char *, int);
# 419 "/usr/include/unistd.h" 3
extern "C" unsigned alarm(unsigned);
# 420 "/usr/include/unistd.h" 3
extern "C" int chdir(const char *);
# 421 "/usr/include/unistd.h" 3
extern "C" int chown(const char *, uid_t, gid_t);
# 422 "/usr/include/unistd.h" 3
extern "C" int close(int) __asm__("_close$UNIX2003");
# 423 "/usr/include/unistd.h" 3
extern "C" size_t confstr(int, char *, size_t) __asm__("_confstr$UNIX2003");
# 424 "/usr/include/unistd.h" 3
extern "C" char *crypt(const char *, const char *);
# 425 "/usr/include/unistd.h" 3
extern "C" char *ctermid(char *);
# 426 "/usr/include/unistd.h" 3
extern "C" int dup(int);
# 427 "/usr/include/unistd.h" 3
extern "C" int dup2(int, int);
# 429 "/usr/include/unistd.h" 3
extern "C" void encrypt(char *, int) __asm__("_encrypt$UNIX2003");
# 433 "/usr/include/unistd.h" 3
extern "C" int execl(const char *, const char *, ...);
# 434 "/usr/include/unistd.h" 3
extern "C" int execle(const char *, const char *, ...);
# 435 "/usr/include/unistd.h" 3
extern "C" int execlp(const char *, const char *, ...);
# 436 "/usr/include/unistd.h" 3
extern "C" int execv(const char *, char *const *);
# 437 "/usr/include/unistd.h" 3
extern "C" int execve(const char *, char *const *, char *const *);
# 438 "/usr/include/unistd.h" 3
extern "C" int execvp(const char *, char *const *);
# 439 "/usr/include/unistd.h" 3
extern "C" int fchown(int, uid_t, gid_t);
# 440 "/usr/include/unistd.h" 3
extern "C" int fchdir(int);
# 441 "/usr/include/unistd.h" 3
extern "C" pid_t fork();
# 442 "/usr/include/unistd.h" 3
extern "C" long fpathconf(int, int);
# 443 "/usr/include/unistd.h" 3
extern "C" int fsync(int) __asm__("_fsync$UNIX2003");
# 444 "/usr/include/unistd.h" 3
extern "C" int ftruncate(int, off_t);
# 445 "/usr/include/unistd.h" 3
extern "C" char *getcwd(char *, size_t);
# 446 "/usr/include/unistd.h" 3
extern "C" gid_t getegid();
# 447 "/usr/include/unistd.h" 3
extern "C" uid_t geteuid();
# 448 "/usr/include/unistd.h" 3
extern "C" gid_t getgid();
# 452 "/usr/include/unistd.h" 3
extern "C" int getgroups(int, gid_t []);
# 454 "/usr/include/unistd.h" 3
extern "C" long gethostid();
# 455 "/usr/include/unistd.h" 3
extern "C" int gethostname(char *, size_t);
# 456 "/usr/include/unistd.h" 3
extern "C" char *getlogin();
# 457 "/usr/include/unistd.h" 3
extern "C" int getlogin_r(char *, size_t);
# 458 "/usr/include/unistd.h" 3
extern "C" int getopt(int, char *const [], const char *) __asm__("_getopt$UNIX2003");
# 459 "/usr/include/unistd.h" 3
extern "C" pid_t getpgid(pid_t);
# 460 "/usr/include/unistd.h" 3
extern "C" pid_t getpgrp();
# 461 "/usr/include/unistd.h" 3
extern "C" pid_t getpid();
# 462 "/usr/include/unistd.h" 3
extern "C" pid_t getppid();
# 463 "/usr/include/unistd.h" 3
extern "C" pid_t getsid(pid_t);
# 464 "/usr/include/unistd.h" 3
extern "C" uid_t getuid();
# 465 "/usr/include/unistd.h" 3
extern "C" char *getwd(char *);
# 466 "/usr/include/unistd.h" 3
extern "C" int isatty(int);
# 467 "/usr/include/unistd.h" 3
extern "C" int lchown(const char *, uid_t, gid_t) __asm__("_lchown$UNIX2003");
# 468 "/usr/include/unistd.h" 3
extern "C" int link(const char *, const char *);
# 469 "/usr/include/unistd.h" 3
extern "C" int lockf(int, int, off_t) __asm__("_lockf$UNIX2003");
# 470 "/usr/include/unistd.h" 3
extern "C" off_t lseek(int, off_t, int);
# 471 "/usr/include/unistd.h" 3
extern "C" int nice(int) __asm__("_nice$UNIX2003");
# 472 "/usr/include/unistd.h" 3
extern "C" long pathconf(const char *, int);
# 473 "/usr/include/unistd.h" 3
extern "C" int pause() __asm__("_pause$UNIX2003");
# 474 "/usr/include/unistd.h" 3
extern "C" int pipe(int [2]);
# 475 "/usr/include/unistd.h" 3
extern "C" ssize_t pread(int, void *, size_t, off_t) __asm__("_pread$UNIX2003");
# 476 "/usr/include/unistd.h" 3
extern "C" ssize_t pwrite(int, const void *, size_t, off_t) __asm__("_pwrite$UNIX2003");
# 477 "/usr/include/unistd.h" 3
extern "C" ssize_t read(int, void *, size_t) __asm__("_read$UNIX2003");
# 478 "/usr/include/unistd.h" 3
extern "C" ssize_t readlink(const char *, char *, size_t);
# 479 "/usr/include/unistd.h" 3
extern "C" int rmdir(const char *);
# 480 "/usr/include/unistd.h" 3
extern "C" int setegid(gid_t);
# 481 "/usr/include/unistd.h" 3
extern "C" int seteuid(uid_t);
# 482 "/usr/include/unistd.h" 3
extern "C" int setgid(gid_t);
# 483 "/usr/include/unistd.h" 3
extern "C" int setpgid(pid_t, pid_t);
# 485 "/usr/include/unistd.h" 3
extern "C" pid_t setpgrp() __asm__("_setpgrp$UNIX2003");
# 489 "/usr/include/unistd.h" 3
extern "C" int setregid(gid_t, gid_t) __asm__("_setregid$UNIX2003");
# 490 "/usr/include/unistd.h" 3
extern "C" int setreuid(uid_t, uid_t) __asm__("_setreuid$UNIX2003");
# 491 "/usr/include/unistd.h" 3
extern "C" pid_t setsid();
# 492 "/usr/include/unistd.h" 3
extern "C" int setuid(uid_t);
# 494 "/usr/include/unistd.h" 3
extern "C" unsigned sleep(unsigned) __asm__("_sleep$UNIX2003");
# 495 "/usr/include/unistd.h" 3
extern "C" void swab(const void *, void *, ssize_t);
# 496 "/usr/include/unistd.h" 3
extern "C" int symlink(const char *, const char *);
# 497 "/usr/include/unistd.h" 3
extern "C" void sync();
# 498 "/usr/include/unistd.h" 3
extern "C" long sysconf(int);
# 499 "/usr/include/unistd.h" 3
extern "C" pid_t tcgetpgrp(int);
# 500 "/usr/include/unistd.h" 3
extern "C" int tcsetpgrp(int, pid_t);
# 501 "/usr/include/unistd.h" 3
extern "C" int truncate(const char *, off_t);
# 502 "/usr/include/unistd.h" 3
extern "C" char *ttyname(int);
# 504 "/usr/include/unistd.h" 3
extern "C" int ttyname_r(int, char *, size_t) __asm__("_ttyname_r$UNIX2003");
# 509 "/usr/include/unistd.h" 3
extern "C" useconds_t ualarm(useconds_t, useconds_t);
# 510 "/usr/include/unistd.h" 3
extern "C" int unlink(const char *);
# 511 "/usr/include/unistd.h" 3
extern "C" int usleep(useconds_t) __asm__("_usleep$UNIX2003");
# 512 "/usr/include/unistd.h" 3
extern "C" pid_t vfork();
# 513 "/usr/include/unistd.h" 3
extern "C" ssize_t write(int, const void *, size_t) __asm__("_write$UNIX2003");
# 515 "/usr/include/unistd.h" 3
extern "C" { extern char *optarg; }
# 516 "/usr/include/unistd.h" 3
extern "C" { extern int optind, opterr, optopt; }
# 186 "/usr/include/sys/_structs.h" 3
extern "C" { typedef
# 184 "/usr/include/sys/_structs.h" 3
struct fd_set {
# 185 "/usr/include/sys/_structs.h" 3
__int32_t fds_bits[((((1024) % (sizeof(__int32_t) * (8))) == (0)) ? ((1024) / (sizeof(__int32_t) * (8))) : (((1024) / (sizeof(__int32_t) * (8))) + (1)))];
# 186 "/usr/include/sys/_structs.h" 3
} fd_set; }
# 191 "/usr/include/sys/_structs.h" 3
extern "C" { static inline int __darwin_fd_isset(int _n, const fd_set *_p)
# 192 "/usr/include/sys/_structs.h" 3
{
# 193 "/usr/include/sys/_structs.h" 3
return ((_p->fds_bits)[_n / (sizeof(__int32_t) * (8))]) & (1 << (_n % (sizeof(__int32_t) * (8))));
# 194 "/usr/include/sys/_structs.h" 3
} }
# 92 "/usr/include/sys/select.h" 3
extern "C" { typedef __darwin_suseconds_t suseconds_t; }
# 137 "/usr/include/sys/select.h" 3
extern "C" int pselect(int, fd_set *, fd_set *, fd_set *, const timespec *, const sigset_t *) __asm__("_pselect$UNIX2003");
# 39 "/usr/include/sys/_select.h" 3
extern "C" int select(int, fd_set *, fd_set *, fd_set *, timeval *) __asm__("_select$UNIX2003");
# 521 "/usr/include/unistd.h" 3
extern "C" void _Exit(int) __attribute__((__noreturn__));
# 522 "/usr/include/unistd.h" 3
extern "C" int accessx_np(const accessx_descriptor *, size_t, int *, uid_t);
# 523 "/usr/include/unistd.h" 3
extern "C" int acct(const char *);
# 524 "/usr/include/unistd.h" 3
extern "C" int add_profil(char *, size_t, unsigned long, unsigned);
# 525 "/usr/include/unistd.h" 3
extern "C" void *brk(const void *);
# 526 "/usr/include/unistd.h" 3
extern "C" int chroot(const char *);
# 527 "/usr/include/unistd.h" 3
extern "C" void endusershell();
# 528 "/usr/include/unistd.h" 3
extern "C" int execvP(const char *, const char *, char *const *);
# 529 "/usr/include/unistd.h" 3
extern "C" char *fflagstostr(unsigned long);
# 530 "/usr/include/unistd.h" 3
extern "C" int getdtablesize();
# 531 "/usr/include/unistd.h" 3
extern "C" int getdomainname(char *, int);
# 532 "/usr/include/unistd.h" 3
extern "C" int getgrouplist(const char *, int, int *, int *);
# 533 "/usr/include/unistd.h" 3
extern "C" int gethostuuid(uuid_t, const timespec *);
# 534 "/usr/include/unistd.h" 3
extern "C" mode_t getmode(const void *, mode_t);
# 535 "/usr/include/unistd.h" 3
extern "C" int getpagesize() __attribute__((__const__));
# 536 "/usr/include/unistd.h" 3
extern "C" char *getpass(const char *);
# 537 "/usr/include/unistd.h" 3
extern "C" int getpeereid(int, uid_t *, gid_t *);
# 538 "/usr/include/unistd.h" 3
extern "C" int getpgid(pid_t);
# 539 "/usr/include/unistd.h" 3
extern "C" int getsgroups_np(int *, uuid_t);
# 540 "/usr/include/unistd.h" 3
extern "C" int getsid(pid_t);
# 541 "/usr/include/unistd.h" 3
extern "C" char *getusershell();
# 542 "/usr/include/unistd.h" 3
extern "C" int getwgroups_np(int *, uuid_t);
# 543 "/usr/include/unistd.h" 3
extern "C" int initgroups(const char *, int);
# 544 "/usr/include/unistd.h" 3
extern "C" int iruserok(unsigned long, int, const char *, const char *);
# 545 "/usr/include/unistd.h" 3
extern "C" int iruserok_sa(const void *, int, int, const char *, const char *);
# 546 "/usr/include/unistd.h" 3
extern "C" int issetugid();
# 547 "/usr/include/unistd.h" 3
extern "C" char *mkdtemp(char *);
# 548 "/usr/include/unistd.h" 3
extern "C" int mknod(const char *, mode_t, dev_t);
# 549 "/usr/include/unistd.h" 3
extern "C" int mkstemp(char *);
# 550 "/usr/include/unistd.h" 3
extern "C" int mkstemps(char *, int);
# 551 "/usr/include/unistd.h" 3
extern "C" char *mktemp(char *);
# 552 "/usr/include/unistd.h" 3
extern "C" int nfssvc(int, void *);
# 553 "/usr/include/unistd.h" 3
extern "C" int profil(char *, size_t, unsigned long, unsigned);
# 554 "/usr/include/unistd.h" 3
extern "C" int pthread_setugid_np(uid_t, gid_t);
# 555 "/usr/include/unistd.h" 3
extern "C" int pthread_getugid_np(uid_t *, gid_t *);
# 556 "/usr/include/unistd.h" 3
extern "C" int rcmd(char **, int, const char *, const char *, const char *, int *);
# 557 "/usr/include/unistd.h" 3
extern "C" int rcmd_af(char **, int, const char *, const char *, const char *, int *, int);
# 559 "/usr/include/unistd.h" 3
extern "C" int reboot(int);
# 560 "/usr/include/unistd.h" 3
extern "C" int revoke(const char *);
# 561 "/usr/include/unistd.h" 3
extern "C" int rresvport(int *);
# 562 "/usr/include/unistd.h" 3
extern "C" int rresvport_af(int *, int);
# 563 "/usr/include/unistd.h" 3
extern "C" int ruserok(const char *, int, const char *, const char *);
# 564 "/usr/include/unistd.h" 3
extern "C" void *sbrk(int);
# 565 "/usr/include/unistd.h" 3
extern "C" int setdomainname(const char *, int);
# 566 "/usr/include/unistd.h" 3
extern "C" int setgroups(int, const gid_t *);
# 567 "/usr/include/unistd.h" 3
extern "C" void sethostid(long);
# 568 "/usr/include/unistd.h" 3
extern "C" int sethostname(const char *, int);
# 570 "/usr/include/unistd.h" 3
extern "C" void setkey(const char *) __asm__("_setkey$UNIX2003");
# 574 "/usr/include/unistd.h" 3
extern "C" int setlogin(const char *);
# 575 "/usr/include/unistd.h" 3
extern "C" void *setmode(const char *) __asm__("_setmode$UNIX2003");
# 576 "/usr/include/unistd.h" 3
extern "C" int setrgid(gid_t);
# 577 "/usr/include/unistd.h" 3
extern "C" int setruid(uid_t);
# 578 "/usr/include/unistd.h" 3
extern "C" int setsgroups_np(int, const uuid_t);
# 579 "/usr/include/unistd.h" 3
extern "C" void setusershell();
# 580 "/usr/include/unistd.h" 3
extern "C" int setwgroups_np(int, const uuid_t);
# 581 "/usr/include/unistd.h" 3
extern "C" int strtofflags(char **, unsigned long *, unsigned long *);
# 582 "/usr/include/unistd.h" 3
extern "C" int swapon(const char *);
# 583 "/usr/include/unistd.h" 3
extern "C" int syscall(int, ...);
# 584 "/usr/include/unistd.h" 3
extern "C" int ttyslot();
# 585 "/usr/include/unistd.h" 3
extern "C" int undelete(const char *);
# 586 "/usr/include/unistd.h" 3
extern "C" int unwhiteout(const char *);
# 587 "/usr/include/unistd.h" 3
extern "C" void *valloc(size_t);
# 589 "/usr/include/unistd.h" 3
extern "C" { extern char *suboptarg; }
# 590 "/usr/include/unistd.h" 3
extern "C" int getsubopt(char **, char *const *, char **);
# 602 "/usr/include/unistd.h" 3
extern "C" int fgetattrlist(int, void *, void *, size_t, unsigned long);
# 603 "/usr/include/unistd.h" 3
extern "C" int fsetattrlist(int, void *, void *, size_t, unsigned long);
# 604 "/usr/include/unistd.h" 3
extern "C" int getattrlist(const char *, void *, void *, size_t, unsigned long) __asm__("_getattrlist$UNIX2003");
# 605 "/usr/include/unistd.h" 3
extern "C" int setattrlist(const char *, void *, void *, size_t, unsigned long) __asm__("_setattrlist$UNIX2003");
# 606 "/usr/include/unistd.h" 3
extern "C" int exchangedata(const char *, const char *, unsigned long);
# 607 "/usr/include/unistd.h" 3
extern "C" int getdirentriesattr(int, void *, void *, size_t, unsigned long *, unsigned long *, unsigned long *, unsigned long);
# 611 "/usr/include/unistd.h" 3
struct fssearchblock;
# 612 "/usr/include/unistd.h" 3
struct searchstate;
# 614 "/usr/include/unistd.h" 3
extern "C" int searchfs(const char *, fssearchblock *, unsigned long *, unsigned, unsigned, searchstate *);
# 615 "/usr/include/unistd.h" 3
extern "C" int fsctl(const char *, unsigned long, void *, unsigned);
# 616 "/usr/include/unistd.h" 3
extern "C" int ffsctl(int, unsigned long, void *, unsigned);
# 618 "/usr/include/unistd.h" 3
extern "C" { extern int optreset; }
# 89 "/usr/include/c++/4.2.1/i686-apple-darwin10/bits/os_defines.h" 3
extern "C" void __dtrace_probe$cxa_runtime$cxa_exception_rethrow$v1();
# 90 "/usr/include/c++/4.2.1/i686-apple-darwin10/bits/os_defines.h" 3
extern "C" int __dtrace_isenabled$cxa_runtime$cxa_exception_rethrow$v1();
# 91 "/usr/include/c++/4.2.1/i686-apple-darwin10/bits/os_defines.h" 3
extern "C" void __dtrace_probe$cxa_runtime$cxa_exception_throw$v1$766f6964202a(void *);
# 92 "/usr/include/c++/4.2.1/i686-apple-darwin10/bits/os_defines.h" 3
extern "C" int __dtrace_isenabled$cxa_runtime$cxa_exception_throw$v1();
# 153 "/usr/include/c++/4.2.1/i686-apple-darwin10/bits/c++config.h" 3
namespace std {
# 165 "/usr/include/c++/4.2.1/i686-apple-darwin10/bits/c++config.h" 3
}
# 74 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
namespace __gnu_cxx {
# 76 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Iterator, class _Container> class __normal_iterator;
# 79 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
}
# 81 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
namespace std {
# 83 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
namespace __detail {
# 87 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef char __one;
# 88 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef char __two[2];
# 90 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp> __one __test_type(int _Tp::*);
# 92 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp> __two &__test_type(...);
# 94 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
}
# 97 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __true_type { };
# 98 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __false_type { };
# 100 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< bool __T0>
# 101 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __truth_type {
# 102 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __false_type __type; };
# 105 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __truth_type< true> {
# 106 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type; };
# 110 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Sp, class _Tp>
# 111 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __traitor {
# 113 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = (((bool)_Sp::__value) || ((bool)_Tp::__value))};
# 114 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef typename __truth_type< __value> ::__type __type;
# 115 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 118 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class , class >
# 119 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __are_same {
# 121 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value};
# 122 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 123 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 125 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 126 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __are_same< _Tp, _Tp> {
# 128 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 129 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 130 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 133 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 134 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_void {
# 136 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value};
# 137 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 138 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 141 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_void< void> {
# 143 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 144 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 145 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 150 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 151 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_integer {
# 153 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value};
# 154 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 155 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 161 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< bool> {
# 163 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 164 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 165 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 168 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< char> {
# 170 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 171 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 172 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 175 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< signed char> {
# 177 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 178 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 179 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 182 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned char> {
# 184 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 185 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 186 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 190 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< wchar_t> {
# 192 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 193 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 194 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 198 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< short> {
# 200 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 201 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 202 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 205 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned short> {
# 207 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 208 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 209 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 212 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< int> {
# 214 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 215 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 216 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 219 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned> {
# 221 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 222 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 223 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 226 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< long> {
# 228 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 229 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 230 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 233 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned long> {
# 235 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 236 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 237 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 240 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< long long> {
# 242 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 243 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 244 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 247 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_integer< unsigned long long> {
# 249 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 250 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 251 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 256 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 257 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_floating {
# 259 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value};
# 260 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 261 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 265 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_floating< float> {
# 267 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 268 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 269 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 272 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_floating< double> {
# 274 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 275 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 276 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 279 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_floating< long double> {
# 281 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 282 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 283 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 288 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 289 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_pointer {
# 291 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value};
# 292 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 293 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 295 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 296 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_pointer< _Tp *> {
# 298 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 299 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 300 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 305 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 306 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_normal_iterator {
# 308 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value};
# 309 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 310 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 312 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Iterator, class _Container>
# 313 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> > {
# 316 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 317 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 318 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 323 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 324 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> > {
# 326 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 331 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 332 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> > {
# 334 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 339 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 340 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> > {
# 342 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 345 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 346 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_pod {
# 349 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum {
# 350 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
__value = (sizeof(__detail::__test_type< _Tp> (0)) != sizeof(__detail::__one))
# 352 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 353 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 358 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 359 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_empty {
# 363 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
private:
# 362 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class >
# 363 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __first { };
# 364 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Up>
# 365 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __second : public _Up {
# 366 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 370 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
public: enum {
# 371 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
__value = (sizeof(__first< _Tp> ) == sizeof(__second< _Tp> ))
# 372 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 373 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 378 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template< class _Tp>
# 379 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
struct __is_char {
# 381 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value};
# 382 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __false_type __type;
# 383 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 386 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_char< char> {
# 388 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 389 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 390 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 394 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
template<> struct __is_char< wchar_t> {
# 396 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
enum { __value = 1};
# 397 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
typedef __true_type __type;
# 398 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
};
# 401 "/usr/include/c++/4.2.1/bits/cpp_type_traits.h" 3
}
# 53 "/usr/include/c++/4.2.1/cstddef" 3
namespace std {
# 55 "/usr/include/c++/4.2.1/cstddef" 3
using ::ptrdiff_t;
# 56 "/usr/include/c++/4.2.1/cstddef" 3
using ::size_t;
# 58 "/usr/include/c++/4.2.1/cstddef" 3
}
# 74 "/usr/include/c++/4.2.1/bits/stl_relops.h" 3
namespace std {
# 76 "/usr/include/c++/4.2.1/bits/stl_relops.h" 3
namespace rel_ops {
# 90 "/usr/include/c++/4.2.1/bits/stl_relops.h" 3
template < class _Tp >
      inline bool
      operator != ( const _Tp & __x, const _Tp & __y )
      { return ! ( __x == __y ); }
# 103 "/usr/include/c++/4.2.1/bits/stl_relops.h" 3
template < class _Tp >
      inline bool
      operator > ( const _Tp & __x, const _Tp & __y )
      { return __y < __x; }
# 116 "/usr/include/c++/4.2.1/bits/stl_relops.h" 3
template < class _Tp >
      inline bool
      operator <= ( const _Tp & __x, const _Tp & __y )
      { return ! ( __y < __x ); }
# 129 "/usr/include/c++/4.2.1/bits/stl_relops.h" 3
template < class _Tp >
      inline bool
      operator >= ( const _Tp & __x, const _Tp & __y )
      { return ! ( __x < __y ); }
# 134 "/usr/include/c++/4.2.1/bits/stl_relops.h" 3
}
# 136 "/usr/include/c++/4.2.1/bits/stl_relops.h" 3
}
# 64 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
namespace std {
# 67 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
template < class _T1, class _T2 >
    struct pair
    {
      typedef _T1 first_type;
      typedef _T2 second_type;

      _T1 first;
      _T2 second;





      pair ( )
      : first ( ), second ( ) { }


      pair ( const _T1 & __a, const _T2 & __b )
      : first ( __a ), second ( __b ) { }


      template < class _U1, class _U2 >
        pair ( const pair < _U1, _U2 > & __p )
 : first ( __p . first ), second ( __p . second ) { }
    };
# 94 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
template < class _T1, class _T2 >
    inline bool
    operator == ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __x . first == __y . first && __x . second == __y . second; }
# 100 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
template < class _T1, class _T2 >
    inline bool
    operator < ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __x . first < __y . first
      || ( ! ( __y . first < __x . first ) && __x . second < __y . second ); }
# 107 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
template < class _T1, class _T2 >
    inline bool
    operator != ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __x == __y ); }
# 113 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
template < class _T1, class _T2 >
    inline bool
    operator > ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __y < __x; }
# 119 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
template < class _T1, class _T2 >
    inline bool
    operator <= ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __y < __x ); }
# 125 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
template < class _T1, class _T2 >
    inline bool
    operator >= ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __x < __y ); }
# 142 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
template < class _T1, class _T2 >
    inline pair < _T1, _T2 >
    make_pair ( _T1 __x, _T2 __y )
    { return pair < _T1, _T2 > ( __x, __y ); }
# 147 "/usr/include/c++/4.2.1/bits/stl_pair.h" 3
}
# 44 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
namespace __gnu_cxx {
# 47 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template< bool __T1, class >
# 48 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
struct __enable_if {
# 49 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
};
# 51 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template< class _Tp>
# 52 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
struct __enable_if< true, _Tp> {
# 53 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef _Tp __type; };
# 57 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template< bool _Cond, class _Iftrue, class _Iffalse>
# 58 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
struct __conditional_type {
# 59 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef _Iftrue __type; };
# 61 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template< class _Iftrue, class _Iffalse>
# 62 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
struct __conditional_type< false, _Iftrue, _Iffalse> {
# 63 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef _Iffalse __type; };
# 67 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template< class _Tp>
# 68 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
struct __add_unsigned {
# 71 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;
# 74 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
# 75 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
};
# 78 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __add_unsigned< char> {
# 79 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef unsigned char __type; };
# 82 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __add_unsigned< signed char> {
# 83 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef unsigned char __type; };
# 86 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __add_unsigned< short> {
# 87 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef unsigned short __type; };
# 90 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __add_unsigned< int> {
# 91 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef unsigned __type; };
# 94 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __add_unsigned< long> {
# 95 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef unsigned long __type; };
# 98 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __add_unsigned< long long> {
# 99 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef unsigned long long __type; };
# 103 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __add_unsigned< bool> ;
# 106 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __add_unsigned< wchar_t> ;
# 110 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template< class _Tp>
# 111 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
struct __remove_unsigned {
# 114 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;
# 117 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
# 118 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
};
# 121 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __remove_unsigned< char> {
# 122 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef signed char __type; };
# 125 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned char> {
# 126 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef signed char __type; };
# 129 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned short> {
# 130 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef short __type; };
# 133 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned> {
# 134 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef int __type; };
# 137 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned long> {
# 138 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef long __type; };
# 141 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __remove_unsigned< unsigned long long> {
# 142 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
typedef long long __type; };
# 146 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __remove_unsigned< bool> ;
# 149 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
template<> struct __remove_unsigned< wchar_t> ;
# 151 "/usr/include/c++/4.2.1/ext/type_traits.h" 3
}
# 82 "/usr/include/c++/4.2.1/cmath" 3
namespace std {
# 86 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp > _Tp __cmath_power ( _Tp, unsigned int );
# 89 "/usr/include/c++/4.2.1/cmath" 3
inline double abs(double __x)
# 90 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_fabs(__x); }
# 93 "/usr/include/c++/4.2.1/cmath" 3
inline float abs(float __x)
# 94 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_fabsf(__x); }
# 97 "/usr/include/c++/4.2.1/cmath" 3
inline long double abs(long double __x)
# 98 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_fabsl(__x); }
# 100 "/usr/include/c++/4.2.1/cmath" 3
using ::acos;
# 103 "/usr/include/c++/4.2.1/cmath" 3
inline float acos(float __x)
# 104 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_acosf(__x); }
# 107 "/usr/include/c++/4.2.1/cmath" 3
inline long double acos(long double __x)
# 108 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_acosl(__x); }
# 110 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    acos ( _Tp __x )
    { return __builtin_acos ( __x ); }
# 116 "/usr/include/c++/4.2.1/cmath" 3
using ::asin;
# 119 "/usr/include/c++/4.2.1/cmath" 3
inline float asin(float __x)
# 120 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_asinf(__x); }
# 123 "/usr/include/c++/4.2.1/cmath" 3
inline long double asin(long double __x)
# 124 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_asinl(__x); }
# 126 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
  inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
      double > :: __type
    asin ( _Tp __x )
    { return __builtin_asin ( __x ); }
# 132 "/usr/include/c++/4.2.1/cmath" 3
using ::atan;
# 135 "/usr/include/c++/4.2.1/cmath" 3
inline float atan(float __x)
# 136 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_atanf(__x); }
# 139 "/usr/include/c++/4.2.1/cmath" 3
inline long double atan(long double __x)
# 140 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_atanl(__x); }
# 142 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
  inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
      double > :: __type
    atan ( _Tp __x )
    { return __builtin_atan ( __x ); }
# 148 "/usr/include/c++/4.2.1/cmath" 3
using ::atan2;
# 151 "/usr/include/c++/4.2.1/cmath" 3
inline float atan2(float __y, float __x)
# 152 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_atan2f(__y, __x); }
# 155 "/usr/include/c++/4.2.1/cmath" 3
inline long double atan2(long double __y, long double __x)
# 156 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_atan2l(__y, __x); }
# 158 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp, typename _Up >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value
            && __is_integer < _Up > :: __value,
        double > :: __type
    atan2 ( _Tp __y, _Up __x )
    { return __builtin_atan2 ( __y, __x ); }
# 165 "/usr/include/c++/4.2.1/cmath" 3
using ::ceil;
# 168 "/usr/include/c++/4.2.1/cmath" 3
inline float ceil(float __x)
# 169 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_ceilf(__x); }
# 172 "/usr/include/c++/4.2.1/cmath" 3
inline long double ceil(long double __x)
# 173 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_ceill(__x); }
# 175 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    ceil ( _Tp __x )
    { return __builtin_ceil ( __x ); }
# 181 "/usr/include/c++/4.2.1/cmath" 3
using ::cos;
# 184 "/usr/include/c++/4.2.1/cmath" 3
inline float cos(float __x)
# 185 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_cosf(__x); }
# 188 "/usr/include/c++/4.2.1/cmath" 3
inline long double cos(long double __x)
# 189 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_cosl(__x); }
# 191 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cos ( _Tp __x )
    { return __builtin_cos ( __x ); }
# 197 "/usr/include/c++/4.2.1/cmath" 3
using ::cosh;
# 200 "/usr/include/c++/4.2.1/cmath" 3
inline float cosh(float __x)
# 201 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_coshf(__x); }
# 204 "/usr/include/c++/4.2.1/cmath" 3
inline long double cosh(long double __x)
# 205 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_coshl(__x); }
# 207 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cosh ( _Tp __x )
    { return __builtin_cosh ( __x ); }
# 213 "/usr/include/c++/4.2.1/cmath" 3
using ::exp;
# 216 "/usr/include/c++/4.2.1/cmath" 3
inline float exp(float __x)
# 217 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_expf(__x); }
# 220 "/usr/include/c++/4.2.1/cmath" 3
inline long double exp(long double __x)
# 221 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_expl(__x); }
# 223 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    exp ( _Tp __x )
    { return __builtin_exp ( __x ); }
# 229 "/usr/include/c++/4.2.1/cmath" 3
using ::fabs;
# 232 "/usr/include/c++/4.2.1/cmath" 3
inline float fabs(float __x)
# 233 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_fabsf(__x); }
# 236 "/usr/include/c++/4.2.1/cmath" 3
inline long double fabs(long double __x)
# 237 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_fabsl(__x); }
# 239 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    fabs ( _Tp __x )
    { return __builtin_fabs ( __x ); }
# 245 "/usr/include/c++/4.2.1/cmath" 3
using ::floor;
# 248 "/usr/include/c++/4.2.1/cmath" 3
inline float floor(float __x)
# 249 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_floorf(__x); }
# 252 "/usr/include/c++/4.2.1/cmath" 3
inline long double floor(long double __x)
# 253 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_floorl(__x); }
# 255 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    floor ( _Tp __x )
    { return __builtin_floor ( __x ); }
# 261 "/usr/include/c++/4.2.1/cmath" 3
using ::fmod;
# 264 "/usr/include/c++/4.2.1/cmath" 3
inline float fmod(float __x, float __y)
# 265 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_fmodf(__x, __y); }
# 268 "/usr/include/c++/4.2.1/cmath" 3
inline long double fmod(long double __x, long double __y)
# 269 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_fmodl(__x, __y); }
# 271 "/usr/include/c++/4.2.1/cmath" 3
using ::frexp;
# 274 "/usr/include/c++/4.2.1/cmath" 3
inline float frexp(float __x, int *__exp)
# 275 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_frexpf(__x, __exp); }
# 278 "/usr/include/c++/4.2.1/cmath" 3
inline long double frexp(long double __x, int *__exp)
# 279 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_frexpl(__x, __exp); }
# 281 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    frexp ( _Tp __x, int * __exp )
    { return __builtin_frexp ( __x, __exp ); }
# 287 "/usr/include/c++/4.2.1/cmath" 3
using ::ldexp;
# 290 "/usr/include/c++/4.2.1/cmath" 3
inline float ldexp(float __x, int __exp)
# 291 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_ldexpf(__x, __exp); }
# 294 "/usr/include/c++/4.2.1/cmath" 3
inline long double ldexp(long double __x, int __exp)
# 295 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_ldexpl(__x, __exp); }
# 297 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
  ldexp ( _Tp __x, int __exp )
  { return __builtin_ldexp ( __x, __exp ); }
# 303 "/usr/include/c++/4.2.1/cmath" 3
using ::log;
# 306 "/usr/include/c++/4.2.1/cmath" 3
inline float log(float __x)
# 307 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_logf(__x); }
# 310 "/usr/include/c++/4.2.1/cmath" 3
inline long double log(long double __x)
# 311 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_logl(__x); }
# 313 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log ( _Tp __x )
    { return __builtin_log ( __x ); }
# 319 "/usr/include/c++/4.2.1/cmath" 3
using ::log10;
# 322 "/usr/include/c++/4.2.1/cmath" 3
inline float log10(float __x)
# 323 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_log10f(__x); }
# 326 "/usr/include/c++/4.2.1/cmath" 3
inline long double log10(long double __x)
# 327 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_log10l(__x); }
# 329 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log10 ( _Tp __x )
    { return __builtin_log10 ( __x ); }
# 335 "/usr/include/c++/4.2.1/cmath" 3
using ::modf;
# 338 "/usr/include/c++/4.2.1/cmath" 3
inline float modf(float __x, float *__iptr)
# 339 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_modff(__x, __iptr); }
# 342 "/usr/include/c++/4.2.1/cmath" 3
inline long double modf(long double __x, long double *__iptr)
# 343 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_modfl(__x, __iptr); }
# 345 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline _Tp
    __pow_helper ( _Tp __x, int __n )
    {
      return __n < 0
        ? _Tp ( 1 ) / __cmath_power ( __x, - __n )
        : __cmath_power ( __x, __n );
    }
# 354 "/usr/include/c++/4.2.1/cmath" 3
using ::pow;
# 357 "/usr/include/c++/4.2.1/cmath" 3
inline float pow(float __x, float __y)
# 358 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_powf(__x, __y); }
# 361 "/usr/include/c++/4.2.1/cmath" 3
inline long double pow(long double __x, long double __y)
# 362 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_powl(__x, __y); }
# 365 "/usr/include/c++/4.2.1/cmath" 3
inline double pow(double __x, int __i)
# 366 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_powi(__x, __i); }
# 369 "/usr/include/c++/4.2.1/cmath" 3
inline float pow(float __x, int __n)
# 370 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_powif(__x, __n); }
# 373 "/usr/include/c++/4.2.1/cmath" 3
inline long double pow(long double __x, int __n)
# 374 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_powil(__x, __n); }
# 376 "/usr/include/c++/4.2.1/cmath" 3
using ::sin;
# 379 "/usr/include/c++/4.2.1/cmath" 3
inline float sin(float __x)
# 380 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_sinf(__x); }
# 383 "/usr/include/c++/4.2.1/cmath" 3
inline long double sin(long double __x)
# 384 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_sinl(__x); }
# 386 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sin ( _Tp __x )
    { return __builtin_sin ( __x ); }
# 392 "/usr/include/c++/4.2.1/cmath" 3
using ::sinh;
# 395 "/usr/include/c++/4.2.1/cmath" 3
inline float sinh(float __x)
# 396 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_sinhf(__x); }
# 399 "/usr/include/c++/4.2.1/cmath" 3
inline long double sinh(long double __x)
# 400 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_sinhl(__x); }
# 402 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sinh ( _Tp __x )
    { return __builtin_sinh ( __x ); }
# 408 "/usr/include/c++/4.2.1/cmath" 3
using ::sqrt;
# 411 "/usr/include/c++/4.2.1/cmath" 3
inline float sqrt(float __x)
# 412 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_sqrtf(__x); }
# 415 "/usr/include/c++/4.2.1/cmath" 3
inline long double sqrt(long double __x)
# 416 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_sqrtl(__x); }
# 418 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sqrt ( _Tp __x )
    { return __builtin_sqrt ( __x ); }
# 424 "/usr/include/c++/4.2.1/cmath" 3
using ::tan;
# 427 "/usr/include/c++/4.2.1/cmath" 3
inline float tan(float __x)
# 428 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_tanf(__x); }
# 431 "/usr/include/c++/4.2.1/cmath" 3
inline long double tan(long double __x)
# 432 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_tanl(__x); }
# 434 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tan ( _Tp __x )
    { return __builtin_tan ( __x ); }
# 440 "/usr/include/c++/4.2.1/cmath" 3
using ::tanh;
# 443 "/usr/include/c++/4.2.1/cmath" 3
inline float tanh(float __x)
# 444 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_tanhf(__x); }
# 447 "/usr/include/c++/4.2.1/cmath" 3
inline long double tanh(long double __x)
# 448 "/usr/include/c++/4.2.1/cmath" 3
{ return __builtin_tanhl(__x); }
# 450 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tanh ( _Tp __x )
    { return __builtin_tanh ( __x ); }
# 456 "/usr/include/c++/4.2.1/cmath" 3
}
# 464 "/usr/include/c++/4.2.1/cmath" 3
namespace __gnu_cxx {
# 466 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_fpclassify ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __fpclassifyf ( ( float ) ( __f ) ) : sizeof ( __f ) == sizeof ( double ) ? __fpclassifyd ( ( double ) ( __f ) ) : __fpclassify ( ( long double ) ( __f ) ) ); }
# 470 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_isfinite ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __inline_isfinitef ( ( float ) ( __f ) ) : sizeof ( __f ) == sizeof ( double ) ? __inline_isfinited ( ( double ) ( __f ) ) : __inline_isfinite ( ( long double ) ( __f ) ) ); }
# 474 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_isinf ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __inline_isinff ( ( float ) ( __f ) ) : sizeof ( __f ) == sizeof ( double ) ? __inline_isinfd ( ( double ) ( __f ) ) : __inline_isinf ( ( long double ) ( __f ) ) ); }
# 478 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_isnan ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __inline_isnanf ( ( float ) ( __f ) ) : sizeof ( __f ) == sizeof ( double ) ? __inline_isnand ( ( double ) ( __f ) ) : __inline_isnan ( ( long double ) ( __f ) ) ); }
# 482 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_isnormal ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __inline_isnormalf ( ( float ) ( __f ) ) : sizeof ( __f ) == sizeof ( double ) ? __inline_isnormald ( ( double ) ( __f ) ) : __inline_isnormal ( ( long double ) ( __f ) ) ); }
# 486 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_signbit ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __inline_signbitf ( ( float ) ( __f ) ) : sizeof ( __f ) == sizeof ( double ) ? __inline_signbitd ( ( double ) ( __f ) ) : __inline_signbit ( ( long double ) ( __f ) ) ); }
# 490 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_isgreater ( _Tp __f1, _Tp __f2 )
    { return __builtin_isgreater ( ( __f1 ), ( __f2 ) ); }
# 495 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_isgreaterequal ( _Tp __f1, _Tp __f2 )
    { return __builtin_isgreaterequal ( ( __f1 ), ( __f2 ) ); }
# 500 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_isless ( _Tp __f1, _Tp __f2 ) { return __builtin_isless ( ( __f1 ), ( __f2 ) ); }
# 504 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_islessequal ( _Tp __f1, _Tp __f2 )
    { return __builtin_islessequal ( ( __f1 ), ( __f2 ) ); }
# 509 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_islessgreater ( _Tp __f1, _Tp __f2 )
    { return __builtin_islessgreater ( ( __f1 ), ( __f2 ) ); }
# 514 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    __capture_isunordered ( _Tp __f1, _Tp __f2 )
    { return __builtin_isunordered ( ( __f1 ), ( __f2 ) ); }
# 519 "/usr/include/c++/4.2.1/cmath" 3
}
# 535 "/usr/include/c++/4.2.1/cmath" 3
namespace std {
# 537 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    fpclassify ( _Tp __f ) { return :: __gnu_cxx :: __capture_fpclassify ( __f ); }
# 541 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    isfinite ( _Tp __f ) { return :: __gnu_cxx :: __capture_isfinite ( __f ); }
# 545 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    isinf ( _Tp __f ) { return :: __gnu_cxx :: __capture_isinf ( __f ); }
# 549 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    isnan ( _Tp __f ) { return :: __gnu_cxx :: __capture_isnan ( __f ); }
# 553 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    isnormal ( _Tp __f ) { return :: __gnu_cxx :: __capture_isnormal ( __f ); }
# 557 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    signbit ( _Tp __f ) { return :: __gnu_cxx :: __capture_signbit ( __f ); }
# 561 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    isgreater ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_isgreater ( __f1, __f2 ); }
# 566 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    isgreaterequal ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_isgreaterequal ( __f1, __f2 ); }
# 571 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    isless ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_isless ( __f1, __f2 ); }
# 576 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    islessequal ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_islessequal ( __f1, __f2 ); }
# 581 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    islessgreater ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_islessgreater ( __f1, __f2 ); }
# 586 "/usr/include/c++/4.2.1/cmath" 3
template < typename _Tp >
    inline int
    isunordered ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_isunordered ( __f1, __f2 ); }
# 591 "/usr/include/c++/4.2.1/cmath" 3
}
# 39 "/usr/include/c++/4.2.1/bits/cmath.tcc" 3
namespace std {
# 41 "/usr/include/c++/4.2.1/bits/cmath.tcc" 3
template < typename _Tp >
    inline _Tp
    __cmath_power ( _Tp __x, unsigned int __n )
    {
      _Tp __y = __n % 2 ? __x : 1;

      while ( __n >>= 1 )
        {
          __x = __x * __x;
          if ( __n % 2 )
            __y = __y * __x;
        }

      return __y;
    }
# 57 "/usr/include/c++/4.2.1/bits/cmath.tcc" 3
}
# 104 "/usr/include/c++/4.2.1/cstdlib" 3
namespace std {
# 106 "/usr/include/c++/4.2.1/cstdlib" 3
using ::div_t;
# 107 "/usr/include/c++/4.2.1/cstdlib" 3
using ::ldiv_t;
# 109 "/usr/include/c++/4.2.1/cstdlib" 3
using ::abort;
# 110 "/usr/include/c++/4.2.1/cstdlib" 3
using ::abs;
# 111 "/usr/include/c++/4.2.1/cstdlib" 3
using ::atexit;
# 112 "/usr/include/c++/4.2.1/cstdlib" 3
using ::atof;
# 113 "/usr/include/c++/4.2.1/cstdlib" 3
using ::atoi;
# 114 "/usr/include/c++/4.2.1/cstdlib" 3
using ::atol;
# 115 "/usr/include/c++/4.2.1/cstdlib" 3
using ::bsearch;
# 116 "/usr/include/c++/4.2.1/cstdlib" 3
using ::calloc;
# 117 "/usr/include/c++/4.2.1/cstdlib" 3
using ::div;
# 118 "/usr/include/c++/4.2.1/cstdlib" 3
using ::exit;
# 119 "/usr/include/c++/4.2.1/cstdlib" 3
using ::free;
# 120 "/usr/include/c++/4.2.1/cstdlib" 3
using ::getenv;
# 121 "/usr/include/c++/4.2.1/cstdlib" 3
using ::labs;
# 122 "/usr/include/c++/4.2.1/cstdlib" 3
using ::ldiv;
# 123 "/usr/include/c++/4.2.1/cstdlib" 3
using ::malloc;
# 125 "/usr/include/c++/4.2.1/cstdlib" 3
using ::mblen;
# 126 "/usr/include/c++/4.2.1/cstdlib" 3
using ::mbstowcs;
# 127 "/usr/include/c++/4.2.1/cstdlib" 3
using ::mbtowc;
# 129 "/usr/include/c++/4.2.1/cstdlib" 3
using ::qsort;
# 130 "/usr/include/c++/4.2.1/cstdlib" 3
using ::rand;
# 131 "/usr/include/c++/4.2.1/cstdlib" 3
using ::realloc;
# 132 "/usr/include/c++/4.2.1/cstdlib" 3
using ::srand;
# 133 "/usr/include/c++/4.2.1/cstdlib" 3
using ::strtod;
# 134 "/usr/include/c++/4.2.1/cstdlib" 3
using ::strtol;
# 135 "/usr/include/c++/4.2.1/cstdlib" 3
using ::strtoul;
# 136 "/usr/include/c++/4.2.1/cstdlib" 3
using ::system;
# 138 "/usr/include/c++/4.2.1/cstdlib" 3
using ::wcstombs;
# 139 "/usr/include/c++/4.2.1/cstdlib" 3
using ::wctomb;
# 143 "/usr/include/c++/4.2.1/cstdlib" 3
inline long abs(long __i) { return labs(__i); }
# 146 "/usr/include/c++/4.2.1/cstdlib" 3
inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); }
# 148 "/usr/include/c++/4.2.1/cstdlib" 3
}
# 161 "/usr/include/c++/4.2.1/cstdlib" 3
namespace __gnu_cxx {
# 164 "/usr/include/c++/4.2.1/cstdlib" 3
using ::lldiv_t;
# 170 "/usr/include/c++/4.2.1/cstdlib" 3
using ::_Exit;
# 174 "/usr/include/c++/4.2.1/cstdlib" 3
inline long long abs(long long __x) { return (__x >= (0)) ? __x : (-__x); }
# 177 "/usr/include/c++/4.2.1/cstdlib" 3
using ::llabs;
# 180 "/usr/include/c++/4.2.1/cstdlib" 3
inline lldiv_t div(long long __n, long long __d)
# 181 "/usr/include/c++/4.2.1/cstdlib" 3
{ lldiv_t __q; (__q.quot) = (__n / __d); (__q.rem) = (__n % __d); return __q; }
# 183 "/usr/include/c++/4.2.1/cstdlib" 3
using ::lldiv;
# 194 "/usr/include/c++/4.2.1/cstdlib" 3
using ::atoll;
# 195 "/usr/include/c++/4.2.1/cstdlib" 3
using ::strtoll;
# 196 "/usr/include/c++/4.2.1/cstdlib" 3
using ::strtoull;
# 198 "/usr/include/c++/4.2.1/cstdlib" 3
using ::strtof;
# 199 "/usr/include/c++/4.2.1/cstdlib" 3
using ::strtold;
# 201 "/usr/include/c++/4.2.1/cstdlib" 3
}
# 203 "/usr/include/c++/4.2.1/cstdlib" 3
namespace std {
# 206 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::lldiv_t;
# 208 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::_Exit;
# 209 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::abs;
# 211 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::llabs;
# 212 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::div;
# 213 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::lldiv;
# 215 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::atoll;
# 216 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::strtof;
# 217 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::strtoll;
# 218 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::strtoull;
# 219 "/usr/include/c++/4.2.1/cstdlib" 3
using __gnu_cxx::strtold;
# 221 "/usr/include/c++/4.2.1/cstdlib" 3
}
# 497 "/usr/local/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {
# 499 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline long long abs(long long);
# 500 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 502 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {
# 504 "/usr/local/cuda/bin/../include/math_functions.h"
template< class T> extern inline T __pow_helper(T, int);
# 505 "/usr/local/cuda/bin/../include/math_functions.h"
template< class T> extern inline T __cmath_power(T, unsigned);
# 506 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 508 "/usr/local/cuda/bin/../include/math_functions.h"
using std::abs;
# 509 "/usr/local/cuda/bin/../include/math_functions.h"
using std::fabs;
# 510 "/usr/local/cuda/bin/../include/math_functions.h"
using std::ceil;
# 511 "/usr/local/cuda/bin/../include/math_functions.h"
using std::floor;
# 512 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sqrt;
# 513 "/usr/local/cuda/bin/../include/math_functions.h"
using std::pow;
# 514 "/usr/local/cuda/bin/../include/math_functions.h"
using std::log;
# 515 "/usr/local/cuda/bin/../include/math_functions.h"
using std::log10;
# 516 "/usr/local/cuda/bin/../include/math_functions.h"
using std::fmod;
# 517 "/usr/local/cuda/bin/../include/math_functions.h"
using std::modf;
# 518 "/usr/local/cuda/bin/../include/math_functions.h"
using std::exp;
# 519 "/usr/local/cuda/bin/../include/math_functions.h"
using std::frexp;
# 520 "/usr/local/cuda/bin/../include/math_functions.h"
using std::ldexp;
# 521 "/usr/local/cuda/bin/../include/math_functions.h"
using std::asin;
# 522 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sin;
# 523 "/usr/local/cuda/bin/../include/math_functions.h"
using std::sinh;
# 524 "/usr/local/cuda/bin/../include/math_functions.h"
using std::acos;
# 525 "/usr/local/cuda/bin/../include/math_functions.h"
using std::cos;
# 526 "/usr/local/cuda/bin/../include/math_functions.h"
using std::cosh;
# 527 "/usr/local/cuda/bin/../include/math_functions.h"
using std::atan;
# 528 "/usr/local/cuda/bin/../include/math_functions.h"
using std::atan2;
# 529 "/usr/local/cuda/bin/../include/math_functions.h"
using std::tan;
# 530 "/usr/local/cuda/bin/../include/math_functions.h"
using std::tanh;
# 584 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {
# 587 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline long abs(long);
# 588 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float abs(float);
# 589 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline double abs(double);
# 590 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float fabs(float);
# 591 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float ceil(float);
# 592 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float floor(float);
# 593 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sqrt(float);
# 594 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float pow(float, float);
# 595 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float pow(float, int);
# 596 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline double pow(double, int);
# 597 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float log(float);
# 598 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float log10(float);
# 599 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float fmod(float, float);
# 600 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float modf(float, float *);
# 601 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float exp(float);
# 602 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float frexp(float, int *);
# 603 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float ldexp(float, int);
# 604 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float asin(float);
# 605 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sin(float);
# 606 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float sinh(float);
# 607 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float acos(float);
# 608 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float cos(float);
# 609 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float cosh(float);
# 610 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float atan(float);
# 611 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float atan2(float, float);
# 612 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float tan(float);
# 613 "/usr/local/cuda/bin/../include/math_functions.h"
extern inline float tanh(float);
# 616 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 619 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float logb(float a)
# 620 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 621 "/usr/local/cuda/bin/../include/math_functions.h"
return logbf(a);
# 622 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 624 "/usr/local/cuda/bin/../include/math_functions.h"
static inline int ilogb(float a)
# 625 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 626 "/usr/local/cuda/bin/../include/math_functions.h"
return ilogbf(a);
# 627 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 629 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float scalbn(float a, int b)
# 630 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 631 "/usr/local/cuda/bin/../include/math_functions.h"
return scalbnf(a, b);
# 632 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 634 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float scalbln(float a, long b)
# 635 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 636 "/usr/local/cuda/bin/../include/math_functions.h"
return scalblnf(a, b);
# 637 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 639 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float exp2(float a)
# 640 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 641 "/usr/local/cuda/bin/../include/math_functions.h"
return exp2f(a);
# 642 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 644 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float exp10(float a)
# 645 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 646 "/usr/local/cuda/bin/../include/math_functions.h"
return exp10f(a);
# 647 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 649 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float expm1(float a)
# 650 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 651 "/usr/local/cuda/bin/../include/math_functions.h"
return expm1f(a);
# 652 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 654 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float log2(float a)
# 655 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 656 "/usr/local/cuda/bin/../include/math_functions.h"
return log2f(a);
# 657 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 659 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float log1p(float a)
# 660 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 661 "/usr/local/cuda/bin/../include/math_functions.h"
return log1pf(a);
# 662 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 664 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rsqrt(float a)
# 665 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 666 "/usr/local/cuda/bin/../include/math_functions.h"
return rsqrtf(a);
# 667 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 669 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float acosh(float a)
# 670 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 671 "/usr/local/cuda/bin/../include/math_functions.h"
return acoshf(a);
# 672 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 674 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float asinh(float a)
# 675 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 676 "/usr/local/cuda/bin/../include/math_functions.h"
return asinhf(a);
# 677 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 679 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float atanh(float a)
# 680 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 681 "/usr/local/cuda/bin/../include/math_functions.h"
return atanhf(a);
# 682 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 684 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float hypot(float a, float b)
# 685 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 686 "/usr/local/cuda/bin/../include/math_functions.h"
return hypotf(a, b);
# 687 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 689 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float cbrt(float a)
# 690 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 691 "/usr/local/cuda/bin/../include/math_functions.h"
return cbrtf(a);
# 692 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 694 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rcbrt(float a)
# 695 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 696 "/usr/local/cuda/bin/../include/math_functions.h"
return rcbrtf(a);
# 697 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 699 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float sinpi(float a)
# 700 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 701 "/usr/local/cuda/bin/../include/math_functions.h"
return sinpif(a);
# 702 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 704 "/usr/local/cuda/bin/../include/math_functions.h"
static inline void sincos(float a, float *sptr, float *cptr)
# 705 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 706 "/usr/local/cuda/bin/../include/math_functions.h"
sincosf(a, sptr, cptr);
# 707 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 709 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erf(float a)
# 710 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 711 "/usr/local/cuda/bin/../include/math_functions.h"
return erff(a);
# 712 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 714 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfinv(float a)
# 715 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 716 "/usr/local/cuda/bin/../include/math_functions.h"
return erfinvf(a);
# 717 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 719 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfc(float a)
# 720 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 721 "/usr/local/cuda/bin/../include/math_functions.h"
return erfcf(a);
# 722 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 724 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float erfcinv(float a)
# 725 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 726 "/usr/local/cuda/bin/../include/math_functions.h"
return erfcinvf(a);
# 727 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 729 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float lgamma(float a)
# 730 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 731 "/usr/local/cuda/bin/../include/math_functions.h"
return lgammaf(a);
# 732 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 734 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float tgamma(float a)
# 735 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 736 "/usr/local/cuda/bin/../include/math_functions.h"
return tgammaf(a);
# 737 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 739 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, float b)
# 740 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 741 "/usr/local/cuda/bin/../include/math_functions.h"
return copysignf(a, b);
# 742 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 744 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double copysign(double a, float b)
# 745 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 746 "/usr/local/cuda/bin/../include/math_functions.h"
return copysign(a, (double)b);
# 747 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 749 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float copysign(float a, double b)
# 750 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 751 "/usr/local/cuda/bin/../include/math_functions.h"
return copysignf(a, (float)b);
# 752 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 754 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float nextafter(float a, float b)
# 755 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 756 "/usr/local/cuda/bin/../include/math_functions.h"
return nextafterf(a, b);
# 757 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 759 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float remainder(float a, float b)
# 760 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 761 "/usr/local/cuda/bin/../include/math_functions.h"
return remainderf(a, b);
# 762 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 764 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float remquo(float a, float b, int *quo)
# 765 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 766 "/usr/local/cuda/bin/../include/math_functions.h"
return remquof(a, b, quo);
# 767 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 769 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float round(float a)
# 770 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 771 "/usr/local/cuda/bin/../include/math_functions.h"
return roundf(a);
# 772 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 774 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long lround(float a)
# 775 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 776 "/usr/local/cuda/bin/../include/math_functions.h"
return lroundf(a);
# 777 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 779 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long llround(float a)
# 780 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 781 "/usr/local/cuda/bin/../include/math_functions.h"
return llroundf(a);
# 782 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 784 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float trunc(float a)
# 785 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 786 "/usr/local/cuda/bin/../include/math_functions.h"
return truncf(a);
# 787 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 789 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float rint(float a)
# 790 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 791 "/usr/local/cuda/bin/../include/math_functions.h"
return rintf(a);
# 792 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 794 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long lrint(float a)
# 795 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 796 "/usr/local/cuda/bin/../include/math_functions.h"
return lrintf(a);
# 797 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 799 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long llrint(float a)
# 800 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 801 "/usr/local/cuda/bin/../include/math_functions.h"
return llrintf(a);
# 802 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 804 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float nearbyint(float a)
# 805 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 806 "/usr/local/cuda/bin/../include/math_functions.h"
return nearbyintf(a);
# 807 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 809 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fdim(float a, float b)
# 810 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 811 "/usr/local/cuda/bin/../include/math_functions.h"
return fdimf(a, b);
# 812 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 814 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fma(float a, float b, float c)
# 815 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 816 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaf(a, b, c);
# 817 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 819 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fmax(float a, float b)
# 820 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 821 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 822 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 824 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float fmin(float a, float b)
# 825 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 826 "/usr/local/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 827 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 829 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, unsigned b)
# 830 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 831 "/usr/local/cuda/bin/../include/math_functions.h"
return umin(a, b);
# 832 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 834 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(int a, unsigned b)
# 835 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 836 "/usr/local/cuda/bin/../include/math_functions.h"
return umin((unsigned)a, b);
# 837 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 839 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned min(unsigned a, int b)
# 840 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 841 "/usr/local/cuda/bin/../include/math_functions.h"
return umin(a, (unsigned)b);
# 842 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 844 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long min(long long a, long long b)
# 845 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 846 "/usr/local/cuda/bin/../include/math_functions.h"
return llmin(a, b);
# 847 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 849 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, unsigned long long b)
# 850 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 851 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin(a, b);
# 852 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 854 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(long long a, unsigned long long b)
# 855 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 856 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin((unsigned long long)a, b);
# 857 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 859 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long min(unsigned long long a, long long b)
# 860 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 861 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmin(a, (unsigned long long)b);
# 862 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 864 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float min(float a, float b)
# 865 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 866 "/usr/local/cuda/bin/../include/math_functions.h"
return fminf(a, b);
# 867 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 869 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(double a, double b)
# 870 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 871 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin(a, b);
# 872 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 874 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(float a, double b)
# 875 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 876 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin((double)a, b);
# 877 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 879 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double min(double a, float b)
# 880 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 881 "/usr/local/cuda/bin/../include/math_functions.h"
return fmin(a, (double)b);
# 882 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 884 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, unsigned b)
# 885 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 886 "/usr/local/cuda/bin/../include/math_functions.h"
return umax(a, b);
# 887 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 889 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(int a, unsigned b)
# 890 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 891 "/usr/local/cuda/bin/../include/math_functions.h"
return umax((unsigned)a, b);
# 892 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 894 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned max(unsigned a, int b)
# 895 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 896 "/usr/local/cuda/bin/../include/math_functions.h"
return umax(a, (unsigned)b);
# 897 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 899 "/usr/local/cuda/bin/../include/math_functions.h"
static inline long long max(long long a, long long b)
# 900 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 901 "/usr/local/cuda/bin/../include/math_functions.h"
return llmax(a, b);
# 902 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 904 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, unsigned long long b)
# 905 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 906 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax(a, b);
# 907 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 909 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(long long a, unsigned long long b)
# 910 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 911 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax((unsigned long long)a, b);
# 912 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 914 "/usr/local/cuda/bin/../include/math_functions.h"
static inline unsigned long long max(unsigned long long a, long long b)
# 915 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 916 "/usr/local/cuda/bin/../include/math_functions.h"
return ullmax(a, (unsigned long long)b);
# 917 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 919 "/usr/local/cuda/bin/../include/math_functions.h"
static inline float max(float a, float b)
# 920 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 921 "/usr/local/cuda/bin/../include/math_functions.h"
return fmaxf(a, b);
# 922 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 924 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(double a, double b)
# 925 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 926 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax(a, b);
# 927 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 929 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(float a, double b)
# 930 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 931 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax((double)a, b);
# 932 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 934 "/usr/local/cuda/bin/../include/math_functions.h"
static inline double max(double a, float b)
# 935 "/usr/local/cuda/bin/../include/math_functions.h"
{
# 936 "/usr/local/cuda/bin/../include/math_functions.h"
return fmax(a, (double)b);
# 937 "/usr/local/cuda/bin/../include/math_functions.h"
}
# 60 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template< class T, int dim = 1>
# 61 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
struct surface : public surfaceReference {
# 63 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface()
# 64 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 65 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 66 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 68 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface(cudaChannelFormatDesc desc)
# 69 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 70 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = desc;
# 71 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 72 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
};
# 75 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template< int dim>
# 76 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
struct surface< void, dim> : public surfaceReference {
# 78 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
surface()
# 79 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
{
# 80 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
(channelDesc) = cudaCreateChannelDesc< void> ();
# 81 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
}
# 82 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
};
# 60 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
template< class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
# 61 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
struct texture : public textureReference {
# 63 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
texture(int norm = 0, cudaTextureFilterMode
# 64 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
fMode = cudaFilterModePoint, cudaTextureAddressMode
# 65 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
aMode = cudaAddressModeClamp)
# 66 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
{
# 67 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 68 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 69 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 70 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 71 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 72 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = cudaCreateChannelDesc< T> ();
# 73 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
}
# 75 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
texture(int norm, cudaTextureFilterMode
# 76 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
fMode, cudaTextureAddressMode
# 77 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
aMode, cudaChannelFormatDesc
# 78 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
desc)
# 79 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
{
# 80 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(normalized) = norm;
# 81 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(filterMode) = fMode;
# 82 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[0]) = aMode;
# 83 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[1]) = aMode;
# 84 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
((addressMode)[2]) = aMode;
# 85 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
(channelDesc) = desc;
# 86 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
}
# 87 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
};
# 324 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int mulhi(int a, int b)
# 325 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 327 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 329 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, unsigned b)
# 330 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 332 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 334 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(int a, unsigned b)
# 335 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 337 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 339 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, int b)
# 340 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 342 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 344 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline long long mul64hi(long long a, long long b)
# 345 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 347 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 349 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b)
# 350 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 352 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 354 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(long long a, unsigned long long b)
# 355 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 357 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 359 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, long long b)
# 360 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 364 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int float_as_int(float a)
# 365 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 367 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 369 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float int_as_float(int a)
# 370 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 372 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 374 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float saturate(float a)
# 375 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 377 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 379 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int mul24(int a, int b)
# 380 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 382 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 384 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned umul24(unsigned a, unsigned b)
# 385 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 389 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void trap()
# 390 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 392 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 394 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void brkpt(int c)
# 395 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 397 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 399 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void syncthreads()
# 400 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 404 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void prof_trigger(int e)
# 405 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 422 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 424 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline void threadfence(bool global = true)
# 425 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 429 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero)
# 430 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 435 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 437 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero)
# 438 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 443 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 445 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest)
# 446 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 451 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 453 "/usr/local/cuda/bin/../include/device_functions.h"
__attribute__((unused)) static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 454 "/usr/local/cuda/bin/../include/device_functions.h"
{int volatile ___ = 1;
# 459 "/usr/local/cuda/bin/../include/device_functions.h"
exit(___);}
# 102 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd(int *address, int val)
# 103 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 105 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 107 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd(unsigned *address, unsigned val)
# 108 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 112 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub(int *address, int val)
# 113 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 115 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 117 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub(unsigned *address, unsigned val)
# 118 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 120 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 122 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch(int *address, int val)
# 123 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 125 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 127 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch(unsigned *address, unsigned val)
# 128 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 130 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 132 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch(float *address, float val)
# 133 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 135 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 137 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin(int *address, int val)
# 138 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 142 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin(unsigned *address, unsigned val)
# 143 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 147 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax(int *address, int val)
# 148 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 150 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 152 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax(unsigned *address, unsigned val)
# 153 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 155 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 157 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc(unsigned *address, unsigned val)
# 158 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 162 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec(unsigned *address, unsigned val)
# 163 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 167 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd(int *address, int val)
# 168 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 170 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 172 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd(unsigned *address, unsigned val)
# 173 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 175 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 177 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr(int *address, int val)
# 178 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 182 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr(unsigned *address, unsigned val)
# 183 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 185 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 187 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor(int *address, int val)
# 188 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 190 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 192 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor(unsigned *address, unsigned val)
# 193 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 195 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 197 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS(int *address, int compare, int val)
# 198 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val)
# 203 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
{int volatile ___ = 1;
# 205 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
exit(___);}
# 75 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val)
# 76 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 78 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 80 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val)
# 81 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 83 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 85 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val)
# 86 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 88 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 90 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool any(bool cond)
# 91 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 93 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 95 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
__attribute__((unused)) static inline bool all(bool cond)
# 96 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
{int volatile ___ = 1;
# 98 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
exit(___);}
# 170 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode)
# 171 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 176 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 178 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 179 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 184 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 186 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest)
# 187 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 194 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero)
# 195 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero)
# 203 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 208 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 210 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero)
# 211 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 216 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 218 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero)
# 219 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 224 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 226 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest)
# 227 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 234 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest)
# 235 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 240 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 242 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest)
# 243 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 245 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 247 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest)
# 248 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 252 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest)
# 253 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
exit(___);}
# 66 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd(float *address, float val)
# 67 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
{int volatile ___ = 1;
# 69 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
exit(___);}
# 124 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned ballot(bool pred)
# 125 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 127 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 129 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline int syncthreads_count(bool pred)
# 130 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 132 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 134 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_and(bool pred)
# 135 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 137 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 139 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_or(bool pred)
# 140 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
{int volatile ___ = 1;
# 142 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
exit(___);}
# 97 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 98 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 99 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 106 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 108 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 109 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 110 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 116 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 118 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 119 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dread(T *res, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 120 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 122 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 125 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 126 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 128 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 131 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline signed char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 132 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 134 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 137 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned char surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 138 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 140 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 143 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline char1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 144 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 146 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 149 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uchar1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 150 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 152 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 155 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline char2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 156 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 160 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 163 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uchar2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 164 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 166 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 169 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline char4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 170 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 174 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 177 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uchar4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 178 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 180 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 183 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 184 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 189 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned short surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 190 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 192 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 195 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline short1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 196 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 198 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 201 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ushort1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 202 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 204 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 207 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline short2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 208 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 212 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 215 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ushort2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 216 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 218 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 221 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline short4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 222 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 226 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 229 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ushort4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 230 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 232 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 235 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline int surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 236 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 238 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 241 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 242 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 244 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 247 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline int1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 248 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 250 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 253 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uint1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 254 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 256 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 259 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline int2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 260 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 264 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 267 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uint2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 268 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 270 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 273 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline int4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 274 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 278 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 281 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uint4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 282 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 284 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 287 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 288 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 290 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 293 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned long long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 294 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 296 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 299 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline longlong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 300 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 302 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 305 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulonglong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 306 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 308 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 311 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline longlong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 312 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 316 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 319 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulonglong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 320 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 322 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 327 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 328 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 330 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 333 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned long surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 334 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 336 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 339 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 340 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 342 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 345 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulong1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 346 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 348 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 351 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 352 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 356 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 359 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulong2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 360 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 364 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 367 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 368 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 372 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 375 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulong4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 376 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 380 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 385 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline float surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 386 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 388 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 391 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline float1 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 392 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 394 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 397 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline float2 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 398 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 402 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 405 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline float4 surf1Dread(surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode)
# 406 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 410 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 457 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 458 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 459 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 466 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 468 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline T
# 469 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 470 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 476 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 478 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 479 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dread(T *res, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 480 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 482 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 485 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 486 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 488 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 491 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline signed char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 492 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 494 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 497 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned char surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 498 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 500 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 503 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline char1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 504 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 506 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 509 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uchar1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 510 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 512 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 515 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline char2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 516 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 520 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 523 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uchar2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 524 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 526 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 529 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline char4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 530 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 534 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 537 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uchar4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 538 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 540 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 543 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 544 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 546 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 549 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned short surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 550 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 555 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline short1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 556 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 558 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 561 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ushort1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 562 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 564 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 567 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline short2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 568 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 572 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 575 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ushort2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 576 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 578 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 581 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline short4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 582 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 586 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 589 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ushort4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 590 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 592 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 595 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline int surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 596 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 598 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 601 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 602 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 604 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 607 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline int1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 608 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 610 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 613 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uint1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 614 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 616 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 619 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline int2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 620 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 624 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 627 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uint2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 628 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 630 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 633 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline int4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 634 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 638 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 641 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline uint4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 642 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 644 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 647 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 648 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 650 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 653 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned long long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 654 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 659 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline longlong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 660 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 662 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 665 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulonglong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 666 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 668 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 671 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline longlong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 672 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 679 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulonglong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 680 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 682 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 687 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 688 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 690 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 693 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline unsigned long surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 694 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 696 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 699 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 700 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 702 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 705 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulong1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 706 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 708 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 711 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 712 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 716 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 719 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulong2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 720 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 724 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 727 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline long4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 728 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 732 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 735 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline ulong4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 736 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 740 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 745 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline float surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 746 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 748 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 751 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline float1 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 752 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 754 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 757 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline float2 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 758 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 762 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 765 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) static inline float4 surf2Dread(surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode)
# 766 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 770 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 817 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 818 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 819 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 837 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 839 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 840 "/usr/local/cuda/bin/../include/surface_functions.h"
surf1Dwrite(T val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 841 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 843 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 846 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 847 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 849 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 851 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(signed char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 852 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 854 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 856 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned char val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 857 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 859 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 861 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 862 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 864 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 866 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 867 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 869 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 871 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 872 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 876 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 877 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 879 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 881 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(char4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 882 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 884 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 886 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uchar4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 887 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 889 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 891 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 892 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 894 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 896 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned short val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 897 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 899 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 901 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 902 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 904 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 906 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 907 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 909 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 911 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 912 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 914 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 916 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 917 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 919 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 921 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(short4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 922 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 924 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 926 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ushort4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 927 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 929 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 931 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 932 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 934 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 936 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 937 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 939 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 941 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 942 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 946 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 947 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 949 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 951 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 952 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 954 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 956 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 957 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 959 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 961 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(int4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 962 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 964 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 966 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(uint4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 967 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 969 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 971 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 972 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 974 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 976 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned long long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 977 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 979 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 981 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 982 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 984 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 986 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 987 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 989 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 991 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(longlong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 992 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 994 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 996 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulonglong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 997 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 999 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1003 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1004 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1006 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1008 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(unsigned long val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1009 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1011 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1013 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1014 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1016 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1018 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulong1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1019 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1021 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1023 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1024 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1026 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1028 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulong2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1029 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1031 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1033 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(long4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1034 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1036 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1038 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(ulong4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1039 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1041 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1045 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1046 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1048 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1050 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float1 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1051 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1053 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1055 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float2 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1056 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1058 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1060 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf1Dwrite(float4 val, surface< void, 1> surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1061 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1063 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1110 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1111 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1112 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1130 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1132 "/usr/local/cuda/bin/../include/surface_functions.h"
template< class T> __attribute__((unused)) static inline void
# 1133 "/usr/local/cuda/bin/../include/surface_functions.h"
surf2Dwrite(T val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1134 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1136 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1139 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1140 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1142 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1144 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(signed char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1145 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1147 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1149 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned char val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1150 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1154 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1155 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1157 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1159 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1160 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1162 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1164 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1165 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1167 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1169 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1170 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1172 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1174 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(char4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1175 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1177 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1179 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uchar4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1180 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1182 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1184 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1185 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1187 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1189 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned short val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1190 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1192 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1194 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1195 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1197 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1199 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1200 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1202 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1204 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1205 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1207 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1209 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1210 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1212 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1214 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(short4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1215 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1217 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1219 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ushort4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1220 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1222 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1224 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1225 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1227 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1229 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1230 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1232 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1234 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1235 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1237 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1239 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1240 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1242 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1244 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1245 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1247 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1249 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1250 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1254 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(int4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1255 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1257 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1259 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(uint4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1260 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1262 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1264 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1265 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1267 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1269 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned long long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1270 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1272 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1274 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1275 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1277 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1279 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1280 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1282 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1284 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(longlong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1285 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1287 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1289 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulonglong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1290 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1292 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1296 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1297 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1299 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1301 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(unsigned long val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1302 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1304 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1306 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1307 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1309 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1311 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulong1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1312 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1314 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1316 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1317 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1319 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1321 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulong2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1322 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1324 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1326 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(long4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1327 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1329 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1331 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(ulong4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1332 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1334 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1338 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1339 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1341 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1343 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float1 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1344 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1346 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1348 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float2 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1349 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1351 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 1353 "/usr/local/cuda/bin/../include/surface_functions.h"
__attribute__((unused)) static inline void surf2Dwrite(float4 val, surface< void, 2> surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
# 1354 "/usr/local/cuda/bin/../include/surface_functions.h"
{int volatile ___ = 1;
# 1356 "/usr/local/cuda/bin/../include/surface_functions.h"
exit(___);}
# 61 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetchi(texture< T, 1, readMode> , int4);
# 63 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetchi(texture< T, 1, readMode> , int4);
# 65 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetchi(texture< T, 1, readMode> , int4);
# 68 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern uint4 __utexfetch(texture< T, dim, readMode> , float4, int = dim);
# 70 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern int4 __itexfetch(texture< T, dim, readMode> , float4, int = dim);
# 72 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< class T, int dim, cudaTextureReadMode readMode> __attribute__((unused)) extern float4 __ftexfetch(texture< T, dim, readMode> , float4, int = dim);
# 80 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType> t, int x)
# 81 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 89 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 91 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType> t, int x)
# 92 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 96 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 98 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType> t, int x)
# 99 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 103 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 105 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType> t, int x)
# 106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 110 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 112 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType> t, int x)
# 113 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 117 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType> t, int x)
# 120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType> t, int x)
# 127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 131 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType> t, int x)
# 134 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 138 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType> t, int x)
# 141 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 145 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 153 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType> t, int x)
# 154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 158 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 160 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType> t, int x)
# 161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 165 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 167 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType> t, int x)
# 168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 172 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 174 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType> t, int x)
# 175 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 179 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 181 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType> t, int x)
# 182 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 186 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType> t, int x)
# 189 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 193 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType> t, int x)
# 196 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 200 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType> t, int x)
# 203 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 207 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 215 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType> t, int x)
# 216 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 220 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 222 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType> t, int x)
# 223 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 227 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 229 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType> t, int x)
# 230 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 234 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 236 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType> t, int x)
# 237 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 241 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 243 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType> t, int x)
# 244 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 248 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 250 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType> t, int x)
# 251 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 255 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 257 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType> t, int x)
# 258 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 262 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 264 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType> t, int x)
# 265 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 279 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long tex1Dfetch(texture< long, 1, cudaReadModeElementType> t, int x)
# 280 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 284 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 286 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned long tex1Dfetch(texture< unsigned long, 1, cudaReadModeElementType> t, int x)
# 287 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 291 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 293 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long1 tex1Dfetch(texture< long1, 1, cudaReadModeElementType> t, int x)
# 294 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 298 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 300 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong1 tex1Dfetch(texture< ulong1, 1, cudaReadModeElementType> t, int x)
# 301 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 305 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 307 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long2 tex1Dfetch(texture< long2, 1, cudaReadModeElementType> t, int x)
# 308 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 312 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 314 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong2 tex1Dfetch(texture< ulong2, 1, cudaReadModeElementType> t, int x)
# 315 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 319 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 321 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long4 tex1Dfetch(texture< long4, 1, cudaReadModeElementType> t, int x)
# 322 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 326 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 328 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong4 tex1Dfetch(texture< ulong4, 1, cudaReadModeElementType> t, int x)
# 329 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 333 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 343 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType> t, int x)
# 344 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 348 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 350 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType> t, int x)
# 351 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 355 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 357 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType> t, int x)
# 358 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 362 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType> t, int x)
# 365 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 369 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat> t, int x)
# 378 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 387 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 389 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat> t, int x)
# 390 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 395 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 397 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
# 398 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 405 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat> t, int x)
# 406 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 413 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
# 414 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 421 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat> t, int x)
# 422 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 427 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 429 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
# 430 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 435 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 437 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat> t, int x)
# 438 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 443 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 445 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
# 446 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat> t, int x)
# 460 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 467 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
# 468 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 473 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 475 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat> t, int x)
# 476 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 481 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 483 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
# 484 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 489 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat> t, int x)
# 492 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 497 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 499 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
# 500 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 505 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat> t, int x)
# 508 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 515 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
# 516 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 521 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 529 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex1D(texture< char, 1, cudaReadModeElementType> t, float x)
# 530 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 538 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 540 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType> t, float x)
# 541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 545 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 547 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType> t, float x)
# 548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 552 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 554 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex1D(texture< char1, 1, cudaReadModeElementType> t, float x)
# 555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 559 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 561 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType> t, float x)
# 562 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 566 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex1D(texture< char2, 1, cudaReadModeElementType> t, float x)
# 569 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 573 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType> t, float x)
# 576 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 580 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex1D(texture< char4, 1, cudaReadModeElementType> t, float x)
# 583 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 587 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType> t, float x)
# 590 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 594 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 602 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex1D(texture< short, 1, cudaReadModeElementType> t, float x)
# 603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 607 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 609 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType> t, float x)
# 610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 614 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 616 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex1D(texture< short1, 1, cudaReadModeElementType> t, float x)
# 617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 621 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 623 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType> t, float x)
# 624 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 628 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 630 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex1D(texture< short2, 1, cudaReadModeElementType> t, float x)
# 631 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 635 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType> t, float x)
# 638 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 642 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex1D(texture< short4, 1, cudaReadModeElementType> t, float x)
# 645 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 649 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType> t, float x)
# 652 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 656 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 664 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex1D(texture< int, 1, cudaReadModeElementType> t, float x)
# 665 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 669 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 671 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType> t, float x)
# 672 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 676 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 678 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex1D(texture< int1, 1, cudaReadModeElementType> t, float x)
# 679 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 683 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 685 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType> t, float x)
# 686 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 690 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 692 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex1D(texture< int2, 1, cudaReadModeElementType> t, float x)
# 693 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 697 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 699 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType> t, float x)
# 700 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 704 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 706 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex1D(texture< int4, 1, cudaReadModeElementType> t, float x)
# 707 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 711 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 713 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType> t, float x)
# 714 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 734 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long tex1D(texture< long, 1, cudaReadModeElementType> t, float x)
# 735 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 739 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 741 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned long tex1D(texture< unsigned long, 1, cudaReadModeElementType> t, float x)
# 742 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 746 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 748 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long1 tex1D(texture< long1, 1, cudaReadModeElementType> t, float x)
# 749 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 753 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 755 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong1 tex1D(texture< ulong1, 1, cudaReadModeElementType> t, float x)
# 756 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 760 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 762 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long2 tex1D(texture< long2, 1, cudaReadModeElementType> t, float x)
# 763 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 767 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 769 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong2 tex1D(texture< ulong2, 1, cudaReadModeElementType> t, float x)
# 770 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 774 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 776 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long4 tex1D(texture< long4, 1, cudaReadModeElementType> t, float x)
# 777 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 781 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 783 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong4 tex1D(texture< ulong4, 1, cudaReadModeElementType> t, float x)
# 784 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 788 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< float, 1, cudaReadModeElementType> t, float x)
# 799 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 803 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 805 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< float1, 1, cudaReadModeElementType> t, float x)
# 806 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 810 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< float2, 1, cudaReadModeElementType> t, float x)
# 813 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 817 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 819 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< float4, 1, cudaReadModeElementType> t, float x)
# 820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 824 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 832 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat> t, float x)
# 833 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 842 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat> t, float x)
# 845 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 850 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
# 853 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 858 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat> t, float x)
# 861 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 866 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
# 869 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 874 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 876 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat> t, float x)
# 877 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 882 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 884 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
# 885 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 890 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 892 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat> t, float x)
# 893 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 898 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 900 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
# 901 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 906 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 914 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat> t, float x)
# 915 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 920 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 922 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
# 923 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 928 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 930 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat> t, float x)
# 931 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 936 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 938 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
# 939 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 944 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 946 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat> t, float x)
# 947 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 952 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 954 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
# 955 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 960 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 962 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat> t, float x)
# 963 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 968 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 970 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
# 971 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 976 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex2D(texture< char, 2, cudaReadModeElementType> t, float x, float y)
# 985 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 993 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 995 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType> t, float x, float y)
# 996 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1000 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1002 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y)
# 1003 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1007 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1009 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex2D(texture< char1, 2, cudaReadModeElementType> t, float x, float y)
# 1010 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1014 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1016 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y)
# 1017 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1021 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1023 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex2D(texture< char2, 2, cudaReadModeElementType> t, float x, float y)
# 1024 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1028 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y)
# 1031 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1035 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1037 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2D(texture< char4, 2, cudaReadModeElementType> t, float x, float y)
# 1038 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1042 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1044 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y)
# 1045 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1049 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1057 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex2D(texture< short, 2, cudaReadModeElementType> t, float x, float y)
# 1058 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1062 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1064 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y)
# 1065 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1069 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1071 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex2D(texture< short1, 2, cudaReadModeElementType> t, float x, float y)
# 1072 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1076 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1078 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y)
# 1079 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1083 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex2D(texture< short2, 2, cudaReadModeElementType> t, float x, float y)
# 1086 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1090 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y)
# 1093 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1097 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1099 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2D(texture< short4, 2, cudaReadModeElementType> t, float x, float y)
# 1100 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1104 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y)
# 1107 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1111 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex2D(texture< int, 2, cudaReadModeElementType> t, float x, float y)
# 1120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y)
# 1127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1131 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex2D(texture< int1, 2, cudaReadModeElementType> t, float x, float y)
# 1134 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1138 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType> t, float x, float y)
# 1141 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1145 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1147 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex2D(texture< int2, 2, cudaReadModeElementType> t, float x, float y)
# 1148 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1152 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType> t, float x, float y)
# 1155 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1159 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2D(texture< int4, 2, cudaReadModeElementType> t, float x, float y)
# 1162 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1166 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType> t, float x, float y)
# 1169 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1173 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1183 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long tex2D(texture< long, 2, cudaReadModeElementType> t, float x, float y)
# 1184 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1190 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned long tex2D(texture< unsigned long, 2, cudaReadModeElementType> t, float x, float y)
# 1191 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1197 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long1 tex2D(texture< long1, 2, cudaReadModeElementType> t, float x, float y)
# 1198 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1204 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong1 tex2D(texture< ulong1, 2, cudaReadModeElementType> t, float x, float y)
# 1205 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1209 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1211 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long2 tex2D(texture< long2, 2, cudaReadModeElementType> t, float x, float y)
# 1212 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1216 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1218 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong2 tex2D(texture< ulong2, 2, cudaReadModeElementType> t, float x, float y)
# 1219 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1223 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1225 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long4 tex2D(texture< long4, 2, cudaReadModeElementType> t, float x, float y)
# 1226 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1230 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1232 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong4 tex2D(texture< ulong4, 2, cudaReadModeElementType> t, float x, float y)
# 1233 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1237 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1247 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< float, 2, cudaReadModeElementType> t, float x, float y)
# 1248 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1252 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1254 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< float1, 2, cudaReadModeElementType> t, float x, float y)
# 1255 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1259 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1261 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< float2, 2, cudaReadModeElementType> t, float x, float y)
# 1262 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1266 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1268 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< float4, 2, cudaReadModeElementType> t, float x, float y)
# 1269 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1273 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1281 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1282 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1291 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1293 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1294 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1299 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1301 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1302 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1307 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1309 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1310 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1315 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1317 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1318 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1323 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1325 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1326 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1331 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1333 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1334 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1339 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1341 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1342 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1347 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1349 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1350 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1355 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1363 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1369 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1371 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1372 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1379 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1380 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1385 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1387 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1388 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1393 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1395 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1396 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1401 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1404 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1409 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1412 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1417 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
# 1420 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1425 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1433 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char tex3D(texture< char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1434 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1442 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1444 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1445 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1449 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1452 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1456 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1458 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char1 tex3D(texture< char1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1463 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1466 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1470 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char2 tex3D(texture< char2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1473 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1477 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1479 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1480 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1484 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1486 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex3D(texture< char4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1487 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1493 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1494 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1498 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1506 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short tex3D(texture< short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1511 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1514 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1518 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1520 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short1 tex3D(texture< short1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1521 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1525 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1527 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1528 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1532 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1534 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short2 tex3D(texture< short2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1535 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1539 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1542 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1546 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex3D(texture< short4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1549 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1553 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1556 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1560 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int tex3D(texture< int, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1569 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1573 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1576 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1580 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int1 tex3D(texture< int1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1583 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1587 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1590 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1594 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1596 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int2 tex3D(texture< int2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1597 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1601 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1604 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1608 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex3D(texture< int4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1611 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1615 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1618 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1622 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1632 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long tex3D(texture< long, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1633 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1639 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline unsigned long tex3D(texture< unsigned long, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1640 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1646 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long1 tex3D(texture< long1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1647 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1653 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong1 tex3D(texture< ulong1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1654 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1658 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1660 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long2 tex3D(texture< long2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1661 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1665 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1667 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong2 tex3D(texture< ulong2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1668 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1672 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1674 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline long4 tex3D(texture< long4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1675 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1679 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1681 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ulong4 tex3D(texture< ulong4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1682 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1686 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1696 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< float, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1697 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1701 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1703 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< float1, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1704 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1708 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1710 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< float2, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1711 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1715 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1717 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< float4, 3, cudaReadModeElementType> t, float x, float y, float z)
# 1718 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1722 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1730 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1731 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1740 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1742 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1743 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1748 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1750 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1751 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1756 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1758 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1759 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1764 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1766 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1767 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1772 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1774 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1775 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1780 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1782 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1783 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1788 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1790 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1791 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1796 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1799 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1804 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1813 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1818 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1821 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1826 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1828 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1829 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1834 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1836 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1837 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1842 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1845 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1850 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1853 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1858 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1861 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1866 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
# 1869 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1874 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1930 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern int4 __itex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1932 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern uint4 __utex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1934 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template< int comp, class T> __attribute__((unused)) extern float4 __ftex2Dgather(texture< T, 2, cudaReadModeElementType> , float2, int = comp);
# 1954 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1955 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1957 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1959 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< signed char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1960 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1962 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1964 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< unsigned char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1965 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1967 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1969 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1970 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1972 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1974 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1975 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1977 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1979 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1980 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1982 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1985 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1987 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1989 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1990 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1992 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1994 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 1995 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 1997 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 1999 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline char4 tex2Dgather(texture< char4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2000 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2002 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2004 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uchar4 tex2Dgather(texture< uchar4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2005 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2007 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2009 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2010 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2012 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2014 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< unsigned short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2015 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2017 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2019 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2020 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2022 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2024 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2025 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2027 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2029 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2032 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2034 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2035 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2037 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2039 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2040 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2042 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2044 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2045 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2047 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2049 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline short4 tex2Dgather(texture< short4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2050 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2052 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2054 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline ushort4 tex2Dgather(texture< ushort4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2055 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2057 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2059 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2060 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2062 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2064 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< unsigned, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2065 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2067 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2069 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2070 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2072 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2074 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2075 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2077 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2079 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2080 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2082 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2084 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2087 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2089 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2090 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2094 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2095 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2097 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2099 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline int4 tex2Dgather(texture< int4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2100 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2102 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2104 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline uint4 tex2Dgather(texture< uint4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2105 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2107 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2109 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2110 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2112 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2114 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2115 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2117 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2120 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2122 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2124 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2125 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2127 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 2129 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
__attribute__((unused)) static inline float4 tex2Dgather(texture< float4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
# 2130 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
{int volatile ___ = 1;
# 2132 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
exit(___);}
# 53 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const uint3 threadIdx; }
# 55 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const uint3 blockIdx; }
# 57 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const dim3 blockDim; }
# 59 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const dim3 gridDim; }
# 61 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
extern "C" { extern const int warpSize; }
# 106 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 107 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaSetupArgument(T
# 108 "/usr/local/cuda/bin/../include/cuda_runtime.h"
arg, size_t
# 109 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset)
# 111 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 112 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
# 113 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 145 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaEventCreate(cudaEvent_t *
# 146 "/usr/local/cuda/bin/../include/cuda_runtime.h"
event, unsigned
# 147 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 149 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 150 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaEventCreateWithFlags(event, 0);
# 151 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 208 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMallocHost(void **
# 209 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 210 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 211 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 213 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 214 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc(ptr, size, flags);
# 215 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 217 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 218 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostAlloc(T **
# 219 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 220 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 221 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 223 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 224 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostAlloc((void **)((void *)ptr), size, flags);
# 225 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 227 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 228 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaHostGetDevicePointer(T **
# 229 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pDevice, void *
# 230 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pHost, unsigned
# 231 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags)
# 233 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 234 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
# 235 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 237 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 238 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMalloc(T **
# 239 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 240 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size)
# 242 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 243 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMalloc((void **)((void *)devPtr), size);
# 244 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 246 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 247 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocHost(T **
# 248 "/usr/local/cuda/bin/../include/cuda_runtime.h"
ptr, size_t
# 249 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, unsigned
# 250 "/usr/local/cuda/bin/../include/cuda_runtime.h"
flags = (0))
# 252 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 253 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocHost((void **)((void *)ptr), size, flags);
# 254 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 256 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 257 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMallocPitch(T **
# 258 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t *
# 259 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch, size_t
# 260 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 261 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height)
# 263 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 264 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
# 265 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 275 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
# 276 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 277 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 278 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 279 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 280 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 282 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 283 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
# 284 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 286 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 287 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbol(const T &
# 288 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 289 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 290 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 291 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 292 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice)
# 294 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 295 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
# 296 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 298 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 299 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 300 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 301 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 302 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 303 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 304 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 306 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 307 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
# 308 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 310 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 311 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyToSymbolAsync(const T &
# 312 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, const void *
# 313 "/usr/local/cuda/bin/../include/cuda_runtime.h"
src, size_t
# 314 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 315 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 316 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyHostToDevice, cudaStream_t
# 317 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 319 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 320 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
# 321 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 329 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 330 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 331 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 332 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 333 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 334 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 336 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 337 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
# 338 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 340 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 341 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbol(void *
# 342 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 343 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 344 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 345 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 346 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost)
# 348 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 349 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
# 350 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 352 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 353 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, char *
# 354 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 355 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 356 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 357 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 358 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 360 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 361 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
# 362 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 364 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 365 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaMemcpyFromSymbolAsync(void *
# 366 "/usr/local/cuda/bin/../include/cuda_runtime.h"
dst, const T &
# 367 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol, size_t
# 368 "/usr/local/cuda/bin/../include/cuda_runtime.h"
count, size_t
# 369 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset = (0), cudaMemcpyKind
# 370 "/usr/local/cuda/bin/../include/cuda_runtime.h"
kind = cudaMemcpyDeviceToHost, cudaStream_t
# 371 "/usr/local/cuda/bin/../include/cuda_runtime.h"
stream = 0)
# 373 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 374 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
# 375 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 377 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolAddress(void **
# 378 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, char *
# 379 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 381 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 382 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
# 383 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 410 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 411 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolAddress(void **
# 412 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const T &
# 413 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 415 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 416 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
# 417 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 425 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
# 426 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, char *
# 427 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 429 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 430 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)symbol);
# 431 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 458 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 459 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetSymbolSize(size_t *
# 460 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size, const T &
# 461 "/usr/local/cuda/bin/../include/cuda_runtime.h"
symbol)
# 463 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 464 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetSymbolSize(size, (const char *)(&symbol));
# 465 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 507 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 508 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 509 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 510 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 511 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 512 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 513 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 515 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 516 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, &tex, devPtr, &desc, size);
# 517 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 552 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 553 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture(size_t *
# 554 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 555 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 556 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 557 "/usr/local/cuda/bin/../include/cuda_runtime.h"
size = (((2147483647) * 2U) + 1U))
# 559 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 560 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
# 561 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 608 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 609 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 610 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 611 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 612 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, const cudaChannelFormatDesc &
# 613 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc, size_t
# 614 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 615 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 616 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch)
# 618 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 619 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch);
# 620 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 666 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 667 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTexture2D(size_t *
# 668 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 669 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const void *
# 670 "/usr/local/cuda/bin/../include/cuda_runtime.h"
devPtr, size_t
# 671 "/usr/local/cuda/bin/../include/cuda_runtime.h"
width, size_t
# 672 "/usr/local/cuda/bin/../include/cuda_runtime.h"
height, size_t
# 673 "/usr/local/cuda/bin/../include/cuda_runtime.h"
pitch)
# 675 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 676 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTexture2D(offset, &tex, devPtr, &(tex.texture< T, dim, readMode> ::channelDesc), width, height, pitch);
# 677 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 708 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 709 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 710 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 711 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 712 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 714 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 715 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindTextureToArray(&tex, array, &desc);
# 716 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 746 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 747 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindTextureToArray(const texture< T, dim, readMode> &
# 748 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex, const cudaArray *
# 749 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 751 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 752 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 753 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 755 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err;
# 756 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 785 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 786 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaUnbindTexture(const texture< T, dim, readMode> &
# 787 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 789 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 790 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaUnbindTexture(&tex);
# 791 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 825 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
# 826 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaGetTextureAlignmentOffset(size_t *
# 827 "/usr/local/cuda/bin/../include/cuda_runtime.h"
offset, const texture< T, dim, readMode> &
# 828 "/usr/local/cuda/bin/../include/cuda_runtime.h"
tex)
# 830 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 831 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaGetTextureAlignmentOffset(offset, &tex);
# 832 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 886 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 887 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncSetCacheConfig(T *
# 888 "/usr/local/cuda/bin/../include/cuda_runtime.h"
func, cudaFuncCache
# 889 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cacheConfig)
# 891 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 892 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncSetCacheConfig((const char *)func, cacheConfig);
# 893 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 930 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 931 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaLaunch(T *
# 932 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 934 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 935 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaLaunch((const char *)entry);
# 936 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 970 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T> inline cudaError_t
# 971 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaFuncGetAttributes(cudaFuncAttributes *
# 972 "/usr/local/cuda/bin/../include/cuda_runtime.h"
attr, T *
# 973 "/usr/local/cuda/bin/../include/cuda_runtime.h"
entry)
# 975 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 976 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaFuncGetAttributes(attr, (const char *)entry);
# 977 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 999 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1000 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1001 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 1002 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array, const cudaChannelFormatDesc &
# 1003 "/usr/local/cuda/bin/../include/cuda_runtime.h"
desc)
# 1005 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 1006 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return cudaBindSurfaceToArray(&surf, array, &desc);
# 1007 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 1028 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template< class T, int dim> inline cudaError_t
# 1029 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaBindSurfaceToArray(const surface< T, dim> &
# 1030 "/usr/local/cuda/bin/../include/cuda_runtime.h"
surf, const cudaArray *
# 1031 "/usr/local/cuda/bin/../include/cuda_runtime.h"
array)
# 1033 "/usr/local/cuda/bin/../include/cuda_runtime.h"
{
# 1034 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaChannelFormatDesc desc;
# 1035 "/usr/local/cuda/bin/../include/cuda_runtime.h"
cudaError_t err = cudaGetChannelDesc(&desc, array);
# 1037 "/usr/local/cuda/bin/../include/cuda_runtime.h"
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err;
# 1038 "/usr/local/cuda/bin/../include/cuda_runtime.h"
}
# 70 "/usr/include/stdio.h" 3
typedef __darwin_va_list va_list;
# 87 "/usr/include/stdio.h" 3
typedef __darwin_off_t fpos_t;
# 98 "/usr/include/stdio.h" 3
struct __sbuf {
# 99 "/usr/include/stdio.h" 3
unsigned char *_base;
# 100 "/usr/include/stdio.h" 3
int _size;
# 101 "/usr/include/stdio.h" 3
};
# 104 "/usr/include/stdio.h" 3
struct __sFILEX;
# 163 "/usr/include/stdio.h" 3
typedef
# 132 "/usr/include/stdio.h" 3
struct __sFILE {
# 133 "/usr/include/stdio.h" 3
unsigned char *_p;
# 134 "/usr/include/stdio.h" 3
int _r;
# 135 "/usr/include/stdio.h" 3
int _w;
# 136 "/usr/include/stdio.h" 3
short _flags;
# 137 "/usr/include/stdio.h" 3
short _file;
# 138 "/usr/include/stdio.h" 3
__sbuf _bf;
# 139 "/usr/include/stdio.h" 3
int _lbfsize;
# 142 "/usr/include/stdio.h" 3
void *_cookie;
# 143 "/usr/include/stdio.h" 3
int (*_close)(void *);
# 144 "/usr/include/stdio.h" 3
int (*_read)(void *, char *, int);
# 145 "/usr/include/stdio.h" 3
fpos_t (*_seek)(void *, fpos_t, int);
# 146 "/usr/include/stdio.h" 3
int (*_write)(void *, const char *, int);
# 149 "/usr/include/stdio.h" 3
__sbuf _ub;
# 150 "/usr/include/stdio.h" 3
__sFILEX *_extra;
# 151 "/usr/include/stdio.h" 3
int _ur;
# 154 "/usr/include/stdio.h" 3
unsigned char _ubuf[3];
# 155 "/usr/include/stdio.h" 3
unsigned char _nbuf[1];
# 158 "/usr/include/stdio.h" 3
__sbuf _lb;
# 161 "/usr/include/stdio.h" 3
int _blksize;
# 162 "/usr/include/stdio.h" 3
fpos_t _offset;
# 163 "/usr/include/stdio.h" 3
} FILE;
# 167 "/usr/include/stdio.h" 3
extern "C" { extern FILE *__stdinp; }
# 168 "/usr/include/stdio.h" 3
extern "C" { extern FILE *__stdoutp; }
# 169 "/usr/include/stdio.h" 3
extern "C" { extern FILE *__stderrp; }
# 249 "/usr/include/stdio.h" 3
extern "C" void clearerr(FILE *);
# 250 "/usr/include/stdio.h" 3
extern "C" int fclose(FILE *);
# 251 "/usr/include/stdio.h" 3
extern "C" int feof(FILE *);
# 252 "/usr/include/stdio.h" 3
extern "C" int ferror(FILE *);
# 253 "/usr/include/stdio.h" 3
extern "C" int fflush(FILE *);
# 254 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *);
# 255 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *, fpos_t *);
# 256 "/usr/include/stdio.h" 3
extern "C" char *fgets(char *, int, FILE *);
# 260 "/usr/include/stdio.h" 3
extern "C" FILE *fopen(const char *, const char *) __asm__("_fopen$UNIX2003");
# 262 "/usr/include/stdio.h" 3
extern "C" int fprintf(FILE *, const char *, ...);
# 263 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
# 264 "/usr/include/stdio.h" 3
extern "C" int fputs(const char *, FILE *) __asm__("_fputs$UNIX2003");
# 265 "/usr/include/stdio.h" 3
extern "C" size_t fread(void *, size_t, size_t, FILE *);
# 266 "/usr/include/stdio.h" 3
extern "C" FILE *freopen(const char *, const char *, FILE *) __asm__("_freopen$UNIX2003");
# 268 "/usr/include/stdio.h" 3
extern "C" int fscanf(FILE *, const char *, ...);
# 269 "/usr/include/stdio.h" 3
extern "C" int fseek(FILE *, long, int);
# 270 "/usr/include/stdio.h" 3
extern "C" int fsetpos(FILE *, const fpos_t *);
# 271 "/usr/include/stdio.h" 3
extern "C" long ftell(FILE *);
# 272 "/usr/include/stdio.h" 3
extern "C" size_t fwrite(const void *, size_t, size_t, FILE *) __asm__("_fwrite$UNIX2003");
# 273 "/usr/include/stdio.h" 3
extern "C" int getc(FILE *);
# 274 "/usr/include/stdio.h" 3
extern "C" int getchar();
# 275 "/usr/include/stdio.h" 3
extern "C" char *gets(char *);
# 277 "/usr/include/stdio.h" 3
extern "C" { extern const int sys_nerr; }
# 278 "/usr/include/stdio.h" 3
extern "C" { extern const char *const sys_errlist[]; }
# 280 "/usr/include/stdio.h" 3
extern "C" void perror(const char *);
# 281 "/usr/include/stdio.h" 3
extern "C" int printf(const char *, ...);
# 282 "/usr/include/stdio.h" 3
extern "C" int putc(int, FILE *);
# 283 "/usr/include/stdio.h" 3
extern "C" int putchar(int);
# 284 "/usr/include/stdio.h" 3
extern "C" int puts(const char *);
# 285 "/usr/include/stdio.h" 3
extern "C" int remove(const char *);
# 286 "/usr/include/stdio.h" 3
extern "C" int rename(const char *, const char *);
# 287 "/usr/include/stdio.h" 3
extern "C" void rewind(FILE *);
# 288 "/usr/include/stdio.h" 3
extern "C" int scanf(const char *, ...);
# 289 "/usr/include/stdio.h" 3
extern "C" void setbuf(FILE *, char *);
# 290 "/usr/include/stdio.h" 3
extern "C" int setvbuf(FILE *, char *, int, size_t);
# 291 "/usr/include/stdio.h" 3
extern "C" int sprintf(char *, const char *, ...);
# 292 "/usr/include/stdio.h" 3
extern "C" int sscanf(const char *, const char *, ...);
# 293 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile();
# 294 "/usr/include/stdio.h" 3
extern "C" char *tmpnam(char *);
# 295 "/usr/include/stdio.h" 3
extern "C" int ungetc(int, FILE *);
# 296 "/usr/include/stdio.h" 3
extern "C" int vfprintf(FILE *, const char *, va_list);
# 297 "/usr/include/stdio.h" 3
extern "C" int vprintf(const char *, va_list);
# 298 "/usr/include/stdio.h" 3
extern "C" int vsprintf(char *, const char *, va_list);
# 300 "/usr/include/stdio.h" 3
extern "C" int asprintf(char **, const char *, ...);
# 301 "/usr/include/stdio.h" 3
extern "C" int vasprintf(char **, const char *, va_list);
# 312 "/usr/include/stdio.h" 3
extern "C" char *ctermid(char *);
# 314 "/usr/include/stdio.h" 3
extern "C" char *ctermid_r(char *);
# 319 "/usr/include/stdio.h" 3
extern "C" FILE *fdopen(int, const char *) __asm__("_fdopen$UNIX2003");
# 322 "/usr/include/stdio.h" 3
extern "C" char *fgetln(FILE *, size_t *);
# 324 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *);
# 325 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE *);
# 328 "/usr/include/stdio.h" 3
extern "C" const char *fmtcheck(const char *, const char *);
# 329 "/usr/include/stdio.h" 3
extern "C" int fpurge(FILE *);
# 331 "/usr/include/stdio.h" 3
extern "C" int fseeko(FILE *, off_t, int);
# 332 "/usr/include/stdio.h" 3
extern "C" off_t ftello(FILE *);
# 333 "/usr/include/stdio.h" 3
extern "C" int ftrylockfile(FILE *);
# 334 "/usr/include/stdio.h" 3
extern "C" void funlockfile(FILE *);
# 335 "/usr/include/stdio.h" 3
extern "C" int getc_unlocked(FILE *);
# 336 "/usr/include/stdio.h" 3
extern "C" int getchar_unlocked();
# 338 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);
# 340 "/usr/include/stdio.h" 3
extern "C" int pclose(FILE *);
# 344 "/usr/include/stdio.h" 3
extern "C" FILE *popen(const char *, const char *) __asm__("_popen$UNIX2003");
# 346 "/usr/include/stdio.h" 3
extern "C" int putc_unlocked(int, FILE *);
# 347 "/usr/include/stdio.h" 3
extern "C" int putchar_unlocked(int);
# 349 "/usr/include/stdio.h" 3
extern "C" int putw(int, FILE *);
# 350 "/usr/include/stdio.h" 3
extern "C" void setbuffer(FILE *, char *, int);
# 351 "/usr/include/stdio.h" 3
extern "C" int setlinebuf(FILE *);
# 353 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *, size_t, const char *, ...);
# 354 "/usr/include/stdio.h" 3
extern "C" char *tempnam(const char *, const char *) __asm__("_tempnam$UNIX2003");
# 355 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *, const char *, va_list);
# 356 "/usr/include/stdio.h" 3
extern "C" int vscanf(const char *, va_list);
# 357 "/usr/include/stdio.h" 3
extern "C" int vsnprintf(char *, size_t, const char *, va_list);
# 358 "/usr/include/stdio.h" 3
extern "C" int vsscanf(const char *, const char *, va_list);
# 360 "/usr/include/stdio.h" 3
extern "C" FILE *zopen(const char *, const char *, int);
# 369 "/usr/include/stdio.h" 3
extern "C" FILE *funopen(const void *, int (*)(void *, char *, int), int (*)(void *, const char *, int), fpos_t (*)(void *, fpos_t, int), int (*)(void *));
# 384 "/usr/include/stdio.h" 3
extern "C" int __srget(FILE *);
# 385 "/usr/include/stdio.h" 3
extern "C" int __svfscanf(FILE *, const char *, va_list);
# 386 "/usr/include/stdio.h" 3
extern "C" int __swbuf(int, FILE *);
# 395 "/usr/include/stdio.h" 3
static inline int __sputc(int _c, FILE *_p) {
# 396 "/usr/include/stdio.h" 3
if (((--(_p->_w)) >= 0) || (((_p->_w) >= (_p->_lbfsize)) && (((char)_c) != ('\n')))) {
# 397 "/usr/include/stdio.h" 3
return (*((_p->_p)++)) = _c; } else {
# 399 "/usr/include/stdio.h" 3
return __swbuf(_c, _p); }
# 400 "/usr/include/stdio.h" 3
}
# 130 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef unsigned CUdeviceptr; }
# 135 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef int CUdevice; }
# 136 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUctx_st *CUcontext; }
# 137 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUmod_st *CUmodule; }
# 138 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUfunc_st *CUfunction; }
# 139 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUarray_st *CUarray; }
# 140 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUtexref_st *CUtexref; }
# 141 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUsurfref_st *CUsurfref; }
# 142 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef CUevent_st *CUevent; }
# 143 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef CUstream_st *CUstream; }
# 144 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef struct CUgraphicsResource_st *CUgraphicsResource; }
# 148 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 146 "/usr/local/cuda/bin/../include/cuda.h"
struct CUuuid_st {
# 147 "/usr/local/cuda/bin/../include/cuda.h"
char bytes[16];
# 148 "/usr/local/cuda/bin/../include/cuda.h"
} CUuuid; }
# 162 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 153 "/usr/local/cuda/bin/../include/cuda.h"
enum CUctx_flags_enum {
# 154 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_AUTO,
# 155 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_SPIN,
# 156 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_YIELD,
# 157 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_SCHED_MASK,
# 158 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_BLOCKING_SYNC,
# 159 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_MAP_HOST = 8,
# 160 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 161 "/usr/local/cuda/bin/../include/cuda.h"
CU_CTX_FLAGS_MASK = 31
# 162 "/usr/local/cuda/bin/../include/cuda.h"
} CUctx_flags; }
# 171 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 167 "/usr/local/cuda/bin/../include/cuda.h"
enum CUevent_flags_enum {
# 168 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_DEFAULT,
# 169 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_BLOCKING_SYNC,
# 170 "/usr/local/cuda/bin/../include/cuda.h"
CU_EVENT_DISABLE_TIMING
# 171 "/usr/local/cuda/bin/../include/cuda.h"
} CUevent_flags; }
# 185 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 176 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_format_enum {
# 177 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 178 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 179 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 180 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 181 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 182 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 183 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 184 "/usr/local/cuda/bin/../include/cuda.h"
CU_AD_FORMAT_FLOAT = 32
# 185 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_format; }
# 195 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 190 "/usr/local/cuda/bin/../include/cuda.h"
enum CUaddress_mode_enum {
# 191 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 192 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 193 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR,
# 194 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_ADDRESS_MODE_BORDER
# 195 "/usr/local/cuda/bin/../include/cuda.h"
} CUaddress_mode; }
# 203 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 200 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfilter_mode_enum {
# 201 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 202 "/usr/local/cuda/bin/../include/cuda.h"
CU_TR_FILTER_MODE_LINEAR
# 203 "/usr/local/cuda/bin/../include/cuda.h"
} CUfilter_mode; }
# 246 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 208 "/usr/local/cuda/bin/../include/cuda.h"
enum CUdevice_attribute_enum {
# 209 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 210 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 211 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 212 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 213 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 214 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 215 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 216 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 217 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 218 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 219 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 220 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 221 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 222 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 223 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 224 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 225 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 226 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 227 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 228 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 229 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 230 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 231 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 232 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 233 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 234 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 235 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 236 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 237 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH,
# 238 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 239 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES,
# 240 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT,
# 241 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS,
# 242 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_ECC_ENABLED,
# 243 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_BUS_ID,
# 244 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID,
# 245 "/usr/local/cuda/bin/../include/cuda.h"
CU_DEVICE_ATTRIBUTE_TCC_DRIVER
# 246 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevice_attribute; }
# 262 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 251 "/usr/local/cuda/bin/../include/cuda.h"
struct CUdevprop_st {
# 252 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsPerBlock;
# 253 "/usr/local/cuda/bin/../include/cuda.h"
int maxThreadsDim[3];
# 254 "/usr/local/cuda/bin/../include/cuda.h"
int maxGridSize[3];
# 255 "/usr/local/cuda/bin/../include/cuda.h"
int sharedMemPerBlock;
# 256 "/usr/local/cuda/bin/../include/cuda.h"
int totalConstantMemory;
# 257 "/usr/local/cuda/bin/../include/cuda.h"
int SIMDWidth;
# 258 "/usr/local/cuda/bin/../include/cuda.h"
int memPitch;
# 259 "/usr/local/cuda/bin/../include/cuda.h"
int regsPerBlock;
# 260 "/usr/local/cuda/bin/../include/cuda.h"
int clockRate;
# 261 "/usr/local/cuda/bin/../include/cuda.h"
int textureAlign;
# 262 "/usr/local/cuda/bin/../include/cuda.h"
} CUdevprop; }
# 317 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 267 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunction_attribute_enum {
# 273 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 280 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 286 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 291 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 296 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 305 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_PTX_VERSION,
# 314 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_BINARY_VERSION,
# 316 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX
# 317 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunction_attribute; }
# 326 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 322 "/usr/local/cuda/bin/../include/cuda.h"
enum CUfunc_cache_enum {
# 323 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_NONE,
# 324 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_SHARED,
# 325 "/usr/local/cuda/bin/../include/cuda.h"
CU_FUNC_CACHE_PREFER_L1
# 326 "/usr/local/cuda/bin/../include/cuda.h"
} CUfunc_cache; }
# 335 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 331 "/usr/local/cuda/bin/../include/cuda.h"
enum CUmemorytype_enum {
# 332 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 333 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 334 "/usr/local/cuda/bin/../include/cuda.h"
CU_MEMORYTYPE_ARRAY
# 335 "/usr/local/cuda/bin/../include/cuda.h"
} CUmemorytype; }
# 344 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 340 "/usr/local/cuda/bin/../include/cuda.h"
enum CUcomputemode_enum {
# 341 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 342 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE,
# 343 "/usr/local/cuda/bin/../include/cuda.h"
CU_COMPUTEMODE_PROHIBITED
# 344 "/usr/local/cuda/bin/../include/cuda.h"
} CUcomputemode; }
# 436 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 349 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_option_enum {
# 355 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 368 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 375 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_WALL_TIME,
# 383 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 391 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 399 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 407 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 414 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 421 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 427 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_TARGET,
# 434 "/usr/local/cuda/bin/../include/cuda.h"
CU_JIT_FALLBACK_STRATEGY
# 436 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_option; }
# 449 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 441 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_target_enum {
# 443 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_10,
# 444 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_11,
# 445 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_12,
# 446 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_13,
# 447 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_20,
# 448 "/usr/local/cuda/bin/../include/cuda.h"
CU_TARGET_COMPUTE_21
# 449 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_target; }
# 460 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 454 "/usr/local/cuda/bin/../include/cuda.h"
enum CUjit_fallback_enum {
# 456 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_PTX,
# 458 "/usr/local/cuda/bin/../include/cuda.h"
CU_PREFER_BINARY
# 460 "/usr/local/cuda/bin/../include/cuda.h"
} CUjit_fallback; }
# 467 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 465 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 466 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE
# 467 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsRegisterFlags; }
# 476 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 472 "/usr/local/cuda/bin/../include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 473 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 474 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 475 "/usr/local/cuda/bin/../include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 476 "/usr/local/cuda/bin/../include/cuda.h"
} CUgraphicsMapResourceFlags; }
# 488 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 481 "/usr/local/cuda/bin/../include/cuda.h"
enum CUarray_cubemap_face_enum {
# 482 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 483 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 484 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 485 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 486 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 487 "/usr/local/cuda/bin/../include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z
# 488 "/usr/local/cuda/bin/../include/cuda.h"
} CUarray_cubemap_face; }
# 497 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 493 "/usr/local/cuda/bin/../include/cuda.h"
enum CUlimit_enum {
# 494 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_STACK_SIZE,
# 495 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_PRINTF_FIFO_SIZE,
# 496 "/usr/local/cuda/bin/../include/cuda.h"
CU_LIMIT_MALLOC_HEAP_SIZE
# 497 "/usr/local/cuda/bin/../include/cuda.h"
} CUlimit; }
# 728 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 502 "/usr/local/cuda/bin/../include/cuda.h"
enum cudaError_enum {
# 508 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_SUCCESS,
# 514 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 520 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 526 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 531 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 538 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 544 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 551 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 561 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 570 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 575 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 580 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 586 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 591 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 599 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 604 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 609 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 615 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 621 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 627 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_ECC_UNCORRECTABLE,
# 633 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNSUPPORTED_LIMIT,
# 639 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 644 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 649 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
# 654 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
# 659 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_OPERATING_SYSTEM,
# 666 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 673 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 682 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 693 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED = 700,
# 704 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 715 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 721 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 727 "/usr/local/cuda/bin/../include/cuda.h"
CUDA_ERROR_UNKNOWN = 999
# 728 "/usr/local/cuda/bin/../include/cuda.h"
} CUresult; }
# 777 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 756 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY2D_st {
# 757 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 758 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcY;
# 760 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 761 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 762 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 763 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 764 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 766 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 767 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstY;
# 769 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 770 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 771 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 772 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 773 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 775 "/usr/local/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 776 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 777 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY2D; }
# 810 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 782 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_MEMCPY3D_st {
# 783 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcXInBytes;
# 784 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcY;
# 785 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcZ;
# 786 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcLOD;
# 787 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype srcMemoryType;
# 788 "/usr/local/cuda/bin/../include/cuda.h"
const void *srcHost;
# 789 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr srcDevice;
# 790 "/usr/local/cuda/bin/../include/cuda.h"
CUarray srcArray;
# 791 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved0;
# 792 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcPitch;
# 793 "/usr/local/cuda/bin/../include/cuda.h"
size_t srcHeight;
# 795 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstXInBytes;
# 796 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstY;
# 797 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstZ;
# 798 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstLOD;
# 799 "/usr/local/cuda/bin/../include/cuda.h"
CUmemorytype dstMemoryType;
# 800 "/usr/local/cuda/bin/../include/cuda.h"
void *dstHost;
# 801 "/usr/local/cuda/bin/../include/cuda.h"
CUdeviceptr dstDevice;
# 802 "/usr/local/cuda/bin/../include/cuda.h"
CUarray dstArray;
# 803 "/usr/local/cuda/bin/../include/cuda.h"
void *reserved1;
# 804 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstPitch;
# 805 "/usr/local/cuda/bin/../include/cuda.h"
size_t dstHeight;
# 807 "/usr/local/cuda/bin/../include/cuda.h"
size_t WidthInBytes;
# 808 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 809 "/usr/local/cuda/bin/../include/cuda.h"
size_t Depth;
# 810 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_MEMCPY3D; }
# 822 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 815 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY_DESCRIPTOR_st {
# 817 "/usr/local/cuda/bin/../include/cuda.h"
size_t Width;
# 818 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 820 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 821 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 822 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY_DESCRIPTOR; }
# 836 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" { typedef
# 827 "/usr/local/cuda/bin/../include/cuda.h"
struct CUDA_ARRAY3D_DESCRIPTOR_st {
# 829 "/usr/local/cuda/bin/../include/cuda.h"
size_t Width;
# 830 "/usr/local/cuda/bin/../include/cuda.h"
size_t Height;
# 831 "/usr/local/cuda/bin/../include/cuda.h"
size_t Depth;
# 833 "/usr/local/cuda/bin/../include/cuda.h"
CUarray_format Format;
# 834 "/usr/local/cuda/bin/../include/cuda.h"
unsigned NumChannels;
# 835 "/usr/local/cuda/bin/../include/cuda.h"
unsigned Flags;
# 836 "/usr/local/cuda/bin/../include/cuda.h"
} CUDA_ARRAY3D_DESCRIPTOR; }
# 917 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuInit(unsigned);
# 944 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDriverGetVersion(int *);
# 982 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGet(CUdevice *, int);
# 1008 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetCount(int *);
# 1037 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetName(char *, int, CUdevice);
# 1066 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceComputeCapability(int *, int *, CUdevice);
# 1094 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceTotalMem_v2(size_t *, CUdevice);
# 1154 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetProperties(CUdevprop *, CUdevice);
# 1235 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuDeviceGetAttribute(int *, CUdevice_attribute, CUdevice);
# 1333 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxCreate_v2(CUcontext *, unsigned, CUdevice);
# 1367 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDestroy(CUcontext);
# 1403 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxAttach(CUcontext *, unsigned);
# 1435 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxDetach(CUcontext);
# 1473 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPushCurrent(CUcontext);
# 1515 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxPopCurrent(CUcontext *);
# 1545 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetDevice(CUdevice *);
# 1575 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSynchronize();
# 1638 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetLimit(CUlimit, size_t);
# 1673 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetLimit(size_t *, CUlimit);
# 1716 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetCacheConfig(CUfunc_cache *);
# 1766 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxSetCacheConfig(CUfunc_cache);
# 1803 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuCtxGetApiVersion(CUcontext, unsigned *);
# 1851 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoad(CUmodule *, const char *);
# 1885 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadData(CUmodule *, const void *);
# 1963 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadDataEx(CUmodule *, const void *, unsigned, CUjit_option *, void **);
# 2000 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleLoadFatBinary(CUmodule *, const void *);
# 2025 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleUnload(CUmodule);
# 2055 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetFunction(CUfunction *, CUmodule, const char *);
# 2089 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetGlobal_v2(CUdeviceptr *, size_t *, CUmodule, const char *);
# 2123 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetTexRef(CUtexref *, CUmodule, const char *);
# 2154 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuModuleGetSurfRef(CUsurfref *, CUmodule, const char *);
# 2197 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetInfo_v2(size_t *, size_t *);
# 2230 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAlloc_v2(CUdeviceptr *, size_t);
# 2291 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocPitch_v2(CUdeviceptr *, size_t *, size_t, size_t, unsigned);
# 2320 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFree_v2(CUdeviceptr);
# 2353 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemGetAddressRange_v2(CUdeviceptr *, size_t *, CUdeviceptr);
# 2392 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemAllocHost_v2(void **, size_t);
# 2422 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemFreeHost(void *);
# 2494 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostAlloc(void **, size_t, unsigned);
# 2532 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr *, void *, unsigned);
# 2557 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemHostGetFlags(unsigned *, void *);
# 2591 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoD_v2(CUdeviceptr, const void *, size_t);
# 2624 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoH_v2(void *, CUdeviceptr, size_t);
# 2657 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoD_v2(CUdeviceptr, CUdeviceptr, size_t);
# 2691 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoA_v2(CUarray, size_t, CUdeviceptr, size_t);
# 2727 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoD_v2(CUdeviceptr, CUarray, size_t, size_t);
# 2761 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoA_v2(CUarray, size_t, const void *, size_t);
# 2795 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoH_v2(void *, CUarray, size_t, size_t);
# 2833 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoA_v2(CUarray, size_t, CUarray, size_t, size_t);
# 2978 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D *);
# 3121 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D *);
# 3273 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D *);
# 3313 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr, const void *, size_t, CUstream);
# 3353 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoHAsync_v2(void *, CUdeviceptr, size_t, CUstream);
# 3390 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr, CUdeviceptr, size_t, CUstream);
# 3432 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyHtoAAsync_v2(CUarray, size_t, const void *, size_t, CUstream);
# 3474 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpyAtoHAsync_v2(void *, CUarray, size_t, size_t, CUstream);
# 3630 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D *, CUstream);
# 3790 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D *, CUstream);
# 3823 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8_v2(CUdeviceptr, unsigned char, size_t);
# 3856 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16_v2(CUdeviceptr, unsigned short, size_t);
# 3889 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32_v2(CUdeviceptr, unsigned, size_t);
# 3927 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8_v2(CUdeviceptr, size_t, unsigned char, size_t, size_t);
# 3965 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16_v2(CUdeviceptr, size_t, unsigned short, size_t, size_t);
# 4003 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32_v2(CUdeviceptr, size_t, unsigned, size_t, size_t);
# 4040 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD8Async(CUdeviceptr, unsigned char, size_t, CUstream);
# 4077 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD16Async(CUdeviceptr, unsigned short, size_t, CUstream);
# 4113 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD32Async(CUdeviceptr, unsigned, size_t, CUstream);
# 4155 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D8Async(CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream);
# 4197 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D16Async(CUdeviceptr, size_t, unsigned short, size_t, size_t, CUstream);
# 4239 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuMemsetD2D32Async(CUdeviceptr, size_t, unsigned, size_t, size_t, CUstream);
# 4342 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayCreate_v2(CUarray *, const CUDA_ARRAY_DESCRIPTOR *);
# 4375 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR *, CUarray);
# 4406 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArrayDestroy(CUarray);
# 4508 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DCreate_v2(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *);
# 4544 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR *, CUarray);
# 4582 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamCreate(CUstream *, unsigned);
# 4622 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamWaitEvent(CUstream, CUevent, unsigned);
# 4646 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamQuery(CUstream);
# 4671 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamSynchronize(CUstream);
# 4693 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuStreamDestroy(CUstream);
# 4741 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventCreate(CUevent *, unsigned);
# 4777 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventRecord(CUevent, CUstream);
# 4809 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventQuery(CUevent);
# 4843 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventSynchronize(CUevent);
# 4866 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventDestroy(CUevent);
# 4909 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuEventElapsedTime(float *, CUevent, CUevent);
# 4954 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetBlockShape(CUfunction, int, int, int);
# 4985 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetSharedSize(CUfunction, unsigned);
# 5042 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncGetAttribute(int *, CUfunction_attribute, CUfunction);
# 5090 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuFuncSetCacheConfig(CUfunction, CUfunc_cache);
# 5119 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetSize(CUfunction, unsigned);
# 5149 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSeti(CUfunction, int, unsigned);
# 5179 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetf(CUfunction, int, float);
# 5211 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetv(CUfunction, int, void *, unsigned);
# 5245 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunch(CUfunction);
# 5281 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGrid(CUfunction, int, int);
# 5321 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuLaunchGridAsync(CUfunction, int, int, CUstream);
# 5354 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuParamSetTexRef(CUfunction, int, CUtexref);
# 5395 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetArray(CUtexref, CUarray, unsigned);
# 5433 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress_v2(size_t *, CUtexref, CUdeviceptr, size_t);
# 5474 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddress2D_v2(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, size_t);
# 5503 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFormat(CUtexref, CUarray_format, int);
# 5541 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetAddressMode(CUtexref, int, CUaddress_mode);
# 5574 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFilterMode(CUtexref, CUfilter_mode);
# 5606 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefSetFlags(CUtexref, unsigned);
# 5632 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddress_v2(CUdeviceptr *, CUtexref);
# 5658 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetArray(CUarray *, CUtexref);
# 5684 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetAddressMode(CUaddress_mode *, CUtexref, int);
# 5708 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFilterMode(CUfilter_mode *, CUtexref);
# 5734 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFormat(CUarray_format *, int *, CUtexref);
# 5757 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefGetFlags(unsigned *, CUtexref);
# 5791 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefCreate(CUtexref *);
# 5811 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuTexRefDestroy(CUtexref);
# 5849 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefSetArray(CUsurfref, CUarray, unsigned);
# 5870 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuSurfRefGetArray(CUarray *, CUsurfref);
# 5911 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnregisterResource(CUgraphicsResource);
# 5949 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsSubResourceGetMappedArray(CUarray *, CUgraphicsResource, unsigned, unsigned);
# 5983 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr *, size_t *, CUgraphicsResource);
# 6024 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource, unsigned);
# 6062 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsMapResources(unsigned, CUgraphicsResource *, CUstream);
# 6097 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGraphicsUnmapResources(unsigned, CUgraphicsResource *, CUstream);
# 6101 "/usr/local/cuda/bin/../include/cuda.h"
extern "C" CUresult cuGetExportTable(const void **, const CUuuid *);
# 60 "/Developer/GPU Computing/C/common/inc/cutil.h"
enum CUTBoolean {
# 62 "/Developer/GPU Computing/C/common/inc/cutil.h"
CUTFalse,
# 63 "/Developer/GPU Computing/C/common/inc/cutil.h"
CUTTrue
# 64 "/Developer/GPU Computing/C/common/inc/cutil.h"
};
# 72 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" void cutFree(void *);
# 90 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" void cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int);
# 103 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" char *cutFindFilePath(const char *, const char *);
# 118 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFilef(const char *, float **, unsigned *, bool = false);
# 134 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFiled(const char *, double **, unsigned *, bool = false);
# 150 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFilei(const char *, int **, unsigned *, bool = false);
# 165 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFileui(const char *, unsigned **, unsigned *, bool = false);
# 181 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFileb(const char *, char **, unsigned *, bool = false);
# 197 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutReadFileub(const char *, unsigned char **, unsigned *, bool = false);
# 211 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFilef(const char *, const float *, unsigned, const float, bool = false);
# 225 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFiled(const char *, const float *, unsigned, const double, bool = false);
# 237 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFilei(const char *, const int *, unsigned, bool = false);
# 249 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFileui(const char *, const unsigned *, unsigned, bool = false);
# 261 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFileb(const char *, const char *, unsigned, bool = false);
# 273 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false);
# 289 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *);
# 302 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *);
# 316 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *);
# 332 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *);
# 348 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *);
# 363 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutLoadPGMf(const char *, float **, unsigned *, unsigned *);
# 375 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePGMub(const char *, unsigned char *, unsigned, unsigned);
# 387 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePPMub(const char *, unsigned char *, unsigned, unsigned);
# 400 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned);
# 412 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePGMi(const char *, unsigned *, unsigned, unsigned);
# 424 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePGMs(const char *, unsigned short *, unsigned, unsigned);
# 436 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutSavePGMf(const char *, float *, unsigned, unsigned);
# 457 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutCheckCmdLineFlag(const int, const char **, const char *);
# 471 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumenti(const int, const char **, const char *, int *);
# 485 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentf(const int, const char **, const char *, float *);
# 499 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentstr(const int, const char **, const char *, char **);
# 514 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *);
# 528 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutCheckCondition(int, const char *, const int);
# 540 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutComparef(const float *, const float *, const unsigned);
# 553 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutComparei(const int *, const int *, const unsigned);
# 567 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareuit(const unsigned *, const unsigned *, const unsigned, const float, const float);
# 580 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareub(const unsigned char *, const unsigned char *, const unsigned);
# 595 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareubt(const unsigned char *, const unsigned char *, const unsigned, const float, const float);
# 609 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareube(const unsigned char *, const unsigned char *, const unsigned, const float);
# 623 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutComparefe(const float *, const float *, const unsigned, const float);
# 638 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutComparefet(const float *, const float *, const unsigned, const float, const float);
# 653 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutCompareL2fe(const float *, const float *, const unsigned, const float);
# 668 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutComparePPM(const char *, const char *, const float, const float, bool = false);
# 681 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutCreateTimer(unsigned *);
# 690 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutDeleteTimer(unsigned);
# 698 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutStartTimer(const unsigned);
# 706 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutStopTimer(const unsigned);
# 714 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" CUTBoolean cutResetTimer(const unsigned);
# 723 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" float cutGetTimerValue(const unsigned);
# 734 "/Developer/GPU Computing/C/common/inc/cutil.h"
extern "C" float cutGetAverageTimerValue(const unsigned);
# 40 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef unsigned char uint8_t;
# 45 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef unsigned short uint16_t;
# 50 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef unsigned uint32_t;
# 55 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef unsigned long long uint64_t;
# 59 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef int8_t int_least8_t;
# 60 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef int16_t int_least16_t;
# 61 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef int32_t int_least32_t;
# 62 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef int64_t int_least64_t;
# 63 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef uint8_t uint_least8_t;
# 64 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef uint16_t uint_least16_t;
# 65 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef uint32_t uint_least32_t;
# 66 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef uint64_t uint_least64_t;
# 70 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef int8_t int_fast8_t;
# 71 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef int16_t int_fast16_t;
# 72 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef int32_t int_fast32_t;
# 73 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef int64_t int_fast64_t;
# 74 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef uint8_t uint_fast8_t;
# 75 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef uint16_t uint_fast16_t;
# 76 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef uint32_t uint_fast32_t;
# 77 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef uint64_t uint_fast64_t;
# 97 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef long long intmax_t;
# 106 "/usr/lib/gcc/i686-apple-darwin10/4.2.1/include/stdint.h" 3
typedef unsigned long long uintmax_t;
# 268 "/usr/include/inttypes.h" 3
extern "C" intmax_t imaxabs(intmax_t);
# 274 "/usr/include/inttypes.h" 3
extern "C" { typedef
# 271 "/usr/include/inttypes.h" 3
struct {
# 272 "/usr/include/inttypes.h" 3
intmax_t quot;
# 273 "/usr/include/inttypes.h" 3
intmax_t rem;
# 274 "/usr/include/inttypes.h" 3
} imaxdiv_t; }
# 276 "/usr/include/inttypes.h" 3
extern "C" imaxdiv_t imaxdiv(intmax_t, intmax_t);
# 279 "/usr/include/inttypes.h" 3
extern "C" intmax_t strtoimax(const char *, char **, int);
# 280 "/usr/include/inttypes.h" 3
extern "C" uintmax_t strtoumax(const char *, char **, int);
# 290 "/usr/include/inttypes.h" 3
extern "C" intmax_t wcstoimax(const wchar_t *, wchar_t **, int);
# 291 "/usr/include/inttypes.h" 3
extern "C" uintmax_t wcstoumax(const wchar_t *, wchar_t **, int);
# 74 "/usr/include/sys/errno.h" 3
extern "C" int *__error();
# 76 "/usr/include/assert.h" 3
extern "C" void __assert_rtn(const char *, const char *, int, const char *) __attribute__((__noreturn__));
# 77 "/usr/include/assert.h" 3
extern "C" void __eprintf(const char *, const char *, unsigned, const char *) __attribute__((__noreturn__));
# 54 "mtgp32-fast.h"
extern "C" { typedef
# 43 "mtgp32-fast.h"
struct MTGP32_PARAMS_FAST_T {
# 44 "mtgp32-fast.h"
int mexp;
# 45 "mtgp32-fast.h"
int pos;
# 46 "mtgp32-fast.h"
int sh1;
# 47 "mtgp32-fast.h"
int sh2;
# 48 "mtgp32-fast.h"
uint32_t tbl[16];
# 49 "mtgp32-fast.h"
uint32_t tmp_tbl[16];
# 50 "mtgp32-fast.h"
uint32_t flt_tmp_tbl[16];
# 52 "mtgp32-fast.h"
uint32_t mask;
# 53 "mtgp32-fast.h"
unsigned char poly_sha1[21];
# 54 "mtgp32-fast.h"
} mtgp32_params_fast_t; }
# 77 "mtgp32-fast.h"
extern "C" { typedef
# 71 "mtgp32-fast.h"
struct MTGP32_STATUS_FAST_T {
# 72 "mtgp32-fast.h"
int idx;
# 73 "mtgp32-fast.h"
int size;
# 74 "mtgp32-fast.h"
int large_size;
# 75 "mtgp32-fast.h"
int large_mask;
# 76 "mtgp32-fast.h"
uint32_t array[0];
# 77 "mtgp32-fast.h"
} mtgp32_status_fast_t; }
# 86 "mtgp32-fast.h"
extern "C" { typedef
# 83 "mtgp32-fast.h"
struct MTGP32_FAST_T {
# 84 "mtgp32-fast.h"
mtgp32_params_fast_t params;
# 85 "mtgp32-fast.h"
mtgp32_status_fast_t *status;
# 86 "mtgp32-fast.h"
} mtgp32_fast_t; }
# 92 "mtgp32-fast.h"
extern "C" { extern mtgp32_params_fast_t mtgp32_params_fast_11213[128]; }
# 97 "mtgp32-fast.h"
extern "C" { extern mtgp32_params_fast_t mtgp32_params_fast_23209[128]; }
# 102 "mtgp32-fast.h"
extern "C" { extern mtgp32_params_fast_t mtgp32_params_fast_44497[128]; }
# 104 "mtgp32-fast.h"
extern "C" int mtgp32_init(mtgp32_fast_t *, const mtgp32_params_fast_t *, uint32_t);
# 106 "mtgp32-fast.h"
extern "C" void mtgp32_init_state(uint32_t [], const mtgp32_params_fast_t *, uint32_t);
# 108 "mtgp32-fast.h"
extern "C" int mtgp32_init_by_array(mtgp32_fast_t *, const mtgp32_params_fast_t *, uint32_t *, int);
# 111 "mtgp32-fast.h"
extern "C" int mtgp32_init_by_str(mtgp32_fast_t *, const mtgp32_params_fast_t *, char *);
# 114 "mtgp32-fast.h"
extern "C" void mtgp32_free(mtgp32_fast_t *);
# 115 "mtgp32-fast.h"
extern "C" void mtgp32_print_idstring(const mtgp32_fast_t *, FILE *);
# 117 "mtgp32-fast.h"
extern "C" { static inline void mtgp32_do_recursion(uint32_t *, uint32_t, uint32_t, uint32_t, int, int, uint32_t, uint32_t [16]); }
# 121 "mtgp32-fast.h"
extern "C" { static inline void mtgp32_next_state(mtgp32_fast_t *); }
# 122 "mtgp32-fast.h"
extern "C" { static inline uint32_t mtgp32_genrand_uint32(mtgp32_fast_t *); }
# 123 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_genrand_close1_open2(mtgp32_fast_t *); }
# 124 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_genrand_close_open(mtgp32_fast_t *); }
# 125 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_genrand_open_close(mtgp32_fast_t *); }
# 126 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_genrand_open_open(mtgp32_fast_t *); }
# 145 "mtgp32-fast.h"
extern "C" { static inline void mtgp32_do_recursion(uint32_t *r, uint32_t x1, uint32_t
# 146 "mtgp32-fast.h"
x2, uint32_t y, int
# 147 "mtgp32-fast.h"
sh1, int sh2, uint32_t
# 148 "mtgp32-fast.h"
mask, uint32_t tbl[16]) {
# 149 "mtgp32-fast.h"
uint32_t x;
# 151 "mtgp32-fast.h"
x = ((x1 & mask) ^ x2);
# 152 "mtgp32-fast.h"
x ^= (x << sh1);
# 153 "mtgp32-fast.h"
y = (x ^ (y >> sh2));
# 154 "mtgp32-fast.h"
(*r) = (y ^ (tbl[y & (15)]));
# 155 "mtgp32-fast.h"
} }
# 161 "mtgp32-fast.h"
extern "C" { static inline void mtgp32_next_state(mtgp32_fast_t *mtgp32) {
# 162 "mtgp32-fast.h"
uint32_t *array = ((mtgp32->status)->array);
# 163 "mtgp32-fast.h"
int idx;
# 164 "mtgp32-fast.h"
int pos = ((mtgp32->params).pos);
# 165 "mtgp32-fast.h"
int large_size = ((mtgp32->status)->large_size);
# 166 "mtgp32-fast.h"
uint32_t large_mask = ((mtgp32->status)->large_mask);
# 167 "mtgp32-fast.h"
int size = ((mtgp32->status)->size);
# 169 "mtgp32-fast.h"
((mtgp32->status)->idx) = ((((mtgp32->status)->idx) + 1) & large_mask);
# 170 "mtgp32-fast.h"
idx = ((mtgp32->status)->idx);
# 171 "mtgp32-fast.h"
mtgp32_do_recursion(&(array[idx]), array[((idx - size) + large_size) & large_mask], array[(((idx - size) + large_size) + 1) & large_mask], array[(((idx + pos) - size) + large_size) & large_mask], (mtgp32->params).sh1, (mtgp32->params).sh2, (mtgp32->params).mask, (mtgp32->params).tbl);
# 179 "mtgp32-fast.h"
} }
# 188 "mtgp32-fast.h"
extern "C" { static inline uint32_t mtgp32_temper(const uint32_t tmp_tbl[16], uint32_t
# 189 "mtgp32-fast.h"
r, uint32_t t) {
# 190 "mtgp32-fast.h"
t ^= (t >> 16);
# 191 "mtgp32-fast.h"
t ^= (t >> 8);
# 192 "mtgp32-fast.h"
r ^= (tmp_tbl[t & (15)]);
# 193 "mtgp32-fast.h"
return r;
# 194 "mtgp32-fast.h"
} }
# 203 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_temper_float(const uint32_t flt_tmp_tbl[16], uint32_t
# 204 "mtgp32-fast.h"
r, uint32_t t) {
# 205 "mtgp32-fast.h"
union {
# 206 "mtgp32-fast.h"
uint32_t u;
# 207 "mtgp32-fast.h"
float f;
# 208 "mtgp32-fast.h"
} x;
# 209 "mtgp32-fast.h"
t ^= (t >> 16);
# 210 "mtgp32-fast.h"
t ^= (t >> 8);
# 211 "mtgp32-fast.h"
r = (r >> 9);
# 212 "mtgp32-fast.h"
(x.u) = (r ^ (flt_tmp_tbl[t & (15)]));
# 213 "mtgp32-fast.h"
return x.f;
# 214 "mtgp32-fast.h"
} }
# 224 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_temper_float_open(const uint32_t flt_tmp_tbl[16], uint32_t
# 225 "mtgp32-fast.h"
r, uint32_t t) {
# 226 "mtgp32-fast.h"
union {
# 227 "mtgp32-fast.h"
uint32_t u;
# 228 "mtgp32-fast.h"
float f;
# 229 "mtgp32-fast.h"
} x;
# 230 "mtgp32-fast.h"
t ^= (t >> 16);
# 231 "mtgp32-fast.h"
t ^= (t >> 8);
# 232 "mtgp32-fast.h"
r = (r >> 9);
# 233 "mtgp32-fast.h"
(x.u) = ((r ^ (flt_tmp_tbl[t & (15)])) | (1));
# 234 "mtgp32-fast.h"
return x.f;
# 235 "mtgp32-fast.h"
} }
# 248 "mtgp32-fast.h"
extern "C" { static inline uint32_t mtgp32_genrand_uint32(mtgp32_fast_t *mtgp32) {
# 249 "mtgp32-fast.h"
int idx;
# 250 "mtgp32-fast.h"
uint32_t *tmp_tbl = ((mtgp32->params).tmp_tbl);
# 251 "mtgp32-fast.h"
uint32_t *array = ((mtgp32->status)->array);
# 252 "mtgp32-fast.h"
int pos = ((mtgp32->params).pos);
# 253 "mtgp32-fast.h"
int large_size = ((mtgp32->status)->large_size);
# 254 "mtgp32-fast.h"
int size = ((mtgp32->status)->size);
# 255 "mtgp32-fast.h"
uint32_t large_mask = ((mtgp32->status)->large_mask);
# 257 "mtgp32-fast.h"
mtgp32_next_state(mtgp32);
# 258 "mtgp32-fast.h"
idx = ((mtgp32->status)->idx);
# 259 "mtgp32-fast.h"
return mtgp32_temper(tmp_tbl, array[idx], array[((((idx + pos) - 1) - size) + large_size) & large_mask]);
# 263 "mtgp32-fast.h"
} }
# 274 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_genrand_close1_open2(mtgp32_fast_t *mtgp32) {
# 275 "mtgp32-fast.h"
int idx;
# 276 "mtgp32-fast.h"
uint32_t *flt_tmp_tbl = ((mtgp32->params).flt_tmp_tbl);
# 277 "mtgp32-fast.h"
uint32_t *array = ((mtgp32->status)->array);
# 278 "mtgp32-fast.h"
int pos = ((mtgp32->params).pos);
# 279 "mtgp32-fast.h"
int large_size = ((mtgp32->status)->large_size);
# 280 "mtgp32-fast.h"
int size = ((mtgp32->status)->size);
# 281 "mtgp32-fast.h"
uint32_t large_mask = ((mtgp32->status)->large_mask);
# 283 "mtgp32-fast.h"
mtgp32_next_state(mtgp32);
# 284 "mtgp32-fast.h"
idx = ((mtgp32->status)->idx);
# 285 "mtgp32-fast.h"
return mtgp32_temper_float(flt_tmp_tbl, array[idx], array[((((idx + pos) - 1) - size) + large_size) & large_mask]);
# 289 "mtgp32-fast.h"
} }
# 300 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_genrand_close_open(mtgp32_fast_t *mtgp32) {
# 301 "mtgp32-fast.h"
return mtgp32_genrand_close1_open2(mtgp32) - (1.0F);
# 302 "mtgp32-fast.h"
} }
# 313 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_genrand_open_close(mtgp32_fast_t *mtgp32) {
# 314 "mtgp32-fast.h"
return (2.0F) - mtgp32_genrand_close1_open2(mtgp32);
# 315 "mtgp32-fast.h"
} }
# 326 "mtgp32-fast.h"
extern "C" { static inline float mtgp32_genrand_open_open(mtgp32_fast_t *mtgp32) {
# 327 "mtgp32-fast.h"
float r;
# 328 "mtgp32-fast.h"
int idx;
# 329 "mtgp32-fast.h"
uint32_t *flt_tmp_tbl = ((mtgp32->params).flt_tmp_tbl);
# 330 "mtgp32-fast.h"
uint32_t *array = ((mtgp32->status)->array);
# 331 "mtgp32-fast.h"
int pos = ((mtgp32->params).pos);
# 332 "mtgp32-fast.h"
int large_size = ((mtgp32->status)->large_size);
# 333 "mtgp32-fast.h"
int size = ((mtgp32->status)->size);
# 334 "mtgp32-fast.h"
uint32_t large_mask = ((mtgp32->status)->large_mask);
# 335 "mtgp32-fast.h"
mtgp32_next_state(mtgp32);
# 336 "mtgp32-fast.h"
idx = ((mtgp32->status)->idx);
# 337 "mtgp32-fast.h"
r = mtgp32_temper_float_open(flt_tmp_tbl, array[idx], array[((((idx + pos) - 1) - size) + large_size) & large_mask]);
# 341 "mtgp32-fast.h"
return r - (1.0F);
# 342 "mtgp32-fast.h"
} }
# 37 "mtgp-cuda-common.h"
extern mtgp32_params_fast_t mtgp32dc_params_fast_11213[];
# 45 "mtgp-cuda-common.h"
struct mtgp32_kernel_status_t {
# 46 "mtgp-cuda-common.h"
uint32_t status[351];
# 47 "mtgp-cuda-common.h"
};
# 54 "mtgp-cuda-common.h"
void make_constant_param(const mtgp32_params_fast_t [], int);
# 63 "mtgp-cuda-common.h"
void make_texture(const mtgp32_params_fast_t [], uint32_t *[3], int);
# 68 "mtgp-cuda-common.h"
int get_suitable_block_num(int, int, int);
# 76 "mtgp-cuda-common.h"
void make_kernel_data(mtgp32_kernel_status_t *, mtgp32_params_fast_t [], int);
# 26 "mtgp32-cuda-hostCalled.h"
__attribute__((unused)) inline void status_read(uint32_t status[(256 * 3)], const mtgp32_kernel_status_t *
# 27 "mtgp32-cuda-hostCalled.h"
d_status, int
# 28 "mtgp32-cuda-hostCalled.h"
bid, int
# 29 "mtgp32-cuda-hostCalled.h"
tid) {int volatile ___ = 1;
# 36 "mtgp32-cuda-hostCalled.h"
exit(___);}
# 47 "mtgp32-cuda-hostCalled.h"
__attribute__((unused)) inline void status_write(mtgp32_kernel_status_t *d_status, const uint32_t
# 48 "mtgp32-cuda-hostCalled.h"
status[(256 * 3)], int
# 49 "mtgp32-cuda-hostCalled.h"
bid, int
# 50 "mtgp32-cuda-hostCalled.h"
tid) {int volatile ___ = 1;
# 58 "mtgp32-cuda-hostCalled.h"
exit(___);}
# 19 "mtgp32-cuda-cuterandAPI.h"
static uint32_t param_tbl[200][16];
# 20 "mtgp32-cuda-cuterandAPI.h"
static uint32_t temper_tbl[200][16];
# 21 "mtgp32-cuda-cuterandAPI.h"
static uint32_t single_temper_tbl[200][16];
# 22 "mtgp32-cuda-cuterandAPI.h"
static uint32_t pos_tbl[200];
# 23 "mtgp32-cuda-cuterandAPI.h"
static uint32_t sh1_tbl[200];
# 24 "mtgp32-cuda-cuterandAPI.h"
static uint32_t sh2_tbl[200];
# 31 "mtgp32-cuda-cuterandAPI.h"
static uint32_t mask;
# 37 "mtgp32-cuda-cuterandAPI.h"
__attribute__((unused)) static uint32_t status[(256 * 3)];
# 43 "mtgp32-cuda-cuterandAPI.h"
__attribute__((unused)) static uint32_t step[1024];
# 52 "mtgp32-cuda-cuterandAPI.h"
void make_constant(const mtgp32_params_fast_t [], int);
# 64 "mtgp32-cuda-cuterandAPI.h"
__attribute__((unused)) inline uint32_t para_rec(uint32_t X1, uint32_t X2, uint32_t Y, int bid) {int volatile ___ = 1;
# 72 "mtgp32-cuda-cuterandAPI.h"
exit(___);}
# 82 "mtgp32-cuda-cuterandAPI.h"
__attribute__((unused)) inline uint32_t temper(uint32_t V, uint32_t T, int bid) {int volatile ___ = 1;
# 89 "mtgp32-cuda-cuterandAPI.h"
exit(___);}
# 102 "mtgp32-cuda-cuterandAPI.h"
__attribute__((unused)) inline void mtgp32_init_shared_memory(mtgp32_kernel_status_t *d_status) {int volatile ___ = 1;
# 123 "mtgp32-cuda-cuterandAPI.h"
exit(___);}
# 134 "mtgp32-cuda-cuterandAPI.h"
__attribute__((unused)) inline uint32_t mtgp32_uint32_device() {int volatile ___ = 1;
# 193 "mtgp32-cuda-cuterandAPI.h"
exit(___);}
# 44 "mtgp32-cuda-cuterandAPI.cu"
void make_constant(const mtgp32_params_fast_t params[], int
# 45 "mtgp32-cuda-cuterandAPI.cu"
block_num) {
# 46 "mtgp32-cuda-cuterandAPI.cu"
const int size1 = (sizeof(uint32_t) * block_num);
# 47 "mtgp32-cuda-cuterandAPI.cu"
const int size2 = ((sizeof(uint32_t) * block_num) * (16));
# 48 "mtgp32-cuda-cuterandAPI.cu"
uint32_t *h_pos_tbl;
# 49 "mtgp32-cuda-cuterandAPI.cu"
uint32_t *h_sh1_tbl;
# 50 "mtgp32-cuda-cuterandAPI.cu"
uint32_t *h_sh2_tbl;
# 51 "mtgp32-cuda-cuterandAPI.cu"
uint32_t *h_param_tbl;
# 52 "mtgp32-cuda-cuterandAPI.cu"
uint32_t *h_temper_tbl;
# 53 "mtgp32-cuda-cuterandAPI.cu"
uint32_t *h_single_temper_tbl;
# 57 "mtgp32-cuda-cuterandAPI.cu"
h_pos_tbl = ((uint32_t *)malloc(size1));
# 58 "mtgp32-cuda-cuterandAPI.cu"
h_sh1_tbl = ((uint32_t *)malloc(size1));
# 59 "mtgp32-cuda-cuterandAPI.cu"
h_sh2_tbl = ((uint32_t *)malloc(size1));
# 60 "mtgp32-cuda-cuterandAPI.cu"
h_param_tbl = ((uint32_t *)malloc(size2));
# 61 "mtgp32-cuda-cuterandAPI.cu"
h_temper_tbl = ((uint32_t *)malloc(size2));
# 62 "mtgp32-cuda-cuterandAPI.cu"
h_single_temper_tbl = ((uint32_t *)malloc(size2));
# 66 "mtgp32-cuda-cuterandAPI.cu"
if ((((((h_pos_tbl == (__null)) || (h_sh1_tbl == (__null))) || (h_sh2_tbl == (__null))) || (h_param_tbl == (__null))) || (h_temper_tbl == (__null))) || (h_single_temper_tbl == (__null)))
# 75 "mtgp32-cuda-cuterandAPI.cu"
{
# 76 "mtgp32-cuda-cuterandAPI.cu"
printf("failure in allocating host memory for constant table.\n");
# 77 "mtgp32-cuda-cuterandAPI.cu"
exit(1);
# 78 "mtgp32-cuda-cuterandAPI.cu"
}
# 82 "mtgp32-cuda-cuterandAPI.cu"
for (int i = 0; i < block_num; i++) {
# 83 "mtgp32-cuda-cuterandAPI.cu"
(h_pos_tbl[i]) = ((params[i]).pos);
# 84 "mtgp32-cuda-cuterandAPI.cu"
(h_sh1_tbl[i]) = ((params[i]).sh1);
# 85 "mtgp32-cuda-cuterandAPI.cu"
(h_sh2_tbl[i]) = ((params[i]).sh2);
# 86 "mtgp32-cuda-cuterandAPI.cu"
for (int j = 0; j < 16; j++) {
# 87 "mtgp32-cuda-cuterandAPI.cu"
(h_param_tbl[(i * 16) + j]) = (((params[i]).tbl)[j]);
# 88 "mtgp32-cuda-cuterandAPI.cu"
(h_temper_tbl[(i * 16) + j]) = (((params[i]).tmp_tbl)[j]);
# 89 "mtgp32-cuda-cuterandAPI.cu"
(h_single_temper_tbl[(i * 16) + j]) = (((params[i]).flt_tmp_tbl)[j]);
# 90 "mtgp32-cuda-cuterandAPI.cu"
}
# 91 "mtgp32-cuda-cuterandAPI.cu"
}
# 93 "mtgp32-cuda-cuterandAPI.cu"
{ cudaError err = cudaMemcpyToSymbol(pos_tbl, h_pos_tbl, size1); if ((cudaSuccess) != err) { fprintf(__stderrp, "Cuda error in file \'%s\' in line %i : %s.\n", "mtgp32-cuda-cuterandAPI.cu", 93, cudaGetErrorString(err)); exit(1); } } ; ;
# 94 "mtgp32-cuda-cuterandAPI.cu"
{ cudaError err = cudaMemcpyToSymbol(sh1_tbl, h_sh1_tbl, size1); if ((cudaSuccess) != err) { fprintf(__stderrp, "Cuda error in file \'%s\' in line %i : %s.\n", "mtgp32-cuda-cuterandAPI.cu", 94, cudaGetErrorString(err)); exit(1); } } ; ;
# 95 "mtgp32-cuda-cuterandAPI.cu"
{ cudaError err = cudaMemcpyToSymbol(sh2_tbl, h_sh2_tbl, size1); if ((cudaSuccess) != err) { fprintf(__stderrp, "Cuda error in file \'%s\' in line %i : %s.\n", "mtgp32-cuda-cuterandAPI.cu", 95, cudaGetErrorString(err)); exit(1); } } ; ;
# 96 "mtgp32-cuda-cuterandAPI.cu"
{ cudaError err = cudaMemcpyToSymbol(param_tbl, h_param_tbl, size2); if ((cudaSuccess) != err) { fprintf(__stderrp, "Cuda error in file \'%s\' in line %i : %s.\n", "mtgp32-cuda-cuterandAPI.cu", 96, cudaGetErrorString(err)); exit(1); } } ; ;
# 97 "mtgp32-cuda-cuterandAPI.cu"
{ cudaError err = cudaMemcpyToSymbol(temper_tbl, h_temper_tbl, size2); if ((cudaSuccess) != err) { fprintf(__stderrp, "Cuda error in file \'%s\' in line %i : %s.\n", "mtgp32-cuda-cuterandAPI.cu", 97, cudaGetErrorString(err)); exit(1); } } ; ;
# 98 "mtgp32-cuda-cuterandAPI.cu"
{ cudaError err = cudaMemcpyToSymbol(single_temper_tbl, h_single_temper_tbl, size2); if ((cudaSuccess) != err) { fprintf(__stderrp, "Cuda error in file \'%s\' in line %i : %s.\n", "mtgp32-cuda-cuterandAPI.cu", 99, cudaGetErrorString(err)); exit(1); } } ; ;
# 104 "mtgp32-cuda-cuterandAPI.cu"
free(h_pos_tbl);
# 105 "mtgp32-cuda-cuterandAPI.cu"
free(h_sh1_tbl);
# 106 "mtgp32-cuda-cuterandAPI.cu"
free(h_sh2_tbl);
# 107 "mtgp32-cuda-cuterandAPI.cu"
free(h_param_tbl);
# 108 "mtgp32-cuda-cuterandAPI.cu"
free(h_temper_tbl);
# 109 "mtgp32-cuda-cuterandAPI.cu"
free(h_single_temper_tbl);
# 113 "mtgp32-cuda-cuterandAPI.cu"
}
# 1 "/tmp/tmpxft_00000cb2_00000000-1_mtgp32-cuda-cuterandAPI.cudafe1.stub.c"
# 1 "/tmp/tmpxft_00000cb2_00000000-1_mtgp32-cuda-cuterandAPI.cudafe1.stub.c" 1
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1
# 91 "/usr/local/cuda/bin/../include/crt/host_runtime.h"
extern "C" {

extern void** __cudaRegisterFatBinary(
  void *fatCubin
);

extern void __cudaUnregisterFatBinary(
  void **fatCubinHandle
);

extern void __cudaRegisterVar(
        void **fatCubinHandle,
        char *hostVar,
        char *deviceAddress,
  const char *deviceName,
        int ext,
        int size,
        int constant,
        int global
);

extern void __cudaRegisterTexture(
        void **fatCubinHandle,
  const struct textureReference *hostVar,
  const void **deviceAddress,
  const char *deviceName,
        int dim,
        int norm,
        int ext
);

extern void __cudaRegisterSurface(
        void **fatCubinHandle,
  const struct surfaceReference *hostVar,
  const void **deviceAddress,
  const char *deviceName,
        int dim,
        int ext
);

extern void __cudaRegisterFunction(
        void **fatCubinHandle,
  const char *hostFun,
        char *deviceFun,
  const char *deviceName,
        int thread_limit,
        uint3 *tid,
        uint3 *bid,
        dim3 *bDim,
        dim3 *gDim,
        int *wSize
);



extern int atexit(void(*)(void)) throw();







}

static void **__cudaFatCubinHandle;

static void __cudaUnregisterBinaryUtil(void)
{
  __cudaUnregisterFatBinary(__cudaFatCubinHandle);
}

# 1 "/usr/local/cuda/bin/../include/common_functions.h" 1
# 90 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 948 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 949 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 2973 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 2974 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 2983 "/usr/local/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak_import__, __weak__)) double exp10(double a); double exp10(double a)
{
  return pow(10.0, a);
}

extern __attribute__((__weak_import__, __weak__)) float exp10f(float a); float exp10f(float a)
{
    return (float)exp10((double)a);
}

extern __attribute__((__weak_import__, __weak__)) void sincos(double a, double *sptr, double *cptr); void sincos(double a, double *sptr, double *cptr)
{
  *sptr = sin(a);
  *cptr = cos(a);
}

extern __attribute__((__weak_import__, __weak__)) void sincosf(float a, float *sptr, float *cptr); void sincosf(float a, float *sptr, float *cptr)
{
  double s, c;

  sincos((double)a, &s, &c);
  *sptr = (float)s;
  *cptr = (float)c;
}

extern __attribute__((__weak_import__, __weak__)) int __isnan(double a); int __isnan(double a)
{
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;

  cvt.d = a;

  return cvt.l << 1 > 0xffe0000000000000ull;
}

extern __attribute__((__weak_import__, __weak__)) int __isinf(double a); int __isinf(double a)
{
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;

  cvt.d = a;

  return cvt.l << 1 == 0xffe0000000000000ull;
}
# 4683 "/usr/local/cuda/bin/../include/math_functions.h" 3
extern __attribute__((__weak_import__, __weak__)) double rsqrt(double a); double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

extern __attribute__((__weak_import__, __weak__)) double rcbrt(double a); double rcbrt(double a)
{
  double s, t;

  if (__isnan(a)) {
    return a + a;
  }
  if (a == 0.0 || __isinf(a)) {
    return 1.0 / a;
  }
  s = fabs(a);
  t = exp2(-3.3333333333333333e-1 * log2(s));
  t = ((t*t) * (-s*t) + 1.0) * (3.3333333333333333e-1*t) + t;

  if (__signbitd(a))



  {
    t = -t;
  }
  return t;
}

extern __attribute__((__weak_import__, __weak__)) double sinpi(double a); double sinpi(double a)
{
  int n;

  if (__isnan(a)) {
    return a + a;
  }
  if (a == 0.0 || __isinf(a)) {
    return sin (a);
  }
  if (a == floor(a)) {
    return ((a / 1.0e308) / 1.0e308) / 1.0e308;
  }
  a = remquo (a, 0.5, &n);
  a = a * 3.1415926535897931e+0;
  if (n & 1) {
    a = cos (a);
  } else {
    a = sin (a);
  }
  if (n & 2) {
    a = -a;
  }
  return a;
}

extern __attribute__((__weak_import__, __weak__)) double erfinv(double a); double erfinv(double a)
{
  double p, q, t, fa;
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;

  fa = fabs(a);
  if (fa >= 1.0) {
    cvt.l = 0xfff8000000000000ull;
    t = cvt.d;
    if (fa == 1.0) {
      t = a * exp(1000.0);
    }
  } else if (fa >= 0.9375) {




    t = log1p(-fa);
    t = 1.0 / sqrt(-t);
    p = 2.7834010353747001060e-3;
    p = p * t + 8.6030097526280260580e-1;
    p = p * t + 2.1371214997265515515e+0;
    p = p * t + 3.1598519601132090206e+0;
    p = p * t + 3.5780402569085996758e+0;
    p = p * t + 1.5335297523989890804e+0;
    p = p * t + 3.4839207139657522572e-1;
    p = p * t + 5.3644861147153648366e-2;
    p = p * t + 4.3836709877126095665e-3;
    p = p * t + 1.3858518113496718808e-4;
    p = p * t + 1.1738352509991666680e-6;
    q = t + 2.2859981272422905412e+0;
    q = q * t + 4.3859045256449554654e+0;
    q = q * t + 4.6632960348736635331e+0;
    q = q * t + 3.9846608184671757296e+0;
    q = q * t + 1.6068377709719017609e+0;
    q = q * t + 3.5609087305900265560e-1;
    q = q * t + 5.3963550303200816744e-2;
    q = q * t + 4.3873424022706935023e-3;
    q = q * t + 1.3858762165532246059e-4;
    q = q * t + 1.1738313872397777529e-6;
    t = p / (q * t);
    if (a < 0.0) t = -t;
  } else if (fa >= 0.75) {




    t = a * a - .87890625;
    p = .21489185007307062000e+0;
    p = p * t - .64200071507209448655e+1;
    p = p * t + .29631331505876308123e+2;
    p = p * t - .47644367129787181803e+2;
    p = p * t + .34810057749357500873e+2;
    p = p * t - .12954198980646771502e+2;
    p = p * t + .25349389220714893917e+1;
    p = p * t - .24758242362823355486e+0;
    p = p * t + .94897362808681080020e-2;
    q = t - .12831383833953226499e+2;
    q = q * t + .41409991778428888716e+2;
    q = q * t - .53715373448862143349e+2;
    q = q * t + .33880176779595142685e+2;
    q = q * t - .11315360624238054876e+2;
    q = q * t + .20369295047216351160e+1;
    q = q * t - .18611650627372178511e+0;
    q = q * t + .67544512778850945940e-2;
    p = p / q;
    t = a * p;
  } else {




    t = a * a - .5625;
    p = - .23886240104308755900e+2;
    p = p * t + .45560204272689128170e+3;
    p = p * t - .22977467176607144887e+4;
    p = p * t + .46631433533434331287e+4;
    p = p * t - .43799652308386926161e+4;
    p = p * t + .19007153590528134753e+4;
    p = p * t - .30786872642313695280e+3;
    q = t - .83288327901936570000e+2;
    q = q * t + .92741319160935318800e+3;
    q = q * t - .35088976383877264098e+4;
    q = q * t + .59039348134843665626e+4;
    q = q * t - .48481635430048872102e+4;
    q = q * t + .18997769186453057810e+4;
    q = q * t - .28386514725366621129e+3;
    p = p / q;
    t = a * p;
  }
  return t;
}

extern __attribute__((__weak_import__, __weak__)) double erfcinv(double a); double erfcinv(double a)
{
  double t;
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;

  if (__isnan(a)) {
    return a + a;
  }
  if (a <= 0.0) {
    cvt.l = 0xfff8000000000000ull;
    t = cvt.d;
    if (a == 0.0) {
        t = (1.0 - a) * exp(1000.0);
    }
  }
  else if (a >= 0.0625) {
    t = erfinv (1.0 - a);
  }
  else if (a >= 1e-100) {




    double p, q;
    t = log(a);
    t = 1.0 / sqrt(-t);
    p = 2.7834010353747001060e-3;
    p = p * t + 8.6030097526280260580e-1;
    p = p * t + 2.1371214997265515515e+0;
    p = p * t + 3.1598519601132090206e+0;
    p = p * t + 3.5780402569085996758e+0;
    p = p * t + 1.5335297523989890804e+0;
    p = p * t + 3.4839207139657522572e-1;
    p = p * t + 5.3644861147153648366e-2;
    p = p * t + 4.3836709877126095665e-3;
    p = p * t + 1.3858518113496718808e-4;
    p = p * t + 1.1738352509991666680e-6;
    q = t + 2.2859981272422905412e+0;
    q = q * t + 4.3859045256449554654e+0;
    q = q * t + 4.6632960348736635331e+0;
    q = q * t + 3.9846608184671757296e+0;
    q = q * t + 1.6068377709719017609e+0;
    q = q * t + 3.5609087305900265560e-1;
    q = q * t + 5.3963550303200816744e-2;
    q = q * t + 4.3873424022706935023e-3;
    q = q * t + 1.3858762165532246059e-4;
    q = q * t + 1.1738313872397777529e-6;
    t = p / (q * t);
  }
  else {




    double p, q;
    t = log(a);
    t = 1.0 / sqrt(-t);
    p = 6.9952990607058154858e-1;
    p = p * t + 1.9507620287580568829e+0;
    p = p * t + 8.2810030904462690216e-1;
    p = p * t + 1.1279046353630280005e-1;
    p = p * t + 6.0537914739162189689e-3;
    p = p * t + 1.3714329569665128933e-4;
    p = p * t + 1.2964481560643197452e-6;
    p = p * t + 4.6156006321345332510e-9;
    p = p * t + 4.5344689563209398450e-12;
    q = t + 1.5771922386662040546e+0;
    q = q * t + 2.1238242087454993542e+0;
    q = q * t + 8.4001814918178042919e-1;
    q = q * t + 1.1311889334355782065e-1;
    q = q * t + 6.0574830550097140404e-3;
    q = q * t + 1.3715891988350205065e-4;
    q = q * t + 1.2964671850944981713e-6;
    q = q * t + 4.6156017600933592558e-9;
    q = q * t + 4.5344687377088206783e-12;
    t = p / (q * t);
  }
  return t;
}

extern __attribute__((__weak_import__, __weak__)) float rsqrtf(float a); float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}

extern __attribute__((__weak_import__, __weak__)) float rcbrtf(float a); float rcbrtf(float a)
{
  return (float)rcbrt((double)a);
}

extern __attribute__((__weak_import__, __weak__)) float sinpif(float a); float sinpif(float a)
{
  return (float)sinpi((double)a);
}

extern __attribute__((__weak_import__, __weak__)) float erfinvf(float a); float erfinvf(float a)
{
  return (float)erfinv((double)a);
}

extern __attribute__((__weak_import__, __weak__)) float erfcinvf(float a); float erfcinvf(float a)
{
  return (float)erfcinv((double)a);
}







extern __attribute__((__weak_import__, __weak__)) int min(int a, int b); int min(int a, int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak_import__, __weak__)) unsigned int umin(unsigned int a, unsigned int b); unsigned int umin(unsigned int a, unsigned int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak_import__, __weak__)) long long int llmin(long long int a, long long int b); long long int llmin(long long int a, long long int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak_import__, __weak__)) unsigned long long int ullmin(unsigned long long int a, unsigned long long int b); unsigned long long int ullmin(unsigned long long int a, unsigned long long int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak_import__, __weak__)) int max(int a, int b); int max(int a, int b)
{
  return a > b ? a : b;
}

extern __attribute__((__weak_import__, __weak__)) unsigned int umax(unsigned int a, unsigned int b); unsigned int umax(unsigned int a, unsigned int b)
{
  return a > b ? a : b;
}

extern __attribute__((__weak_import__, __weak__)) long long int llmax(long long int a, long long int b); long long int llmax(long long int a, long long int b)
{
  return a > b ? a : b;
}

extern __attribute__((__weak_import__, __weak__)) unsigned long long int ullmax(unsigned long long int a, unsigned long long int b); unsigned long long int ullmax(unsigned long long int a, unsigned long long int b)
{
  return a > b ? a : b;
}
# 5000 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 5001 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 91 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 164 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2



#pragma options align=natural
# 2 "/tmp/tmpxft_00000cb2_00000000-1_mtgp32-cuda-cuterandAPI.cudafe1.stub.c" 2
# 1 "/tmp/tmpxft_00000cb2_00000000-3_mtgp32-cuda-cuterandAPI.fatbin.c" 1
# 1 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 1
# 83 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
extern "C" {
# 97 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct __cudaFatDebugEntryRec {
    char* gpuProfileName;
    char* debug;
    struct __cudaFatDebugEntryRec *next;
    unsigned int size;
} __cudaFatDebugEntry;

typedef struct __cudaFatElfEntryRec {
    char* gpuProfileName;
    char* elf;
    struct __cudaFatElfEntryRec *next;
    unsigned int size;
} __cudaFatElfEntry;

typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag = (1 << 1),
      __cudaFatSassDebugFlag = (1 << 2)
} __cudaFatCudaBinaryFlag;
# 152 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct {
    char* name;
} __cudaFatSymbol;
# 166 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
typedef struct __cudaFatCudaBinaryRec {
    unsigned long magic;
    unsigned long version;
    unsigned long gpuInfoVersion;
    char* key;
    char* ident;
    char* usageMode;
    __cudaFatPtxEntry *ptx;
    __cudaFatCubinEntry *cubin;
    __cudaFatDebugEntry *debug;
    void* debugInfo;
    unsigned int flags;
    __cudaFatSymbol *exported;
    __cudaFatSymbol *imported;
    struct __cudaFatCudaBinaryRec *dependends;
    unsigned int characteristic;
    __cudaFatElfEntry *elf;
} __cudaFatCudaBinary;
# 203 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode,
        __cudaFatForcePTX
    } __cudaFatCompilationPolicy;
# 227 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 240 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
unsigned char fatCheckJitForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *ptx );
# 250 "/usr/local/cuda/bin/../include/__cudaFatFormat.h"
void fatFreeCubin( char* cubin, char* dbgInfoFile );





void __cudaFatFreePTX( char* ptx );


}
# 2 "/tmp/tmpxft_00000cb2_00000000-3_mtgp32-cuda-cuterandAPI.fatbin.c" 2


extern "C" {


static const unsigned long long __deviceText_$compute_11$[] = {
0x6f69737265762e09ull,0x2e090a342e31206eull,0x7320746567726174ull,0x616d202c31315f6dull,
0x6f745f3436665f70ull,0x2f2f090a3233665full,0x656c69706d6f6320ull,0x2f20687469772064ull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x706f2f2e2e2f6e69ull,0x62696c2f34366e65ull,
0x2f2f090a65622f2full,0x636e65706f766e20ull,0x756220322e332063ull,0x32206e6f20746c69ull,
0x312d30312d303130ull,0x2d2d2f2f090a0a39ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x6f43202f2f090a2dull,0x20676e696c69706dull,0x706d742f706d742full,
0x303030305f746678ull,0x3030305f32626330ull,0x5f372d3030303030ull,0x632d32337067746dull,
0x657475632d616475ull,0x2e495041646e6172ull,0x2820692e33707063ull,0x6c6f662f7261762full,
0x2f41652f73726564ull,0x6873346354354165ull,0x68336c4244575045ull,0x2b2b5564565a742dull,
0x706d542d2f49542bull,0x2e23494263632f2dull,0x0a29704d56305363ull,0x2d2d2d2d2d2f2f09ull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x0a0a2d2d2d2d2d2dull,0x2d2d2d2d2d2f2f09ull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x090a2d2d2d2d2d2dull,0x6f6974704f202f2full,
0x2d2f2f090a3a736eull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x20202f2f090a2d2dull,0x703a746567726154ull,0x3a415349202c7874ull,0x45202c31315f6d73ull,
0x696c3a6e6169646eull,0x6f50202c656c7474ull,0x6953207265746e69ull,0x2f090a32333a657aull,
0x2809334f2d20202full,0x617a696d6974704full,0x76656c206e6f6974ull,0x202f2f090a296c65ull,
0x6544280930672d20ull,0x6576656c20677562ull,0x20202f2f090a296cull,0x7065522809326d2dull,
0x697664612074726full,0x0a29736569726f73ull,0x2d2d2d2d2d2f2f09ull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x0a0a2d2d2d2d2d2dull,0x3109656c69662e09ull,0x616d6d6f633c2209ull,
0x3e656e696c2d646eull,0x656c69662e090a22ull,0x706d742f22093209ull,0x5f746678706d742full,
0x3262633030303030ull,0x303030303030305full,0x7067746d5f362d30ull,0x2d616475632d3233ull,
0x646e617265747563ull,0x616475632e495041ull,0x227570672e326566ull,0x09656c69662e090aull,
0x2f7273752f220933ull,0x2f6363672f62696cull,0x7070612d36383669ull,0x69777261642d656cull,
0x2e322e342f30316eull,0x64756c636e692f31ull,0x6665646474732f65ull,0x69662e090a22682eull,
0x752f22093409656cull,0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,
0x7472632f6564756cull,0x5f6563697665642full,0x2e656d69746e7572ull,0x6c69662e090a2268ull,
0x73752f2209350965ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x74736f682f656475ull,0x73656e696665645full,0x69662e090a22682eull,0x752f22093609656cull,
0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,0x6975622f6564756cull,
0x7079745f6e69746cull,0x2e090a22682e7365ull,0x22093709656c6966ull,0x636f6c2f7273752full,
0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x642f6564756c636eull,0x79745f6563697665ull,
0x090a22682e736570ull,0x093809656c69662eull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x745f726576697264ull,0x0a22682e73657079ull,
0x3909656c69662e09ull,0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x656361667275732full,0x682e73657079745full,0x656c69662e090a22ull,
0x73752f2209303109ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x747865742f656475ull,0x657079745f657275ull,0x662e090a22682e73ull,0x2209313109656c69ull,
0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x762f6564756c636eull,
0x79745f726f746365ull,0x090a22682e736570ull,0x323109656c69662eull,0x6c2f7273752f2209ull,
0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x5f6563697665642full,
0x705f68636e75616cull,0x726574656d617261ull,0x662e090a22682e73ull,0x2209333109656c69ull,
0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x632f6564756c636eull,
0x61726f74732f7472ull,0x7373616c635f6567ull,0x69662e090a22682eull,0x2f2209343109656cull,
0x6c636e692f727375ull,0x363833692f656475ull,0x2e73657079745f2full,0x6c69662e090a2268ull,
0x752f220935310965ull,0x756c636e692f7273ull,0x2e656d69742f6564ull,0x6c69662e090a2268ull,
0x752f220936310965ull,0x672f62696c2f7273ull,0x2d363836692f6363ull,0x61642d656c707061ull,
0x342f30316e697772ull,0x636e692f312e322eull,0x6474732f6564756cull,0x090a22682e746e69ull,
0x373109656c69662eull,0x32337067746d2209ull,0x75632d616475632dull,0x5041646e61726574ull,
0x662e090a22682e49ull,0x2209383109656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,
0x692f2e2e2f6e6962ull,0x632f6564756c636eull,0x75665f6e6f6d6d6full,0x2e736e6f6974636eull,
0x6c69662e090a2268ull,0x752f220939310965ull,0x6c61636f6c2f7273ull,0x69622f616475632full,
0x636e692f2e2e2f6eull,0x74616d2f6564756cull,0x6974636e75665f68ull,0x090a22682e736e6full,
0x303209656c69662eull,0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,
0x6564756c636e692full,0x6f635f6874616d2full,0x2e73746e6174736eull,0x6c69662e090a2268ull,
0x752f220931320965ull,0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,
0x7665642f6564756cull,0x636e75665f656369ull,0x22682e736e6f6974ull,0x09656c69662e090aull,
0x7273752f22093232ull,0x632f6c61636f6c2full,0x2f6e69622f616475ull,0x756c636e692f2e2eull,
0x31315f6d732f6564ull,0x5f63696d6f74615full,0x6e6f6974636e7566ull,0x662e090a22682e73ull,
0x2209333209656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x732f6564756c636eull,0x6f74615f32315f6dull,0x636e75665f63696dull,0x22682e736e6f6974ull,
0x09656c69662e090aull,0x7273752f22093432ull,0x632f6c61636f6c2full,0x2f6e69622f616475ull,
0x756c636e692f2e2eull,0x33315f6d732f6564ull,0x5f656c62756f645full,0x6e6f6974636e7566ull,
0x662e090a22682e73ull,0x2209353209656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,
0x692f2e2e2f6e6962ull,0x732f6564756c636eull,0x6f74615f30325f6dull,0x636e75665f63696dull,
0x22682e736e6f6974ull,0x09656c69662e090aull,0x7273752f22093632ull,0x632f6c61636f6c2full,
0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x30325f6d732f6564ull,0x736e6972746e695full,
0x090a22682e736369ull,0x373209656c69662eull,0x6c2f7273752f2209ull,0x6475632f6c61636full,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x656361667275732full,0x6f6974636e75665full,
0x2e090a22682e736eull,0x09383209656c6966ull,0x6f6c2f7273752f22ull,0x616475632f6c6163ull,
0x2f2e2e2f6e69622full,0x2f6564756c636e69ull,0x5f65727574786574ull,0x75665f6863746566ull,
0x2e736e6f6974636eull,0x6c69662e090a2268ull,0x752f220939320965ull,0x6c61636f6c2f7273ull,
0x69622f616475632full,0x636e692f2e2e2f6eull,0x74616d2f6564756cull,0x6974636e75665f68ull,
0x5f6c62645f736e6full,0x0a22682e31787470ull,0x74736e6f632e090aull,0x206e67696c612e20ull,
0x61702038622e2034ull,0x5b6c62745f6d6172ull,0x0a3b5d3030383231ull,0x2074736e6f632e09ull,
0x34206e67696c612eull,0x6d65742038622e20ull,0x5b6c62745f726570ull,0x0a3b5d3030383231ull,
0x2074736e6f632e09ull,0x34206e67696c612eull,0x6e69732038622e20ull,0x706d65745f656c67ull,
0x315b6c62745f7265ull,0x090a3b5d30303832ull,0x2e2074736e6f632eull,0x2034206e67696c61ull,
0x5f736f702038622eull,0x5d3030385b6c6274ull,0x736e6f632e090a3bull,0x6e67696c612e2074ull,
0x732038622e203420ull,0x385b6c62745f3168ull,0x632e090a3b5d3030ull,0x6c612e2074736e6full,
0x622e2034206e6769ull,0x62745f3268732038ull,0x0a3b5d3030385b6cull,0x6465726168732e09ull,
0x206e67696c612e20ull,0x74732038622e2034ull,0x3730335b73757461ull,0x68732e090a3b5d32ull,
0x6c612e2064657261ull,0x622e2034206e6769ull,0x345b706574732038ull,0x2e090a3b5d363930ull,
0x752e2074736e6f63ull,0x206b73616d203233ull,0x36383833382d203dull,0x0000000a0a3b3830ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_11",(char*)__deviceText_$compute_11$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;
static __cudaFatElfEntry __elfEntries0 = {0, 0, 0, 0} ;



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section ("__NV_CUDA,__fatbin")))= {0x1ee55a01,0x00000004,0xa14f518d,(char*)"6bda6472a64898d5",(char*)"mtgp32-cuda-cuterandAPI.cu",(char*)"-v  ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0x83f2272a,&__elfEntries0};
# 3 "/tmp/tmpxft_00000cb2_00000000-1_mtgp32-cuda-cuterandAPI.cudafe1.stub.c" 2
static void __sti____cudaRegisterAll_58_tmpxft_00000cb2_00000000_4_mtgp32_cuda_cuterandAPI_cpp1_ii_mask(void) __attribute__((__constructor__));
static void __sti____cudaRegisterAll_58_tmpxft_00000cb2_00000000_4_mtgp32_cuda_cuterandAPI_cpp1_ii_mask(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)&__fatDeviceText); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&param_tbl, (char*)"param_tbl", "param_tbl", 0, 12800, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&temper_tbl, (char*)"temper_tbl", "temper_tbl", 0, 12800, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&single_temper_tbl, (char*)"single_temper_tbl", "single_temper_tbl", 0, 12800, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&pos_tbl, (char*)"pos_tbl", "pos_tbl", 0, 800, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&sh1_tbl, (char*)"sh1_tbl", "sh1_tbl", 0, 800, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&sh2_tbl, (char*)"sh2_tbl", "sh2_tbl", 0, 800, 1, 0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&mask, (char*)"mask", "mask", 0, 4, 1, 0);}
# 1 "/tmp/tmpxft_00000cb2_00000000-1_mtgp32-cuda-cuterandAPI.cudafe1.stub.c" 2
