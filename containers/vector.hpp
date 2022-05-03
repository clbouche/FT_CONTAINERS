/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:03:50 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/03 17:42:24 by clbouche         ###   ########.fr       */
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
#include "../utils/utils_relational_operators.hpp"

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
	*		- range constructor ✅
	*		- copy ✅ 
    * destructor:         	Destruct vector ✅ 
    * operator=:            Assign vector ✅
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
    * operator[]:           Access element ✅
    * at:                   Access element ✅
    * front:                Access first element ✅
    * back:                 Access last element ✅
    *
    * - Modifiers:
    * assign:               Assign vector content
	*		- vector content with int ✅ 
	*		- vector content with iterator ✅
    * push_back:            Add element at the end ✅
    * pop_back:             Delete last element ✅
    * insert:               Insert elements ✅
    * erase:                Erase elements ✅
    * swap:                 Swap content ✅
    * clear:                Clear content ✅
    *
    * - Non-member function overloads:
    * relational operators: Relational operators for vector
	*		- operator== ✅
	*		- operator!= ✅
	*		- operator< ✅
	*		- operator<= ✅
	*		- operator> ✅
	*		- operator>= ✅
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

		/* ------------------------------------------------------------- */
		/* ---------------------- MEMBERS VARIABLES -------------------- */
		/* ------------------------------------------------------------- */
			//to use the same object 
			allocator_type 		_alloc; 

			//pointer on the first value of my vector
			pointer				_start; 

			//pointer of the final value of my vector
			pointer				_end;

			//size of the vector
			size_type				_size;
			
			//capacity allocated  
			pointer				_capacity;

			/**
			* @brief 
			* 
			* @param __n 
			* @return const size_type 
			*/
			const size_type    computeCapacity( size_type __n )
			{
			if (this->capacity() > (this->size() + __n))
				return (this->capacity());
			const size_type __len = size() + std::max(size(), __n);
			return (__len < size() || __len > max_size()) ? max_size() : __len;
			}
			
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
				const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
				_start = _alloc.allocate(n);
				_end = _start;
				_capacity = this->_start + n;
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
				this->_capacity = this->_start + n;
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
			// vector (const vector& x) : _alloc(x.get_allocator()) {
			// 	this->_start = this->_alloc.allocate(x.size());
			// 	this->_capacity = this->_start + x.size();
			// 	this->_end = this->_start;
			// 	this->assign(x.begin(), x.end());
			// }

			vector (const vector & x) :
				_alloc(x.get_allocator())
			{
				this->_start = this->_alloc.allocate(x.size());
				this->_capacity = this->_start + x.size();
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
			iterator 	begin() { return _start; };

			const_iterator begin() const { return _start; };

			/**
			 * @return an iterator pointing to the last element in the vector
			 */
			iterator	end() { return _end; };

			const_iterator end() const { return _end; };

			/**
			 * @return an reverse_iterator pointing to the last element in the vector
			 */
			reverse_iterator	rbegin() { return (reverse_iterator(_end)); };

			const_reverse_iterator rbegin() const { return (reverse_iterator(_end)); };

			/**
			 * @return an reverse_iterator pointing to the first element in the vector
			 */
			reverse_iterator	rend() { return (reverse_iterator(_start)); };

			const_reverse_iterator rend() const { return (reverse_iterator(_start)); };


		/* ------------------------------------------------------------- */
		/* ------------------------- CAPACITY -------------------------- */
		/* ------------------------------------------------------------- */

			/**
			 * @brief Number of actual objects in the vector (!= capacity)
			 * 
			 * @return size_typenumbers of the element in the vector
			 */
			size_type	size() const { return (_end - _start); };

			/**
			 * @return size_type size maximum of a vector
			 */
			size_type	max_size() const { return (_alloc.max_size()); };
				
			/**
			 * @brief  Resizes the container so that it contains n elements
			 * 
			 * @param n the new size of the vector
			 * @param val if specified, the value of the new element of the vector
			 */
			void		resize ( size_type n, value_type val = value_type() )
			{
				if (n > max_size())
					throw std::length_error("vector::resize");
				else if (n < this->size())
				{
					while (this->size() > n)
					{
						--_end;
						_alloc.destroy(_end);
					}
				}
				else
				{
					this->reserve(n);
					this->insert(this->end(), (n - this->size()), val);
				}
			}

			/**
			 * @return size_type of the actual capacity of the vector
			 */
			size_type	capacity() const { return (this->_capacity - this->_start);};
			
			/**
			 * @brief Permite to know if the vector is empty or not
			 */
			bool	empty() const { return (_start == _end); };

			/**
			 * @brief Requests that the vector capacity be at least enough to contain n elements.
			 *
			 * @param n minimum value to increase the capacity of the vector 
			 * @todo revoir comment je gere la capacité
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
					this->_capacity = this->_start + n;
				}
			}

		/* ------------------------------------------------------------- */
		/* ---------------------- ELEMENT ACCESS ----------------------- */
		/* ------------------------------------------------------------- */

			/**
			 * @brief Returns a reference to the element at n position.
			 * 
			 * @param n position in the vector container to return
			 * @return reference of the vector
			 */
			reference	operator[] (size_type n) {
				return (static_cast<reference>(*(this->_start + n)));
			}
			
			const_reference	operator[] (size_type n) const {
					return (static_cast<const_reference>(*(this->_start + n)));
			}

			/**
			 * @brief Returns a reference to the element at n position. 
			 * diff w/ operator[] = exception if n > size.
			 * 
			 * @param n position in the vector container to return 
			 * @return reference of the vector
			 */
			reference at (size_type n) {
				if (n >= this->size())
					throw std::out_of_range("vector::out_of_range");
				return ((*this)[n]);
			}
			
			const_reference at (size_type n) const {
				if (n >= this->size())
					throw std::out_of_range("vector::out_of_range");
				return ((*this)[n]);
			}

			/**
			 * @brief Return a reference to the first element of the vector.
			 * 
			 * @return reference of the vector
			 */
			reference front() {
				return (*this->_start);
			}
			const_reference front() const {
				return (*this->_start);
			}

			/**
			 * @brief Return a reference to the last element of the vector.
			 * 
			 * @return reference of the vector
			 */
			reference back() {
				return (*(this->_end - 1));
			}
			const_reference back() const {
				return (*(this->_end - 1));
			}	

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
					this->clear();
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
			// void assign (size_type n, const value_type& val) {
			// 	this->clear();
			// 	if (n != 0)  {
			// 		this->reserve(n);
			// 		for (; n != 0; n--, _end++)
			// 			_alloc.construct(_end, val);
			// 	}
			// }

			void		assign ( size_type n, const value_type& val )
			{
				this->clear();
				if (n == 0)
					return ;
				this->reserve(n);
				while (n--)
				{
					this->_alloc.construct(this->_end, val);
					this->_end++;
				}
			}


			/**
			 * @brief Adds a new element at the end of the vector, after its current last element. 
			 * The content of val is copied (or moved) to the new element
			 * 
			 * @param val the new value to insert in the vector
			 */
			void push_back (const value_type& val) {
				if (this->_end == this->_capacity)
				{
					this->reserve(computeCapacity(1));
				}
				this->_alloc.construct(this->_end, val);
				this->_end++;	
			}

			/**
			 * @brief Removes the last element in the vector, effectively reducing the container size by one.
			 * 
			 * @todo probleme avec la capacity
			 */
			void pop_back () {
					--this->_end;
				this->_alloc.destroy((this->_end));
			}

			/**
			 * @brief the vector is extended by inserting a single element
			 * 
			 * @param position where the new element is inserted
			 * @param val value to be copied (or moved) in the inserted element 
			 * @return iterator that points to the first of the newly inserted element
			 */
			// iterator insert (iterator position, const value_type& val) {
			// 	difference_type index = position - begin();
			// 	insert(position, 1, val);
			// 	return (&_start[index]);				
			// }

			iterator	insert ( iterator position, const value_type& val )
			{
				
				size_type	insert_idx = ft::distance(this->begin(), position);
				insert(position, 1, val);
				return (iterator(this->_start + insert_idx));
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
				if (n != 0) {
					size_type new_size = this->size() + n;
					size_type	insert_idx = ft::distance(this->begin(), position);
					ptrdiff_t i = this->size() - 1;
					this->reserve(computeCapacity(n));
					while(i >= static_cast<ptrdiff_t>(insert_idx)) {
						this->_alloc.construct(this->_start + n + i, this->_start[i]);
						this->_alloc.destroy(this->_start + i);
						i--;
					}
					for (size_type i = 0; i < n; i++)
						this->_alloc.construct(this->_start + insert_idx + i, val);
					this->_end = this->_start + new_size;
				}
			}
	
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
			void insert (iterator position, InputIterator first, InputIterator last, 
			typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				size_type	dist = ft::distance(first, last);
				if (dist != 0) {
					size_type new_size = this->size() + dist;
					size_type	insert_idx = ft::distance(this->begin(), position);
					ptrdiff_t i = this->size() - 1;
					InputIterator tmp;
					this->reserve(this->size() + dist);
					while(i >= static_cast<ptrdiff_t>(insert_idx)) {
						this->_alloc.construct(this->_start + dist + i, this->_start[i]);
						this->_alloc.destroy(this->_start + i);
						i--;
					}
					tmp = first;
					for (tmp = first, i = 0; tmp != last; tmp++, i++)
						this->_alloc.construct(this->_start + insert_idx + i, *tmp);
					this->_end = this->_start + new_size;
				}
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
				if (first != this->end() && first != last) {
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
				return (first);
			}

			/**
			 * @brief Exchanges the content of the container by the content of x.
			 * 
			 * @param x another vector object of the same type
			 */
			void swap (vector& x) {
				std::swap(this->_start, x._start);
				std::swap(this->_end, x._end);
				std::swap(this->_capacity, x._capacity);
			}
		
			/**
			 * @brief Removes all elements from the vector (which are destroyed),
			 * leaving the container with a size of 0.
			 * 
			 */
			void clear(){
				this->erase(this->begin(), this->end());
			}


		/* ------------------------------------------------------------- */
		/* ----------------------- ALLOCATOR --------------------------- */
		/* ------------------------------------------------------------- */

			/**
			 * @brief Get the allocator object
			 * 
			 * @return allocator_type 
			 */
			allocator_type get_allocator() const {
				return (this->_alloc);
			}
	};

	/* ------------------------------------------------------------- */
	/* ------------------ RELATIONAL OPERATORS --------------------- */
	/* ------------------------------------------------------------- */
	/**
	 * @brief 
	 *
	 * operation	 equivalent operation
	 *	a!=b			!(a==b)
	 *	a>b				b<a
	 *	a<=b			!(b<a)
	 *	a>=b			!(a<b)
	*
	 */

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
		
}

#endif