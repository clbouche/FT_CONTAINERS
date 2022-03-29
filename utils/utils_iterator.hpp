/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:37:43 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/29 14:59:07 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_ITERATOR_HPP
# define UTILS_ITERATOR_HPP

#include <cstddef>

/**
 * @brief 
 * 
 */

namespace ft {
	
	class	input_iterator_tag { };
	class	output_iterator_tag { };
	class	forward_iterator_tag { };
	class	bidirectionnal_iterator_tag { };
	class	random_access_iterator_tag { };
	
	template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
  	struct iterator {
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
  };
}

/**
 * @brief 
 * 
 * @param Cond true if .. . False, otherwise.
 * 
 */

namespace ft {

	template <bool Cond, class T = void>
	struct enable_if {};

	template<class T> 
	struct enable_if<true, T> { typedef T type; };
	
}

namespace ft {
	
	template <typename T, bool is_integral>
	struct	is_int {
		typedef T 			type;
		static const bool	value = is_integral;
	};

	template<typename> struct is_integral_t : public is_int<bool, false> {};

	template<> struct is_integral_t<bool> : public is_int<bool, true> {};

	template<> struct is_integral_t<char> : public is_int<char, true> {};

	template<> struct is_integral_t<wchar_t> : public is_int<wchar_t, true> {};

	template<> struct is_integral_t<signed char> : public is_int<signed char, true> {};

	template<> struct is_integral_t<short int> : public is_int<short int, true> {};

	template<> struct is_integral_t<int> : public is_int<int, true> {};

	template<> struct is_integral_t<long int> : public is_int<long int, true> {};

	template<> struct is_integral_t<long long int> : public is_int<long long int, true> {};

	template<> struct is_integral_t<unsigned char> : public is_int<unsigned char, true> {};

	template<> struct is_integral_t<unsigned short int> : public is_int<unsigned short int, true> {};

	template<> struct is_integral_t<unsigned int> : public is_int<unsigned int, true> {};

	template<> struct is_integral_t<unsigned long int> : public is_int<unsigned long int, true> {};

	template<> struct is_integral_t<unsigned long long int> : public is_int<unsigned long long int, true> {};

	template <class T> struct is_integral : public is_integral_t<T> {};

}

#endif