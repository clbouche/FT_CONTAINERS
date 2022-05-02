/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:37:35 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/02 17:14:54 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

#include "../utils/utils_iterator.hpp"
#include "../RBTree/RBT_node.hpp"

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
		
		typedef		T									value_type;
		typedef		T&									reference;
		typedef		T*									pointer;
		typedef 	ft::bidirectionnal_iterator_tag		iterator_category;
		typedef		ptrdiff_t							difference_type;
		typedef		RBT_iterator<T>						_Self;
    //    typedef _Rb_tree_node_base::_Base_ptr _Base_ptr;
		typedef		ft::RBT_Node<T>*					_Link_type;

		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */
		
		_Link_type 	_node;

		/* ------------------------------------------------------------- */
		/* --------------------- MEMBERS FUNCTIONS --------------------- */	
		/* ------------------------------------------------------------- */

		RBT_iterator() : _node(0) {};

		explicit RBT_iterator(_Link_type x) : _node(x) {};

		reference	operator* ( void ) const
		{
			return (_node->pair);
		}

		pointer		operator->( void ) const 
		{
			return (&(node->pair));
		}

		_Self&		operator++( void)
		{
			_node = ft::RBT_increment(_node);
			return *this;
		}
		
	};

}

//   _Self&
//       operator++()
//       {
//     _M_node = _Rb_tree_increment(_M_node);
//     return *this;
//       }
// 
//       _Self
//       operator++(int)
//       {
//     _Self __tmp = *this;
//     _M_node = _Rb_tree_increment(_M_node);
//     return __tmp;
//       }
// 
//       _Self&
//       operator--()
//       {
//     _M_node = _Rb_tree_decrement(_M_node);
//     return *this;
//       }
// 
//       _Self
//       operator--(int)
//       {
//     _Self __tmp = *this;
//     _M_node = _Rb_tree_decrement(_M_node);
//     return __tmp;
//       }
// 
//       bool
//       operator==(const _Self& __x) const
//       { return _M_node == __x._M_node; }
// 
//       bool
//       operator!=(const _Self& __x) const
//       { return _M_node != __x._M_node; }
// 
//       _Base_ptr _M_node;
//     };

# endif RBT_ITERATOR_HPP