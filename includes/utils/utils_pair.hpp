/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pair.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:46:27 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/10 13:40:47 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PAIR_HPP
# define UTILS_PAIR_HPP

#include <utility>
#include <iostream>

namespace ft {

		/** ✅
    * ------------------------ FT::PAIR ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct pair 
	* 		- default constructor ✅
	*		- copy ✅
	*		- pair ✅
    * operator=:            Assign pair ✅
    *
	* Non-member functions overloads:
	* 	Relational operators: Relational operator for pair
	* operator==
	* operator!=
	* operator<
	* operator<=
	* operator>
	* operator>=
    * ------------------------------------------------------------- *
    */

	template <class _T1, class _T2> 
	struct pair {
		/* ------------------------------------------------------------- */
		/* ----------------------- MEMBERS TYPES ----------------------- */	
		/* ------------------------------------------------------------- */

			typedef _T1		first_type;
			typedef	_T2		second_type;

		/* ------------------------------------------------------------- */
		/* --------------------- MEMBERS VARIABLES --------------------- */	
		/* ------------------------------------------------------------- */

			first_type		first;
			second_type		second;

		/* ------------------------------------------------------------- */
		/* --------------------- MEMBERS FUNCTIONS --------------------- */	
		/* ------------------------------------------------------------- */

			/**
			 * @brief Construct a new pair object with its elements value_initialized
			 * 
			 */
			pair() : first(_T1()), second(_T2()) { };

			/**
			 * @brief Construct a new pair object with the contents of the pair object.
			 * 
			 * @tparam U first_type
			 * @tparam V second_type
			 * @param pr An another pair object
			 */
			template< class U, class V >
			pair (const pair<U,V >& pr) : first(pr.first), second(pr.second) { };

			/**
			 * @brief Construct a new pair object with two objet of the 
			 * type of first and second
			 * 
			 * @param a Permite to construct first
			 * @param b Permite to construct second
			 */
			pair (const first_type& a, const second_type& b) : first(a), second(b) { };


		/* ------------------------------------------------------------- */
		/* ------------------------- OPERATORS ------------------------- */	
		/* ------------------------------------------------------------- */
			pair& operator= (const pair& pr) {
				if (*this != pr) {
					this->first = pr.first;
					this->second = pr.second;
				}
				return *this;
			}

		};

		template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first==rhs.first && lhs.second==rhs.second; }

		template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs==rhs); }

		template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

		template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(rhs<lhs); }

		template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return rhs<lhs; }

		template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs<rhs); }

		/**
		 * @brief Constructs a pair object with its first element set to x and its second element set to y.
		 * The template types can be implicitly deduced from the arguments passed to make_pair.
		 * pair objects can be constructed from other pair objects containing different types, if the respective types are implicitly convertible.
		 *
		 * @param x Values for the members first of the pair object being constructed.
		 * @param y Values for the members second of the pair object being constructed.
		 * @return pair<T1, T2> A pair object whose elements first and second are set to x and y respectivelly.
		 */
		template <class T1, class T2>
		pair<T1, T2> make_pair ( T1 x, T2 y )
		{ return (pair<T1, T2>(x, y)); }

}

		template <typename T, typename U>
		std::ostream &operator<<(std::ostream &os, const ft::pair<T, U> &pair)
		{
			os << "[" << pair.first << "]=\"" << pair.second << "\"";
			return os;
		}

		template <typename T, typename U>
		std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &pair)
		{
			os << "[" << pair.first << "]=\"" << pair.second << "\"";
			return os;
		}

#endif