	/***********************************************************************\
	* \file Created by jH@CKtheRipper, 04/04/11
	*       Stream and Substream classes declarations
	*       Inspired from Pierre L'Ecuyer's original RngStream.h
	* \author jH@CKtheRipper
	\***********************************************************************/


#include <cuda.h>

#include "Stream.h"
#include "ParameterizedStatus.h"
#include "utils.h" // TODO move to details

namespace shoverand {
	namespace prng {
		namespace MRG32k3a {

			/**
			The default seed of the package; will be the seed of the first
			declared RngStream, unless SetPackageSeed is called.
			*/
			double Stream::nextSeed__[6] =
			{
				12345.0, 12345.0, 12345.0, 12345.0, 12345.0, 12345.0
			};


			/**
			* Stream constructor
			*/
			__host__
			Stream::Stream () {

				/* Information on a stream. The arrays {Cg, Bg, Ig} contain respecively
						the current state of the stream, the starting state of the current
						SubStream, and the starting state of the stream. nextSeed__
						will be the seed of the next declared RngStream. */


				for (int i = 0; i < 6; ++i) {
					Cg_[i] = nextSeed__[i];
				}

				shoverand::utils::Math::MatVecModM (ParameterizedStatusMRG32k3a::A1p127_host, nextSeed__, nextSeed__, m1);
				shoverand::utils::Math::MatVecModM (ParameterizedStatusMRG32k3a::A2p127_host, &nextSeed__[3], &nextSeed__[3], m2);

			}

		} // end of namespace MRG32k3a
	} // end of namespace prng
} // end of namespace shoverand
