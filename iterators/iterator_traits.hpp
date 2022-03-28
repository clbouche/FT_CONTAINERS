/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:14:49 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/28 10:19:08 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
#include "random_access_iterator.hpp"
#include "../utils/utils_iterator.hpp"

namespace	ft {

	/**
	 * @brief iterator_traits allows to determine if the pointer 
	 * is an iterator or not.
	 * 
	 */

	template <class Iterator>
	struct iterator_traits {
		typedef typename	Iterator::difference_type	difference_type;
		typedef typename	Iterator::value_type		value_type;
		typedef typename	Iterator::pointer			pointer;
		typedef typename	Iterator::reference			refenrece;
		typedef typename	Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits< T*> {
		typedef	std::ptrdiff_t					difference_type;
		typedef	T								value_type;
		typedef	T*								pointer;
		typedef	T&								reference;
		typedef	ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct	iterator_traits< const T*> {
		typedef std::ptrdiff_t					difference_type;
		typedef	T 								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <typename Iterator>
	typename ft::iterator_traits<Iterator>::difference_type
	distance (Iterator first, Iterator last)
	{
		return (__distance(first, last, typename ft::iterator_traits<Iterator>::iterator_category()));
	}

	template <typename RandomAccessIterator>
	typename ft::iterator_traits<RandomAccessIterator>::difference_type
	__distance (RandomAccessIterator first, RandomAccessIterator last, ft::random_access_iterator_tag)
	{
		return (last - first);
	}

	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	__distance (InputIterator first, InputIterator last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	diff;
		for (diff = 0; first != last; ++first, ++diff) {
			;
		}
		return (diff);
	}


}



#endif