/*
 *  MRG32k3a.hxx
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 1/31/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef MRG32k3a_HXX
#define MRG32k3a_HXX


#include <shoverand/core/SeedStatus.hxx>
//#include <shoverand/prng/mrg32k3a/Stream.cu>
#include <shoverand/prng/mrg32k3a/SubStream.h> // TODO shouldn't be included here

#include <shoverand/prng/mrg32k3a/ParameterizedStatus.h>
#include <shoverand/prng/mrg32k3a/SeedStatus.h>
#include <shoverand/core/RNG.hxx>


	
namespace shoverand {
	namespace prng {	
		namespace MRG32k3a {

			/** Class statically checking the RNGAlgorithm policy's interface.
			Most of this class' methods are marked as __host__ so that BCCL
			can check their presence. 
			You should use them in device code only, when nothing precised.
			*/
			// TODO force people to use it through RNG<>
			template < class T >
			class MRG32k3a {
				
				
			public:
				
				// TODO insert in core namespace
				typedef SeedStatusMRG32k3a 			SeedStatusType;
				typedef ParameterizedStatusMRG32k3a ParameterizedStatusType;

			private:

				SeedStatusType ss_;
				ParameterizedStatusType* ps_;
				
				/** SubStream defining the random sequence allocated to current thread */
				SubStream*	s_;
				
				
			public:
				
				__device__
				MRG32k3a(ParameterizedStatusType* ps)
				:ss_(SeedStatusType(23)), ps_(ps) 
				{}
				
				
				/** Init is divided in two parts:
				* 	- first, initialize the different streams for every threadblock
				* 	- second, allocate a SubStream per thread
				*/
				__host__ __device__
				void init() {

					// create the independent random sequence associated to current thread
					s_ = new SubStream(ps_);
				}
				
				__host__ __device__
				T next() {
					return s_->next();
				}
				

				// concept checking class 
				// (friend allows to expose private methods to this class only)
				template <class U, template <typename> class Algo>
				friend class RNGAlgorithm;

			};

		} // end of namespace MRG32k3a
	} // end of namespace prng
} // end of namespace shoverand

#endif // MRG32k3a_HXX
