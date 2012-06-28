/*
 *  MTGP.hxx
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 1/31/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef MTGP_HXX
#define MTGP_HXX

#include <SeedStatus.hxx>
#include <ParameterizedStatus.hxx>


#include "mtgp-cuda-common.h"

#include "to-move-into-class.h"
//#include "mtgp32-cuda-cuterandAPI.h"




template <class T>
class MTGP;


/** SeedStatus specialization for MTGP */
template <>
class SeedStatus<MTGP> {
   // TODO
public: int toto;
   SeedStatus<MTGP> (int i):toto(i) {} 
};

/** ParameterizedStatus specialization for MTGP */
template <>
class ParameterizedStatus<MTGP> {
   // TODO
};

typedef SeedStatus<MTGP> SeedStatusMTGP;
typedef ParameterizedStatus<MTGP> ParameterizedStatusMTGP;

/** Class statically checking the RNGAlgorithm policy's interface. */
template < class T >
class MTGP {

private:

   SeedStatusMTGP ss_;
   ParameterizedStatusMTGP ps_;
   int toto;
   
public:

   __device__
   MTGP():ss_(SeedStatusMTGP(23)) { }
   
   __host__ void init() {
     // this->make_constant_param(NULL, 42);
     // this->make_texture(NULL, NULL, 42);
   }
   
   
   __host__ __device__
   T next();
   
   __device__ T foo();

   // concept checking class 
   // (friend allows to expose private methods to this class only)
   template <class U, template <typename> class Algo>
   friend class RNGAlgorithm;
   
private:
   // TODO: change functions calls to methods...
   
};


template <class T>
T MTGP<T>::next() {

      int pos = pos_tbl[blockIdx.x];
      int index = threadIdx.x;
      uint32_t r;
      float o;
      
      // copy status data from global memory to shared memory.
      status_read(status, d_status, blockIdx.x, threadIdx.x);
      
   
         r = para_rec(status[index],
                      status[(index + 1) % LARGE_SIZE],
                      status[(index + pos) % LARGE_SIZE],
                      blockIdx.x);
         status[(index + N) % LARGE_SIZE] = r;
         o = temper_single(r, status[(index + pos - 1) % LARGE_SIZE], blockIdx.x);
         d_data[size * blockIdx.x + i + threadIdx.x] = o;
         __syncthreads();
         index = (index + THREAD_NUM) % LARGE_SIZE;
      
      // write back status for next call
      status_write(d_status, status, blockIdx.x, threadIdx.x, index);
   
   return 
}

template <class T>
T MTGP<T>::foo() {
   return ss_.toto;
}

#endif // MTGP_HXX
