/** 
 *  \file uniform_01.hpp
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/14/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 * Adapted from:
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id: uniform_01.hpp 52492 2009-04-19 14:55:57Z steven_watanabe $
 *
 * Revision history
 *  2001-02-18  moved to individual header files
 */

#ifndef SHOVERAND_DISTRIBUTION_UNIFORM_01_HPP
#define SHOVERAND_DISTRIBUTION_UNIFORM_01_HPP

#include <shoverand/distribution/pass_through_engine.hpp>
#include <shoverand/distribution/ptr_helper.hpp>
#include <limits> // replaced Boost's limits with STL's to be portable

namespace boost {
	
   namespace detail {
      
      template<class RealType>
      class new_uniform_01
      {
      public:
         typedef RealType input_type;
         typedef RealType result_type;
         
         // compiler-generated copy ctor and copy assignment are fine
         
         __host__ __device__
         result_type min () const { return result_type(0); }

         __host__ __device__
         result_type max () const { return result_type(1); }

         __host__ __device__         
         void reset() { }
         
         template<class Engine>
         __host__ __device__
         result_type operator()(Engine& eng) {
            for (;;) {
               typedef typename Engine::result_type base_result;
               result_type factor = result_type(1) /
               (result_type((eng.max)()-(eng.min)()) +
                result_type(std::numeric_limits<base_result>::is_integer ? 1 : 0));
               result_type result = result_type(eng() - (eng.min)()) * factor;
               if (result < result_type(1))
                  return result;
            }
         }
         
      };

      
      /** Base use is through variate_generator. Thus, we chose to implement uniform_01's
            new interface only.
       */
		template<class UniformRandomNumberGenerator>
      struct select_uniform_01
      {
         template<class RealType>
         struct apply {
				// TODO check this specialization: might not work
				typedef UniformRandomNumberGenerator type;
         };
      };
      
      template<>
      struct select_uniform_01<float>
      {
         template<class RealType>
         struct apply
         {
            typedef new_uniform_01<float> type;
         };
      };
      
      template<>
      struct select_uniform_01<double>
      {
         template<class RealType>
         struct apply
         {
            typedef new_uniform_01<double> type;
         };
      };
      
      template<>
      struct select_uniform_01<long double>
      {
         template<class RealType>
         struct apply
         {
            typedef new_uniform_01<long double> type;
         };
      };
      
   } // namespace detail
   
   // Because it is so commonly used: uniform distribution on the real [0..1)
   // range.  This allows for specializations to avoid a costly int -> float
   // conversion plus float multiplication
   template<class UniformRandomNumberGenerator = double, class RealType = double>
   class uniform_01
   : public detail::select_uniform_01<UniformRandomNumberGenerator>::template apply<RealType>::type
   {
      typedef typename detail::select_uniform_01<UniformRandomNumberGenerator>::template apply<RealType>::type impl_type;
      typedef boost::random::detail::ptr_helper<UniformRandomNumberGenerator> traits;
   public:

      __host__ __device__      
      uniform_01() {}
      
      __host__ __device__      
      explicit uniform_01(typename traits::rvalue_type rng)
      : impl_type(rng)
      {
      }
      
   };
   
} // namespace boost

#endif // SHOVERAND_DISTRIBUTION_UNIFORM_01_HPP
