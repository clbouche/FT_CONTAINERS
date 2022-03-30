/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:07:29 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/30 16:47:02 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "../utils/utils_iterator.hpp"

namespace ft {
	
	/**
	 * @brief Random-access iterators are iterators that can be used to access
	 * elements at an arbitrary offset position relative to the element 
	 * they point to, offering the same functionality as pointers.
	 * 
	 * Random-access iterators are the most complete iterators in terms of functionality.
	 */
   
	template < typename T >
	class	random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
		
		public:

		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */
		
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer               pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference             reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;


		protected: 
			pointer	_ptr;
		
		public:
		/* ------------------------------------------------------------- */
		/* ----------------------- COPELIAN CLASS ----------------------- */	
		/* ------------------------------------------------------------- */
		
		/*
		 * Default constructor : point on null 
		*/
		random_access_iterator(void) : _ptr(0) {}

		/*
		 * Pointer constructor : point to the element passed in argument.
		*/
		random_access_iterator(pointer elem) : _ptr(elem) {}

		/*
		 * Copy constructor : copy the pointer who point to the element.
		*/
		random_access_iterator(const random_access_iterator& other) : _ptr(other._ptr) {}
	
		/*
		 * Assignation constructor : give a random access iterator who is a copy
		*/
		random_access_iterator &operator=(const random_access_iterator& other) {
			if (this == &other)
				return (*this);
			this->_ptr = other._ptr;
			return (*this);
		}

		/*
		 * Default destructor
		*/
		~random_access_iterator() {}


		/* ------------------------------------------------------------- */
		/* ------------------------- GETTERS --------------------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief Convert a reverse iterator in an iterator
		 * @return the iterator
		 */
		pointer	base() const
		{
			return (this->_ptr);
		}

		/* ------------------------------------------------------------- */
		/* ------------------------ OPERATORS -------------------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief Dereference the rvalue
		 * @return The rvalue (value where point the pointer)
		 */
		reference operator*(void) const { 
			return (*this->_ptr); 
		}

		/**
		 * @brief Give the pointer to the lvalue
		 * @return The lvalue (the pointer to the element)
		*/
		pointer operator->(void) { 
			return &(this->operator*());
		}
		
		/**
		 * @brief Increment the pointer to the next element in memory
		 * @return A reference to the next value
		*/
		random_access_iterator& operator++(void) {
			_ptr++;
			return (*this);
		}
		
		/**
		 * @brief Preincrement the pointer to the next element in memory
		 * @return A reference to the current element
		*/
		random_access_iterator operator++(int)
		{
			random_access_iterator rtn(*this);
			operator++();
			return (rtn);
		}

		/**
		 * @brief Decrement the pointer to the previous element in memory
		 * @return A reference to the next value
		*/
		random_access_iterator& operator--(void)
		{
			_ptr--;
			return (*this);
		}
		
		/**
		 * @brief Predecrement the pointer to the next element in memory
		 * @return A reference to the current element
		*/
		random_access_iterator operator--(int)
		{
			random_access_iterator rtn(*this);
			operator--();
			return (rtn);
		}

		/**
		 * @brief Addition (a + n): random access iterator at this + "n" in memory.
		 * 
		 * @param n the number of element to skip
		 * @return random access iterator who point to this + n 
		*/
		random_access_iterator operator+(difference_type n) const { 
			return (_ptr + n); 
		}
		
		// /**
		//  * @brief Addition 
		//  * 
		//  * @param rhs iterator 
		//  * @return random_access_iterator who point to this + rhs
		//  */
		// random_access_iterator operator+(random_access_iterator &rhs) const { return (_ptr + rhs); }


		/**
		 * @brief Subtraction (a - n): random access iterator at this + 'n' in memory
		 * 
		 * @param n the number of element to skip
		 * @return random_access_iterator who point to this + n
		 */
		random_access_iterator operator-(difference_type n) const { 
			return (_ptr - n);
		}

		/**
		 * @brief Access to the random access iterator this + n
		 * 
		 * @param n the number of element to skip
		 * @return reference to the new value
		 */
		random_access_iterator&	operator+=(difference_type n) {
			_ptr += n;
			return (*this);
		}

		/**
		 * @brief Access to the random access iterator this - n
		 * 
		 * @param n the number of element to skip 
		 * @return reference to the new value
		 */
		random_access_iterator&	operator-=(difference_type n) {
			_ptr -= n;
			return (*this);
		} 

		/**
		 * @brief Access to a member of the container
		 * 
		 * @param n index of the element 
		 * @return reference to the n element of the container 
		 * @return undefined if the reference returned is out of container's range.
		 */
		reference	operator[](difference_type n) const {
			return *(*this + n);
		 }

		 operator random_access_iterator<const T> () const
			{
				return (random_access_iterator<const T>(this->_ptr));
			}

	};

	/**
	 * @brief Check equality between lhs & rhs.
	 * 
	 * @param lhs 
	 * @param rhs 
	 * @return true if equal
	 * @return false otherwise
	 */
	template<typename T_L, typename T_R>
	inline bool	operator==(const ft::random_access_iterator<T_L> lhs,
		const ft::random_access_iterator<T_R> rhs) {
			return(lhs.base() == rhs.base());
		}

	/**
	 * @brief Check the inequality between lhs & rhs
	 * 
	 * @param lhs 
	 * @param rhs 
	 * @return true if inequal
	 * @return false otherwise
	 */
	template<typename T_L, typename T_R>
	inline bool	operator!=(const ft::random_access_iterator<T_L> lhs, 
		const ft::random_access_iterator<T_R> rhs) {
			return !(lhs.base() == rhs.base());
		}

	/**
	 * @brief Check the inferiority between lhs & rhs
	 * 
	 * @param lhs 
	 * @param rhs 
	 * @return true if lhs is lower than rhs
	 * @return false otherwise
	 */
	template<typename T_L, typename T_R>
	inline bool	operator<(const ft::random_access_iterator<T_L> lhs, 
		const ft::random_access_iterator<T_R> rhs) {
			return (lhs.base() < rhs.base());
		}

	/**
	 * @brief Check the superiority between lhs & rhs
	 * 
	 * @param lhs 
	 * @param rhs 
	 * @return true if lhs is higher than rhs
	 * @return false otherwise
	 */
	template<typename T_L, typename T_R>
	inline bool	operator>(const ft::random_access_iterator<T_L> lhs, 
		const ft::random_access_iterator<T_R> rhs){
			return (lhs.base() < rhs.base());
		}
	
	/**
	 * @brief Check if lhs is inferior or equal to rhs
	 * 
	 * @param lhs 
	 * @param rhs 
	 * @return true if lhs is inferior or equal to rhs
	 * @return false otherwise
	 */
	template<typename T_L, typename T_R>
	inline bool	operator<=(const ft::random_access_iterator<T_L> lhs,
		const ft::random_access_iterator<T_R> rhs) {
			return (lhs.base() <= rhs.base());
		}

	/**
	 * @brief Check if lhs is superior or equal to rhs
	 * 
	 * @param lhs 
	 * @param rhs 
	 * @return true if lhs is superior or equal to rhs
	 * @return false otherwise
	 */
	template<typename T_L, typename T_R>
	inline bool	operator>=(const ft::random_access_iterator<T_L> lhs,
		const ft::random_access_iterator<T_R> rhs) {
			return (lhs.base() >= rhs.base());
		}

	/*
	** Addition (n + a): random access iterator where the element is pointed at this + "n" in memory. 
	*/
	template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator+(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs) {
        return (lhs.base() + rhs.base());
    }

	/*
	** Substraction (n + a): random access iterator where the element is pointed at this - "n" in memory. 
	*/
	template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator-(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs) {
        return (lhs.base() - rhs.base());
    }
}

#endif