/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:55:01 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/15 14:57:30 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "../utils/utils_iterator.hpp"
#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"

namespace ft {

	/**
	 * @brief Reverse_iterator is an iterator adaptor that reverses the direction
	 * of a given iterator. In other words, when porvided with an iterator 
	 * produces a new iterator that moves from the end to the beginning of the 
	 * sequence.
	 * 
	 * @tparam _Iterator the given iterator.
	 */

	template <typename _Iterator>
	class	reverse_iterator
	: public ft::iterator<typename ft::iterator_traits<_Iterator>::iterator_category, 
				typename ft::iterator_traits<_Iterator>::value_type>
	{
	
		public:
		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */
		
			typedef _Iterator	iterator_type;
			typedef typename	ft::iterator_traits<_Iterator>::iterator_category	iterator_category;
			typedef typename	ft::iterator_traits<_Iterator>::value_type			value_type;
			typedef typename	ft::iterator_traits<_Iterator>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<_Iterator>::pointer				pointer;
			typedef typename	ft::iterator_traits<_Iterator>::reference			reference;
			
		/* ------------------------------------------------------------- */
		/* ---------------------- PRIVATE MEMBERS ---------------------- */	
		/* ------------------------------------------------------------- */
		protected:
			iterator_type _current;


		public:
		/* ------------------------------------------------------------- */
		/* ----------------------- CONSTRUCTORS ------------------------ */	
		/* ------------------------------------------------------------- */

		reverse_iterator() : _current() {};

		explicit reverse_iterator (iterator_type it) : _current(it) {};
		
		template <class Iterator>
  		reverse_iterator (const reverse_iterator & rev_it) : _current(rev_it.base()) {};
		
		~reverse_iterator();
		
		/* ------------------------------------------------------------- */
		/* --------------------------- GETTER -------------------------- */	
		/* ------------------------------------------------------------- */

		reverse_iterator	base() const {
			return (this->_current);
		};

		/* ------------------------------------------------------------- */
		/* ----------------- MEMBERS OVERLOAD OPERATORS ---------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief 
		 * 
		 * @return reference 
		 *
		 * @todo le dereferencement de reverse_iterator s'occupe de current--
		 * je dois donc faire un tmp 
		 */
		reference	operator*() const {
			return (*this->_current);
		};


		reverse_iterator	operator+(difference_type n) const {
			return (this->_current - n);
		};

		reverse_iterator&	operator++() {
			--this->_current;
			return (*this);
		};

		reverse_iterator	operator++(int) {
			reverse_iterator	tmp(*this);
			this->_current--;
			return (tmp);
		};

		reverse_iterator&	operator+=(difference_type n) {
			this->_current -= n;
			return (*this);
		};

		reverse_iterator	operator-(difference_type n) const {
			return (this->_current + n);
		};

		reverse_iterator&	operator--() {
			++this->_current;
			return (*this);
		};

		reverse_iterator	operator--(int) {
			reverse_iterator	tmp(*this);
			this->_current++;
			return (tmp);
		};

		reverse_iterator&	operator-=(difference_type n) {
			this->_current += n;
			return (*this);
		}

		pointer	operator->() const {
			return (this->_current);
		};

		reference	operator[](difference_type n) const {
			return (*(this->_current + n));
		};

	};

		/* ------------------------------------------------------------- */
		/* ---------------- NON MEMBERS OVERLOAD OPERATORS ------------- */	
		/* ------------------------------------------------------------- */	
	
		// template<class Iterator>
		// bool	operator== (const reverse_iterator<Iterator> &lhs, 
		// 			const reverse_iterator<Iterator> &rhs) {
								
		// 			}
		// template <class Iterator>
  		// bool	operator!= (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs) {
					   
		// 			}

		// template <class Iterator>
		// bool	operator<  (const reverse_iterator<Iterator>& lhs,
		// 			const reverse_iterator<Iterator>& rhs) {
							
		// 			}

		// template <class Iterator>
  		// bool	operator<= (const reverse_iterator<Iterator>& lhs,
        //         	const reverse_iterator<Iterator>& rhs) {
						
		// 			}

		// template <class Iterator>
 		// bool	operator>  (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs) {
					   
		// 			}

		// template <class Iterator>
  		// bool	operator>= (const reverse_iterator<Iterator>& lhs,
        //            const reverse_iterator<Iterator>& rhs) {
					   
		// 			}

		//operator+

		//operator-
}

#endif