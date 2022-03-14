/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:14:49 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/14 10:21:49 by clbouche         ###   ########.fr       */
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
}

#endif