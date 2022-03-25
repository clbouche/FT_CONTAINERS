/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:03:50 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/25 14:10:58 by claclou          ###   ########.fr       */
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

/*TO DELETE*/
#include <vector>


namespace	ft {

	/**
    * ------------------------ FT::VECTOR ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct vector 
	* 		- default constructor ✅
	*		- fill constructor ✅ 
	*		- range constructor
	*		- copy ✅ 
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
    * size:                 Return size ✅
    * max_size:             Return maximum size ✅
    * resize:               Change size
    * capacity:             Return size of allocated storage capacity ✅
    * empty:                Test whether vector is empty ✅ 
    * reserve:              Request a change in capacity ✅
    *
    * - Element access:
    * operator[]:           Access element 
    * at:                   Access element
    * front:                Access first element
    * back:                 Access last element
	* data:					Access data
    *
    * - Modifiers:
    * assign:               Assign vector content
	*		- vector content with int ✅ 
	*		- vector content with iterator
    * push_back:            Add element at the end
    * pop_back:             Delete last element
    * insert:               Insert elements
    * erase:                Erase elements ✅
    * swap:                 Swap content
    * clear:                Clear content ✅
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
			
			typedef	typename	ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;

			typedef typename	allocator_type::size_type										size_type;
	
		private:

			//to use the same object 
			allocator_type 		_alloc; 

			//pointer on the first value of my vector
			pointer				_start; 

			//pointer of the final value of my vector
			pointer				_end;

			//size of the vector
			size_type				_size;
			
			//capacity allocated  
			size_type				_capacity;
			
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
				_capacity(0) {};

			/**
			 * @brief Construct a new vector object with elements.
			 * 
			 * @param n numbers of elements.
			 * @param val (optionnal) value to fill the container with.
			 */
			explicit vector (size_type n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n) {
				_start = _alloc.allocate(n);
				_end = _start;
				assign(n, val);
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
				: _alloc(alloc) {
				difference_type n = last - first;
				this->_start = this->_alloc.allocate(n);
				this->_capacity = this->_size;
				this->_end = this->_start;
				while (n--) {
						this->_alloc.construct(this->_end, *first);
						this->_end++;
						first++;
					}
					// assign(first, last);
			}
			
			/**
			 * @brief Construct a new vector object
			 * 
			 * @param x another vector object of the same type
			 */
			vector (const vector& x) : _alloc(x.get_allocator()) {
				this->_start = this->_alloc.allocate(x.size);
				this->_capacity = this->_start + x.size;
				this->_end = this->_start;
				this->assign(x.begin(), x.end());
			}
			
			/**
			 * @brief Assignation operator
			 * 
			 * @param other vector object
			 * @return vector& - the new vector
			 */
			vector&	operator=(const vector &other) {
				if (*this != other) {
					this->clear();
					this->assign(other.begin(), other.end());
				}
				return *this;
			};
			
			/**
			 * @brief Destroy the vector object
			 */
			~vector(void) {
				this->clear();
				_alloc.deallocate(_start, this->capacity());
			};

		/* ------------------------------------------------------------- */
		/* ------------------------- ITERATORS ------------------------- */
		/* ------------------------------------------------------------- */

			/**
			 * @return an iterator pointing to the first element in the vector
			 */
			iterator 	begin() const { return _start; };

			/**
			 * @return an iterator pointing to the last element in the vector
			 */
			iterator	end() const { return _end; };

			/**
			 * @return an reverse_iterator pointing to the last element in the vector
			 */
			reverse_iterator	rbegin() const { return (reverse_iterator(_end)); };

			/**
			 * @return an reverse_iterator pointing to the first element in the vector
			 */
			reverse_iterator	rend() const { return (reverse_iterator(_start)); };

			/**
			 * @return a const_iterator pointing to the first element in the vector
			 */
			const_iterator	cbegin() const { return _start; }; 

			/**
			 * @return a const_iterator pointing to the last element in the vector
			 */
			const_iterator	cend() const { return _end;};
				
			/**
			 * @return a const_reverse_iterator to the last element element in the vector
			 */
			const_reverse_iterator	crbegin() { return (reverse_iterator(_end));};
				
			/**
			 * @return a const_reverse_iterator pointing to the first element in the vector
			 */
			const_reverse_iterator	crend() { return (reverse_iterator(_start)); };

		/* ------------------------------------------------------------- */
		/* ------------------------- CAPACITY -------------------------- */
		/* ------------------------------------------------------------- */

			/**
			 * @brief Number of actual objects in the vector (!= capacity)
			 * 
			 * @return size_typenumbers of the element in the vector
			 */
			size_t	size() const { return (_end - _start); };

			/**
			 * @brief  
			 * 
			 * @return size_type size maximum of a vector
			 */
			size_t	max_size() const { return (_alloc.max_size()); };
				
			/**
			 * @brief 
			 * 
			 */
			//void	resize(size_type n, value_type val = value_type());

			/**
			 * @brief The actual capacity of the vector
			 * 
			 * @return size_type
			 */
			size_t	capacity() const { return (this->_capacity);};
			
			/**
			 * @brief Permite to know if the vector is empty or not
			 * 
			 * @return bool 
			 */
			bool	empty() const { return (_start == _end); };

			/**
			 * @brief Requests that the vector capacity be at least enough to contain n elements.
			 *
			 * @param n minimum value to increase the capacity of the vector 
			 * @todo peut etre revoir comment je gere la capacité
			 */
			void	reserve(size_type n) {
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				if (this->capacity() < n) {
					const size_type old_size = this->size();
					pointer		tmp = this->_alloc.allocate(n, this->_start);
					for	(size_type i = 0; i < this->size(); i++) {
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
					this->reserve(last - first);
					this->empty();
					_end = _start;
					for(; first != last; first++, _end++)
						_alloc.construct(_end, *first);
			}
			
			/**
			 * @brief new contents are n elements, each initialized to a copy of val.
			 * 
			 * @param n numbers of elements in the vector
			 * @param val value of each element in the vector
			 */
			void assign (size_type n, const value_type& val) {
				this->clear();
				if (n != 0) {
					this->reserve(n);
					for (; n != 0; n--, _end++)
						_alloc.construct(_end, val);
				}
			}

			void push_back (const value_type& val) {
				(void)val;
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
			 * @todo ajouter la fonction computeCapacity d'arthur
			 */
			void insert (iterator position, size_type n, const value_type& val) {
				if n != 0 {
					size_t		new_size = this->size() + n;
					pointer		new_curr = _alloc.allocate(new_size);
					for	(size_type i = 0 < this->size() + n; i++) {
						if (i =< this->size())
							new_curr[i]= 
							//si on a pas depasser la size de base, on copie ce qu'on a deja
						else
						new_curr[i] = val;
						//sinon on copie val jusqu'a arriver a la new size
					}
					
					//besoin de creer un nouveau vector de la nouvelle taille 
					//d'y remettre les infos qu'il possédait deja 
					//et d'y ajouter les nouvelles valeur 
					//faire pointer _end sur la fin
					reserve(n);
				}			
			}

			// if (n == 0)
			// 			return ;
			// 		size_type	new_size = this->size() + n;
			// 		size_type	insert_idx	= ft::distance(this->begin(), position);
			// 		ptrdiff_t	i			= this->size() - 1;
			// 		size_type	j;
			// 		this->reserve(computeCapacity(n));
			// 		while (i >= static_cast<ptrdiff_t>(insert_idx))
			// 		{
			// 			this->_alloc.construct(this->_start + n + i, this->_start[i]);
			// 			this->_alloc.destroy(this->_start + i);
			// 			i--;
			// 		}
			// 		j = 0;
			// 		while (j < n)
			// 		{
			// 			this->_alloc.construct(this->_start + insert_idx + j, val);
			// 			j++;
			// 		}
			// 		this->_end = this->_start + new_size;

			

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
				(void)position;
				(void)first;
				(void)last;
			}

			
			//POSITION
			/**
			 * @brief Removes from the vector either a single element at the position.
			 * 
			 * @param position Iterator pointing to a single element to be removed from the vector.
			 * @return iterator An iterator pointing to the new location of the element 
			 */
			iterator erase (iterator position) {
				return (erase(position, position + 1));
			}


			//RANGE OF ELEMENTS
			iterator erase (iterator first, iterator last) {
				pointer p_first = &(*first);
				for (; &(*first) != &(*last); first++)
					_alloc.destroy(&(*first));
				for (int i = 0; i < _end - &(*last); i++)
				{
					_alloc.construct(p_first + i, *(&(*last) + i));
					_alloc.destroy(&(*last) + i);
				}
				_end -= (&(*last) - p_first);
				return (iterator(p_first));
			}

			/**
			 * @brief 
			 * 
			 * @param x 
			 */
			void swap (vector& x) {
				(void)x;
			}
		
			

			/**
			 * @brief Removes all elements from the vector (which are destroyed),
			 * leaving the container with a size of 0.
			 * 
			 */
			void clear(){
				this->erase(this->begin(), this->end());
			}

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