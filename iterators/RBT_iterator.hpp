/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:37:35 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/05 18:16:58 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

#include "../utils/utils_iterator.hpp"
#include "../RBTree/RBT_node.hpp"
#include "../utils/utils_base_iterators.hpp"

namespace ft {

	/**
	 * @brief Bidirectional iterators are iterators that can be used to access 
	 * the sequence of elements in a range in both directions (towards the end
	 *  and towards the beginning).
	 * 
	 */

	template<typename T> 
	struct RBT_iterator {

		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */
		
		typedef				T									value_type;
		typedef				T&									reference;
		typedef				T*									pointer;
		typedef 			ft::bidirectionnal_iterator_tag		iterator_category;
		typedef				ptrdiff_t							difference_type;
		typedef				RBT_iterator<T>						_Self;
		typedef	typename	RBT_node<T>::node_pointer			_node_pointer;
		typedef				RBT_node<T>*						_Link_type;

		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */
		
		_node_pointer 	_node;

		/* ------------------------------------------------------------- */
		/* --------------------- MEMBERS FUNCTIONS --------------------- */	
		/* ------------------------------------------------------------- */

		RBT_iterator() : _node(0) {};

		explicit RBT_iterator(_Link_type x) : _node(x) {};

		reference	operator* ( void ) const
		{
			return _node->pair;
		}

		pointer		operator->( void ) const 
		{
			return &(_node->pair);
		}

		_Self&		operator++( void)
		{
			_node = ft::RBT_increment(_node);
			return *this;
		}

		_Self		operator++(int)
		{
			_Self tmp = *this;
			_node = ft::RBT_increment(_node);
			return tmp; 			
		}

		_Self&		operator--( void) 
		{
			_node = ft::RBT_decrement(_node);
			return *this;
		}		

		_Self 		operator--(int)
		{
			_Self tmp = *this;
			_node = ft::RBT_decrement(_node);
			return tmp;
		}

		bool		operator==(const _Self x ) const 
		{
			return _node == x._node;
		}

		bool 		operator!=(const _Self x) const 
		{
			return _node != x._node;
		}		
	};

	template< typename T >
	struct 	RBT_const_iterator {

		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */

		typedef 			T									value_type;
		typedef const 		T&									reference;
		typedef const 		T*									pointer;
		typedef 			RBT_iterator<T>						iterator;
		typedef 			ft::bidirectionnal_iterator_tag		iterator_category;
		typedef				ptrdiff_t							difference_type;
		typedef				RBT_const_iterator<T>				_Self;
		typedef	typename	RBT_node<T>::const_node_pointer		_node_pointer;
		typedef	const 		RBT_node<T>*						_Link_type;

		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */

		_node_pointer	_node;

		/* ------------------------------------------------------------- */
		/* --------------------- MEMBERS FUNCTIONS --------------------- */	
		/* ------------------------------------------------------------- */

		RBT_const_iterator( void ) : _node(0) {}

		RBT_const_iterator(_Link_type x) : _node(x) {}

		RBT_const_iterator(const iterator& it) : _node(it._node) {}

		iterator	_const_cast( void ) const
		{
			return (iterator(const_cast<typename iterator::_node_pointer>(_node)));
		}
		
		reference	operator*( void ) const 
		{
			return _node->pair;
		}

		pointer		operator->( void ) const 
		{
			return &(_node->pair);
		}

		_Self&		operator++ ( void )
		{
			_node = ft::RBT_increment(_node);
			return *this;
		}

		_Self	operator++( int ) 
		{
			_Self tmp = *this;
			_node = ft::RBT_increment(_node);
			return tmp;
		}

		_Self&		operator--( void) 
		{
			_node = ft::RBT_decrement(_node);
			return *this;
		}		

		_Self 		operator--(int)
		{
			_Self tmp = *this;
			_node = ft::RBT_decrement(_node);
			return tmp;
		}

		bool		operator==(const _Self x ) const 
		{
			return _node == x._node;
		}

		bool 		operator!=(const _Self x) const 
		{
			return _node != x._node;
		}	
	};
	
	template< typename Val >
	inline bool		operator==(const RBT_iterator<Val>& x, 
								const RBT_const_iterator<Val>& y)
	{
		return (x._node == y._node);
	}

	template< typename Val >
	inline bool		operator!=(const RBT_iterator<Val>& x, 
								const RBT_const_iterator<Val>& y)
	{
		return (x.node != y.node );
	}
}

# endif