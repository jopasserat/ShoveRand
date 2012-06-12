#ifndef TINYMT_SEED_STATUS
#define TINYMT_SEED_STATUS

#include <shoverand/core/SeedStatus.hxx>

#include "ParameterizedStatus.h"


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
	// not available through forward declaration only
	//typedef shoverand::prng::TinyMT::unsigned int 			   unsigned int;

  public:
		unsigned int status0_;
		unsigned int status1_;
		unsigned int status2_;
		unsigned int status3_;

public:
	__host__ __device__
	SeedStatus<shoverand::prng::TinyMT::TinyMT> () {}

	__device__
	SeedStatus<shoverand::prng::TinyMT::TinyMT> (ParameterizedStatusTinyMT* params) {
		
//			shoverand::prng::TinyMT::Stream* stream  = params->allStreams_ + (gridDim.x * blockIdx.y + blockIdx.x);
		
		// advance to the SubStream corresponding to thread id IN THE BLOCK
		this->jumpAhead(params,
							 blockDim.y * blockDim.x * threadIdx.z + blockDim.x * threadIdx.y + threadIdx.x);
	}

private:
	__device__
	/** Allow jump ahead in the sequence */
	void jumpAhead(ParameterizedStatusTinyMT* params, long pow) {
		// TODO
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
