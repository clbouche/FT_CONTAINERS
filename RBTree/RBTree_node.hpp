/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_node.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:04:21 by clbouche          #+#    #+#             */
/*   Updated: 2022/04/22 13:47:14 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_NODE_HPP
# define  RBTREE_NODE_HPP 

# define BLACK_node	0
# define RED_node	1

# include <memory>
#include <iostream>

namespace ft { 

	/**
    * ------------------------ FT::RBT_node ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct node 
	* 		- empty constructor ✅
	*		- constructor whitout value ✅
	*		- constructor with value ✅
	*		- copy constructor ✅
    * destructor:         	Destruct node ✅
	* 
	* - Operators for node:
    * operator=:            Assign node
	* operator==:			Check equality
	* operator!=:			Check inequality
	* operator>:			Check inferiority
	* operator<:			Check superiority
	* operator>=:			Check if equal or inferior
	* operator<=:			Check if equal or superior
	* 
	* - Operators for value:
	* operator=:            Assign node
	* operator==:			Check equality
	* operator!=:			Check inequality
	* operator>:			Check inferiority
	* operator<:			Check superiority
	* operator>=:			Check if equal or inferior
	* operator<=:			Check if equal or superior
    * ------------------------------------------------------------- *
    */

	template <typename T>
	struct RBT_node {

	public:
	/* ------------------------------------------------------------- */
	/* --------------------------- ALIAS --------------------------- */	
	/* ------------------------------------------------------------- */

		// contain the key and the pair
		typedef T 		value_type;

	/* ------------------------------------------------------------- */
	/* -------------------------- MEMBERS -------------------------- */	
	/* ------------------------------------------------------------- */

		int				color;
		value_type		pair; 
		RBT_node		*root;
		RBT_node		*parent;
		RBT_node		*left;
		RBT_node		*right;

	/* ------------------------------------------------------------- */
	/* ---------------------- COPELIAN CLASS ----------------------- */	
	/* ------------------------------------------------------------- */
	
		/**
		 * @brief Default contructor
		 * 
		 */
		RBT_node (void) : color(RED_node), pair(T()), parent(0), left(0), right(0) 
			{}; 

		/**
		 * @brief Construct a new RBT_node object whitout pair
		 *
		 */
		RBT_node ( RBT_node *parent, RBT_node *left, RBT_node *right) :
			color(RED_node), pair(T()), parent(parent), left(left), right(right)
			{};
			
		/**
		 * @brief Construct a new RBT_node object with pair
		 * 
		 */
		RBT_node (const value_type &pair, RBT_node *parent = 0, RBT_node *left = 0, 
				RBT_node *right = 0) : 
				color(RED_node), pair(pair), parent(parent), left(left), right(right)
			{};

		/**
		 * @brief Construct a new RBT_node object with copy
 		 * 
		 */
		RBT_node ( const RBT_node &node ) : pair(node.pair), parent(node.parent), 
				left(node.left), right(node.right)
			{};

		~RBT_node( void ) 
			{};

	/* ------------------------------------------------------------- */
	/* ------------------------ OPERATORS -------------------------- */	
	/* ------------------------------------------------------------- */

		// RBT_node	&operator= ( const RBT_node &rhs ) {
		// 	if (rhs != *this)
		// 	{
		// 		this->pair = rhs.pair;
		// 		this->color = rhs.color;
		// 		this->root = rhs.root;
		// 		this->parent = rhs.parent;
		// 		this->left = rhs.left;
		// 		this->right = rhs.right;
		// 	}
		// 	return (*this);
		// }

		// bool		operator== ( const RBT_node &rhs ) {
		// 	return (this->pair == rhs.pair && this->parent == rhs.parent);
		// }

		// bool		operator!= ( const RBT_node &rhs ) {
		// 	return (!(this == rhs));
		// }

		// bool		operator>( const RBT_node &rhs) {
		// 	return (this->pair > rhs.pair && this->parent > rhs.parent);
		// }

		// bool		operator<( const RBT_node &rhs) {
		// 	return (this->pair < rhs.pair && this->parent < rhs.parent);
		// }

		// // operator RBt_node<const T> () const{
		// // 	return (RBT_node<const T>(this));
		// // }

	};

	// template <class T>
	// std::ostream &operator<<(std::ostream &out, ft::RBT_node<T> &node)
	// {
	// 	if (&node != nullptr)
	// 	{
	// 		std::string colors;
	// 		node.color == ft::RBT_node<T>::BLACK ? colors = "⚫" : colors = "🔴";
	// 		out << "Node " << node.value << " " << colors;
	// 	}
	// 	return out;
	// }

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const ft::pair<T1,T2>& p)
{
    os << p.first << ": \"" << p.second << "\"";
    return os;
}
}

#endif 