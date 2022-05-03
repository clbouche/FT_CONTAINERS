/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:04:20 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/03 17:46:21 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <memory>
#include "../utils/utils_pair.hpp"
#include "../RBTree/algo.hpp"
#include "../RBTree/RBT_node.hpp"
#include "../iterators/RBT_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"

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
	* Operators:
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
		public:
        /* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */

        typedef		Key             									key_type;
        typedef		T													mapped_type;
		typedef		ft::pair<const key_type, mapped_type>				value_type;
		typedef		Compare												key_compare;
		typedef 			Alloc 												allocator_type;
		typedef	typename	allocator_type::reference							reference;
		typedef	typename 	allocator_type::const_reference						const_reference;
		typedef	typename 	allocator_type::pointer								pointer;
		typedef	typename	allocator_type::const_pointer						const_pointer;
		typedef		ft::RBT_iterator<value_type>						iterator;
		typedef		ft::RBT_const_iterator<value_type>					const_iterator;
		typedef	typename	ft::reverse_iterator<iterator>						reverse_iterator;
		typedef	typename	ft::reverse_iterator<const_iterator> 				const_reverse_iterator;
		typedef	typename	ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef	typename	allocator_type::size_t								size_type;

		/**
		 * @todo IMPLEMENTER VALUE_COMPARE !!!!!!!!!!!!!
		 * 
		 */


		private:
		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */

		allocator_type												_alloc;
		Compare														_comp;
		ft::RBTree<const key_type, value_type, Compare, Alloc> 		_RBTree;

		
		public:
		/* ------------------------------------------------------------- */
		/* ---------------------- COPELIAN CLASS ----------------------- */	
		/* ------------------------------------------------------------- */

		explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
		{

		}

		template <class InputIterator>
  		map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type()) 
		{
			
		}
	
		map (const map& x)
		{
			
		}


 		map& 	operator= (const map& x)
		{
		 
		}
		
		~map()
		{
			
		}
	
		/* ------------------------------------------------------------- */
		/* ------------------------- ITERATORS ------------------------- */	
		/* ------------------------------------------------------------- */
	
		iterator		begin()
		{

		}
		
		const_iterator	begin() const
		{

		}
		
		iterator		end()
		{

		}
		
		const_iterator 	end() const
		{

		}
				
		reverse_iterator	rbegin()
		{

		}
		
		const_reverse_iterator	rbegin() const
		{

		}
		
		/* ------------------------------------------------------------- */
		/* ------------------------- CAPACITY -------------------------- */	
		/* ------------------------------------------------------------- */

		bool	empty() const
		{
			
		}
		
		size_type	size() const
		{
			
		}

		size_type	max_size() const
		{
			
		}



		/* ------------------------------------------------------------- */
		/* ---------------------- ELEMENT ACCESS ----------------------- */
		/* ------------------------------------------------------------- */

		mapped_type&	operator[] (const key_type& k)
		{
			
		}

		/* ------------------------------------------------------------- */
		/* ------------------------- MODIFIERS ------------------------- */	
		/* ------------------------------------------------------------- */
	
		pair<iterator,bool>		insert (const value_type& val)
		{
			
		}

		iterator 	insert (iterator position, const value_type& val)
		{
			
		}
		
		template <class InputIterator>
  		void 	insert (InputIterator first, InputIterator last)
		{
		  
		}


		void 	erase (iterator position)
		{
			
		}

		size_type 	erase (const key_type& k)
		{
			
		}

		void 	erase (iterator first, iterator last)
		{
			
		}

		void 	swap (map& x)
		{
			
		}

		void	clear()
		{
			
		}

		/* ------------------------------------------------------------- */
		/* ------------------------- OBSERVERS ------------------------- */	
		/* ------------------------------------------------------------- */

		key_compare 	key_comp() const
		{
			
		}

		// value_compare		value_comp() const
		// {
			
		// }

		/* ------------------------------------------------------------- */
		/* ------------------------- OPERATIONS ------------------------ */	
		/* ------------------------------------------------------------- */

    	iterator 	find (const key_type& k)
		{

		}
		
		const_iterator 		find (const key_type& k) const
		{
			
		}

		size_type 	count (const key_type& k) const
		{
			
		}

    	iterator	 lower_bound (const key_type& k)
		{

		}
		
		const_iterator 		lower_bound (const key_type& k) const
		{
			
		}

		iterator 	upper_bound (const key_type& k)
		{

		}
		
		const_iterator 	upper_bound (const key_type& k) const
		{
			
		}

		pair<const_iterator,const_iterator> 	equal_range (const key_type& k) const
		{

		}
		
		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			
		}
		
		/* ------------------------------------------------------------- */
		/* ------------------------- ALLOCATOR ------------------------- */	
		/* ------------------------------------------------------------- */

		allocator_type 	get_allocator() const
		{
			
		}

		
		/* ------------------------------------------------------------- */
		/* ------------------ RELATIONAL OPERATORS --------------------- */
		/* ------------------------------------------------------------- */
	};
	
}

#endif