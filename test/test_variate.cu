/*
 *  test_variate.cu
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/13/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#include <iostream>


#include <shoverand/distribution/variate_generator.hpp>
#include <shoverand/distribution/uniform_01.hpp>

#include <shoverand/prng/mrg32k3a/MRG32k3a.hxx>
#include <shoverand/prng/mrg32k3a/ParameterizedStatus.h>

using shoverand::MRG32k3a;

int main(int, char**) {
   boost::uniform_01<double, double>          		 distribution;
	MRG32k3a< double >::ParameterizedStatusType	    p;
	MRG32k3a< double >							 			 engine(p) ;
	
	std::cout << distribution(engine) << std::endl << engine() << std::endl;

   //distribution(engine);
      
   boost::variate_generator
         < 
         MRG32k3a< double >,
         boost::uniform_01<double, double>
         >
         
         myVariateGenerator(engine, distribution);

	std::cout << "variate = " << myVariateGenerator() << std::endl;
   
   return 0;
}
