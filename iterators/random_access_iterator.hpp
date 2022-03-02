/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:07:29 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/02 15:51:26 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "../utils/utils_iterator.hpp"

namespace ft {
	
	/*
    * ------------------- FT::RANDOM_ACCESS_ITERATOR -------------------- *
    *
    * - Coplien form:
    * constructor:			Construct vector_iterator
    * destructor:			Destruct vector_iterator
    * operator=: 			Assign vector_iterator
    * copy constructor:		Construct vector_iterator by copy	
    * 
    * - Comparaisons
    * equality: 			Return bool
	* inequality:			Return bool
	*
	* - References
	* .
    * . 
    *
    * - Mutable
    * .
    *
    * - Incrementation
    * preincrement:         
    * postincrement:
    * . 
    * 
    * - Decrementation: 
    * predecrement: 
    * postdecrement:
    * . 
    * 
    * - Arithmetic 
    * +:
    * -:
    * 
    * - < > <= >=  
    * 
    * - Assignment 
    * +=:
    * +-:
    * 
    * - Offset assignment operator
    * - []:
    * ------------------------------------------------------------- *
    */

	template < typename T>
	class	random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
		
        

	};
}

#endif