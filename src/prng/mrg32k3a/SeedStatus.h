#ifndef MRG32k3A_SEED_STATUS
#define MRG32k3A_SEED_STATUS

#include <shoverand/core/SeedStatus.hxx>

#include "ParameterizedStatus.h"
#include "Stream.h"
#include "utils.h"


// forward declaration of class MRG32k3a
namespace shoverand { namespace prng {	 namespace MRG32k3a {
			
			template <class T>
			class MRG32k3a;
			
		}
	} // end of namespace prng
} // end of namespace shoverand


// out of namespace to allow template specialization 
// TODO add to core namespace

	/** SeedStatus specialization for MRG32k3a. It implements SubStream's functionnalities
	    of the original algorithm. 
	*/
	template <>
	class SeedStatus<shoverand::prng::MRG32k3a::MRG32k3a> {

	private:
		typedef shoverand::prng::MRG32k3a::ParameterizedStatusMRG32k3a ParameterizedStatusMRG32k3a;
		
	  public: 
		double Cg_[6];
		
		
	public:
		__host__ __device__
		SeedStatus<shoverand::prng::MRG32k3a::MRG32k3a> () {}
		
		__device__
		void setUp (ParameterizedStatusMRG32k3a* params) {
			
			shoverand::prng::MRG32k3a::Stream* stream  = params->allStreams_ + (gridDim.x * blockIdx.y + blockIdx.x);
			
			for (unsigned i = 0; i < 6; ++i) {
				Cg_[i] = stream->getCg(i);
			}
			
			// advance to the SubStream corresponding to thread id IN THE BLOCK
			this->jumpAhead(params,
								 blockDim.y * blockDim.x * threadIdx.z + blockDim.x * threadIdx.y + threadIdx.x);
		}
	
	private:
		__device__
		void jumpAhead(ParameterizedStatusMRG32k3a* params, long pow) {
			
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


			shoverand::utils::Math::MatPowModM(params->A1p76_, A1_pN, m1, pow);  // (A1^(2^76))^n mod m
			shoverand::utils::Math::MatPowModM(params->A2p76_, A2_pN, m2, pow);  // (A2^(2^76))^n mod m

			shoverand::utils::Math::MatVecModM(A1_pN, Cg_, Cg_, m1);
			shoverand::utils::Math::MatVecModM(A2_pN, &(Cg_[3]), &(Cg_[3]), m2);

		}

	};
	
namespace shoverand {
	namespace prng {	
		namespace MRG32k3a {
	typedef ::SeedStatus < shoverand::prng::MRG32k3a::MRG32k3a > SeedStatusMRG32k3a;
		}
	} // end of namespace prng
} // end of namespace shoverand
	
	
#endif // MRG32k3A_SEED_STATUS
