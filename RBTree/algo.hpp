/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:51:42 by claclou           #+#    #+#             */
/*   Updated: 2022/05/02 16:14:23 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_HPP
# define ALGO_HPP

#include "RBT_node.hpp"
#include "../iterators/RBT_iterator.hpp"
#include "../utils/utils_pair.hpp"

#include <string>
#include <iostream>

# define BLACK_n	0
# define RED_n	1

namespace ft {
	
	/**
    * ------------------------ FT::RBT ------------------------- *
    *
    * - Coplien form:
    * default constructor ✅
	* Copy constructor 
	* Assign constructor ✅
	* Destructor ✅
	* 
	* - Members functions:
	* max:					Return the higher value of the tree ✅
	* min:					Return the smallest value of the tree ✅
	* insert:				Insert a new node in the tree ✅ 
	* delete_node:			Delete a node with key, value or position 
	* delete_tree:			Delete the entire tree ✅
	* fixInsert: 			Change the organisation of the tree to follow the rules of the RBT ✅
	* fixDelete:			Idem ✅
	* Rotation:
	*	rightRotate
	*	leftRotate
	* clear:				delete and clear the tree ✅
	* findNode:				search and find a node in the tree with pair or key
	* swap: 
	*
	* - Friends functions:
	* 	operator== 
	* 	operator<  
	* 
	* - Non members functions:
	* relational operators: Relational operators for RBT
	* 	operator== 
	* 	operator!= 
	* 	operator<  
	*	operator>  
	*	operator<= 
	* 	operator>= 
	* ------------------------------------------------------------- *
    */
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
			delete_tree(this->_root);
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

		bool	_comp(value_type a, value_type b, Compare u = Compare())
		{
			return u(a.first, b.first);
		}

		void	NodesTransplant(Node *i, Node *j) 
		{
			if (i->parent == NULL)
				this->_root = j;
			else if (i == i->parent->left)
				i->parent->left = j;
			else
				i->parent->right = j;
			j->parent = i->parent;
		}
		
		void	clear ( void )
		{
			delete_tree(this->_root);
			this->_root = NULL;
			this->_size = 0;
			this->_leaf_left->parent = NULL;
			this->_leaf_right->parent = NULL;
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
		
		/**
		 * @todo
		 * remplacer par iterator(insert_pos) le return 
		 *  
		 */
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
			fixRBTPropertiesAfterInsert(insert_pos);
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
			if (originalColor == BLACK_n)
				fixRBTPropertiesAfterDelete(new_parent);
			// if (!isLeaf(this->_root))
			// 	this->setHeader();
			// else
			// 	this->_root = NULL;
		}


		/**
		 * @brief Delete node with key value
		 * 
		 */
		void	delete_node(key_type key)
		{
			Node	*tmp;

			tmp = find_node(key);
			if (tmp != this->end())
				delete_node(tmp);
		}

		/**
		 * @brief Delete tree - recursive
		 * 
		 */
		void	delete_tree ( Node *root )
		{
			if (root != NULL)
			{
				delete_tree(root->left);
				delete_tree(root->right);
			}
			if (root != this->_empty && root != NULL && root != this->_leaf_left && root != this->_leaf_right)
			{
				this->_node_alloc.destroy(root);
				this->_node_alloc.deallocate(root, 1);
			}
		}

		/* ------------------------------------------------------------- */
		/* ------------------------ FIX RULES -------------------------- */	
		/* ------------------------------------------------------------- */

		void	fixRBTPropertiesAfterInsert(Node *node)
		{
			Node	*tmp;

			while(node->parent->color == RED_n) {
				if (node->parent == node->parent->parent->right) {
					tmp = node->parent->parent->left;
					if (tmp && tmp->color == RED_n) {
						tmp->color = BLACK_n;
						node->parent->color = BLACK_n;
						node->parent->parent->color = RED_n;
						node = node->parent->parent;
					}
					else {
						if (node == node->parent->left) {
							node = node->parent;
							rightRotate(node);
						}
						node->parent->color = BLACK_n;
						node->parent->parent->color = RED_n;
						leftRotate(node->parent->parent);
					}
				}
				else {
					tmp = node->parent->parent->right;
					if (tmp && tmp->color == RED_n) {
						tmp->color = BLACK_n;
						node->parent->color = BLACK_n;
						node->parent->parent->color = RED_n;
						node = node->parent->parent;
					}
					else {
						if (node == node->parent->right) {
							node = node->parent;
							leftRotate(node);
						}
						node->parent->color = BLACK_n;
						node->parent->parent->color = RED_n;
						rightRotate(node->parent->parent);
					}
				}
				if (node == this->_root) 
					break;
			}	
			this->_root->color = BLACK_n;
		}


		void	fixRBTPropertiesAfterDelete(Node *node) 
		{
			Node	*tmp;

			while(node != this->_root && node->color == BLACK_n) {
				if (node == node->parent->left) {
					tmp = node->parent->right;
					if (tmp->color == RED_n) {
						tmp->color = BLACK_n;
						node->parent->color = RED_n;
						leftRotate(node->parent);
						tmp = node->parent->right;
					}
					if (tmp->left->color == BLACK_n && tmp->right->color == BLACK_n) {
						tmp->color = RED_n;
						node = node->parent;
					}
					else {
						if (tmp->right->color == BLACK_n) {
							tmp->left->color = BLACK_n;
							tmp->color = RED_n;
							rightRotate(tmp);
							tmp = node->parent->right;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK_n;
						tmp->right->color = BLACK_n;
						leftRotate(node->parent);
						node = this->_root;
					}
				}
				else {
					tmp = node->parent->left;
					if (tmp->color == RED_n) {
						tmp->color = BLACK_n;
						node->parent->color = RED_n;
						rightRotate(node->parent);
						tmp = node->parent->left;
					}
					if (tmp->right->color == BLACK_n) {
						tmp->color = RED_n;
						node = node->parent;
					}
					else {
						if (tmp->left->color == BLACK_n) {
							tmp->right->color = BLACK_n;
							tmp->color = RED_n;
							rightRotate(node->parent);
							tmp = node->parent->left;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK_n;
						tmp->left->color = BLACK_n;
						rightRotate(node->parent);
						node = this->_root;
					}
				}
			}
			node->color = BLACK_n;	
		}

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
				this->_root = tmp;
			else if (node == node->parent->right)
				node->parent->right = tmp;
			else
				node->parent->left = tmp;
			tmp->right = node;
			node->parent = tmp;
		}

		/* ------------------------------------------------------------- */
		/* ---------------------------- FIND --------------------------- */	
		/* ------------------------------------------------------------- */

		/**
		 * @todo
		 * REMPLACER PAR ITERATOR et return this->end() si tmp == NULL
		 */

		Node	*find_node(key_type key) const
		{
			Node	*tmp = this->_root;
			if (tmp != NULL) {
				return (find_nodeHelper(tmp, key));
			}
			return (tmp);
		}

		/**
		 * @brief find a node compare to the key_value
		 * 
		 * @param node at the begginning, this node is root
		 * @param key the key_value to compare to the other node
		 * @return Node* Return the node who is not responding to the key_compare comparaison
		 */
		Node	*find_nodeHelper(Node *node, key_type key) const
		{
			if (node == NULL || isLeaf(node))
				return (NULL);
			if (!key_compare()(node->pair.first, key) && !key_compare()(key, node->pair.first))
				return (node);
			if (key_compare()(key, node->pair.first))
				return (find_nodeHelper(node->left, key));
			return (find_nodeHelper(node->right, key));
		}

		Node	*find_node(value_type pair) const
		{
			Node	*tmp = this->_root;
			
			if (tmp != NULL)
				return (find_nodeHelper(tmp, pair));
			return (tmp);
		}

		Node	*find_nodeHelper(Node *node, value_type pair) const 
		{
			if (node == NULL || isLeaf(node))
				return (NULL);
			if (!key_compare()(node->pair.first, pair.first) && !key_compare()(pair.first, node->pair.first))
				return (node);
			if (key_compare()(pair.first, node->pair.first))
				return (find_nodeHelper(node->left, pair));
			return (find_nodeHelper(node->right, pair));
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