/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:35:58 by claclou           #+#    #+#             */
/*   Updated: 2022/04/21 17:58:54 by claclou          ###   ########.fr       */
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

		typedef		ft::RBT_node<T>			Node;

		typedef		T						value_type;

		typedef 	Alloc 					allocator_type;

        // typedef 	Compare					key_compare;


	private:

	/* ------------------------------------------------------------- */
	/* ------------------------- VARIABLES ------------------------- */	
	/* ------------------------------------------------------------- */
	
		Node					*_root;
		Node					*_nil_node; 
        allocator_type          _allocValue;
        std::allocator<Node>    _allocNode;
        size_t              	_size;
		Compare             	_comp; 
		
	public: 
	
	/* ------------------------------------------------------------- */
	/* ----------------------- CONSTRUCTORS ------------------------ */	
	/* ------------------------------------------------------------- */

	RBT() {
		std::cout << "Hello RBTree" << std::endl;
		// _nil_node = new Node();
		// this->_root = _nil_node;
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
		Node	*new_node = new Node(value, NULL, NULL, NULL); 
		_root = insert(_root, new_node);
		_size++;

	}

	Node *insert(Node *node, Node *new_node) {
		if (_root == NULL) {
			std::cout << "root est NULL" << std::endl;
			_root = new_node;
			new_node->color = BLACK_node;
			return (new_node);
		}
		if (_comp(new_node->pair, node->pair) == true)
			{
				node->left = new_node;
				new_node->parent = node;
			}
			if (_comp(new_node->pair, node->pair) == false)
			{
				node->right = new_node;
				new_node->parent = node;
			}
			// fixRBTPropertiesAfterInsert();
			return node;
	}
	

	/* ------------------------------------------------------------- */
	/* -------------------------- DELETE --------------------------- */	
	/* ------------------------------------------------------------- */

	void	erase(Node *node)
	{
		
	}

	void	erase(const value_type value)
	{
		if (_root == NULL) {
			std::cout << "Empty tree" << std::endl;
			return ;
		}
	}

	/* ------------------------------------------------------------- */
	/* -------------------------- FIX RBT -------------------------- */	
	/* ------------------------------------------------------------- */

	void	fixRBTPropertiesAfterInsert(){
			
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
			std::cout << "(" << node->pair << ") (" << sColor << ")" << std::endl;
			// printTreeHelper(node->left, indent, false);
			// printTreeHelper(node->right, indent, true);
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