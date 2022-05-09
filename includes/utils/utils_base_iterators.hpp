/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_base_iterators.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:59:50 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/05 18:14:40 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BASE_ITERATORS_HPP
# define UTILS_BASE_ITERATORS_HPP

#include "../RBTree/RBT_node.hpp"

namespace ft {
	
	template <typename T>
	bool						is_leaf (ft::RBT_node<T>* x )
	{
		if (x->parent == NULL && x->left == NULL && x->right == NULL)
			return (true);
		return (false);
	}

	/**
	 * @brief Incremente a node to find the key_value superior of x.
	 * 
	 */
	template < typename T >
	static ft::RBT_node<T>*		local_RBT_increment( ft::RBT_node<T>* x) throw()
	{
		if (x->right && x->right->parent != 0)
		{
			x = x->right;
			while(x->left != 0 && x->left->parent != 0)
				x = x->left;
		}
		else
		{
			ft::RBT_node<T>* y = x->parent;
			while (x == y->right)
			{
				x = y;
				y = y->parent;
			}
			if (x->right != y)
				x = y; 
		}
		return x;
	}

	template< typename T >
	ft::RBT_node<T>*	RBT_increment(ft::RBT_node<T>* x) throw ()
	{
		return (local_RBT_increment(x));
	}

	template< typename T >
	const ft::RBT_node<T>*	RBT_increment(const ft::RBT_node<T>* x) throw ()
	{
		return (local_RBT_increment(const_cast<ft::RBT_node<T>*>(x)));
	}

	template< typename T >
	static ft::RBT_node<T>*		local_RBT_decrement( ft::RBT_node<T>* x) throw ()
	{
		if (x->color == RED_n && x->parent->parent == x)
			x = x->right;
		else if (x->left != 0 && !is_leaf(x->left))
		{
			ft::RBT_node<T>*	y = x->left;
			while(y->right != 0 && !is_leaf(y->right))
				y = y->right;
			x = y;
		}
		else 
		{
			ft::RBT_node<T>* y = x->parent;
			while(x == y->left)
			{
				x = y;
				y = y->parent;
			}
			x = y;
		}
		return x;
	}

	template< typename T >
	ft::RBT_node<T>*	RBT_decrement(ft::RBT_node<T>* x) throw()
	{
		return (local_RBT_decrement(x));
	}

	template< typename T>
	const ft::RBT_node<T>*		RBT_decrement(const ft::RBT_node<T>* x) throw()
	{
		return (local_RBT_decrement(const_cast<ft::RBT_node<T>*> (x)));
	}
}

#endif 
