/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:03:50 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/02 17:02:19 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include "../iterators/random_access_iterator.hpp"
#include "../utils/utils_iterator.hpp"

namespace	ft {

	/*
    * ------------------------ FT::VECTOR ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct vector
    * destructor:         	Destruct vector
    * operator=:            Assign vector
    *
    * - Iterators:
    * begin:                Return iterator to beginning
    * end:                  Return iterator to end
    * rbegin:               Return reverse iterator to reverse beginning
    * rend:                 Return reverse iterator to reverse end
    *
    * - Capacity:
    * size:                 Return size
    * max_size:             Return maximum size
    * resize:               Change size
    * capacity:             Return size of allocated storage capacity
    * empty:                Test whether vector is empty
    * reserve:              Request a change in capacity
    *
    * - Element access:
    * operator[]:           Access element
    * at:                   Access element
    * front:                Access first element
    * back:                 Access last element
    *
    * - Modifiers:
    * assign:               Assign vector content
    * push_back:            Add element at the end
    * pop_back:             Delete last element
    * insert:               Insert elements
    * erase:                Erase elements
    * swap:                 Swap content
    * clear:                Clear content
    *
    * - Non-member function overloads:
    * relational operators: Relational operators for vector
    * swap:                 Exchange contents of two vectors
    * ------------------------------------------------------------- *
    */

	template < typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */

			typedef	T			value_type;
			typedef	Alloc		allocator_type;
			typedef	typename 	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			typedef	typename	ft::random_access_iterator<value_type>			iterator;
			typedef	typename	ft::random_access_iterator< const value_type>	const_iterator;
			typedef	typename	ft::random_access_iterator<value_type>			reverse_iterator;
			typedef	typename	ft::random_access_iterator< const value_type>	const_reverse_iterator;
			//typedef	ptrdiff_t	difference_type;
			typedef	std::size_t			size_type;	

		private:
			allocator_type 		_alloc;
			size_type			_size;
			size_type			_capacity;

		public:
		/* ------------------------------------------------------------- */
		/* ---------------------- COPELIAN CLASS ----------------------- */	
		/* ------------------------------------------------------------- */

			explicit vector (const allocator_type& alloc = allocator_type()) : 
				_size(0),
				_capacity(0) {
				(void)alloc;
				std::cout << "ALOHA VECTOR - empty constructor" << std::endl;
				
			}

			explicit vector (size_type n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()):
				_size(n),
				_alloc(alloc) {
					
				(void)alloc;
				(void)val;
				std::cout << "ALOHA VECTOR - n elments constructor" << std::endl;
				}
			
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, 
				const allocator_type& alloc = allocator_type()) 
				{
					
					(void)first;
					(void)last;
					std::cout << "ALOHA VECTOR - range contructor " << std::endl;
				}
			
			vector (const vector& x) {
				(void)x;
				std::cout << "ALOHA VECTOR - copy constructor" << std::endl;
			}

			~vector() { };
			vector&	operator=(const vector &other) {
				this->size = other.size;
				return *this;
			};

		/* ------------------------------------------------------------- */
		/* ------------------------- ITERATORS ------------------------- */
		/* ------------------------------------------------------------- */


		//iterator 	begin() {
			//return iterator sur le debut; };

		//iterator	end() {
			//return iterator sur la fin; };

		//reverse_iterator	rbegin() { 
			//return iterator sur la fin; };

		//reverse_iterator	rend() {
			//return iterator sur le debut); };

		//const_iterator	cbegin() {
			//return const iterator sur le debut; };

		//const_iterator	cend() {
			//return const iterator sur la fin;};
			
		//const_reverse_iterator	crbegin() {
			//return const iterator sur la fin;};
			
		//const_reverse_iterator	crend() {
			//return const iterator sur le debut;};

		/* ------------------------------------------------------------- */
		/* ------------------------- CAPACITY -------------------------- */
		/* ------------------------------------------------------------- */

		//size_type	size() const { 
			//return this->size; };

		//size_type	max_size const {
			//return this->max_size; };
			
		//void	resize(size_type n, value_type val = value_type());
		//size_type	capacity() const { 
			// return capacity of the vector };
			
		//bool	empty() const {
			//if (empty)
				//return (true);
			//return (false)};

		//void	reserve(size_type n) {
			//	
		//}

		//void	shrink_to_fit() {
				
		//}

		/* ------------------------------------------------------------- */
		/* ---------------------- ELEMENT ACCESS ----------------------- */
		/* ------------------------------------------------------------- */

		// reference	operator[] (size_type n) {
		//	
		// }
		//	const_reference	operator[] (size_type n) const {
		//	
		// }

		// 	reference at (size_type n) {
		//	
		// }
		// const_reference at (size_type n) const {
		//	
		// }

		//	reference front() {
			
		// }
		// const_reference front() const {
			
		// }

		// reference back() {
			
		// }
		// const_reference back() const {
			
		// }

		// value_type* data() noexcept {
			
		// }
		// const value_type* data() const noexcept {
			
		// }

		/* ------------------------------------------------------------- */
		/* ------------------------- MODIFIERS ------------------------- */	
		/* ------------------------------------------------------------- */

		//RANGE VERSION : new contents are elements constructed from each of 
		//the elements in the range between first and last, in the same order.
		
		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last) {
			//   
		//   }
		

		//FILL VERSION : new contents are n elements, each initialized to a copy of val.

		// void assign (size_type n, const value_type& val) {
			
		// }

		// void push_back (const value_type& val) {
			// 
		// }

		// void pop_back () {
			// 
		// }

		//SINGLE ELEMENT 
		// iterator insert (iterator position, const value_type& val) {
			// 
		// }
		
		//FILL VERSION
		// void insert (iterator position, size_type n, const value_type& val) {
			// 
		// }

		//RANGE VERSION
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last) {
			// 
		// }

		//POSITION
		// iterator erase (iterator position) {
			// 
		// }

		//RANGE OF ELEMENTS
		// iterator erase (iterator first, iterator last) {
		// 
		// }

		// void swap (vector& x) {
			// 
		// }

		// void clear(){
			// 
		// }

		//template <class... Args>
		// iterator emplace (const_iterator position, Args&&... args) {
			// 
		// }

		// template <class... Args>
		// void emplace_back (Args&&... args) {
			//   
		//   }

		/* ------------------------------------------------------------- */
		/* ----------------------- ALLOCATOR --------------------------- */
		/* ------------------------------------------------------------- */

		// allocator_type get_allocator() const {
			// 
		// }
	};
		
}

#endif