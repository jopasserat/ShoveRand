
/* Program to compute swaption portfolio using NVIDIA CUDA */

#include <stdio.h>
#include <cutil_inline.h>

// parameters for LIBOR calculation

#include <params.h>

////////////////////////////////////////////////////////////////////////
// include kernel routines
////////////////////////////////////////////////////////////////////////

#include <mrg32k3a_cuda.h>
#include <libor_kernels.cu>

////////////////////////////////////////////////////////////////////////
// declaration of CPU calls
////////////////////////////////////////////////////////////////////////

extern "C"
void copy_constants(int, int, int, int *, float, float *, float *, float *);

extern "C"
void Pathcalc_Portfolio_CPU(float *, float *, float *);

extern "C"
void Pathcalc_Portfolio_CPU2(float *, float *);

extern "C" 
void CPU_mrg32k3a_init(uint *V1, uint *V2, int offset);

extern "C" 
void CPU_mrg32k3a_normal(int, float *);


////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv){
    
  int    N=NN, Nmat=NMAT, Nopt=NOPT, 
         maturities[] = {4,4,4,8,8,8,20,20,20,28,28,28,40,40,40};
  float  delta=0.25, lambda[NN], L0[NN],
         swaprates[]  = {.045,.05,.055,.045,.05,.055,.045,.05,
                         .055,.045,.05,.055,.045,.05,.055 };

  uint  V1[] = { 1, 2, 3 };  // seeds
  uint  V2[] = { 1, 2, 3 };  // seeds

  // 'h_' prefix - CPU (host) memory space

  int     i;
  float  *h_v, *h_Lb, *h_v2, *h_Lb2, *h_z;
  double  v, v_err, Lb, Lb_err; 

  unsigned int hTimer;
  double  gpuTime;

  // 'd_' prefix - GPU (device) memory space

  float  *d_v, *d_Lb, *d_z;

  CUT_DEVICE_INIT(argc, argv);
  CUT_SAFE_CALL( cutCreateTimer(&hTimer) );

  // Copy all constants into device constant memory

  for (i=0; i<NN; i++) lambda[i] = 0.2;
  for (i=0; i<NN; i++) L0[i] = 0.051;

  cudaMemcpyToSymbol("N", &N, sizeof(N));
  cudaMemcpyToSymbol("Nmat", &Nmat, sizeof(Nmat));
  cudaMemcpyToSymbol("Nopt", &Nopt, sizeof(Nopt));
  cudaMemcpyToSymbol("maturities", maturities, sizeof(maturities));
  cudaMemcpyToSymbol("delta", &delta, sizeof(delta));
  cudaMemcpyToSymbol("lambda", lambda, sizeof(lambda));        
  cudaMemcpyToSymbol("L0", L0, sizeof(L0));        
  cudaMemcpyToSymbol("swaprates", swaprates, sizeof(swaprates));

  copy_constants(N,Nmat,Nopt,maturities,delta,lambda,L0,swaprates);

  // Allocate memory on host and device

  h_v      = (float *)malloc(sizeof(float)*NPATH);
  h_v2     = (float *)malloc(sizeof(float)*NPATH);
  CUDA_SAFE_CALL( cudaMalloc((void **)&d_v, sizeof(float)*NPATH) );
  h_Lb     = (float *)malloc(sizeof(float)*NPATH);
  h_Lb2    = (float *)malloc(sizeof(float)*NPATH);
  CUDA_SAFE_CALL( cudaMalloc((void **)&d_Lb, sizeof(float)*NPATH) );
  h_z      = (float *)malloc(sizeof(float)*NPATH*Nmat);
  CUDA_SAFE_CALL( cudaMalloc((void **)&d_z, sizeof(float)*NPATH*Nmat) );

  // Random number generation

  gpu_mrg32k3a_init(V1, V2, 0);
  gpu_mrg32k3a_normal(NPATH/64, 64, Nmat, d_z);

  CPU_mrg32k3a_init(V1, V2, 0);
  CPU_mrg32k3a_normal(NPATH*Nmat, h_z);

  // CUDA computation on GPU

  CUT_SAFE_CALL( cutResetTimer(hTimer) );
  CUT_SAFE_CALL( cutStartTimer(hTimer) );
  Pathcalc_Portfolio_GPU2<<<NPATH/64, 64>>>(d_z, d_v);
  CUT_CHECK_ERROR("Pathcalc_Portfolio_GPU2() execution failed\n");
  CUDA_SAFE_CALL( cudaThreadSynchronize() );
  CUT_SAFE_CALL( cutStopTimer(hTimer) );

  gpuTime = cutGetTimerValue(hTimer);
  printf("\nGPU time (No Greeks) : %f msec\n", gpuTime);

  // Gold computation on CPU

  CUT_SAFE_CALL( cutResetTimer(hTimer) );
  CUT_SAFE_CALL( cutStartTimer(hTimer) );
  Pathcalc_Portfolio_CPU2(h_z, h_v2);
  CUT_SAFE_CALL( cutStopTimer(hTimer) );

  gpuTime = cutGetTimerValue(hTimer);
  printf("CPU time (No Greeks) : %f msec\n", gpuTime);

  // fetch CUDA results and compare to Gold results

  CUDA_SAFE_CALL( cudaMemcpy(h_v, d_v, sizeof(float)*NPATH,
                  cudaMemcpyDeviceToHost) );

  v     = 0.0;
  v_err = 0.0;
  for (i=0; i<NPATH; i++) {
    v     += h_v[i] / NPATH;
    v_err += abs(h_v[i]-h_v2[i]) / NPATH;
  }

  printf("average value v  = %15.8f\n", v);
  printf("average error    = %15.8f\n", v_err);

  // CUDA computation on GPU

  CUT_SAFE_CALL( cutResetTimer(hTimer) );
  CUT_SAFE_CALL( cutStartTimer(hTimer) ); 
  Pathcalc_Portfolio_GPU<<<NPATH/64, 64>>>(d_z, d_v,d_Lb);
  CUT_CHECK_ERROR("Pathcalc_Portfolio_GPU() execution failed\n");
  CUDA_SAFE_CALL( cudaThreadSynchronize() );
  CUT_SAFE_CALL( cutStopTimer(hTimer) );

  gpuTime = cutGetTimerValue(hTimer);
  printf("\nGPU time (Greeks) : %f msec\n", gpuTime);

  // Gold computation on CPU

  CUT_SAFE_CALL( cutResetTimer(hTimer) );
  CUT_SAFE_CALL( cutStartTimer(hTimer) );
  Pathcalc_Portfolio_CPU(h_z, h_v2,h_Lb2);
  CUT_SAFE_CALL( cutStopTimer(hTimer) );

  gpuTime = cutGetTimerValue(hTimer);
  printf("CPU time (Greeks) : %f msec\n", gpuTime);

  // fetch CUDA results and compare to Gold results

  CUDA_SAFE_CALL( cudaMemcpy(h_v, d_v, sizeof(float)*NPATH,
                  cudaMemcpyDeviceToHost) );
  CUDA_SAFE_CALL( cudaMemcpy(h_Lb, d_Lb, sizeof(float)*NPATH,
                  cudaMemcpyDeviceToHost) );
    
  v      = 0.0;
  v_err  = 0.0;
  Lb     = 0.0;
  Lb_err = 0.0;
  for (i=0; i<NPATH; i++) {
    v      += h_v[i] / NPATH;
    v_err  += abs(h_v[i]-h_v2[i]) / NPATH;
    Lb     += h_Lb[i] / NPATH;
    Lb_err += abs(h_Lb[i]-h_Lb2[i]) / NPATH;
  }

  printf("average value v  = %15.8f\n", v);
  printf("average error    = %15.8f\n", v_err);
  printf("average value Lb = %15.8f\n", Lb);
  printf("average error    = %15.8f\n", Lb_err);

  // Release memory and exit cleanly

  free(h_v);
  free(h_v2);
  free(h_Lb);
  free(h_Lb2);

  CUDA_SAFE_CALL( cudaFree(d_v));
  CUDA_SAFE_CALL( cudaFree(d_Lb));

  CUT_SAFE_CALL( cutDeleteTimer(hTimer) );
  CUT_EXIT(argc, argv);
}
