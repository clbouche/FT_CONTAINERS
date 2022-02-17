/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:03:50 by clbouche          #+#    #+#             */
/*   Updated: 2022/02/17 14:43:38 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>


namespace	ft {

	//template<value_type T, allocator_type Alloc>
	class vector
	{
	private:
		size_t size;
	public:

	/* ------------------------------------------------------------- */
    /* --------------------------- ALIAS --------------------------- */	

	typedef	typename	iterator;
	typedef	typename	const_iterator;
	typedef	typename	revserse_iterator;
	typedef	typename	const_reverse_iterator;

	//redefinir size_type = size_t
	

		vector() { std::cout << "ALOHA 3" << std::endl;};
		~vector() { };
		vector&	operator=(const vector &other) { };

	/* ------------------------------------------------------------- */
    /* ------------------------- ITERATORS ------------------------- */

	//iterator 	begin() {
		//return iterator sur le debut; };

	//iterator	end() {
		//return iterator sur la fin; };

	//revserse_iterator	rbegin() { 
		//return iterator sur la fin; };

	//revserse_iterator	rend() {
		//return iterator sur le debut); };

	//const_iterator	cbegin() {
		//return const iterator sur le debut; };

	//const_iterator	cend() {
		//return const iterator sur la fin;};
		
	//const_reverse_iterator	crbegin() {
		//return const iterator sur la fin;};
		
	//const_revserse_iterator	crend() {
		//return const iterator sur le debut;};

	/* ------------------------------------------------------------- */
    /* ------------------------- CAPACITY -------------------------- */
	//size_type	size() const { 
		//return this->size; };

	//size_type	max_size const {
		//return this->max_size; };
		
	//void	resize(size_t n, value_type val = value_type());
	//size_type	capacity() const { 
		// return capacity of the vector };
		
	//bool	empty() const {
		//if (empty)
			//return (true);
		//return (false)};

	//void	
	};
		
}

#endif