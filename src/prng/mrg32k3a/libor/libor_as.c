// ***********************************************
// LIBOR Market Model with adjoint sensitivities
// ***********************************************
// 
// This example calculates the value of swaption portfolio
// using a standard C implementation
//
// The example can by compiled with:
//
//  gcc -O3 -ffast-math -o libor_as libor_as.c -lm
//


#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>


#define NPATH 96*1000

/* Monte Carlo LIBOR path calculation                      */

void path_calc(const int N, const int Nmat, const double delta,
               double L[], const double lambda[], const double z[])
{
  int      i, n;
  double   sqez, lam, con1;
  double v, vrat;

  for(n=0; n<Nmat; n++) {
    sqez = sqrt(delta)*z[n];

    v = 0.0;
    for (i=n+1; i<N; i++) {
      lam  = lambda[i-n-1];
      con1 = delta*lam;
      v   += (con1*L[i])/(1.0+delta*L[i]);
      vrat = exp(con1*v + lam*(sqez-0.5*con1));
      L[i] = L[i]*vrat;
    }
  }
}


/* forward path calculation storing data
   for subsequent reverse path calculation */

void path_calc_b1(const int N, const int Nmat, const double delta,
                  double L[], const double lambda[], const double z[],
                  double L2[])
{
  int    i, n;
  double sqez, lam, v, vrat, con1;

  for (i=0; i<N; i++) L2[i] = L[i];
   
  for(n=0; n<Nmat; n++) {
    sqez = sqrt(delta)*z[n];

    v = 0;
    for (i=n+1; i<N; i++) {
      lam  = lambda[i-n-1];
      con1 = delta*lam;
      v   += (con1*L[i])/(1.0+delta*L[i]);
      vrat = exp(con1*v + lam*(sqez-0.5*con1));
      L[i] = L[i]*vrat;

      // store these values for reverse path //
      L2[i+(n+1)*N] = L[i];
    }
  }
}


/* reverse path calculation of deltas using stored data */

void path_calc_b2(const int N, const int Nmat, const double delta,
                  double L_b[], const double lambda[],
                  const double z[], const double L2[])
{
  int    i, n;
  double faci, v1;

  for (n=Nmat-1; n>=0; n--) {
    v1 = 0.0;
    for (i=N-1; i>n; i--) {
      v1    += lambda[i-n-1]*L2[i+(n+1)*N]*L_b[i];
      faci   = delta/(1.0+delta*L2[i+n*N]);
      L_b[i] = L_b[i]*L2[i+(n+1)*N]/L2[i+n*N]
              + v1*lambda[i-n-1]*faci*faci;
    }
  }
}


/* calculate the portfolio value v */

void portfolio(const int N, const int Nmat, const double delta,
               const int Nopt, const int maturities[],
               const double swaprates[],
               const double L[], double *v )
{
  int    i, m, n;
  double b, s, swapval;
  double *B, *S;

  B = (double *)malloc(sizeof(double)*N);
  S = (double *)malloc(sizeof(double)*N);

  b = 1.0;
  s = 0.0;

  for (n=Nmat; n<N; n++) {
    b    = b/(1.0+delta*L[n]);
    s    = s + delta*b;
    B[n] = b;
    S[n] = s;
  }

  *v = 0;

  for (i=0; i<Nopt; i++){
    m = maturities[i] + Nmat-1;
    swapval = B[m] + swaprates[i]*S[m] - 1.0;
    if (swapval<0)
      *v += -100.0*swapval;
  }

  // apply discount //

  for (n=0; n<Nmat; n++)
    *v = *v/(1.0+delta*L[n]);

  free(B);
  free(S);
 }


/* calculate the portfolio value v, and its sensitivity to L */
/* hand-coded reverse mode sensitivity */

void portfolio_b(const int N, const int Nmat, const double delta, 
                 const int Nopt, const int maturities[],
                 const double swaprates[],
                 const double L[], double L_b[], double *v) 
{
  int      m, n;
  double   b, s, swapval;
  double   *B, *S, *B_b, *S_b;

  B   = (double *)malloc(sizeof(double)*(N-Nmat));
  S   = (double *)malloc(sizeof(double)*(N-Nmat));
  B_b = (double *)malloc(sizeof(double)*(N-Nmat));
  S_b = (double *)malloc(sizeof(double)*(N-Nmat));

  // for (n=0; n<N; n++) L_b[n] = 0;

  b = 1.0;
  s = 0.0;
  for (m=0; m<N-Nmat; m++) {
    n    = m + Nmat;
    b    = b/(1.0+delta*L[n]);
    s    = s + delta*b;
    B[m] = b;
    S[m] = s;
  }

  *v = 0;

  for (m=0; m<N-Nmat; m++) {
    B_b[m] = 0;
    S_b[m] = 0;
  }

  for (n=0; n<Nopt; n++){
    m = maturities[n] - 1;
    swapval = B[m] + swaprates[n]*S[m] - 1.0;
    if (swapval<0) {
      *v     += -100*swapval;
      S_b[m] += -100*swaprates[n];
      B_b[m] += -100;
    }
  }

  for (m=N-Nmat-1; m>=0; m--) {
    n = m + Nmat;
    B_b[m] += delta*S_b[m];
    L_b[n]  = -B_b[m]*B[m]*delta/(1.0+delta*L[n]);
    if (m>0) {
      S_b[m-1] += S_b[m];
      B_b[m-1] += B_b[m]/(1.+delta*L[n]);
    }
  }

  // apply discount //

  b = 1.0;
  for (n=0; n<Nmat; n++) b = b/(1.0+delta*L[n]);

  *v = b*(*v);

  for (n=0; n<Nmat; n++){
    L_b[n] = -(*v)*delta/(1.0+delta*L[n]);
  }

  for (n=Nmat; n<N; n++){
    L_b[n] = b*L_b[n];
  }

  free(B);
  free(S);
  free(B_b);
  free(S_b);
}


/* -------------------------------------------------------- */

int main()
{

   double delta = 0.25; /* LIBOR interval  */

   // data for swaption portfolio //
   int    Nopt = 15;
   int    maturities[] = {4,4,4,8,8,8,20,20,20,28,28,28,40,40,40};
   double swaprates[]  = {.045,.05,.055,.045,.05,.055,.045,.05,
                         .055,.045,.05,.055,.045,.05,.055 };

   int       i, N, Nmat, path, npath;
   double    v, *L, *lambda, *z, *L2, *L_b;
   double    v_sum[2] = {0.0};
  
   Nmat = 40;
   N = Nmat+40;
   
   L        = (double *)malloc(sizeof(double)*N);
   L2       = (double *)malloc(sizeof(double)*N*(Nmat+1));
   L_b      = L;
   lambda   = (double *)malloc(sizeof(double)*N);
   z        = (double *)malloc(sizeof(double)*Nmat);
  
   npath = NPATH;

  //----------------------------------------------------------//
  //                                                          //
  // A real application would generate a different random     //
  // vector z for each path but here we set one and reuse it  //
  //                                                          //
  //----------------------------------------------------------//
     
   for (i = 0 ; i < Nmat ; i++) z[i] = 0.3;


   for (path=0; path<npath; path++) {
                   
      for(i=0;i<N;i++) 
      {
        L[i] = 0.05;
        lambda[i] = 0.2;
      }
      
      // path_calc(N,Nmat,delta,L,lambda,z);
      // portfolio(N,Nmat,delta,Nopt,maturities,swaprates,L,&v);
      
      path_calc_b1(N,Nmat,delta,L,lambda,z,L2);
      portfolio_b(N,Nmat,delta,Nopt,maturities,swaprates,L,L_b,&v);
      path_calc_b2(N,Nmat,delta,L_b,lambda,z,L2);
      
      v_sum[0] = v_sum[0] + v;
      v_sum[1] = v_sum[1] + L_b[N-1];
      //printf("path = % d, v = %f\n", path, v); 
       
  }
    
  printf("v   = %f\n", v_sum[0]/npath);
  printf("L_b = %f\n", v_sum[1]/npath);
  printf("The Number of Simulation = %d\n", npath);

  return 0;
}
