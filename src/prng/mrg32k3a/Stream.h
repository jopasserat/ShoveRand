/***********************************************************************\
 * \file Created by jH@CKtheRipper, 04/04/11 
 *       Stream and Substream classes declarations
 *       Inspired from Pierre L'Ecuyer's original RngStream.h
 * \author jH@CKtheRipper
 \***********************************************************************/



#ifndef STREAM_H
#define STREAM_H

#include <iosfwd>

namespace MRG32k3a {
   
   /** Class Stream represents random streams on the host.
      It does not appear on the device since threads are 
      only handling independent sub-streams.
    */
   class Stream {
   public:
      
      /** Stream class default constructor */
      __host__ explicit Stream();
      
      /** Stream constants initializations
         \param blocksNumber Number of blocks in the considered kernel: will
                           be equivalent to the number of created Streams.
       */
      __host__ static void init(unsigned int blocksNumber);
      
      /** Free memory on both sides */
      __host__ static void destroy();
      
      // static members
      
      /* Global Streams that will serve as a base from sub-streams (device side) */
      static Stream* allStreams;
      
      /** Global Streams that will serve as a base from sub-streams (host equivalent) */
      static Stream* allStreams_host;
      
      // getters
      
      __host__ __device__ inline double getCg(unsigned i) const {
         return Cg_[i];
      }
      
      __host__ __device__ inline double getBg(unsigned i) const {
         return Bg_[i];
      }
      
//   private:
	public:
      double Cg_[6];
      double Bg_[6];
      double Ig_[6];
      
      /** Seed used for the next created stream */
      static double nextSeed__[6];


	// TODO: remove this section (debug purpose only)
	public:
	friend std::ostream& operator<< (std::ostream&, const Stream&);

   };
   
} // end of namespace MRG32k3a



#endif // STREAM_H
