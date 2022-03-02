/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:37:43 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/02 15:39:58 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_ITERATOR_HPP
# define UTILS_ITERATOR_HPP

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

#endif