/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_node.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:04:21 by clbouche          #+#    #+#             */
/*   Updated: 2022/04/13 14:15:11 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_NODE_HPP
# define  RBTREE_NODE_HPP 

# include <memory>
# define BLACK	0
# define RED	1

namespace ft { 

	/** ✅
    * ------------------------ FT::RBT_node ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct node 
	* 		- empty constructor 
	*		- parent constructor
	*		- child constructor
	*		- copy constructor
    * destructor:         	Destruct node 
	* 
	* - Operators:
    * operator=:            Assign node
	* operator==:			Check equality
	* operator!=:			Check inequality
	* operator>:			Check inferiority
	* operator<:			Check superiority
	* operator>=:			Check if equal or inferior
	* operator<=:			Check if equal or superior
	* 
    * ------------------------------------------------------------- *
    */

	template <typename T>
	struct RBT_node {

	public:
	/* ------------------------------------------------------------- */
	/* --------------------------- ALIAS --------------------------- */	
	/* ------------------------------------------------------------- */

		typedef T 		value_type;

	/* ------------------------------------------------------------- */
	/* -------------------------- MEMBERS -------------------------- */	
	/* ------------------------------------------------------------- */

		int				color;
		value_type		value;
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
		RBT_node (void) : color(RED), value(T()), parent(0), left(0), right(0) 
			{}; 

		/**
		 * @brief Construct a new RBT_node object whitout value
		 *
		 */
		RBT_node ( RBT_node *parent, RBT_node *left, RBT_node *right) :
			color(RED), value(T()), parent(parent), left(left), right(right)
			{};
			
		/**
		 * @brief Construct a new RBT_node object with value
		 * 
		 */
		RBT_node (const value_type &value, RBT_node *parent, RBT_node *left, 
				RBT_node *right) : 
				color(RED), value(value), parent(parent), left(left), right(right)
			{};

		/**
		 * @brief Construct a new RBT_node object with copy
 		 * 
		 */
		RBT_node ( const RBT_node &node ) : value(node.value), parent(node.parent), 
				left(node.left), right(node.right)
			{};

		~RBT_node( void ) 
			{};

	/* ------------------------------------------------------------- */
	/* ------------------------ OPERATORS -------------------------- */	
	/* ------------------------------------------------------------- */

		RBT_node	&operator= ( const RBT_node &rhs ) {
			if (rhs != *this)
			{
				this->value = rhs.value;
				this->color = rhs.color;
				this->left = rhs.left;
				this->right = rhs.right;
				this->parent = rhs.parent;
			}
			return (*this);
		}

		bool		operator== ( const RBT_node &rhs ) {
			return (this->value == rhs.value && this->parent == rhs.parent);
		}

		bool		operator!= ( const RBT_node &rhs ) {
			return (!(this == rhs));
		}

		bool		operator>( const RBT_node &rhs) {
			return (this->value > rhs.value && this->parent > rhs.parent);
		}

		bool		operator<( const RBT_node &rhs) {
			return (this->value < rhs.value && this->parent < rhs.parent);
		}

		// operator RBt_node<const T> () const{
		// 	return (RBT_node<const T>(this));
		// }

};

#endif 