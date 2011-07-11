/*
 *  utils.h
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/7/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

/** Some defines to spare constant memory... */
#define        m1         4294967087.0   // 2^32 - 209
#define        m2         4294944443.0   // 2^32 - 22853
#define        norm       1.0 / (m1 + 1.0)
#define        a12        1403580.0       // a1_2
#define        a13n       810728.0        // -a1_3
#define        a21        527612.0        //  a2_1 
#define        a23n       1370589.0       // -a2_3
#define        two17      131072.0        // 2^17
#define        two53      9007199254740992.0 // 2^53
#define        fact       5.9604644775390625e-8f     /* 1 / 2^24  */

#define        MATRIX_ROW     3
#define        MATRIX_COLUMN  3

/* The following are the transition matrices of the two MRG components
 * (in matrix form), raised to the powers 1, 2^76, and 2^127, resp.
 */
// __constant__ double A1p0[3][3];
// __constant__ double A2p0[3][3];
// __constant__ double A1p76[3][3];
// __constant__ double A2p76[3][3];
// __constant__ double A1p127[3][3];
// __constant__ double A2p127[3][3];



__device__ const double A1p76[3][3] = {
   {      82758667.0, 1871391091.0, 4127413238.0 },
   {    3672831523.0,   69195019.0, 1871391091.0 },
   {    3672091415.0, 3528743235.0,   69195019.0 }
};

__device__ double** A2p76;/*[3][3] = {
   {    1511326704.0, 3759209742.0, 1610795712.0 },
   {    4292754251.0, 1511326704.0, 3889917532.0 },
   {    3859662829.0, 4292754251.0, 3708466080.0 }
};*/

__device__ const double A1p127[3][3] = {
   {    2427906178.0, 3580155704.0,  949770784.0 },
   {     226153695.0, 1230515664.0, 3580155704.0 },
   {    1988835001.0,  986791581.0, 1230515664.0 }
};

__device__ const double A2p127[3][3] = {
   {    1464411153.0,  277697599.0, 1610723613.0 },
   {      32183930.0, 1464411153.0, 1022607788.0 },
   {    2824425944.0,   32183930.0, 2093834863.0 }
};

/*  A matrices powers from (A^76)^1 up to (A^76)^512 */
// __constant__ double A1_pows [11][3][3];
// __constant__ double A2_pows [11][3][3];

__device__ const double A1_pows [11][3][3] = { 
   {  { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } },
   {  { 82758667.0, 1871391091.0, 4127413238.0 }, { 3672831523.0,   69195019.0, 1871391091.0 }, { 3672091415.0, 3528743235.0, 69195019.0 } },
   {  { 3.36137e+09, 2.3293e+09, 9.96519e+07 } , { 2.00867e+09, 2.93176e+09, 2.3293e+09 } , { 1.11353e+09, 2.3741e+09, 2.93176e+09 } },
   {  { 2.13871e+09, 3.21018e+09, 2.30172e+08 } , { 1.01179e+09, 3.53602e+09, 3.21018e+09 } , { 2.84722e+09, 6.20673e+08, 3.53602e+09 } },
   {  { 1.83159e+09, 1.58826e+09, 1.31433e+09 } , { 2.38599e+09, 2.50808e+09, 1.58826e+09 } , { 1.78762e+09, 6.61437e+08, 2.50808e+09 } },
   {  { 2.04282e+09, 4.01645e+08, 4.01041e+09 } , { 3.99806e+09, 2.10605e+09, 4.01645e+08 } , { 2.29685e+09, 5.3118e+08, 2.10605e+09 } },
   {  { 2.1845e+09, 2.70304e+09, 2.30761e+09 } , { 1.51704e+09, 2.8237e+09, 2.70304e+09 } , { 1.78608e+09, 6.1756e+07, 2.8237e+09 } },
   {  { 3.24248e+09, 4.21073e+09, 5.20437e+08 } , { 6.68035e+07, 3.70726e+09, 4.21073e+09 } , { 1.46074e+09, 2.92168e+09, 3.70726e+09 } },
   {  { 2.32605e+09, 4.18359e+09, 4.04901e+09 } , { 2.60453e+09, 1.45391e+09, 4.18359e+09 } , { 2.31193e+09, 1.80536e+09, 1.45391e+09 } },
   {  { 4.14073e+09, 7.52526e+08, 2.82814e+09 } , { 1.99111e+09, 2.09751e+09, 7.52526e+08 } , { 1.67327e+09, 1.60257e+09, 2.09751e+09 } },
   {  { 1.96542e+09, 3.22182e+09, 2.04071e+09 } , { 1.26818e+09, 1.82502e+09, 3.22182e+09 } , { 2.88049e+09, 1.51013e+08, 1.82502e+09 } }
};

__device__ double A2_pows;/*[11][3][3] = {
   {  { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } },
   {  { 1.51133e+09, 3.75921e+09, 1.6108e+09 } , { 4.29275e+09, 1.51133e+09, 3.88992e+09 } , { 3.85966e+09, 4.29275e+09, 3.70847e+09 }},
   {  { 9.72103e+08, 9.64808e+08, 8.78036e+08 } , { 4.24855e+09, 9.72103e+08, 1.92663e+09 } , { 1.44863e+09, 4.24855e+09, 3.19611e+09 } },
   {  { 9.07239e+08, 2.92629e+09, 2.86585e+09 } , { 8.40689e+08, 9.07239e+08, 1.2492e+09 } , { 4.27877e+09, 8.40689e+08, 3.3311e+09 } },
   {  { 3.49738e+09, 3.17425e+09, 3.18251e+09 } , { 3.86482e+09, 3.49738e+09, 3.0384e+09 } , { 2.54688e+09, 3.86482e+09, 2.98021e+09 } },
   {  { 7.84581e+08, 2.65342e+09, 3.8428e+08 } , { 3.46234e+09, 7.84581e+08, 1.92303e+09 } , { 3.69099e+07, 3.46234e+09, 5.64222e+08 } },
   {  { 1.40581e+09, 4.17421e+09, 2.38421e+09 } , { 1.1278e+08, 1.40581e+09, 3.41212e+09 } , { 3.92527e+09, 1.1278e+08, 1.36504e+09 } },
   {  { 2.61947e+09, 3.13258e+06, 8.04703e+08 } , { 3.63047e+09, 2.61947e+09, 2.64523e+09 } , { 3.21677e+09, 3.63047e+09, 4.07219e+09 } },
   {  { 1.77634e+09, 1.18994e+09, 4.09576e+09 } , { 3.8136e+09, 1.77634e+09, 7.89476e+08 } , { 4.1197e+09, 3.8136e+09, 2.14536e+09 } },
   {  { 3.76949e+09, 1.0387e+09, 2.72404e+09 } , { 2.82675e+08, 3.76949e+09, 8.45493e+07 } , { 3.83672e+09, 2.82675e+08, 1.4121e+09 } },
   {  { 3.41941e+08, 2.19094e+09, 3.28734e+09 } , { 4.80943e+08, 3.41941e+08, 2.6028e+09 } , { 8.53742e+08, 4.80943e+08, 4.22841e+09 } }
};*/

// the following functions are used on both host and device sides
// they are marked inlined so that utils.h can be included
// in several compilation units without any linking problem


/**
 * Return (a*s + c) MOD m; a, s, c and m must be < 2^35
 *  \author Pierre L'Ecuyer
 */
 __host__ __device__ 
double MultModM (double a, double s, double c, double m)
{
   double v;
   long a1;
   
   v = a * s + c;
   
   if (v >= two53 || v <= -two53) {
      // changed static_casts to regular casts due to cuda
      a1 = (long) (a / two17); 
      a -= a1 * two17;
      
      v  = a1 * s;
      
      a1 = (long) (v / m);
      v -= a1 * m;
      
      v = v * two17 + a * s + c;
   }
   
   a1 = (long) (v / m);
   
   /* in case v < 0)*/
   if ((v -= a1 * m) < 0.0)    return v += m;   
   else                        return v;
}


/**
 * Compute the vector v = A*s MOD m. Assume that -m < s[i] < m.
 * Works also when v = s.
 *  \author Pierre L'Ecuyer
 */
 __host__ __device__
void MatVecModM (const double A[3][3], const double s[3], double v[3],
                 double m)
{
   int i;
   double x[3];               // Necessary if v = s
   
   for (i = 0; i < 3; ++i) {
      x[i] = MultModM (A[i][0], s[0], 0.0, m);
      x[i] = MultModM (A[i][1], s[1], x[i], m);
      x[i] = MultModM (A[i][2], s[2], x[i], m);
   }
   for (i = 0; i < 3; ++i)
      v[i] = x[i];
}


/**
 * Compute the matrix C = A*B MOD m. Assume that -m < s[i] < m.
 * Note: works also if A = C or B = C or A = B = C.
 *  \author Pierre L'Ecuyer
 */
 __host__ __device__
void MatMatModM (const double A[3][3], const double B[3][3],
                 double C[3][3], double m)
{
   int i, j;
   double V[3], W[3][3];
   
   for (i = 0; i < 3; ++i) {
      for (j = 0; j < 3; ++j)
         V[j] = B[j][i];
      MatVecModM (A, V, V, m);
      for (j = 0; j < 3; ++j)
         W[j][i] = V[j];
   }
   for (i = 0; i < 3; ++i)
      for (j = 0; j < 3; ++j)
         C[i][j] = W[i][j];
}

__device__
void MatVecModM_device (double* A, const double s[3], double v[3],
                 double m)
{
   int i;
   double x[3];               // Necessary if v = s
   
   for (i = 0; i < 3; ++i) {
      x[i] = MultModM (A[i*MATRIX_ROW + 0], s[0], 0.0, m);
      x[i] = MultModM (A[i*MATRIX_ROW + 1], s[1], x[i], m);
      x[i] = MultModM (A[i*MATRIX_ROW + 2], s[2], x[i], m);
   }
   for (i = 0; i < 3; ++i)
      v[i] = x[i];
}

 __device__
void MatMatModM_device ( double* A,  double* B,
                 double C[3][3], double m)
{
//    int i, j;
//    double V[3], W[3][3];
//    
//    for (i = 0; i < 3; ++i) {
//       for (j = 0; j < 3; ++j)
//          V[j] = B[j*MATRIX_ROW + i];
//       MatVecModM_device (A, V, V, m);
//       for (j = 0; j < 3; ++j)
//          W[j][i] = V[j];
//    }
//    for (i = 0; i < 3; ++i)
//       for (j = 0; j < 3; ++j)
//          C[i][j] = W[i][j];
      
//       C[1][0] = A1_pows[1 & (threadIdx.x >> 1)][0][0];
         C[2][0] = *B;
}


__device__
void MatPowModM (double* A,  double B[3][3], double m, long n)
{
    int i, j;
    double W[3][3];

    /* initialize: W = A; B = I */
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j) {
            W[i][j] = *(A + i * MATRIX_COLUMN + j);
            B[i][j] = 0.0;
        }
    for (j = 0; j < 3; ++j)
        B[j][j] = 1.0;

    /* Compute B = A^n mod m using the binary decomposition of n */
    while (n > 0) {
        if (n % 2) MatMatModM (W, B, B, m);
        MatMatModM (W, W, W, m);
        n /= 2;
    }
}

/**
 * Compute the matrix B = (A^(2^e) Mod m);  works also if A = B. 
 *
 *  \author Pierre L'Ecuyer
 */
 __host__
void MatTwoPowModM (const double A[3][3], double B[3][3], double m, long e)
{
   int i, j;
   
   /* initialize: B = A */
   if (A != B) {
      for (i = 0; i < 3; ++i)
         for (j = 0; j < 3; ++j)
            B[i][j] = A[i][j];
   }
   /* Compute B = A^(2^e) mod m */
   for (i = 0; i < e; i++)
      MatMatModM (B, B, B, m);
}
