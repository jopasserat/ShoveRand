/*
 *  \file variate_generator.hpp
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/13/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *    
 *  Adapted from:
 *
 *  Copyright Jens Maurer 2002
 *  Distributed under the Boost Software License, Version 1.0. (See
 *  accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 *
 *  See http://www.boost.org for most recent version including documentation.
 *
 *  $Id: variate_generator.hpp 27375 2005-02-14 11:53:50Z johnmaddock $
 *
 */

#ifndef SHOVERAND_VARIATE_GENERATOR_HPP
#define SHOVERAND_VARIATE_GENERATOR_HPP

// implementation details
#include <thrust/random/uniform_int_distribution.h> // TODO recode
#include <thrust/random/uniform_real_distribution.h> // TODO recode
#include <shoverand/distribution/pass_through_engine.hpp>
#include <boost/limits.hpp>

namespace boost {
   
   namespace random {
      namespace detail {
         
         template<bool have_int, bool want_int>
         struct engine_helper;
         
         // for consistency, always have two levels of decorations
         template<>
         struct engine_helper<true, true>
         {
            template<class Engine, class DistInputType>
            struct impl
            {
               typedef pass_through_engine<Engine> type;
            };
         };
         
         
         // following traits seem impossible to implement without modifying thrust
         /*
         template<>
         struct engine_helper<false, false>
         {
            template<class Engine, class DistInputType>
            struct impl
            {
               // default uniform real distribution is U01
               typedef thrust::random::uniform_real_distribution<Engine, DistInputType> type;
            };
         };
         
         template<>
         struct engine_helper<true, false>
         {
            template<class Engine, class DistInputType>
            struct impl
            {
               // default uniform real distribution is U01
               typedef thrust::random::uniform_real_distribution<Engine, DistInputType> type;
            };
         };
         
         template<>
         struct engine_helper<false, true>
         {
            template<class Engine, class DistInputType>
            struct impl
            {
               typedef thrust::random::uniform_int_distribution<Engine, unsigned long> type;
            };
         };
         */
         
         
      } // namespace detail
   } // namespace random
   
   
   template<class Engine, class Distribution>
   class variate_generator
   {
   private:
      typedef random::detail::pass_through_engine<Engine> decorated_engine;
      
   public:
      typedef typename decorated_engine::base_type engine_value_type;
      typedef Engine engine_type;
      typedef Distribution distribution_type;
      typedef typename Distribution::result_type result_type;
      
      __host__ __device__
      variate_generator(Engine e, Distribution d)
      : eng_(decorated_engine(e)), dist_(d) { }

      __host__ __device__      
      result_type operator()() { return dist_(eng_); }

      template<class T>
      __host__ __device__      
      result_type operator()(T value) { return dist_(eng_, value); }
      
      __host__ __device__      
      engine_value_type& engine() { return eng_.base().base(); }
      
      __host__ __device__      
      const engine_value_type& engine() const { return eng_.base().base(); }

      __host__ __device__      
      distribution_type& distribution() { return dist_; }

      __host__ __device__      
      const distribution_type& distribution() const { return dist_; }
      
      __host__ __device__      
      result_type min () const { return (distribution().min)(); }

      __host__ __device__      
      result_type max () const { return (distribution().max)(); }
      
   private:

      enum {
         have_int = std::numeric_limits<typename decorated_engine::result_type>::is_integer,
         want_int = std::numeric_limits<typename Distribution::input_type>::is_integer
      };
      typedef typename random::detail::engine_helper<have_int, want_int>::template impl<decorated_engine, typename Distribution::input_type>::type internal_engine_type;

      
      internal_engine_type eng_;
      distribution_type dist_;
   };
   
} // namespace boost

#endif // SHOVERAND_VARIATE_GENERATOR_HPP
