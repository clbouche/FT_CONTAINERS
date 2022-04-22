/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:35:58 by claclou           #+#    #+#             */
/*   Updated: 2022/04/22 14:34:30 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include <string>
#include "RBTree_node.hpp" 

# define BLACK_node	0
# define RED_node	1


namespace	ft {
	
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
	* insert:		add node ✅
	* 
    * ------------------------------------------------------------- *
    */
	template < class T, class Compare = std::less <T>, class Alloc = std::allocator<T> > 
	class RBT {
		
	public:
	
	/* ------------------------------------------------------------- */
	/* --------------------------- ALIAS --------------------------- */	
	/* ------------------------------------------------------------- */

		typedef				ft::RBT_node<T>			Node;

		typedef				T						value_type;

		typedef	typename	T::first_type			key_type;

		typedef	typename	T::second_type			mapped_type;

		typedef 			Alloc 					allocator_type;

		typedef typename	allocator_type::template
							rebind<Node>::other		node_allocator;

        // typedef 	Compare					key_compare;


	private:

	/* ------------------------------------------------------------- */
	/* ------------------------- VARIABLES ------------------------- */	
	/* ------------------------------------------------------------- */
	
		Node					*_root;
		Node					*_empty;
		// Node					*_nil_node; 
        // allocator_type          _allocValue;
        node_allocator		    _node_alloc;
        size_t              	_size;
		Compare             	_comp; 
		
	public: 
	
	/* ------------------------------------------------------------- */
	/* ----------------------- CONSTRUCTORS ------------------------ */	
	/* ------------------------------------------------------------- */

	RBT(const node_allocator& node_alloc = node_allocator() ) : _node_alloc(node_alloc) {
		Node	tmp;
		
		std::cout << "Hello RBTree" << std::endl;
		_empty = _node_alloc.allocate(1);
		_node_alloc.construct(_empty, tmp);
		this->_root = NULL;
		this->_size = 0;
	}
	
	~RBT() {
		// _allocNode.deallocate(_nil_node, 1);
	}

	/* ------------------------------------------------------------- */
	/* -------------------------- INSERT --------------------------- */	
	/* ------------------------------------------------------------- */

	void	insert(const value_type value ) {
		// Node	*new_node = new Node(value, NULL, NULL, NULL); 
		_root = findPositionToInsert(_root, value);
		_size++;

	}

	Node *findPositionToInsert(Node *node, value_type value)
	{
		if (node == NULL){
			_size++;
			//Node	*newNode = new Node(value, parent);
			return (insert(node, value));
		}

		if (_comp(value, node->pair))
			node->left = findPositionToInsert(node->left, value);
		else if (_comp(node->pair, value))
			node->right = findPositionToInsert(node->right, value);
		return (insert(node, value));
		// fixRBTPropertiesAfterInsert();
	}

	Node	*insert ( Node *position, value_type to_insert )
	{
		Node	new_one(to_insert, NULL, NULL, NULL);
		//Node	*x = this->_root;
		Node	*insert_pos = NULL;

		new_one.parent = position;
		new_one.color = (new_one.parent == NULL) ? BLACK_node : RED_node;
		if (position == NULL)
		{
			this->_root = _node_alloc.allocate(1);
			insert_pos = this->_root;
		}
		else if (_comp(new_one.pair, position->pair))
		{
			// std::cout << "Deallocate node (" << y->left << ") for data : " << y->left->data.first << "/" << y->left->data.second << std::endl;
			this->_node_alloc.destroy(position->left);
			this->_node_alloc.deallocate(position->left, 1);
			position->left = _node_alloc.allocate(1);
			insert_pos = position->left;
		}
		else
		{
			// std::cout << "Deallocate node (" << y->right << ") for data : " << y->right->data.first << "/" << y->right->data.second << std::endl;
			this->_node_alloc.destroy(position->right);
			this->_node_alloc.deallocate(position->right, 1);
			position->right = _node_alloc.allocate(1);
			insert_pos = position->right;
		}
		construct_node(insert_pos, new_one);
		this->_size++;
		//setHeader();
		if (insert_pos->parent == NULL)
		{
			insert_pos->color = BLACK_node;
			return (insert_pos);
		}
		if (insert_pos->parent->parent == NULL)
		{
			return (insert_pos);
		}
		//insert_fix(insert_pos);
		return (insert_pos);
	}

	void		construct_node ( Node *pos, Node node )
	{
		Node	*leaf_r_addr;
		Node	leaf_r(pos);
		Node	*leaf_l_addr;
		Node	leaf_l(pos);


		// Right leaf node
		leaf_r_addr = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(leaf_r_addr, leaf_r);
		node.right = leaf_r_addr;
		// node.right = NULL;
		// Left leaf node
		leaf_l_addr = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(leaf_l_addr, leaf_l);
		node.left = leaf_l_addr;
		// node.left = NULL;
		// leaf_r.parent = pos;
		this->_node_alloc.construct(pos, node);
	}

	/* ------------------------------------------------------------- */
	/* -------------------------- DELETE --------------------------- */	
	/* ------------------------------------------------------------- */

    void	erase(value_type value) {
		Node	*tmp_node = _root;
		tmp_node = findNodeToDelete(_root, value); 
		erase(tmp_node);
	}

	Node *findNodeToDelete(Node *node, value_type value)
	{
		if (!node) {
			std::cout << "Empty tree" << std::endl;
			return node;
		}
		if (_comp(value, node->pair))
			node->left = findNodeToDelete(node->left, value);
		else if (_comp(node->pair, value))
			node->right = findNodeToDelete(node->right, value);
		std::cout << std::endl << "FIND NODE: " << node->pair.first << std::endl;
		return node;
	}

	void	erase(Node	*to_delete)
	{
		Node	*tmp;
		Node	*new_root;
		int		original_color;

		tmp = to_delete;
		original_color = tmp->color;
		if (to_delete->left == NULL)
		{
			new_root = to_delete->right;
			rbTransplant(to_delete, to_delete->right);
		}
		else if (isLeaf(to_delete->right))
		{
			new_root = to_delete->left;
			rbTransplant(to_delete, to_delete->left);
		}
		else
		{
			tmp = minimum(to_delete->right);
			original_color = tmp->color;
			new_root = tmp->right;
			if (tmp->parent == to_delete)
			{
				new_root->parent = tmp;
			}
			else
			{
				rbTransplant(tmp, tmp->right);
				tmp->right = to_delete->right;
				tmp->right->parent = tmp;
			}
			rbTransplant(to_delete, tmp);
			if (isLeaf(tmp->left))
			{
				this->_node_alloc.destroy(tmp->left);
				this->_node_alloc.deallocate(tmp->left, 1);
			}
			tmp->left = to_delete->left;
			tmp->left->parent = tmp;
			tmp->color = to_delete->color;
		}
		if (isLeaf(to_delete->left) && isLeaf(to_delete->right))
		{
			this->_node_alloc.destroy(to_delete->left);
			this->_node_alloc.deallocate(to_delete->left, 1);
		}
		this->_node_alloc.destroy(to_delete);
		this->_node_alloc.deallocate(to_delete, 1);
		this->_size--;
		// if (original_color == BLACK)
		// {
		// 	delete_fix(new_root);
		// }
	}

	void	rbTransplant ( Node *x, Node *y )
	{
		if (x->parent == NULL)
		{
			this->_root = y;
		}
		else if (x == x->parent->left)
		{
			if (isLeaf(x->parent->left))
			{
				// std::cout << "Deallocate node (" << x->parent->left << ") for data : " << x->parent->left->data.first << "/" << x->parent->left->data.second << std::endl;
				this->_node_alloc.destroy(x->parent->left);
				this->_node_alloc.deallocate(x->parent->left, 1);
			}
			x->parent->left = y;
		}
		else
		{
			if (isLeaf(x->parent->right))
			{
				// std::cout << "Deallocate node (" << x->parent->right << ") for data : " << x->parent->right->data.first << "/" << x->parent->right->data.second << std::endl;
				this->_node_alloc.destroy(x->parent->right);
				this->_node_alloc.deallocate(x->parent->right, 1);
			}
			x->parent->right = y;
		}
		y->parent = x->parent;
	}


	/* ------------------------------------------------------------- */
	/* -------------------------- FIX RBT -------------------------- */	
	/* ------------------------------------------------------------- */

	void	fixRBTPropertiesAfterInsert(){
			
		}
	
	/* ------------------------------------------------------------- */
	/* -------------------------- MIN MAX -------------------------- */	
	/* ------------------------------------------------------------- */

	Node	*maximum ( Node *node ) const
	{
		while (!isLeaf(node->right) && node->right != NULL)
		{
			node = node->right;
		}
		return (node);
	}

	Node	*minimum ( Node *node ) const
	{
		while (!isLeaf(node->left) && node->left != NULL)
		{
			node = node->left;
		}
		return (node);
	}
	
	/* ------------------------------------------------------------- */
	/* --------------------------- PRINT --------------------------- */	
	/* ------------------------------------------------------------- */
	
	bool			isLeaf( Node *node ) const
	{
		if (node->pair == T() && node->left == NULL && node->right == NULL)
			return (true);
		return (false);
	}

	void    printTreeHelper ( Node *node, std::string indent, bool side ) const
	{
		if (node != NULL && !isLeaf(node))
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
			std::cout << "(" << node->pair << ") (" << sColor << ")" << std::endl;
			printTreeHelper(node->left, indent, false);
			printTreeHelper(node->right, indent, true);
		}
	}

	void    printTree ( void ) const
	{
		if (this->_root != NULL)
		{
			printTreeHelper(this->_root, "", true);
		}
	}

	};
}

#endif 