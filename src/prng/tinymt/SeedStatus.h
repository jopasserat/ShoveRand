#ifndef TINYMT_SEED_STATUS
#define TINYMT_SEED_STATUS

#include <shoverand/core/SeedStatus.hxx>

#include "ParameterizedStatus.h"
#include "Stream.h"
#include "utils.h"


// forward declaration of class TinyMT
namespace shoverand { namespace prng {	 namespace TinyMT {
			
			template <class T>
			class TinyMT;
			
		}
	} // end of namespace prng
} // end of namespace shoverand


// out of namespace to allow template specialization 
// TODO add to core namespace

	/** SeedStatus specialization for TinyMT. It implements SubStream's functionnalities
	    of the original algorithm. 
	*/
	template <>
	class SeedStatus<shoverand::prng::TinyMT::TinyMT> {

	private:
		typedef shoverand::prng::TinyMT::ParameterizedStatusTinyMT ParameterizedStatusTinyMT;
		typedef shoverand::prng::TinyMT::result_type result_type;
		
	  public: 
		    result_type status[4];
			 result_type mat1;
			 result_type mat2;
			 result_type tmat;
		
		
	public:
		__host__
		SeedStatus<shoverand::prng::TinyMT::TinyMT> () {}
		
		__device__
		SeedStatus<shoverand::prng::TinyMT::TinyMT> (ParameterizedStatusTinyMT* params) {
			
			shoverand::prng::TinyMT::Stream* stream  = params->allStreams_ + (gridDim.x * blockIdx.y + blockIdx.x);
			
			for (unsigned i = 0; i < 6; ++i) {
				Cg_[i] = stream->getCg(i);
			}
			
			// advance to the SubStream corresponding to thread id IN THE BLOCK
			this->jumpAhead(params,
								 blockDim.y * blockDim.x * threadIdx.z + blockDim.x * threadIdx.y + threadIdx.x);
		}
	
	private:
		__device__
		void jumpAhead(ParameterizedStatusTinyMT* params, long pow) {
			
			/** A1^N temporary matrix */
			double A1_pN[3][3] = {
				{       0.0,        1.0,       0.0 },
				{       0.0,        0.0,       1.0 },
				{ -810728.0,  1403580.0,       0.0 }
			};
			
			/** A2^N temporary matrix */
			double A2_pN[3][3] = {
				{        0.0,        1.0,       0.0 },
				{        0.0,        0.0,       1.0 },
				{ -1370589.0,        0.0,  527612.0 }
			};


			shoverand::utils::Math::MatPowModM(params->A1p76, A1_pN, m1, pow);  // (A1^(2^76))^n mod m
			shoverand::utils::Math::MatPowModM(params->A2p76, A2_pN, m2, pow);  // (A2^(2^76))^n mod m

			shoverand::utils::Math::MatVecModM(A1_pN, Cg_, Cg_, m1);
			shoverand::utils::Math::MatVecModM(A2_pN, &(Cg_[3]), &(Cg_[3]), m2);

		}

	};
	
namespace shoverand {
	namespace prng {	
		namespace TinyMT {
	typedef ::SeedStatus < shoverand::prng::TinyMT::TinyMT > SeedStatusTinyMT;
		}
	} // end of namespace prng
} // end of namespace shoverand
	
	
#endif // TINYMT_SEED_STATUS
