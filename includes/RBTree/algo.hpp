/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:51:42 by claclou           #+#    #+#             */
/*   Updated: 2022/05/09 13:28:15 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_HPP
# define ALGO_HPP

#include "RBT_node.hpp"
#include "../iterators/RBT_iterator.hpp"
#include "../utils/utils_pair.hpp"
#include "../utils/utils_relational_operators.hpp"

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
	* Copy constructor ✅ 
	* Assign constructor ✅
	* Destructor ✅
	* 
	* - Members functions:
	* max:					Return the higher value of the tree ✅
	* min:					Return the smallest value of the tree ✅
	* insert:				Insert a new node in the tree ✅ 
	* delete_node:			Delete a node with key, value or position ✅
	* delete_tree:			Delete the entire tree ✅
	* fixInsert: 			Change the organisation of the tree to follow the rules of the RBT ✅
	* fixDelete:			Idem ✅
	* Rotation:
	*	rightRotate ✅
	*	leftRotate 	✅
	* clear:				delete and clear the tree ✅
	* findNode:				search and find a node in the tree with pair or key ✅
	* swap: 				
	*
	* - Friends functions:
	* 	operator== ✅
	* 	operator<  ✅
	* 
	* - Non members functions:
	* relational operators: Relational operators for RBT
	* 	operator== ✅
	* 	operator!= ✅
	* 	operator<  ✅
	*	operator>  ✅
	*	operator<= ✅
	* 	operator>= ✅
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
		typedef				ft::RBT_iterator<T>			iterator;


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
		 * 
		 */
		RBTree (const RBTree& copy) 
		{
			Node		tmp;
			iterator	it;
			
			this->_empty = _node_alloc.allocate(1);
			_node_alloc.construct(this->_empty, tmp);
			this->_leaf_left = _node_alloc.allocate(1);
			_node_alloc.construct(this->_leaf_left, tmp);
			this->_leaf_right = _node_alloc.allocate(1);
			_node_alloc.construct(this->_leaf_right, tmp);
			this->_root = NULL;	
			this->_size = 0;
			
			it = copy.begin();
			while(it != copy.end())	
			{
				insert(*it);
				it++;
			}
		}

		/**
		 * @brief Destructor. 
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

		void		swap ( RBTree &x )
		{
			x.unsetLeafs();
			this->unsetLeafs();
			std::swap(this->_root, x._root);
			std::swap(this->_leaf_left, x._leaf_left);
			std::swap(this->_leaf_right, x._leaf_right);
			std::swap(this->_empty, x._empty);
			std::swap(this->_size, x._size);
			if (this->_root)
				this->setLeafs();
			if (x._root)
				x.setLeafs();
			std::swap(this->_node_alloc, x._node_alloc);
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
		/* --------------------------- LEAFS --------------------------- */	
		/* ------------------------------------------------------------- */

		void	setLeafs( void )
		{
			Node	*most_right = this->maximum(this->_root);
			Node	*most_left = this->minimum(this->_root);

			this->_leaf_right->parent = most_right;
			this->_leaf_right->parent->right = this->_leaf_right;
			this->_leaf_left->parent = most_left;
			this->_leaf_left->parent->left = this->_leaf_left;
			this->_empty->parent = 0;
		}

		void	unsetLeafs( void )
		{
			if (this->_leaf_right->parent)
				this->_leaf_right->parent->right = this->_empty;
			if (this->_leaf_left->parent)
				this->_leaf_left->parent->left = this->_empty;
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
		
		iterator	insert ( value_type to_insert )
		{
			Node	new_node(to_insert, NULL, this->_empty, this->_empty);
			Node	*insert_pos = NULL;

			this->unsetLeafs();
			Node *position = FindPositionToInsert(&new_node);
			new_node.parent = position;
			new_node.color = (new_node.parent == NULL) ? BLACK_n : RED_n;
			if (position == NULL)
			{
				this->_root = _node_alloc.allocate(1);
				insert_pos = this->_root;
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
				this->setLeafs();
				insert_pos->color = BLACK_n;
				return (iterator(insert_pos));
			}
			if (insert_pos->parent->parent == NULL)
			{
				this->setLeafs();
				return (iterator(insert_pos));
			}
			fixRBTPropertiesAfterInsert(insert_pos);
			this->setLeafs();
			return (iterator(insert_pos));
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
			
			this->unsetLeafs();
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
			if (!isLeaf(this->_root))
				this->setLeafs();
			else
				this->_root = NULL;
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
				if (node == node->parent->left) 
				{
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
			if (tmp->left != NULL && tmp->left != this->_empty)
				tmp->left->parent = node;
			tmp->parent = node->parent;
			if (node->parent == NULL || node->parent == this->_empty) 
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
			if (tmp->right != NULL && tmp->right != this->_empty)
				tmp->right->parent = node;
			tmp->parent = node->parent;
			if (node->parent == NULL || node->parent == this->_empty)
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

		iterator	find_node(key_type key) const
		{
			if (this->_root != NULL) {
				return (find_nodeHelper(this->_root, key));
			}
			return (this->end());
		}

		/**
		 * @brief find a node compare to the key_value
		 * 
		 * @param node at the begginning, this node is root
		 * @param key the key_value to compare to the other node
		 * @return Node* Return the node who is not responding to the key_compare comparaison
		 */
		iterator	find_nodeHelper(Node *node, key_type key) const
		{
			if (node == NULL || isLeaf(node))
				return (this->end());
			if (!key_compare()(node->pair.first, key) && !key_compare()(key, node->pair.first))
				return (iterator(node));
			if (key_compare()(key, node->pair.first))
				return (find_nodeHelper(node->left, key));
			return (find_nodeHelper(node->right, key));
		}

		iterator	find_node(value_type pair) const
		{			
			if (this->_root != NULL)
				return (find_nodeHelper(this->_root, pair));
			return (this->end());
		}

		iterator	find_nodeHelper(Node *node, value_type pair) const 
		{
			if (node == NULL || isLeaf(node))
				return (this->end());
			if (!key_compare()(node->pair.first, pair.first) && !key_compare()(pair.first, node->pair.first))
				return (iterator(node));
			if (key_compare()(pair.first, node->pair.first))
				return (find_nodeHelper(node->left, pair));
			return (find_nodeHelper(node->right, pair));
		}

		/* ------------------------------------------------------------- */
		/* ------------------------- ITERATORS ------------------------- */	
		/* ------------------------------------------------------------- */

		iterator		end ( void ) const
		{
			return (iterator(this->_leaf_right));
		}

		iterator		begin ( void ) const
		{
			if (this->_root == NULL)
				return (this->end());
			return (iterator(this->_leaf_left->parent));
		}

		/* ------------------------------------------------------------- */
		/* --------------------------- GETTER -------------------------- */	
		/* ------------------------------------------------------------- */

		size_t		size( void ) const 
		{
			return (this->_size);
		}

		size_t			max_size ( void ) const
		{
			return (node_allocator().max_size());
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
				if (node != this->_empty)
				{
					std::cout << indent;
					if (node == this->_leaf_left)
					{
						std::cout << "L----";
						std::cout << "Left leaf" << std::endl;
					}
					else if (node == this->_leaf_right)
					{
						std::cout << "R----";
						std::cout << "r_leaf_right leaf" << std::endl;
					}
					else
					{
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
			}
		
		/* ------------------------------------------------------------- */
		/* ------------------------- OPERATORS ------------------------- */	
		/* ------------------------------------------------------------- */
		
		template <class T1, class T2, class T3, class T4>
		friend inline bool	operator== (	const RBTree<T1, T2, T3, T4> &x,
											const RBTree<T1, T2, T3, T4> &y );

		template <class T1, class T2, class T3, class T4>
		friend inline bool	operator< (	const RBTree<T1, T2, T3, T4> &x,
										const RBTree<T1, T2, T3, T4> &y );

	};

	template< class K, class T, class Compare, class Alloc >
	inline bool	operator== ( const RBTree<K, T, Compare, Alloc> &x,
								const RBTree<K, T, Compare, Alloc> &y )
	{ return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin())); }

	template< class K, class T, class Compare, class Alloc > 
	inline bool operator!= (const RBTree<K, T, Compare, Alloc> &x, 
								const RBTree<K, T, Compare, Alloc> &y)
	{ return (!(x == y)); }

	template< class K, class T, class Compare, class Alloc >
	inline bool	operator< (const RBTree<K, T, Compare, Alloc> &x, 
							const RBTree<K, T, Compare, Alloc> &y)
	{ return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end())); }

	template< class K, class T, class Compare, class Alloc >
	inline bool	operator> (const RBTree<K, T, Compare, Alloc> &x, 
							const RBTree<K, T, Compare, Alloc> &y)
	{ return (y < x ); }

	template< class K, class T, class Compare, class Alloc >
	inline bool	operator<= (const RBTree<K, T, Compare, Alloc> &x, 
							const RBTree<K, T, Compare, Alloc> &y)
	{ return (!(y < x)); }

	template< class K, class T, class Compare, class Alloc >
	inline bool	operator>= (const RBTree<K, T, Compare, Alloc> &x, 
							const RBTree<K, T, Compare, Alloc> &y)
	{ return (!(x < y)); }
}



#endif