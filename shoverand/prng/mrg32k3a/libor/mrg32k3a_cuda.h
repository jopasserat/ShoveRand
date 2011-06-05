
/*********************************************************************************
*                                                                                *
* mrg32k3a generator for GPU RNG library based on algorithms described in:       *
*                                                                                *
* Good parameter sets for combined multiple recursive random number generators   *
* P. L'Ecuyer. Operations Research, 47(1):159-164, 1999.                         *
* http://www.iro.umontreal.ca/~lecuyer/myftp/papers/combmrg2.ps                  *
*                                                                                *
* An object-oriented random-number package with many long streams and substreams *
* P. L'Ecuyer, R. Simar, E.J. Chen and W.D. Kelton.                              *
* Operations Research, 50(6):1073-1075, 2002                                     *
* http://www.iro.umontreal.ca/~lecuyer/myftp/papers/streams00.pdf                *
*                                                                                *
* Copyright Mike Giles, 2009                                                     *
*                                                                                *
*********************************************************************************/

// C99-compliant unsigned 64-bit integers on both host and device

typedef unsigned long long ull;

// enum list for template routines

enum distribution_types { UNIFORM, EXPONENTIAL, NORMAL };

// skip-ahead matrices held in global constant memory

__constant__ uint mrg32k3a_v1[3], mrg32k3a_A1[9*148],
                  mrg32k3a_v2[3], mrg32k3a_A2[9*148];

// various constants

#define mrg32k3a_pi       3.14159265358979323846
#define mrg32k3a_norm     2.3283065498378288e-10

#define mrg32k3a_2pow32m1 4294967295

#define mrg32k3a_m1       4294967087
#define mrg32k3a_m1c             209
#define mrg32k3a_m2       4294944443
#define mrg32k3a_m2c           22853

#define mrg32k3a_a12                   1403580
#define mrg32k3a_a13     (4294967087 -  810728)
#define mrg32k3a_a13n                   810728

#define mrg32k3a_a21                    527612
#define mrg32k3a_a23     (4294944443 - 1370589)
#define mrg32k3a_a23n                  1370589


/**************************************************************************

low-level device routines for mrg32k3a generator for GPU RNG library

**************************************************************************/

//
// initialise the seeds for each thread using skip-ahead matrices
//

__device__ void gpu_mrg32k3a_stream_init(uint *v1, uint *v2, int np)
{
  int   i, m, n;
  uint  vlo, vhi, vt0, vt1, vt2;
  ull   vt, off;

  for (m=0; m<3; m++) {
    v1[m] = mrg32k3a_v1[m];
    v2[m] = mrg32k3a_v2[m];
  }

  off = ((ull) np) * (threadIdx.x + blockDim.x*blockIdx.x);
  n  = 0;

  while (off>0) {
    m = off%8 - 1;
    if (m>=0) {
      vt0 = v1[0];
      vt1 = v1[1];
      vt2 = v1[2];

      for (i=0; i<3; i++) {
        // vt[i] = ( (mrg32k3a_A1[i+3*0+9*m+63*n]*v1[0])%mrg32k3a_m1
        //         + (mrg32k3a_A1[i+3*1+9*m+63*n]*v1[1])%mrg32k3a_m1
        //         + (mrg32k3a_A1[i+3*2+9*m+63*n]*v1[2])%mrg32k3a_m1) % mrg32k3a_m1;

        vlo  =          mrg32k3a_A1[i+3*0+9*m+63*n]*vt0;
        vhi  = __umulhi(mrg32k3a_A1[i+3*0+9*m+63*n],vt0);
        vt   = vlo + vhi*((ull) mrg32k3a_m1c);

        vlo  =          mrg32k3a_A1[i+3*1+9*m+63*n]*vt1;
        vhi  = __umulhi(mrg32k3a_A1[i+3*1+9*m+63*n],vt1);
        vt  += vlo + vhi*((ull) mrg32k3a_m1c);

        vlo  =          mrg32k3a_A1[i+3*2+9*m+63*n]*vt2;
        vhi  = __umulhi(mrg32k3a_A1[i+3*2+9*m+63*n],vt2);
        vt  += vlo + vhi*((ull) mrg32k3a_m1c);

        vt = (vt & mrg32k3a_2pow32m1) + (vt>>32)*mrg32k3a_m1c;
        if (vt>=mrg32k3a_m1) vt -= mrg32k3a_m1;

        v1[i] = vt;
      }

      vt0 = v2[0];
      vt1 = v2[1];
      vt2 = v2[2];

      for (i=0; i<3; i++) {
        // vt[i] = ( (mrg32k3a_A2[i+3*0+9*m+63*n]*v2[0])%mrg32k3a_m2
        //         + (mrg32k3a_A2[i+3*1+9*m+63*n]*v2[1])%mrg32k3a_m2
        //         + (mrg32k3a_A2[i+3*2+9*m+63*n]*v2[2])%mrg32k3a_m2) % mrg32k3a_m2;


        vlo  =          mrg32k3a_A2[i+3*0+9*m+63*n]*vt0;
        vhi  = __umulhi(mrg32k3a_A2[i+3*0+9*m+63*n],vt0);
        vt   = vlo + vhi*((ull) mrg32k3a_m2c);

        vlo  =          mrg32k3a_A2[i+3*1+9*m+63*n]*vt1;
        vhi  = __umulhi(mrg32k3a_A2[i+3*1+9*m+63*n],vt1);
        vt  += vlo + vhi*((ull) mrg32k3a_m2c);

        vlo  =          mrg32k3a_A2[i+3*2+9*m+63*n]*vt2;
        vhi  = __umulhi(mrg32k3a_A2[i+3*2+9*m+63*n],vt2);
        vt  += vlo + vhi*((ull) mrg32k3a_m2c);

        vt = (vt & mrg32k3a_2pow32m1) + (vt>>32)*mrg32k3a_m2c;
        if (vt>=mrg32k3a_m2) vt -= mrg32k3a_m2;

        v2[i] = vt;
      }
    }
    off = off/8;
    n++;
  }
}


//
// advance the internal state by one step
//

__inline__ __device__ void gpu_mrg32k3a_next_step(uint *v1, uint *v2, uint &p)
{
  uint vs0, vs1, vs2, plo, phi, pl2;
  ull  prod;

  vs1 = v1[1];  vs0 = mrg32k3a_m1-v1[0];
  prod = (ull)mrg32k3a_a12*vs1 + (ull)mrg32k3a_a13n*vs0;
  phi  = prod>>32;  plo  = prod & mrg32k3a_2pow32m1;

  //pl2 = mrg32k3a_a12*vs1;  plo = pl2 + mrg32k3a_a13n*vs0;
  //phi = __umulhi(mrg32k3a_a12,vs1) + __umulhi(mrg32k3a_a13n,vs0);
  //if (plo<pl2) phi++;

  pl2 = plo + umul24(phi,mrg32k3a_m1c);
  if (pl2>=mrg32k3a_m1 | pl2<plo ) pl2 -= mrg32k3a_m1; 

  v1[0] = v1[1]; v1[1] = v1[2]; v1[2] = pl2;

  vs2 = v2[2];  vs0 = mrg32k3a_m2-v2[0];
  prod = (ull)mrg32k3a_a21*vs2 + (ull)mrg32k3a_a23n*vs0;
  phi  = prod>>32;  plo =  prod & mrg32k3a_2pow32m1;

  //pl2 = mrg32k3a_a21*vs2;  plo = pl2 + mrg32k3a_a23n*vs0;
  //phi = __umulhi(mrg32k3a_a21,vs2) + __umulhi(mrg32k3a_a23n,vs0);
  //if (plo<pl2) phi++;

  prod = plo + phi*(ull)mrg32k3a_m2c;
  phi  = prod>>32;  pl2 =  prod & mrg32k3a_2pow32m1;

  //pl2 = plo + phi*mrg32k3a_m2c;      //
  //phi = __umulhi(phi,mrg32k3a_m2c);  // extra pass because m2c>m1c
  //if (pl2<plo) phi++;                //

  plo = pl2 + umul24(phi,mrg32k3a_m2c);
  if (plo>=mrg32k3a_m2 | plo<pl2 ) plo -= mrg32k3a_m2;

  v2[0] = v2[1]; v2[1] = v2[2]; v2[2] = plo;

  p = v1[2] - v2[2];
  if(v1[2] <= v2[2]) p += mrg32k3a_m1;
}


//
// compute the next random number from a uniform distribution
//

template <class FP>
__device__ void gpu_mrg32k3a_next_uniform(uint *v1, uint *v2, FP &x)
{
  uint p;

  gpu_mrg32k3a_next_step(v1, v2, p);
  x = (FP)mrg32k3a_norm*(FP)p;
}


//
// compute the next random number from an exponential distribution
//

template <class FP>
__device__ void gpu_mrg32k3a_next_exponential(uint *v1, uint *v2, FP &x)
{
  uint p;

  gpu_mrg32k3a_next_step(v1, v2, p);
  x = log((FP)mrg32k3a_norm*(FP)p);
}


//
// compute the next random number from a normal distribution
// using Box-Muller method which generates them in pairs 
//

template <class FP>
__device__ void gpu_mrg32k3a_next_normal(uint *v1, uint *v2, FP &x0, FP &x1)
{
  uint p;
  FP   x2;

  if ( isnan(x1) ) {
    gpu_mrg32k3a_next_step(v1, v2, p);
    x2 = sqrt(-(FP)2.0*log((FP)mrg32k3a_norm*(FP)p));

    gpu_mrg32k3a_next_step(v1, v2, p);
    sincos((FP)2.0*(FP)mrg32k3a_pi*(FP)mrg32k3a_norm*(FP)p,&x0,&x1);

    x0 = x0*x2;
    x1 = x1*x2;
  }
  else {
    x0 = x1;
    x1 = (FP)nanf("");
  }
}


//
// compute the next random number from a gamma distribution
//

template <class FP>
__device__ void gpu_mrg32k3a_next_gamma(uint *v1, uint *v2, FP alpha, FP &x, FP &x1)
{
  FP prefix, d, c, v, u;

  if (alpha <= (FP)1.0) {
    gpu_mrg32k3a_next_uniform(v1, v2, u);
    prefix = pow(u, (FP)1.0/alpha);
    alpha += (FP)1.0;
  }
  else {
    prefix = (FP)1.0;
  }

  d = alpha - (FP)1.0/(FP)3.0;
  c = rsqrt((FP)9.0*d);

  do {
    gpu_mrg32k3a_next_normal(v1, v2, x, x1);
    v = (FP)1.0 + c*x;
    v = v*v*v;
    gpu_mrg32k3a_next_uniform(v1, v2, u);
    //    printf(" gpu: x, u = %f %f \n",x,u);
  } while ( (v<=(FP)0.0) || log(u)>= (FP)0.5*x*x + d*((FP)1.0-v+log(v)));

  x = prefix*d*v;
}


/**************************************************************************

kernel routines for mrg32k3a generator for GPU RNG library

**************************************************************************/

template <distribution_types distribution, class FP>
__global__ void gpu_mrg32k3a_kernel(int np, FP *d_P)
{
  uint v1[3], v2[3];
  int  n, i0;
  FP   x, x2 = nanf("");

  // initialisation for first point

  gpu_mrg32k3a_stream_init(v1, v2, np);

  // now do points

  i0 = threadIdx.x + np*blockDim.x*blockIdx.x;

  for (n=0; n<np; n++) {
    switch ( distribution ) {
      case UNIFORM:
        gpu_mrg32k3a_next_uniform(v1, v2, x);
        break;
      case EXPONENTIAL:
        gpu_mrg32k3a_next_exponential(v1, v2, x);
        break;
      case NORMAL:
        gpu_mrg32k3a_next_normal(v1, v2, x, x2);
        break;
    }

    d_P[i0] = x;
    i0 += blockDim.x;
  }
}


template <class FP>
__global__ void gpu_mrg32k3a_gamma_kernel(int np, FP alpha, FP *d_P)
{
  uint v1[3], v2[3];
  int  n, i0;
  FP   x, x2 = nanf("");

  // initialisation for first point

  gpu_mrg32k3a_stream_init(v1, v2, np*8);

  // now do points

  i0 = threadIdx.x + np*blockDim.x*blockIdx.x;

  for (n=0; n<np; n++) {
    gpu_mrg32k3a_next_gamma(v1, v2, alpha, x, x2);
    d_P[i0] = x;
    i0 += blockDim.x;
  }
}

//
// this version stores the random numbers consecutively
//

template <distribution_types distribution, class FP>
__global__ void gpu_mrg32k3a_kernel2(int np, int N, FP *d_P)
{
  uint v1[3], v2[3];
  int  m, n, i, j, iw, ir, ig;
  FP   x, x2=(FP)nanf("");

  __shared__ FP P[65*16];

  // define key indices

  i = threadIdx.x%16;
  j = threadIdx.x/16;

  iw =    i     + 16*j;                  // write to shared
  ir = 65*i     + 16*j;                  // read from shared
  ig =    i + np*(16*j + 64*blockIdx.x); // write to device

  // initialisation for first point

  gpu_mrg32k3a_stream_init(v1, v2, np);

  // now do points

  for (n=0; n<np; n++) {
    switch ( distribution ) {
      case UNIFORM:
        gpu_mrg32k3a_next_uniform(v1, v2, x);
        break;
      case EXPONENTIAL:
        gpu_mrg32k3a_next_exponential(v1, v2, x);
        break;
      case NORMAL:
        gpu_mrg32k3a_next_normal(v1, v2, x, x2);
        break;
    }

    P[iw] = x;
    iw += 65;   // 64 + 1 to avoid bank contention

    // after each set of 16 points, store to device memory

    if (n%16 == 15) {
      __syncthreads();

      for (m=0; m<16; m++) {
        if (ig < N) d_P[ig] = P[ir];
        ig += np;
        ir += 1;
      }

      iw -= 16*65;
      ig -= 16*np - 16;
      ir -= 16;
      
      __syncthreads();
    }
  }
}

/**************************************************************************

high-level routines for mrg32k3a generator for GPU RNG library

**************************************************************************/

//
// compute skip-ahead matrices and copy them and the seed vectors to device
//

template <class Int>
void gpu_mrg32k3a_init(uint *v1o, uint *v2o, Int offset)
{
  ull   a1, a2, v1b[3], v2b[3];
  uint  A1[9*148], A2[9*148], v1[3], v2[3];
  int   m, n, i, j, k;

  // check that "long long" is correct length

  if (sizeof(ull) != 8) {
    printf("sizeof(unsigned long long) = %d bytes \n",sizeof(ull));
    printf("mrg32k3a routines must be re-compiled for 8-byte long long\n");
    exit(1);
  }

  // check that offset is not negative

  if (offset<0) {
    printf("offset = %d \n",offset);
    printf("offset is not allowed to be negative\n");
    exit(1);
  }

  // calculate matrices and offset seeds

  for (i=0; i<3; i++) {
    v1[i] = v1o[i];
    v2[i] = v2o[i];
  }

  A1[0] = 0;            A1[3] = 1;            A1[6] = 0;
  A1[1] = 0;            A1[4] = 0;            A1[7] = 1;
  A1[2] = mrg32k3a_a13; A1[5] = mrg32k3a_a12; A1[8] = 0; 

  A2[0] = 0;            A2[3] = 1;            A2[6] = 0;
  A2[1] = 0;            A2[4] = 0;            A2[7] = 1;
  A2[2] = mrg32k3a_a23; A2[5] = 0;            A2[8] = mrg32k3a_a21;

  for (n=0; n<21; n++) {
    for (m=0; m<7; m++) {
      for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
          a1 = 0;
          a2 = 0;
          for (k=0; k<3; k++) {
            a1 += ( ((ull) A1[i+3*k+63*n])
                  * ((ull) A1[k+3*j+9*m+63*n]) ) % mrg32k3a_m1;
            a2 += ( ((ull) A2[i+3*k+63*n])
                  * ((ull) A2[k+3*j+9*m+63*n]) ) % mrg32k3a_m2;
          }
          A1[i+3*j+9*(m+1)+63*n] = a1%mrg32k3a_m1;
          A2[i+3*j+9*(m+1)+63*n] = a2%mrg32k3a_m2;
	}
      }
    }

    m = offset%8 - 1;
    if (m>=0) {
      for (i=0; i<3; i++) {
        v1b[i] = v1[i];
        v2b[i] = v2[i];
      }

      for (i=0; i<3; i++) {
        v1[i] = ( (A1[i+3*0+9*m+63*n]*v1b[0])%mrg32k3a_m1
                + (A1[i+3*1+9*m+63*n]*v1b[1])%mrg32k3a_m1
                + (A1[i+3*2+9*m+63*n]*v1b[2])%mrg32k3a_m1) % mrg32k3a_m1;
        v2[i] = ( (A2[i+3*0+9*m+63*n]*v2b[0])%mrg32k3a_m2
                + (A2[i+3*1+9*m+63*n]*v2b[1])%mrg32k3a_m2
                + (A2[i+3*2+9*m+63*n]*v2b[2])%mrg32k3a_m2) % mrg32k3a_m2;
      }
    }
    offset = offset/8;
  }

  // copy over seeds and matrices

  cutilSafeCall(cudaMemcpyToSymbol(mrg32k3a_v1,v1,sizeof(uint)*3));
  cutilSafeCall(cudaMemcpyToSymbol(mrg32k3a_v2,v2,sizeof(uint)*3));
  cutilSafeCall(cudaMemcpyToSymbol(mrg32k3a_A1,A1,sizeof(uint)*9*148));
  cutilSafeCall(cudaMemcpyToSymbol(mrg32k3a_A2,A2,sizeof(uint)*9*148));
}


//
// compute random numbers and put them in a device array
//

template <class FP>
void gpu_mrg32k3a_uniform(int nb, int nt, int np, FP *d_P)
{
  if (nt==1) {
    int np2 = 16*((np-1)/1024+1);  // np/64 rounded up to multiple of 16
    // gpu_mrg32k3a_uniform_kernel2<<<nb, 64>>>(np2, nb*np, d_P);
    gpu_mrg32k3a_kernel2<UNIFORM><<<nb, 64>>>(np2, nb*np, d_P);
  }
  else {
    // gpu_mrg32k3a_uniform_kernel<<<nb, nt>>>(np, d_P);
    gpu_mrg32k3a_kernel<UNIFORM><<<nb, nt>>>(np, d_P);
  }
  cutilCheckMsg("gpu_mrg32k3a_uniform execution failed\n");
}

template <class FP>
void gpu_mrg32k3a_exponential(int nb, int nt, int np, FP *d_P)
{
  if (nt==1) {
    int np2 = 16*((np-1)/1024+1);  // np/64 rounded up to multiple of 16
    // gpu_mrg32k3a_exponential_kernel2<<<nb, 64>>>(np2, nb*np, d_P);
    gpu_mrg32k3a_kernel2<EXPONENTIAL><<<nb, 64>>>(np2, nb*np, d_P);
  }
  else {
    // gpu_mrg32k3a_exponential_kernel<<<nb, nt>>>(np, d_P);
    gpu_mrg32k3a_kernel<EXPONENTIAL><<<nb, nt>>>(np, d_P);
  }
  cutilCheckMsg("gpu_mrg32k3a_exponential execution failed\n");
}

template <class FP>
void gpu_mrg32k3a_normal(int nb, int nt, int np, FP *d_P)
{
  if (nt==1) {
    int np2 = 16*((np-1)/1024+1);  // np/64 rounded up to multiple of 16
    // gpu_mrg32k3a_normal_kernel2<<<nb, 64>>>(np2, nb*np, d_P);
    gpu_mrg32k3a_kernel2<NORMAL><<<nb, 64>>>(np2, nb*np, d_P);
  }
  else {
    // gpu_mrg32k3a_normal_kernel<<<nb, nt>>>(np, d_P);
    gpu_mrg32k3a_kernel<NORMAL><<<nb, nt>>>(np, d_P);
  }
  cutilCheckMsg("gpu_mrg32k3a_normal execution failed\n");
}

template <class FP>
void gpu_mrg32k3a_gamma(int nb, int nt, int np, FP alpha, FP *d_P)
{
  gpu_mrg32k3a_gamma_kernel<<<nb, nt>>>(np, alpha, d_P);
  cutilCheckMsg("gpu_mrg32k3a_gamma execution failed\n");
}
