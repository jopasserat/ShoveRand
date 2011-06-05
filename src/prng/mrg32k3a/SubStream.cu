/** Empty since function/methods calls implies inlining.
 \see SubStream.h
 */


/*#include <cuda.h>

#include <SubStream.h>
#include <Stream.h>
#include <utils.h>
*/

namespace MRG32k3a {
 
   /** Init through RngStream
    \param s Stream used as a base for current sub-stream
    \author jH@CKtheRipper
    */
  /* __device__
   SubStream::SubStream(Stream allStreams[]) {
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
   
   */
   
   /** 
    Draw next number
    \author jH@CKtheRipper
    */
 /*  __device__
   double SubStream::next() {
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
  */ 
   
   /** 
    Rise A matrices to the power of n.
    
    \param n Number of jumps through the SubStreams.
    If n is set to 0, the current stream is 
    resetted to its original state.
    \author jH@CKtheRipper
    */
   /* __device__ 
    void SubStream::jumpAhead(long pow) {
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
   */
} // end of namespace MRG32k3a
