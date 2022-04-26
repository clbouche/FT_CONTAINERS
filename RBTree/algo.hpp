/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:51:42 by claclou           #+#    #+#             */
/*   Updated: 2022/04/26 19:20:52 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_HPP
# define ALGO_HPP

#include "RBT_node.hpp"
#include "../utils/utils_pair.hpp"

#include <string>
#include <iostream>

namespace ft {
	
	template <class K, class T, class Compare = std::less<K>, class Alloc = std::allocator<T> >
	class RBTree {

		public:
		/* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */

		typedef				K 							key_type;
		typedef 			T							value_type;
		typedef 			Alloc						allocator_type;
		typedef				ft::RBT_node<T>				node;
		typedef				Compare						key_compare;

		
		typedef typename	allocator_type::template
							rebind<node>::other			node_allocator;

		private:
		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */

		node			*_root;
		node			*_empty;
		node			*_leaf_left;
		node			*_leaf_right;
		node_allocator	_node_alloc;
		int				_size;

		public:
		/*-------------------------------------------------------------- */
		/* --------------------------- CONTRUCT  ----------------------- */	
		/* -------------------------- & DESTRUCT  ---------------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief Default Constructor
		 * 
		 * @param nodeAlloc 
		 */
		RBTree (const node_allocator& nodeAlloc = node_allocator() ) :
					_node_alloc(nodeAlloc) 
		{
			node	tmp;
			
			std::cout << "Hello RBT" << std::endl;
			this->_empty = _node_alloc.allocate(1);
			_node_alloc.construct(this->_empty, tmp);
			this->_leaf_left = _node_alloc.allocate(1);
			_node_alloc.construct(this->_leaf_left, tmp);
			this->_leaf_right = _node_alloc.allocate(1);
			_node_alloc.construct(this->_leaf_right, tmp);
			this->_root = NULL;	
			this->_size = 0;
		}

		/**
		 * @brief Copy constructor
		 * @todo inserer tous les nodes de la copy dans le nouvel arbre 
		 * @todo implementer insert + iterator
		 * 
		 */
		// RBTree (const RBTree& copy) 
		// {
		// 	this->_root = NULL;
			
		// }

		/**
		 * @brief Destructor. 
		 * @todo supprimer l'arbre 
		 * @todo leaks : desallouer tous les nodes alloues.
		 * 
		 */
		~RBTree (void)
		{
			//deleteTree(this->_root);
			_node_alloc.destroy(this->_empty);
			_node_alloc.deallocate(this->_empty, 1);
			_node_alloc.destroy(this->_leaf_left);
			_node_alloc.deallocate(this->_leaf_left, 1);
			_node_alloc.destroy(this->_leaf_right);
			_node_alloc.deallocate(this->_leaf_right, 1);
		}

		/* ------------------------------------------------------------- */
		/* --------------------------- UTILS --------------------------- */	
		/* ------------------------------------------------------------- */

		bool	isLeaf( node *node ) const
		{
			if (node->left == NULL && node->right == NULL)
				return (true);
			return (false);
		}

		/* ------------------------------------------------------------- */
		/* -------------------------- INSERT --------------------------- */	
		/* ------------------------------------------------------------- */
		
		node	*FindPositionToInsert(node *new_node)
		{
			node	*check = this->_root;
			node	*position = NULL;
			while (check != NULL && check != this->_empty)
			{
				position = check;
				if (_comp(new_node->pair, check->pair))
					check = check->left;
				else
					check = check->right;
			}
			return (position);
		}
		node	*insert ( value_type to_insert )
		{
			node	new_node(to_insert, NULL, this->_empty, this->_empty);
			node	*insert_pos = NULL;

			node *position = FindPositionToInsert(&new_node);
			//this->unsetHeader();
			new_node.parent = position;
			if (position == NULL)
			{
				this->_root = _node_alloc.allocate(1);
				insert_pos = this->_root;
				this->_root->color = BLACK_n;
			}
			else if (key_compare()(new_node.pair.first, position->pair.first))
			{
				position->left = _node_alloc.allocate(1);
				insert_pos = position->left;
			}
			else
			{
				position->right = _node_alloc.allocate(1);
				insert_pos = position->right;
			}
			this->_node_alloc.construct(insert_pos, new_node);
			this->_size++;
			if (insert_pos->parent == NULL)
			{
				//this->setHeader();
				insert_pos->color = BLACK_n;
				return (insert_pos);
			}
			if (insert_pos->parent->parent == NULL)
			{
				//this->setHeader();
				return (insert_pos);
			}
			//this->setHeader();
			//insert_fix(insert_pos);
			return (insert_pos);
		}

		/* ------------------------------------------------------------- */
		/* -------------------------- DELETE --------------------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief Delete a node when we have the value and the key
		 * 
		 */
		void	delete_node(node *node) {
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

		/* ------------------------------------------------------------- */
		/* ------------------------ FIX RULES -------------------------- */	
		/* ------------------------------------------------------------- */

		void	fixRBTPropertiesAfterInsert(){
			
		}

		void	fixRBTPropertiesAfterDelete() {
			
		}

		/* ------------------------------------------------------------- */
		/* ------------------------ ROTATIONS -------------------------- */	
		/* ------------------------------------------------------------- */
		
		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		// void	leftRotate(node *node) {
		// 	node	tmp = node->right;
		// 	node->right = tmp->left;
		// 	if (tmp->left != NULL)
		// 		tmp->left->parent = node;
		// 	tmp->parent = node->parent;
		// 	if (node->parent == NULL) 
		// 		this->_root = tmp;
		// 	else if (node == node->parent->left)
		// 		node->parent->left = tmp;
		// 	else
		// 		node->parent->right = tmp;
		// 	tmp->left = node;
		// 	node->parent = tmp;
		// }

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	rightRotate(node *node) {
			(void)node;
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	leftRightRotate(node *node ) {
			(void)node;			
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	rightLeftRotate(node *node ) {
			(void)node;			
		}

		void	recolor(node *node ) {
			(void)node;
		}

		/* ------------------------------------------------------------- */
		/* --------------------------- PRINT --------------------------- */	
		/* ------------------------------------------------------------- */

		void	printTree ( void ) const
		{
			if (this->_root != NULL)
				printTreeHelper(this->_root, "", true);
		}

		void	printTreeHelper ( node *node, std::string indent, bool side ) const
		{
			if (!isLeaf(node))
			{
				std::cout << indent;
				if (side)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "   ";
				}

				std::string sColor = node->color ? "🔴" : "⚫";
				std::cout << "(" << node->pair.first << ") (" << sColor << ")" << std::endl;
				printTreeHelper(node->left, indent, false);
				printTreeHelper(node->right, indent, true);
			}
		}

		private:

		/* ------------------------------------------------------------- */
		/* --------------------------- UTILS --------------------------- */	
		/* ------------------------------------------------------------- */
		bool _comp(value_type a, value_type b, Compare u = Compare())
		{
			return u(a.first, b.first);
		}

	};
}



#endif