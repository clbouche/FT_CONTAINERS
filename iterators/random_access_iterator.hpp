/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:07:29 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/03 17:01:33 by claclou          ###   ########.fr       */
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
	* constructor:			Construct vector_iterator ✅
	* destructor:			Destruct vector_iterator ✅
	* operator=: 			Assign vector_iterator ✅
	* copy constructor:		Construct vector_iterator by copy ✅
	* 
	* - Comparaisons
	* equality: 			Return bool ✅
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
	* preincrement:         ✅
	* postincrement:		✅
	* . 
	* 
	* - Decrementation: 
	* predecrement: 		✅
	* postdecrement:		✅
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

	/*
	** Random-access iterators are iterators that can be used to access elements at an arbitrary offset 
	** position relative to the element they point to, offering the same functionality as pointers.
	** 
	** Random-access iterators are the most complete iterators in terms of functionality
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


		private: 
			pointer	_ptr;
		
		public:
		/* ------------------------------------------------------------- */
		/* ----------------------- COPELIAN CLASS ----------------------- */	
		/* ------------------------------------------------------------- */
		
		/*
		** Default constructor : point on null 
		*/
		random_access_iterator(void) : _ptr(0) {}

		/*
		** Pointer constructor : point to the element passed in argument.
		*/
		random_access_iterator(pointer elem) : _ptr(elem) {}

		/*
		** Copy constructor : copy the pointer who point to the element.
		*/
		random_access_iterator(const random_access_iterator& other) : _ptr(other._ptr) {}
	
		/*
		** Assignation constructor : give a random access iterator who is a copy
		*/
		random_access_iterator &operator=(const random_access_iterator& other) {
			if (this == &other)
				return (*this);
			this->_ptr = other._ptr;
			return (*this);
		}

		/*
		** Default destructor
		*/
		~random_access_iterator() {}
		
		/* ------------------------------------------------------------- */
		/* ------------------------- GETTERS --------------------------- */	
		/* ------------------------------------------------------------- */

		/*
		**	Getter ptr : return	the iterator.
		*/
		pointer	base() const
		{
			return (this->_ptr);
		}

		/* ------------------------------------------------------------- */
		/* ------------------------ OPERATORS -------------------------- */	
		/* ------------------------------------------------------------- */

		/*
		** Return the rvalue (value where point the pointer).
		*/
		reference operator*(void) const { return (*_ptr); }

		/*
		** Return the lvalue (the pointer to the element).
		*/
		pointer operator->(void) { return &(this->operator*()); }
		
		/*
		** Preincrement: point to the next element in memory.
		*/
		random_access_iterator& operator++(void) {
			_ptr++;
			return (*this);
		}
		
		/*
		** Postincrement: point to the next element in memory.
		*/
		random_access_iterator operator++(int)
		{
			random_access_iterator rtn(*this);
			operator++();
			return (rtn);
		}

		/*
		** Predecrement: point to the previous element in memory.
		*/
		random_access_iterator& operator--(void)
		{
			_ptr--;
			return (*this);
		}

		/*
		** Postdecrement: point to the previous element in memory.
		*/
		random_access_iterator operator--(int)
		{
			random_access_iterator rtn(*this);
			operator--();
			return (rtn);
		}

		/*
		** Addition (a + n): random access iterator where the element is pointed at this + "n" in memory.
		*/
		random_access_iterator operator+(difference_type n) const { return (_ptr + n); }

		/*
		** Addition (a + b): random access iterator where ... i don't know.
		*/
		random_access_iterator operator+(random_access_iterator &rhs) const { return (_ptr + rhs); }

		/*
		** Substration: random access iterator where the element is pointed at this - "n" in memory.
		*/
		random_access_iterator operator-(difference_type n) const { return (_ptr - n); }


		// operator+= 

		//operator-= 

		bool	operator==() { }

		//operator!=
	};

	/*
	** Addition (n + a): random access iterator where the element is pointed at this + "n" in memory. 
	*/
	template <typename T> 
	ft::random_access_iterator<T> operator+(
	typename ft::random_access_iterator<T>::difference_type n,
	typename ft::random_access_iterator<T>& rai)
	{
		return (&(*rai) + n);
	}

	/*
	** Soustraction (n + a): random access iterator where the element is pointed at this - "n" in memory. 
	*/
	template<typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator-(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }

	/*
    ** Equality: check if the pointer of "lhs" is equal than "rhs" in the memory. 
    */
    template<typename T_L, typename T_R>
    inline bool operator==(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    /* 
	** Soustraction: 
	*/ 
    // template<typename T_L, typename T_R>
    // typename ft::random_access_iterator<T_L>::difference_type
    // operator-(const ft::random_access_iterator<T_L> lhs,
    //           const ft::random_access_iterator<T_R> rhs)
    // {
    //     return (lhs.base() - rhs.base());
    // }
}

#endif