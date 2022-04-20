/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:05:54 by clbouche          #+#    #+#             */
/*   Updated: 2022/04/18 17:12:18 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include "RBTree_node.hpp"
#include "../utils/utils_pair.hpp"
#include <memory>
#include <iostream>
#include <string>
#include <functional>
#include <cstddef>

namespace ft {
	/**
    * ------------------------ FT::RBTree ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct tree ✅
	* 		- empty constructor 
	*		- copy constructor 
    * destructor:         	Destruct tree ✅
	* operator=:            Assign tree 
	* 
	* - Modifiers:
	* rotation:
    * 		- left_rotate
	* 		- right_rotate
	* 		- left_right_rotate
	* 		- right_left_rotate
	*		- no rotation
	* change_colors
	* delete:
	* 		- delete tree
	*		- delete node with value 
	*		- delete node with ptr
	* insert:			add node
	* 

    * ------------------------------------------------------------- *
    */

   template < class T, typename Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
	class RBTree {

		public:
		
		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */

		typedef 			T 							value_type;
		typedef typename 	T::first_type				key_type;
		typedef typename	T::second_type				mapped_type;
		typedef				ft::RBT_node<T> 			node;
		typedef	typename	Alloc::template 
							rebind<node>::other			node_allocator;
		typedef typename	node_allocator::pointer		nodePtr;
		typedef typename	node_allocator::reference	nodeRef;
	
		private:
		
		/* ------------------------------------------------------------- */
		/* ---------------------- MEMBERS VARIABLES -------------------- */
		/* ------------------------------------------------------------- */

		nodePtr			_root; 
		nodePtr			_empty;
		node_allocator	_alloc;
		
		public : 

		/* ------------------------------------------------------------- */
		/* ---------------------- COPELIAN CLASS ----------------------- */	
		/* ------------------------------------------------------------- */
		
		/**
		 * @brief Construct a new RBTree object
		 * 
		 * @param node_alloc 
		 */
		RBTree (const node_allocator& node_alloc = node_allocator) : 
			_alloc(node_alloc) {
			node	tmp;

			std::cout << "Hello RBTree" << std::endl;
			this->_empty = _alloc.allocate(1);
			_alloc.construct(this->_empty, tmp);
			this->_root = NULL;
		}

//faire une constructeur par copy 

		/**
		 * @brief Destroy the RBTree object
		 * 
		 */
		~RBTree() {
			clear();
			_alloc.destroy(this->_empty);
			_alloc.deallocate(this->_empty, 1);
		};

		/* ------------------------------------------------------------- */
		/* --------------------- MEMBERS FUNCTIONS --------------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief 
		 * 
		 * @param value 
		 * @todo verifier qu'il y a deja un root sinon ajouter en tant que root et colorer en noir
		 * else, rouge et pas parent. 
		 */
		void	insert(value_type value) {
			
		}
		
//insertion d'une node
		node<T>	insert(node<T> *node, )
	};
	
}



#endif