/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:51:42 by claclou           #+#    #+#             */
/*   Updated: 2022/04/27 17:45:34 by clbouche         ###   ########.fr       */
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
		typedef				ft::RBT_node<T>				Node;
		typedef				Compare						key_compare;

		
		typedef typename	allocator_type::template
							rebind<Node>::other			node_allocator;

		private:
		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */

		Node			*_root;
		Node			*_empty;
		Node			*_leaf_left;
		Node			*_leaf_right;
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
			Node	tmp;
			
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

		bool	isLeaf( Node *node ) const
		{
			if (node->left == NULL && node->right == NULL)
				return (true);
			return (false);
		}

		bool _comp(value_type a, value_type b, Compare u = Compare())
		{
			return u(a.first, b.first);
		}

		void NodesTransplant(Node *i, Node *j) 
		{
			if (i->parent == NULL)
				this->_root = j;
			else if (i == i->parent->left)
				i->parent->left = j;
			else
				i->parent->right = j;
			j->parent = i->parent;
		}

		/* ------------------------------------------------------------- */
		/* ------------------------- MIN / MAX ------------------------- */	
		/* ------------------------------------------------------------- */

		Node	*maximum(Node *node) 
		{
			while(node->right != this->_empty)
				node = node->right;
			return (node);
		}
		
		Node 	*minimum(Node *node) 
		{
			while(node->left != this->_empty)
				node = node->left;
			return (node);
		}

		/* ------------------------------------------------------------- */
		/* -------------------------- INSERT --------------------------- */	
		/* ------------------------------------------------------------- */
		
		Node	*FindPositionToInsert(Node *new_node)
		{
			Node	*check = this->_root;
			Node	*position = NULL;
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
		
		Node	*insert ( value_type to_insert )
		{
			Node	new_node(to_insert, NULL, this->_empty, this->_empty);
			Node	*insert_pos = NULL;

			Node *position = FindPositionToInsert(&new_node);
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
			// fixRBTPropertiesAfterInsert(insert_pos);
			return (insert_pos);
		}

		/* ------------------------------------------------------------- */
		/* -------------------------- DELETE --------------------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @brief Delete node with the value
		 * 
		 */
		void	delete_node(value_type value) {
			Node	*tmp(this->_root);

			while(tmp != this->_empty) {
				if ((*tmp).pair == value)
					return (delete_node(tmp));
				if (key_compare()(tmp->pair.first, value.first))
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
		}

		/**
		 * @brief Delete node with the position of the node to delete
		 * 
		 */
		void	delete_node(Node *NodeToBeDeleted) {
			Node	*tmp = NodeToBeDeleted;
			Node	*new_parent;
			int originalColor = tmp->color;
			
			// this->unsetHeader();
			if (NodeToBeDeleted->left == this->_empty) {
				new_parent = NodeToBeDeleted->right;
				NodesTransplant(NodeToBeDeleted, NodeToBeDeleted->right);
			}
			else if (NodeToBeDeleted->right == this->_empty) {
				new_parent = NodeToBeDeleted->left;
				NodesTransplant(NodeToBeDeleted, NodeToBeDeleted->left);
			}
			else
			{
				tmp = minimum(NodeToBeDeleted->right);
				originalColor = tmp->color;
				new_parent = tmp->right;
				if (tmp->parent == NodeToBeDeleted)
					new_parent->parent = tmp;
				else
				{
					NodesTransplant(tmp, tmp->right);
					tmp->right = NodeToBeDeleted->right;
					tmp->right->parent = tmp;
				}
				NodesTransplant(NodeToBeDeleted, tmp);
				tmp->left = NodeToBeDeleted->left;
				tmp->left->parent = tmp;
				tmp->color = NodeToBeDeleted->color;
			}
			this->_node_alloc.destroy(NodeToBeDeleted);
			this->_node_alloc.deallocate(NodeToBeDeleted, 1);
			this->_size--;
			// if (original_color == BLACK)
				// fixRBTPropertiesAfterDelete(parent);
			// if (!isLeaf(this->_root))
			// 	this->setHeader();
			// else
			// 	this->_root = NULL;
		}


		/**
		 * @brief Delete node with key value
		 * 
		 */
		// void	delete_node(key_type key)
		// {
		// 	//use function find to find the position
		// 	//use delete_node with the node_position;
		// }

		/**
		 * @brief Delete tree - recursive
		 * 
		 */
		void	delete_tree ( Node *node )
			{
				if (node != NULL)
				{
					delete_tree(node->left);
					delete_tree(node->right);
				}
				if (node != this->_empty && node != NULL) //&& node != this->_leaf_left && node != this->_leaf_right)
				{
					this->_node_alloc.destroy(node);
					this->_node_alloc.deallocate(node, 1);
				}
			}
		/* ------------------------------------------------------------- */
		/* ------------------------ FIX RULES -------------------------- */	
		/* ------------------------------------------------------------- */

		// void	fixRBTPropertiesAfterInsert(){
			
		// }

		// void	fixRBTPropertiesAfterDelete() {
			
		// }

		/* ------------------------------------------------------------- */
		/* ------------------------ ROTATIONS -------------------------- */	
		/* ------------------------------------------------------------- */
		
		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	leftRotate(Node *node) {
			Node	*tmp = node->right;
			node->right = tmp->left;
			if (tmp->left != NULL)
				tmp->left->parent = node;
			tmp->parent = node->parent;
			if (node->parent == NULL) 
				this->_root = tmp;
			else if (node == node->parent->left)
				node->parent->left = tmp;
			else
				node->parent->right = tmp;
			tmp->left = node;
			node->parent = tmp;
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	rightRotate(Node *node) {
			Node *tmp = node->left;
			node->left = tmp->right;
			if (tmp->right != NULL)
				tmp->right->parent = node;
			tmp->parent = node->parent;
			if (node->parent == NULL)
				this->root = tmp;
			else if (node == node->parent->right)
				node->parent->right = tmp;
			else
				node->parent->left = tmp;
			tmp->right = node;
			node->parent = tmp;
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	leftRightRotate(Node *node ) {
			(void)node;			
		}

		/**
		 * @brief 
		 * 
		 * @param node 
		 */
		void	rightLeftRotate(Node *node ) {
			(void)node;			
		}

		void	recolor(Node *node ) {
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

		void	printTreeHelper ( Node *node, std::string indent, bool side ) const
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


	};
}



#endif