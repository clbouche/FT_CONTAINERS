/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:05:54 by clbouche          #+#    #+#             */
/*   Updated: 2022/04/20 08:53:51 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# define BLACK_node	0
# define RED_node	1

#include "RBTree_node.hpp"
#include <iostream>
#include <memory>
#include <string>

namespace ft {
	/**
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

   template < class T, class Compare = std::less <typename T::first_type>, class Alloc = std::allocator<T> > 
   class RBTree {

	   public:

		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */

		//first value of the pair, the value.
		typedef typename	T::first_type						mapped_type;

		//second value of the pair, the key.
		typedef	typename	T::second_type						key_type;

		//result of std::less
		typedef				Compare								key_compare;

		//the pair
		typedef				T									value_type;
		typedef 			Alloc								allocator_type;
		
		//all the informations of the node
		typedef				ft::RBT_node<T>						Node;
		
		//solution for alloc problem
		typedef typename	allocator_type::template
							rebind<Node>::other					nodeAlloc;

		//easier to call
		typedef typename	nodeAlloc::pointer					nodePtr; 
		typedef typename	nodeAlloc::reference				nodeRef;

	
		private:
		
		/* ------------------------------------------------------------- */
		/* --------------------- MEMBERS VAR --------------------------- */	
		/* ------------------------------------------------------------- */

		nodePtr			_empty;
		nodePtr			_root;
		nodeAlloc		_node_alloc;
		key_compare		_comp;

		public:
		
		/* ------------------------------------------------------------- */
		/* --------------------- CONSTRUCTOR --------------------------- */	
		/* ------------------------------------------------------------- */
		
		RBTree () {
			std::cout << "Hello RBTree" << std::endl;
			_root = NULL;
			//this->_empty = _node_alloc.allocate(1);
		}

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
		/* ------------------------- HELPERS --------------------------- */	
		/* ------------------------------------------------------------- */


		/* ------------------------------------------------------------- */
		/* --------------------------- PRINT --------------------------- */	
		/* ------------------------------------------------------------- */

		// void	printRBTree(void) {
			
			
		// 	for (node tmp = _root; node != _empty; )
		// }

		/* ------------------------------------------------------------- */
		/* ------------------------ INSERT ----------------------------- */	
		/* ------------------------------------------------------------- */

        void        insert(const value_type value) { 
			std::cout << "coucou" << std::endl;
			this->_root = insert(this->_root, value); }


 		nodePtr insert(nodePtr tmp_node, value_type value, Node* parent = NULL)
        {
            if (tmp_node == NULL){
				std::cout << "coucou root" << std::endl;
				nodePtr new_node(value, parent, this->_empty, this->_empty);
				new_node->color = BLACK_node;
				return (new_node);
			}
            if (_comp(value.first, tmp_node->pair.first))
                tmp_node->left = insert(tmp_node->left, value, tmp_node);
            else if (_comp(tmp_node->pair.first, value.first))
               tmp_node->right = insert(tmp_node->right, value, tmp_node);
            else
                return tmp_node; //if the value exist already in the tree
		}

				
		// /**
		//  * @brief Insertion of a new value in the tree 
		//  * 
		//  * @param value value of the node
		//  */
		// nodePtr 	insert(const value_type value ) {
		// 	Node			new_node(RED, value, NULL, this->_empty, this->_empty);
		// 	nodePtr 	tmp_node = this->_root;
		
		// 	if (tmp_node == NULL) {
		// 		this->_root = new_node;
		// 		new_node.color = BLACK;
		// 	}

        //     if (_comp(key.first, node->pair.first))
        //         node->left = insert(node->left, key, node);
        //     else if (_comp(node->pair.first, key.first))
        //         node->right = insert(node->right, key, node);
        //     else                // Equal keys
        //         return node;

		// 	//verifier que la key_value n'existe pas deja sinon print pas 2 valeurs identiques

		// 	//creer un node temporaire qui pointe sur root
		// 	//comparer avec std::less et envoyer a droite ou a gauche selon ce qui est renvoye
		// 	//sauf si le node en question est vide
		// 	//dans ce cas : on le remplit avec le node
		// 	//le parent de ce nouveau node devient celui sur lequel le node temporaire pointe
		// 	//checkInsert();
		// }



		/**
		 * @brief Insertion of a new node in the tree
		 * 
		 * @param node contain value and key
		 */
		// nodePtr	insert(nodePtr node ) {
		// 	(void)node;
		// }

		/* ------------------------------------------------------------- */
		/* ----------------------- DELETE ------------------------------ */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief Delete a node when we have the value and the key
		 * 
		 */
		void	delete_node(nodePtr node) {
			(void)node;
		}

		/**
		 * @brief Delete a node when we have just the value
		 * 
		 */
		void	delete_node(value_type value) {
			(void)value;
		}

		/**
		 * @brief Delete all the elements of the tree
		 * 
		 */
		void	delete_tree() {
			
		}

		private:
		
		/* ------------------------------------------------------------- */
		/* -------------------------- FIX RBT -------------------------- */	
		/* ------------------------------------------------------------- */

		void	fixRBTPropertiesAfterInsert(){
			
		}
		
		/* ------------------------------------------------------------- */
		/* ---------------------- ROTATIONS ---------------------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	left_rotate(nodePtr node) {
			(void)node;
		}	

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	right_rotate(nodePtr node) {
			(void)node;
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	left_right_rotate(nodePtr node ) {
			(void)node;			
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	right_left_rotate(nodePtr node ) {
			(void)node;			
		}

		void	recolor(nodePtr node ) {
			(void)node;
		}

   };
	
}


#endif