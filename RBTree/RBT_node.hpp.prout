/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:31:22 by claclou           #+#    #+#             */
/*   Updated: 2022/05/05 14:01:44 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef RBTREE_NODE_HPP
# define RBTREE_NODE_HPP

# define BLACK_n	0
# define RED_n	1

namespace ft 
{
	template< typename T >
	class RBT_node
	{
		public:
		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */
			typedef			RBT_node<T>*	node_pointer;
			typedef const	RBT_node<T>*	const_node_pointer;
			typedef			T				value_type;

		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */
			RBT_node	*parent;
			RBT_node	*left;
			RBT_node	*right;
			int			color;
			value_type	pair;

		/*-------------------------------------------------------------- */
		/* --------------------------- CONTRUCT  ----------------------- */	
		/* -------------------------- & DESTRUCT  ---------------------- */	
		/* ------------------------------------------------------------- */

			/**
			 * @brief Default constructor
			 */
			RBT_node ( void ) : parent(0), left(0), right(0), color(RED_n), 
								pair(T()) {}

			/**
			 * @brief Construct a new rbtree node object 
			 * 
			 */
			RBT_node(RBT_node *parent, RBT_node *left, RBT_node *right) :
					parent(parent), left(left), right(right),
					color(RED_n), pair(T()) {}

			/**
			 * @brief Construct a new RB node object
			 * 
			 */
			RBT_node ( const value_type &val, RBT_node *parent = 0, 
						RBT_node *left = 0, RBT_node *right = 0) :
				parent(parent),
				left(left),
				right(right),
				color(RED_n),
				pair(val)
			{}


			/**
			 * @brief Construct a new rbtree node object with copy
			 * 
			 */
			RBT_node(RBT_node const &copy) :
				parent(copy.parent),
				left(copy.left),
				right(copy.right),
				color(copy.color),
				pair(copy.pair)
			{}

			/**
			 * @brief Assign node
			 * 
			 */
			RBT_node& operator=(const RBT_node& other)
			{
				if (this != &other) {
				this->parent = other.parent;
				this->left = other.left;
				this->right = other.right;
				this->pair = other.pair;
				this->color = other.color;
				}
				return *this;
			}	

			/**
			 * @brief Destroy the rbt node object
			 * 
			 */
			~RBT_node( void )
			{}
	};

}

#endif
