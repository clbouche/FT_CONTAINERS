/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:05:54 by clbouche          #+#    #+#             */
/*   Updated: 2022/04/19 16:42:02 by clbouche         ###   ########.fr       */
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
    * ------------------------ FT::RBTree------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct tree 
	* 		- empty constructor 
	*		- constructor with root value
	*		- copy constructor
    * destructor:         	Destruct node 
	* 
	* - Operators:
    * operator=:            Assign tree
	* 
	* - Modifiers: 
	* insert:
	* delete:
	* rotation: 
	*		- 
	*		- 
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
							rebind<Node>::other					node_allocator;

		//easier to call
		typedef typename	node_allocator::pointer				node_pointer; 
		typedef typename	node_allocator::reference			node_reference;
	
		private:
		
		/* ------------------------------------------------------------- */
		/* --------------------- MEMBERS VAR --------------------------- */	
		/* ------------------------------------------------------------- */

		node_pointer	_empty;
		node_pointer	_root;
		node_allocator	_node_alloc;
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

		~RBTree () {
			
		}
		
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


 		node_pointer insert(node_pointer tmp_node, value_type value, Node* parent = NULL)
        {
            if (tmp_node == NULL){
				std::cout << "coucou root" << std::endl;
				node_pointer new_node(value, parent, this->_empty, this->_empty);
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
		// node_pointer 	insert(const value_type value ) {
		// 	Node			new_node(RED, value, NULL, this->_empty, this->_empty);
		// 	node_pointer 	tmp_node = this->_root;
		
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
		// node_pointer	insert(node_pointer node ) {
		// 	(void)node;
		// }

		/* ------------------------------------------------------------- */
		/* ----------------------- DELETE ------------------------------ */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief Delete a node when we have the value and the key
		 * 
		 */
		void	delete_node(node_pointer node) {
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
		void	left_rotate(node_pointer node) {
			(void)node;
		}	

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	right_rotate(node_pointer node) {
			(void)node;
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	left_right_rotate(node_pointer node ) {
			(void)node;			
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	right_left_rotate(node_pointer node ) {
			(void)node;			
		}

		void	recolor(node_pointer node ) {
			(void)node;
		}

   };
	
}


#endif