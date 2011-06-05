/*
 *  test_variate.cu
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/13/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#include <shoverand/distribution/variate_generator.hpp>
#include <shoverand/distribution/uniform_01.hpp>
#include <thrust/random.h>


class myrandomengine : public thrust::random::default_random_engine {
  public:
  
};

int main(int, char**) {
   boost::uniform_01<double, double>                          distribution;
   myrandomengine                             engine;
   distribution<boost::uniform_01 >(engine);
 
   /*  
   boost::variate_generator
         < 
         thrust::random::default_random_engine,
         thrust::random::uniform_real_distribution<float>
         >
         
         myVariateGenerator(engine, distribution);
   */
   return 0;
}
