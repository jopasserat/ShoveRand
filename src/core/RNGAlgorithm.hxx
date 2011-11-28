/*
 *  RNGAlgorithm.hxx
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 1/31/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef RNG_ALGORITHM_HXX
#define RNG_ALGORITHM_HXX

#include <boost/concept_check.hpp>

#include "SeedStatus.hxx"
#include "ParameterizedStatus.hxx"

/** Class describing the RNGAlgorithm policy. */
template < 
         class T,
         template <class> class Algo
         >
class RNGAlgorithm {

private:
	Algo<T> al_;
   T value_;
   SeedStatus< Algo > ss_;
   ParameterizedStatus< Algo >* ps_;
   
   
private:
   template <class U>
   void same_type(const U&, const U&);
   
   
public:
	
	// TODO add variate_generator must_haves
	// TODO force RNG implementations to provide SeedStatusType and ParameterizedStatusType typdefs
	
	
	// concept requirements
	BOOST_CONCEPT_USAGE(RNGAlgorithm) {
      al_.init(42);                // require Algo<T>::init()
      al_.release();					// require Algo<T>::release()
		value_ = al_.next();       // require T Algo<T>::next() 
      same_type(ss_, al_.ss_);   // require Algo<T>::ss_ to be of SeedStatus<Algo> type
     
		// TODO find a way to check ParameterizedStatus
		// same_type(ps_, al_.ps_);   // require Algo<T>::ps_ to be of ParameterizedStatus<Algo> type
   }

};

#endif // RNG_ALGORITHM_HXX
