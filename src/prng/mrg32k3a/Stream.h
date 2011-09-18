/***********************************************************************\
 * \file Created by jH@CKtheRipper, 04/04/11 
 *       Stream and Substream classes declarations
 *       Inspired from Pierre L'Ecuyer's original RngStream.h
 * \author jH@CKtheRipper
 \***********************************************************************/



#ifndef STREAM_H
#define STREAM_H

namespace shoverand {
	namespace prng {
		namespace MRG32k3a {
			
			/** Class Stream represents random streams on the host.
				It does not appear on the device since threads are 
				only handling independent sub-streams.
			*/
			class Stream {
			public:
				
				/** Stream class default constructor */
				__host__
				explicit Stream();


				// getters
				
				__host__ __device__ inline double getCg(unsigned i) const {
					return Cg_[i];
				}
				
		//   private:
			public:
				double Cg_[6];
				
				/** Bg and Ig are unused in this implementation */
				//double Bg_[6];
				//double Ig_[6];
				
				/** Seed used for the next created stream */
				static double nextSeed__[6];

			};
			
		} // end of namespace MRG32k3a
	} // end of namespace prng
} // end of namespace shoverand


#endif // STREAM_H
