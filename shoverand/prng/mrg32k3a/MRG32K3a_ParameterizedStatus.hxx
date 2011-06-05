/*
 *  MRG32k3a_ParameterizedStatus.hxx
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 3/17/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef MRG32k3a_PARAMETERIZEDSTATUS_HXX
#define MRG32k3a_PARAMETERIZEDSTATUS_HXX

#include <ParameterizedStatus.hxx>

template <class T>
class MRG32k3a;

namespace shoverand {
namespace prng {

   
template<>
class ParameterizedStatus<MRG32k3a> {
   
};

   
} // end of namespace prng
} // end of namespace shoverand

#endif // MRG32k3a_PARAMETERIZEDSTATUS_HXX
