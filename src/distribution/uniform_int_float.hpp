/* Adapted from:
 *
 * boost random/detail/uniform_int_float.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org for most recent version including documentation.
 *
 * $Id: uniform_int_float.hpp 52492 2009-04-19 14:55:57Z steven_watanabe $
 *
 */

#ifndef SHOVERAND_RANDOM_UNIFORM_INT_FLOAT_HPP
#define SHOVERAND_RANDOM_UNIFORM_INT_FLOAT_HPP

#include <shoverand/distribution/uniform_01.hpp>


namespace shoverand {
	namespace distribution {
		namespace detail {

			template<class UniformRandomNumberGenerator, class IntType = unsigned long>
				class uniform_int_float
				{
					public:
						typedef UniformRandomNumberGenerator base_type;
						typedef IntType result_type;

						__host__ __device__
						uniform_int_float(base_type rng, IntType min_arg = 0, IntType max_arg = 0xffffffff)
							: _rng(rng), _min(min_arg), _max(max_arg)
						{
							init();
						}


						__host__ __device__
						result_type min () const { return _min; }
						__host__ __device__
						result_type max () const { return _max; }
						__host__ __device__
						base_type& base() { return _rng.base(); }
						__host__ __device__
						const base_type& base() const { return _rng.base(); }

						__host__ __device__
						result_type operator()()
						{
							return static_cast<IntType>(_rng() * _range) + _min;
						}


					private:
						__host__ __device__
						void init()
						{
							_range = static_cast<base_result>(_max-_min)+1;
						}

						typedef typename base_type::result_type base_result;
						uniform_01<base_type> _rng;
						result_type _min, _max;
						base_result _range;
				};


		} // namespace detail
	} // namespace distribution
} // namespace shoverand

#endif // SHOVERAND_RANDOM_UNIFORM_INT_FLOAT_HPP

