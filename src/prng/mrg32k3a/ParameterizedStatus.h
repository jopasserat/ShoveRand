#ifndef MRG32K3A_PARAMETERIZED_STATUS
#define MRG32K3A_PARAMETERIZED_STATUS


#include <shoverand/core/ParameterizedStatus.hxx>


// forward declaration of MRG32k3a class
namespace shoverand {
	namespace prng {	
		namespace MRG32k3a {

			template <class T>
			class MRG32k3a;
			
			class Stream;
			
		}
	} // end of namespace prng
} // end of namespace shoverand


/** ParameterizedStatus specialization for MRG32k3a */
template <>
class ParameterizedStatus<shoverand::prng::MRG32k3a::MRG32k3a> {
	
	private:
		
		typedef shoverand::prng::MRG32k3a::Stream Stream;
		
  public: // TODO try to get rid of this public qualifier
	// following members will be stored in device memory
	  
   Stream* allStreams_;
	
   double* A1p76_;
   double* A2p76_;
   double* A1p127_;
   double* A2p127_;

   double* A1_pows_;
   double* A2_pows_;
	
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
	ParameterizedStatus<shoverand::prng::MRG32k3a::MRG32k3a>() {
		
		
	}

	/** Allocate memory for ParameterizedStatus elements
	 *  on device.
	 * This method must be called before every kernel launch.
	 * Memory then needs to be manually released by a call to shutdown.
	 * @param blocksNumber Number of blocks in the kernel that is to
	 * 						  be launched.
	 * @see shutdown
	 * */
	__host__ 
	void setUp (unsigned short blocksNumber);

	/** Release device memory allocated by setUp.
	 * This method MUST BE CALLED AFTER setUp.
	 * @see setUp
	 * */
	__host__ 
	void shutdown();
	
		
};

	

namespace shoverand {
	namespace prng {	
		namespace MRG32k3a {
				typedef ::ParameterizedStatus < shoverand::prng::MRG32k3a::MRG32k3a > ParameterizedStatusMRG32k3a;
		}
	} // end of namespace prng
} // end of namespace shoverand


#endif // MRG32K3A_PARAMETERIZED_STATUS
