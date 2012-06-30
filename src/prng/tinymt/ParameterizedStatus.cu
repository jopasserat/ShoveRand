
#include "ParameterizedStatus.h"
#include "Stream.h"

#include <cuda.h>
#include <shoverand/util/myCutil.h>

#include <shoverand/util/tinymt/util.hxx>

// TODO let users defining it at runtime
const std::string ParameterizedStatus<shoverand::prng::TinyMT::TinyMT> :: filename_ = "../../test/tinymt32dc.0.20.txt";

__host__
void ParameterizedStatus<shoverand::prng::TinyMT::TinyMT> :: setUp (unsigned short inBlockId) {
	// TODO figure out how to statically determine template param instead of plain
	// unsigned int
	shoverand::util::TinyMT<unsigned int>::setParams(
			ParameterizedStatus<shoverand::prng::TinyMT::TinyMT> :: filename_.c_str(),
			&mat1_,
			&mat2_,
			&tmat_,
			inBlockId
	);

}

__host__
void ParameterizedStatus<shoverand::prng::TinyMT::TinyMT> :: shutdown() {

}
