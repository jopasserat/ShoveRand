#ifndef MRG32K3A_PARAMETERIZED_STATUS
#define MRG32K3A_PARAMETERIZED_STATUS


#include <shoverand/core/ParameterizedStatus.hxx>
#include <shoverand/prng/mrg32k3a/Stream.h>


// forward declaration of MRG32k3a class
namespace shoverand {
	namespace prng {	
		namespace MRG32k3a {

			template <class T>
			class MRG32k3a;
			
		}
	} // end of namespace prng
} // end of namespace shoverand


// TODO replace by expanded namespaces names in the code
using namespace shoverand::prng;

	/** ParameterizedStatus specialization for MRG32k3a */
	template <>
	class ParameterizedStatus<MRG32k3a::MRG32k3a> {
		
	public:
         MRG32k3a::Stream* allStreams_;
       	MRG32k3a::Stream* allStreams_host;
         
         double* A1p76;
         double* A2p76;
         double* A1p127;
         double* A2p127;

         double* A1_pows;
         double* A2_pows;
			
			// following array are static to allow to initialization of const values
			static const double A1p0_host[3][3];
			static const double A2p0_host[3][3];
			static const double A1p76_host[3][3];
			static const double A2p76_host[3][3];
			static const double A1p127_host[3][3];
			static const double A2p127_host[3][3];
			
			static const double A1_pows_host[11][3][3];
			static const double A2_pows_host[11][3][3];


	public:
		
			// TODO find a way to default construct correctly
         __host__
         ParameterizedStatus<MRG32k3a::MRG32k3a>() {
				
				
         }
		
         __host__
         void setUp (unsigned short blocksNumber);

			__host__
			void release();
				
   };

	

namespace shoverand {
	namespace prng {	
		namespace MRG32k3a {
				typedef ::ParameterizedStatus < ::MRG32k3a::MRG32k3a > ParameterizedStatusMRG32k3a;
		}
	} // end of namespace prng
} // end of namespace shoverand


#endif // MRG32K3A_PARAMETERIZED_STATUS
