/*
 *  SubStream.h
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/7/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef SubStream_H
#define SubStream_H


#include <Stream.h>
#include <utils.h>
#include <cmath>

namespace MRG32k3a {
   
   
   class SubStream {
   private:
      /** Current sub-stream state */
      double Cg_[6]; 
      
      /** Starting state of the current sub-stream */
      double Bg_[6];
      
   public:
      
      /** Init through RngStream
       \param s Stream used as a base for current sub-stream
       */
      __device__ SubStream(Stream allStreams[]) {
         
         // get stream corresponding to block id
         Stream* stream  = allStreams + (blockIdx.x * blockDim.x + blockIdx.y);
         
         // copy stream state in current SubStream
         for (unsigned i = 0; i < 6; ++i) {
            Cg_[i] = stream->getCg(i);
            Bg_[i] = stream->getBg(i);
         }
         
         // advance to the SubStream corresponding to thread id
         this->jumpAhead(threadIdx.x + blockDim.x * threadIdx.y);
      }
      
      
      /** Draw next number */
      __device__ double next() {
         
         long k;
         double p1, p2, u;
         
         // changed static_casts to regular casts due to cuda
         
         // Component 1
         p1 = a12 * Cg_[1] - a13n * Cg_[0];
         k = (long) (p1 / m1);
         p1 -= k * m1;
         
         if (p1 < 0.0)  p1 += m1;
         
         Cg_[0] = Cg_[1]; Cg_[1] = Cg_[2]; Cg_[2] = p1;
         
         // Component 2
         p2 = a21 * Cg_[5] - a23n * Cg_[3];
         k = (long) (p2 / m2);
         p2 -= k * m2;
         
         if (p2 < 0.0) p2 += m2;
         
         Cg_[3] = Cg_[4]; Cg_[4] = Cg_[5]; Cg_[5] = p2;
         
         // Combination
         u = ((p1 > p2) ? (p1 - p2) * norm : (p1 - p2 + m1) * norm);
         
         return u;
      }
      
      
      /** Jump n SubStreams ahead in current stream
       \param n Number of sub-streams to jump
       */
      __device__ void jumpAhead(long pow) {
         
         double A1_pN[3][3] = {
            {       0.0,        1.0,       0.0 },
            {       0.0,        0.0,       1.0 },
            { -810728.0,  1403580.0,       0.0 }
         };
         
         double A2_pN[3][3] = {
            {        0.0,        1.0,       0.0 },
            {        0.0,        0.0,       1.0 },
            { -1370589.0,        0.0,  527612.0 }
         };
         
         
         
         MyMatPowModM(A1_pN, A2_pN, pow);
         
         
         MatVecModM(A1_pN, Bg_, Bg_, m1);
         MatVecModM(A2_pN, &Bg_[3], &Bg_[3], m2);
         
         for (unsigned i = 0; i < 6; ++i) {
            Cg_[i] = Bg_[i];
         }
      }
      
   };
   
} // end of namespace MRG32k3a

#endif // SubStream_H
