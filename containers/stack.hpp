/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:04:42 by clbouche          #+#    #+#             */
/*   Updated: 2022/04/05 15:43:40 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include "vector.hpp"

namespace	ft {
	/**
    * ------------------------ FT::STACK ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct stack ✅
	* 
	* - Members functions:
	* empty:				Test whether stack is empty ✅ 
	* size:					Return size ✅
	* top:					Return the last element inserted into the stack ✅
	* push:					Inserts a new element at the top of the stack ✅
	* pop: 					Removes the element on top of the stack ✅
	*
	* - Friends functions:
	* 	operator== ✅
	* 	operator<  ✅
	* 
	* - Non members functions:
	* relational operators: Relational operators for vector
	* 	operator== ✅
	* 	operator!= ✅
	* 	operator<  ✅
	*	operator>  ✅
	*	operator<= ✅
	* 	operator>= ✅
	* ------------------------------------------------------------- *
    */

	template < typename T, typename Container = ft::vector<T> >
	class stack
	{
		public: 

			/**
			 * @brief the first template parameter (T).
			 * 
			 */
			typedef typename Container::value_type		value_type;
			
			/**
			 * @brief the second template parametre (COntainer)
			 * 
			 */
			typedef 		Container					container_type;

			/**
			 * @brief an unsigned integral type 
			 * 
			 */
			typedef typename Container::size_type		size_type;		


		protected:
			container_type								 _c;
			
		public:

		/* ------------------------------------------------------------- */
		/* ------------------------ CONSTRUCTOR ------------------------ */	
		/* ------------------------------------------------------------- */
		
			/**
			 * @brief Construct a new stack object
			 * 
			 * @param ctnr 
			 */
			explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) { }

		/* ------------------------------------------------------------- */
		/* -------------------- MEMBERS FUNCTIONS ---------------------- */
		/* ------------------------------------------------------------- */

			/**
			 * @brief  Return true if the size of the stack is 0.
			 */
			bool empty() const { return _c.empty(); }

			/**
			 * @brief  Number of actual objects in the vector
			 * 
			 * @return size_type size of the stack.
			 */
			size_type size() const	{ return _c.size(); }

			/**
			 * @brief the top element is the last element inserted into the stack

			 * 
			 * @return value_type& a reference to the top element in the stack.
			 */
			value_type& top() { return _c.back(); }

			const value_type& top() const { return _c.back(); }


			/**
			 * @brief Inserts a new element at the top of the stack
			 * 
			 * @param val Value to which the inserted element is initialized.
			 */
			void push (const value_type& val) { _c.push_back(val); }

			/**
			 * @brief Removes the element on top of the stack
			 * 
			 */
			void pop() { _c.pop_back(); }

		/* ------------------------------------------------------------- */
		/* ------------------------- FRIENDS --------------------------- */
		/* ------------------------------------------------------------- */

			template<typename T1, typename Container1>
			friend bool operator==(const stack< T1, Container1>&, const stack< T1, Container1>&);

			template<typename T1, typename Container1>
			friend bool operator<(const stack< T1, Container1>&, const stack< T1, Container1>&);
	};

	
	/* ------------------------------------------------------------- */
	/* ------------------ NON MEMBERS FUNCTIONS -------------------- */
	/* ------------------------------------------------------------- */


		// template <class T, class Container>
		// bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		// 	return lhs._c == rhs._c;
		// }

		template<typename T, typename Container>
		inline bool operator==(const stack< T, Container>& __x, const stack< T, Container>& __y) { 
			return __x._c == __y._c; }

		template<typename T, typename Container>
		inline bool operator!=(const stack< T, Container>& __x, const stack< T, Container>& __y) { 
			return !(__x == __y); }

		template<typename T, typename Container>
		inline bool operator<(const stack< T, Container>& __x, const stack< T, Container>& __y) { 
			return __x._c < __y._c; }

		template<typename T, typename Container>
		inline bool operator>(const stack< T, Container>& __x, const stack< T, Container>& __y) { 
			return __y < __x; }

		template<typename T, typename Container>
		inline bool operator<=(const stack<T, Container>& __x, const stack<T, Container>& __y) { 
			return !(__y < __x); }

		template<typename T, typename Container>
		inline bool
		operator>=(const stack<T, Container>& __x, const stack<T, Container>& __y) {
			return !(__x < __y); }
}

#endif