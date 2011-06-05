/*
 *  ptr_helper.hpp
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/13/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 *  Adapted from:
 *
 * Copyright Jens Maurer 2002
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id: ptr_helper.hpp 24096 2004-07-27 03:43:34Z dgregor $
 *
 */

#ifndef BOOST_RANDOM_DETAIL_PTR_HELPER_HPP
#define BOOST_RANDOM_DETAIL_PTR_HELPER_HPP



namespace boost {
   namespace random {
      namespace detail {
         
         // type_traits could help here, but I don't want to depend on boost::type_traits.
         template<class T>
         struct ptr_helper
         {
            typedef T value_type;
            typedef T& reference_type;
            typedef const T& rvalue_type;
            
            __host__ __device__
            static reference_type ref(T& r) { return r; }
            
            __host__ __device__            
            static const T& ref(const T& r) { return r; }
         };
         
         template<class T>
         struct ptr_helper<T&>
         {
            typedef T value_type;
            typedef T& reference_type;
            typedef T& rvalue_type;

            __host__ __device__
            static reference_type ref(T& r) { return r; }
            
            __host__ __device__            
            static const T& ref(const T& r) { return r; }
         };
         
         template<class T>
         struct ptr_helper<T*>
         {
            typedef T value_type;
            typedef T& reference_type;
            typedef T* rvalue_type;
            
            __host__ __device__            
            static reference_type ref(T * p) { return *p; }
            
            __host__ __device__            
            static const T& ref(const T * p) { return *p; }
         };

         
      } // namespace detail
   } // namespace random
} // namespace boost


#endif // BOOST_RANDOM_DETAIL_PTR_HELPER_HPP
