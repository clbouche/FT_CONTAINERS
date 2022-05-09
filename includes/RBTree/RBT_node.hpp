/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:57:16 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/09 11:59:34 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_NODE_HPP
# define RB_NODE_HPP

# include <memory>

# define BLACK_n	0
# define RED_n	1

namespace ft
{
	template <typename T>
	struct RBT_node
	{
		public:
		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */
			typedef	T							value_type;

			typedef	RBT_node<T>					node_type;

			typedef RBT_node<T>*				node_pointer;

			typedef const RBT_node<T>*			const_node_pointer;

			typedef	std::allocator<node_type>	allocator_type;

		private:
			allocator_type	_alloc;

		public:
		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */
			value_type			pair;
			RBT_node			*parent;
			RBT_node			*left;
			RBT_node			*right;
			int					color;

		/*-------------------------------------------------------------- */
		/* --------------------------- CONTRUCT  ----------------------- */	
		/* -------------------------- & DESTRUCT  ---------------------- */	
		/* ------------------------------------------------------------- */
			/**
			 * @brief Default.
			 * Create an empty value initialized node
			 */
			RBT_node ( void ) : pair(T()), parent(0), left(0), right(0), color(BLACK_n)
			{}

			/**
			 * @brief Construct a new RB node object
			 * Create a RB_node with default initialized value
			 *
			 */
			RBT_node ( RBT_node *parent, RBT_node *left = 0, RBT_node *right = 0, int color = BLACK_n ) :
				pair(T()), parent(parent), left(left), right(right), color(color)
			{}

			/**
			 * @brief Construct a new RB node object
			 * Create a RB_node with default initialized value
			 *
			 */
			RBT_node ( const value_type &val, RBT_node *parent = 0, RBT_node *left = 0, RBT_node *right = 0,
				int color = BLACK_n ) :
				pair(val), parent(parent), left(left), right(right), color(color)
			{}

			/**
			 * @brief Copy a RB_node
			 *
			 */
			RBT_node ( const RBT_node &node ) :
				pair(node.pair),
				parent(node.parent),
				left(node.left),
				right(node.right),
				color(node.color)
			{}

			/**
			 * @brief Assigns rhs as the new content for the RB_node object.
			 * Member value is assigned rhs.value, member left is assigned rhs.left,
			 * and member right is assigned right.value.
			 *
			 */
			RBT_node	&operator= ( const RBT_node &rhs )
			{
				if (rhs != *this)
				{
					this->pair = rhs.pair;
					this->color = rhs.color;
					this->left = rhs.left;
					this->right = rhs.right;
					this->parent = rhs.parent;
				}
				return (*this);
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
