
// constant data for swaption portfolio: stored in device memory,
// initialised by host and read by device threads

__constant__ int    N, Nmat, Nopt, maturities[NOPT]; 
__constant__ float  delta, lambda[NN], L0[NN], swaprates[NOPT];


/* Monte Carlo LIBOR path calculation */

__device__ void path_calc(float *z, float *L)
{
  int   i, n;
  float sqez, lam, con1, v, vrat;

  for(n=0; n<Nmat; n++) {
    sqez = sqrtf(delta)*(*z);
    z += blockDim.x;  // note increment by blockDim.x, not 1
    v = 0.0f;

    for (i=n+1; i<N; i++) {
      lam  = lambda[i-n-1];
      con1 = delta*lam;
      v   += con1*L[i]/(1.0f+delta*L[i]);
      vrat = expf(con1*v + lam*(sqez-0.5f*con1));
      L[i] = L[i]*vrat;
    }
  }
}


/* forward path calculation storing data
   for subsequent reverse path calculation */

__device__ void path_calc_b1(float *z, float *L, float *L2)
{
  int   i, n;
  float sqez, lam, con1, v, vrat;

  for (i=0; i<N; i++) L2[i] = L[i];
   
  for(n=0; n<Nmat; n++) {
    sqez = sqrtf(delta)*(*z);
    z += blockDim.x;  // note increment by blockDim.x, not 1
    v = 0.0f;

    for (i=n+1; i<N; i++) {
      lam  = lambda[i-n-1];
      con1 = delta*lam;
      v   += con1*L[i]/(1.0f+delta*L[i]);
      vrat = expf(con1*v + lam*(sqez-0.5f*con1));
      L[i] = L[i]*vrat;

      // store these values for reverse path //
      L2[i+(n+1)*N] = L[i];
    }
  }
}


/* reverse path calculation of deltas using stored data */

__device__ void path_calc_b2(float *L_b, float *L2)
{
  int   i, n;
  float faci, v1;

  for (n=Nmat-1; n>=0; n--) {
    v1 = 0.0f;
    for (i=N-1; i>n; i--) {
      v1    += lambda[i-n-1]*L2[i+(n+1)*N]*L_b[i];
      faci   = delta/(1.0f+delta*L2[i+n*N]);
      L_b[i] = L_b[i]*L2[i+(n+1)*N]/L2[i+n*N]
              + v1*lambda[i-n-1]*faci*faci;
    }
  }
}


/* calculate the portfolio value v */

__device__ float portfolio(float *L)
{
  int   n, m, i;
  float v, b, s, swapval;
  float B[NMAT], S[NMAT];

  b = 1.0f;
  s = 0.0f;

  for (n=Nmat; n<N; n++) {
    b = b/(1.0f+delta*L[n]);
    s = s + delta*b;
    B[n-Nmat] = b;
    S[n-Nmat] = s;
  }

  v = 0.0f;

  for (i=0; i<Nopt; i++){
    m = maturities[i] -1;
    swapval = B[m] + swaprates[i]*S[m] - 1.0f;
    if (swapval < 0.0f)
      v += -100.0f*swapval;
  }

  // apply discount //

  for (n=0; n<Nmat; n++)
    v = v/(1.0f+delta*L[n]);

  return v;
}


/* calculate the portfolio value v, and its sensitivity to L */
/* hand-coded reverse mode sensitivity */

__device__ float portfolio_b(float *L, float *L_b) 
{
  int   m, n;
  float v, b, s, swapval;
  float B[NMAT], S[NMAT], B_b[NMAT], S_b[NMAT];

  b = 1.0f;
  s = 0.0f;
  for (m=0; m<N-Nmat; m++) {
    n    = m + Nmat;
    b    = b/(1.0f+delta*L[n]);
    s    = s + delta*b;
    B[m] = b;
    S[m] = s;
  }

  v = 0.0;

  for (m=0; m<N-Nmat; m++) {
    B_b[m] = 0.0f;
    S_b[m] = 0.0f;
  }

  for (n=0; n<Nopt; n++){
    m = maturities[n] - 1;
    swapval = B[m] + swaprates[n]*S[m] - 1.0f;
    if (swapval < 0.0f) {
      v      += -100.0f*swapval;
      S_b[m] += -100.0f*swaprates[n];
      B_b[m] += -100.0f;
    }
  }

  for (m=N-Nmat-1; m>=0; m--) {
    n = m + Nmat;
    B_b[m] += delta*S_b[m];
    L_b[n]  = -B_b[m]*B[m]*delta/(1.0f+delta*L[n]);
    if (m>0) {
      S_b[m-1] += S_b[m];
      B_b[m-1] += B_b[m]/(1.0f+delta*L[n]);
    }
  }

  // apply discount //

  b = 1.0f;
  for (n=0; n<Nmat; n++) b = b/(1.0f+delta*L[n]);

  v = b*v;

  for (n=0; n<Nmat; n++){
    L_b[n] = -v*delta/(1.0f+delta*L[n]);
  }

  for (n=Nmat; n<N; n++){
    L_b[n] = b*L_b[n];
  }

  return v;
}


/* -------------------------------------------------------- */

__global__ void Pathcalc_Portfolio_GPU(float *d_z, float *d_v, float *d_Lb)
{
  int   tid = threadIdx.x + blockIdx.x*blockDim.x;
  float L[NN], L2[L2_SIZE];
  float *L_b = L;

  /* initialise forward rates */
  for (int i=0; i<N; i++) L[i] = L0[i];

  /* move pointer to correct starting point */
  d_z = d_z + threadIdx.x + Nmat*blockIdx.x*blockDim.x;

  /* LIBOR path calculation and adjoint for Greeks */
  path_calc_b1(d_z,L,L2);
  d_v[tid] = portfolio_b(L,L_b);
  path_calc_b2(L_b, L2);
  d_Lb[tid] = L_b[NN-1];
}


__global__ void Pathcalc_Portfolio_GPU2(float *d_z, float *d_v)
{
  int   tid = threadIdx.x + blockIdx.x*blockDim.x;
  float L[NN];

  /* initialise forward rates */
  for (int i=0; i<N; i++) L[i] = L0[i];

  /* move pointer to correct starting point */
  d_z = d_z + threadIdx.x + Nmat*blockIdx.x*blockDim.x;

  /* LIBOR path calculation */
  path_calc(d_z,L);
  d_v[tid] = portfolio(L);
}
