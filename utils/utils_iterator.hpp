/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:37:43 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/14 16:50:14 by clbouche         ###   ########.fr       */
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
	
	template <typename T, bool is_int>
	struct	is_integral {
		typedef T 			type;
		static const bool	value = is_int;
	};

	template<> struct is_integral : public is_integral<bool, false> {};

	template<> struct is_integral<bool> : public is_integral<bool, true> {};

	template<> struct is_integral<char> : public is_integral<char, true> {};

	template<> struct is_integral<char16_t> : public is_integral<char16_t, true> {};

	template<> struct is_integral<char32_t> : public is_integral<char32_t, true> {};

	template<> struct is_integral<wchar_t> : public is_integral<wchar_t, true> {};

	template<> struct is_integral<signed char> : public is_integral<signed char, true> {};

	template<> struct is_integral<short int> : public is_integral<short int, true> {};

	template<> struct is_integral<int> : public is_integral<int, true> {};

	template<> struct is_integral<long int> : public is_integral<long int, true> {};

	template<> struct is_integral<long long int> : public is_integral<long long int, true> {};

	template<> struct is_integral<unsigned char> : public is_integral<unsigned char, true> {};

	template<> struct is_integral<unsigned short int> : public is_integral<unsigned short int, true> {};

	template<> struct is_integral<unsigned int> : public is_integral<unsigned int, true> {};

	template<> struct is_integral<unsigned long int> : public is_integral<unsigned long int, true> {};

	template<> struct is_integral<unsigned long long int> : public is_integral<unsigned long long int, true> {};

	template <class T> struct is_integral : public is_integral<T> {};

}

#endif