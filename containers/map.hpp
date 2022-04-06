/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:04:20 by clbouche          #+#    #+#             */
/*   Updated: 2022/04/06 14:46:19 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <memory>
#include "../utils/utils_pair.hpp"

namespace	ft {
	/** ✅
    * ------------------------ FT::MAP ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct map 
	* 		- empty constructor 
	*		- range constructor
	*		- copy 
    * destructor:         	Destruct map 
    * operator=:            Assign map 
    *
    * - Iterators:
    * begin:                Return iterator to beginning 
    * end:                  Return iterator to end 
    * rbegin:               Return reverse iterator to reverse beginning 
    * rend:                 Return reverse iterator to reverse end 
    *
    * - Capacity:
    * empty:                Test whether map is empty 
    * size:                 Return size 
    * max_size:             Return maximum size 
    *
    * - Element access:
    * operator[]:           Access element
    * at:                   Access element
    *
    * - Modifiers:
    * insert:               Insert elements 
    * erase:                Erase elements 
    * swap:                 Swap content 
    * clear:                Clear content 
	* 
	* - Observers:
	* key_comp:				Return key comparaison object
	* value_comp:			Return value comparaison object 
    *
	* Operatons:
	* find:					Get iterator to element
	* count:				Count elements with a specific key
	* lower_bound:			Return iterator to lower bound
	* upper_bound:			Return oterator to upper bound
	* equal_range:			Get range of equal elements.
	* 
    * ------------------------------------------------------------- *
    */

   template < typename Key,                                     		// map::key_type
           typename T,                                       			// map::mapped_type
           typename Compare = std::less< Key >,                     	// map::key_compare
           typename Alloc = std::allocator< ft::pair< const Key,T > >	// map::allocator_type
           > 
	class map
	{
		private:
		
		public:

	};
	
}

#endif