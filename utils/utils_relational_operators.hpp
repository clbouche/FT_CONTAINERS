/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_relational_operators.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:00:41 by clbouche          #+#    #+#             */
/*   Updated: 2022/03/29 16:20:07 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RELATIONAL_OPERATORS_HPP
# define UTILS_RELATIONAL_OPERATORS_HPP

namespace ft {

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return (false);
			++first1; 
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
	while (first1!=last1) {
		if (first2==last2 || *first2<*first1) 
			return (false);
		else if (*first1<*first2) 
			return (true);
		++first1; 
		++first2;
		}
		return (first2!=last2);
	}
	
}

#endif