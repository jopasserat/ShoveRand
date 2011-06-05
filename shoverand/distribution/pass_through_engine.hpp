/*
 *  pass_through_engine.hpp
 *  
 *
 *  Adapted from:
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id: pass_through_engine.hpp 24096 2004-07-27 03:43:34Z dgregor $
 */

#ifndef SHOVERAND_DISTRIBUTION_PASS_THROUGH_ENGINE_HPP
#define SHOVERAND_DISTRIBUTION_PASS_THROUGH_ENGINE_HPP

#include <shoverand/distribution/ptr_helper.hpp>


namespace boost {
   namespace random {
      namespace detail {
         
         template<class UniformRandomNumberGenerator>
         class pass_through_engine
         {
         private:
            typedef ptr_helper<UniformRandomNumberGenerator> helper_type;
            
         public:
            typedef typename helper_type::value_type base_type;
            typedef typename base_type::result_type result_type;
            
            __host__ __device__
            explicit pass_through_engine(UniformRandomNumberGenerator rng)
            // make argument an rvalue to avoid matching Generator& constructor
            : rng_(static_cast<typename helper_type::rvalue_type>(rng))
            { }
            
            __host__ __device__
            result_type min () const { return (base().min)(); }

            __host__ __device__            
            result_type max () const { return (base().max)(); }

            __host__ __device__           
            base_type& base() { return helper_type::ref(rng_); }

            __host__ __device__            
            const base_type& base() const { return helper_type::ref(rng_); }
            
            __host__ __device__
            result_type operator()() { return base()(); }
            
         private:
            UniformRandomNumberGenerator rng_;
         };
         
      } // namespace detail
   } // namespace random
} // namespace boost

#endif // SHOVERAND_DISTRIBUTION_PASS_THROUGH_ENGINE_HPP
