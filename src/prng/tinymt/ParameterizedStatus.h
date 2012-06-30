#ifndef TINYMT_PARAMETERIZED_STATUS
#define TINYMT_PARAMETERIZED_STATUS

#include <shoverand/core/ParameterizedStatus.hxx>
#include <string>

// forward declaration of MRG32k3a class
namespace shoverand {
	namespace prng {
		namespace TinyMT {

			template <class T>
			class TinyMT;
		}
	} // end of namespace prng
} // end of namespace shoverand

/** ParameterizedStatus specialization for TinyMT */
template <>
class ParameterizedStatus<shoverand::prng::TinyMT::TinyMT> {
public:
	unsigned int mat1_;
	unsigned int mat2_;
	unsigned int tmat_;


public:

	__host__
	void setUp(unsigned short inBlockId);

	__host__
	void shutdown();

private:
	static const std::string filename_;
};

namespace shoverand {
	namespace prng {
		namespace TinyMT {
				typedef ::ParameterizedStatus < shoverand::prng::TinyMT::TinyMT > ParameterizedStatusTinyMT;
		}
	} // end of namespace prng
} // end of namespace shoverand

#endif // TINYMT_PARAMETERIZED_STATUS
