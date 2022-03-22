/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:03:50 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/22 15:47:38 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <iostream>
#include "../iterators/random_access_iterator.hpp"
#include "../utils/utils_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace	ft {

	/**
    * ------------------------ FT::VECTOR ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct vector 
	* 		- default constructor ✅
	*		- fill constructor
	*		- range constructor
    * destructor:         	Destruct vector ✅ 
    * operator=:            Assign vector
    *
    * - Iterators:
    * begin:                Return iterator to beginning ✅
    * end:                  Return iterator to end ✅
    * rbegin:               Return reverse iterator to reverse beginning ✅
    * rend:                 Return reverse iterator to reverse end ✅
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
	* display:				Access to all elements
    *
    * - Modifiers:
    * assign:               Assign vector content
	*		- vector content with int
	*		- vector content with iterator
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

			//first template parameter (T)
			typedef	T			value_type;

			//second template parameter (alloc)
			typedef	Alloc		allocator_type;

			//reference to an element in the vector (default : value_type&)
			typedef	typename 	allocator_type::reference									reference;

			//constant reference to an element in the vector (default : const value_type&)
			typedef	typename	allocator_type::const_reference								const_reference;

			//pointer to an element in the vector (default : value_type*)
			typedef	typename	allocator_type::pointer										pointer;

			//constant pointer to an element in the vector (default :const value_type*)
			typedef	typename	allocator_type::const_pointer								const_pointer;

			//random access iterator to value_type (can read or modify any element stored)
			typedef	typename	ft::random_access_iterator<value_type>						iterator;

			//random access iterator to const value_type (can read element stored)
			typedef	typename	ft::random_access_iterator< const value_type>				const_iterator;

			//ft::reverse_iterator<iterator> (can read or modify any element in a reversed vector)
			typedef	typename	ft::reverse_iterator<iterator>								reverse_iterator;

			//ft::reverse_iterator<const_iterator> (can read any element in a reversed the vector)
			typedef	typename	ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			
			typedef	typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;

		private:

			//to use the same object 
			allocator_type 		_alloc; 

			//pointer on the first value of my vector
			pointer				_start; 

			//pointer of the final value of my vector
			pointer				_end;

			//size of the vector
			size_t				_size;
			
			//capacity allocated  
			size_t				_capacity;
			
		public:
		/* ------------------------------------------------------------- */
		/* ---------------------- COPELIAN CLASS ----------------------- */	
		/* ------------------------------------------------------------- */

			/**
			 * @brief Construct a new empty vector object. 
			 * 
			 * @param alloc Allocator object. The container keeps and uses
			 *				an internal copy of this allocator.
			 */
			explicit vector (const allocator_type& alloc = allocator_type()) : 
				_alloc(alloc),
				_start(0),
				_end(0),
				_capacity(0) 
			{
				std::cout << "ALOHA VECTOR - empty constructor" << std::endl;
			}

			/**
			 * @brief Construct a new vector object with elements.
			 * 
			 * @param n numbers of elements.
			 * @param val (optionnal) value to fill the container with.
			 *
			 * @todo remplacer par la fonction assign une fois implementer 
			 * assign(n, val);
			 */
			explicit vector (size_t n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n)
			{
				std::cout << "ALOHA VECTOR - " << n << " elements constructor" << std::endl;
				_start = _alloc.allocate(n);
				_end = _start;
				while(n--)
				{
					_alloc.construct(_end, val);
					_end++;
				}	
			}
			
			/**
			 * @brief Construct a new vector object with as many elements as the interval between first and last.
			 * 
			 * @param first InputIterator to the initial position in a range.
			 * @param last InputIterator to the final position of a range.
			 *
			 * @todo utiliser assign aussi mais pour les iterateurs.
			 */
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, 
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) 
				: _alloc(alloc)
				{
					std::cout << "ALOHA VECTOR - range contructor " << std::endl;
					InputIterator tmp(first);
					while(tmp++ != last)
						_size++;

					_capacity = _size;
					_start = _alloc.allocate(_capacity);
					for (int i = 0; first != last; ++first, ++i)
						_alloc.construct(&_start[i], * first);
				}
			
			/**
			 * @brief Construct a new vector object
			 * 
			 * @param x another vector object of the same type
			 *
			 * @todo ben l'implementer mdr
			 */
			vector (const vector& x) {
				(void)x;
				std::cout << "ALOHA VECTOR - copy constructor" << std::endl;
			}

			/**
			 * @brief Assignation operator
			 * 
			 * @param other vector object
			 * @return vector& - the new vector
			 */
			vector&	operator=(const vector &other) {
				this->size = other.size;
				return *this;
			};
			
			/**
			 * @brief Destroy the vector object
			 *
			 * @todo utiliser clear
			 * @todo il faut desallouer la memoire
			 * 
			 */
			~vector(void) { 
				std::cout << "GOOD BYE VECTOR" << std::endl;
			};

		/* ------------------------------------------------------------- */
		/* ------------------------- ITERATORS ------------------------- */
		/* ------------------------------------------------------------- */

		/**
		 * @return an iterator pointing to the first element in the vector
		 */
		iterator 	begin() {
			return _start; };

		/**
		 * @return an iterator pointing to the last element in the vector
		 */
		iterator	end() {
			return _end; };

		/**
		 * @return an reverse_iterator pointing to the last element in the vector
		 */
		reverse_iterator	rbegin() { 
			return (reverse_iterator(_end)); };

		/**
		 * @return an reverse_iterator pointing to the first element in the vector
		 */
		reverse_iterator	rend() {
			return (reverse_iterator(_start)); };

		// /**
		//  * @return a const_iterator pointing to the first element in the vector
		//  */
		// const_iterator	cbegin() {
		// 	return const _start; };

		// /**
		//  * @return a const_iterator pointing to the last element in the vector
		//  */
		// const_iterator	cend() {
		// 	return const _end;};
			
		// /**
		//  * @return a const_reverse_iterator to the last element element in the vector
		//  */
		// const_reverse_iterator	crbegin() {
		// 	return const (reverse_iterator(_end));};
			
		// /**
		//  * @return a const_reverse_iterator pointing to the first element in the vector
		//  */
		// const_reverse_iterator	crend() {
		// 	return const (reverse_iterator(_start)); };

		/* ------------------------------------------------------------- */
		/* ------------------------- CAPACITY -------------------------- */
		/* ------------------------------------------------------------- */

		/**
		 * @brief Number of actual objects in the vector (!= capacity)
		 * 
		 * @return size_t numbers of the element in the vector
		 */
		size_t	size() const { 
			return (_end - _start); };

		size_t	max_size() const {
			return (_alloc.max_size()); };
			
		//void	resize(size_t n, value_type val = value_type());

		size_t	capacity() const { 
			return (this->_capacity);};
			
		//bool	empty() const {
			//if (empty)
				//return (true);
			//return (false)};

		/**
		 * @brief Requests that the vector capacity be at least enough to contain n elements.
		 *
		 * 
		 */
		void	reserve(size_t n) {
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			if (this->capacity() < n) {
				const size_t old_size = this->size();
				pointer		tmp = this->_alloc.allocate(n, this->_start);
				for	(size_t i = 0; i < this->size(); i++) {
					this->_alloc.construct(tmp + i, this->_start[i]);
					this->_alloc.destroy(&(this->_start[i]));
				}
				this->_alloc.deallocate(this->_start, this->capacity());
				this->_start = tmp;
				this->_end = tmp + old_size;
				this->_capacity = old_size + n;
			}
		}


		//void	shrink_to_fit() {
				
		//}

		/* ------------------------------------------------------------- */
		/* ---------------------- ELEMENT ACCESS ----------------------- */
		/* ------------------------------------------------------------- */

		// reference	operator[] (size_t n) {
		//	
		// }
		//	const_reference	operator[] (size_t n) const {
		//	
		// }

		// 	reference at (size_t n) {
		//	
		// }
		// const_reference at (size_t n) const {
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

		/**
		 * @brief new contents are elements constructed from each of the 
		 * elements in the range between first and last, in the same order.
		 * 
		 * @param first input iterators to the first position
		 * @param last input iterators to the final position
		 */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
			//   for (; first != last; first++, start++) {
			// 	  _alloc.construct(_end, *first);
			//   }
		  }
		
		/**
		 * @brief new contents are n elements, each initialized to a copy of val.
		 * 
		 * @param n numbers of elements in the vector
		 * @param val value of each element in the vector
		 */
		void assign (size_t n, const value_type& val) {
			
		}

		void push_back (const value_type& val) {
			
		}

		// void pop_back () {
			// 
		// }

		/**
		 * @brief the vector is extended by inserting a single element
		 * 
		 * @param position where the new element is inserted
		 * @param val value to be copied (or moved) in the inserted element 
		 * @return iterator that points to the first of the newly inserted element
		 */
		iterator insert (iterator position, const value_type& val) {
			difference_type index = position - begin();
			insert(position, 1, val);
			return (&_start[index]);				
		}
		
		//FILL VERSION
		/**
		 * @brief the vector is extended by inserting new elements
		 * 
		 * @param position where the new elements are inserted.
		 * @param n number of element to insert.
		 * @param val value to be copied (or moved) to the inserted elements
		 */
		void insert (iterator position, size_t n, const value_type& val) {
			//if n == 0
			//	return ;
			difference_type	index = position - begin();
			pointer 		_newcurr;

			reserve(n);
			
		}

		// pointer 			_new_curr;
		// 	size_type 			new_elems = n;
		// 	size_type 			i = 0;

		// 	_new_curr = alloc_obj.allocate(_size + n); //on rajout n size en plus car n x t vont etre add 
		// 	iterator it = iterator(_curr);
		// 	for (size_type j = 0; j < _size + new_elems; j++)
		// 	{
		// 		// on copie sauf si on arrive a l'iterateur
		// 		if (it != position) // test...
		// 			_new_curr[j] = _curr[i];
		// 		else
		// 		{
		// 			i -= 1;
		// 			for (;n > 0; n--)
		// 				_new_curr[j++] = x;
		// 			j -= 1;
		// 		}
		// 		it++;
		// 		i++;
		// 	}
		// 	alloc_obj.deallocate(_curr, _capacity);
		// 	_curr = _new_curr; // deallocate avant !!
		// 	_size += new_elems;
		// 	_capacity += new_elems; //revoir les calculs de cpacite 

		//RANGE VERSION

		/**
		 * @brief the vector is extended by inserting a range of elements. 
		 * Copies of the elements in the range [first, last] are inserted 
		 * at position in the same order.
		 * 
		 * @param position where the new elements are inserted
		 * @param first input iterator to the first element of the range
		 * @param last input iterator to the final element of the range
		 */
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last) {
			
		}

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