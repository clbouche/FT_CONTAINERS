/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:04:20 by clbouche          #+#    #+#             */
/*   Updated: 2022/05/10 13:16:58 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <memory>
#include "utils/utils_pair.hpp"
#include "RBTree/algo.hpp"
#include "RBTree/RBT_node.hpp"
#include "iterators/RBT_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include "iterators/iterator_traits.hpp"
#include "utils/utils_iterator.hpp"

namespace	ft {
	/** ✅
    * ------------------------ FT::MAP ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct map 
	* 		- empty constructor ✅
	*		- range constructor ✅
	*		- copy              ✅
    * destructor:         	Destruct map ✅
    * operator=:            Assign map ✅
    *
    * - Iterators:
    * begin:                Return iterator to beginning ✅
    * end:                  Return iterator to end ✅
    * rbegin:               Return reverse iterator to reverse beginning ✅
    * rend:                 Return reverse iterator to reverse end ✅
    *
    * - Capacity:
    * empty:                Test whether map is empty ✅
    * size:                 Return size ✅
    * max_size:             Return maximum size ✅
    *
    * - Element access:
    * operator[]:           Access element ✅
    *
    * - Modifiers:
    * insert:               Insert elements ✅
    * erase:                Erase elements ✅
    * swap:                 Swap content ✅
    * clear:                Clear content ✅
	* 
	* - Observers:
	* key_comp:				Return key comparaison object ✅
	* value_comp:			Return value comparaison object ✅
    *
	* Operators:
	* find:					Get iterator to element ✅
	* count:				Count elements with a specific key ✅
	* lower_bound:			Return iterator to lower bound ✅
	* upper_bound:			Return oterator to upper bound ✅
	* equal_range:			Get range of equal elements ✅
	* 
    * ------------------------------------------------------------- *
    */

   template < class Key,                                     		// map::key_type
           	class T,                                       			// map::mapped_type
           	class Compare = std::less< Key >,                     	// map::key_compare
          	class Alloc = std::allocator< ft::pair< const Key,T > >	// map::allocator_type
           > 
	class map
	{
		public:
        /* ------------------------------------------------------------- */
		/* --------------------------- ALIAS --------------------------- */	
		/* ------------------------------------------------------------- */

        typedef				Key             									key_type;
        typedef				T													mapped_type;
		typedef				ft::pair<const key_type, mapped_type>				value_type;
		typedef				Compare												key_compare;
		typedef 			Alloc 												allocator_type;
		typedef	typename	allocator_type::reference							reference;
		typedef	typename 	allocator_type::const_reference						const_reference;
		typedef	typename 	allocator_type::pointer								pointer;
		typedef	typename	allocator_type::const_pointer						const_pointer;
		typedef				ft::RBT_iterator<value_type>						iterator;
		typedef				ft::RBT_const_iterator<value_type>					const_iterator;
		typedef	typename	ft::reverse_iterator<iterator>						reverse_iterator;
		typedef	typename	ft::reverse_iterator<const_iterator> 				const_reverse_iterator;
		typedef	typename	ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef	typename	allocator_type::size_type							size_type;

		class value_compare : std::binary_function<value_type, value_type, bool>
		{
			friend class ft::map<key_type, mapped_type, key_compare, Alloc>;
			
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

		private:
		/* ------------------------------------------------------------- */
		/* -------------------------- MEMBERS -------------------------- */	
		/* ------------------------------------------------------------- */

		allocator_type												_alloc;
		Compare														_comp;
		ft::RBTree<const key_type, value_type, Compare, Alloc> 		_RBTree;

		
		public:
		/* ------------------------------------------------------------- */
		/* ---------------------- COPELIAN CLASS ----------------------- */	
		/* ------------------------------------------------------------- */

		explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_comp(comp),
			_RBTree()
		{ }

		template <class InputIterator>
  		map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_comp(comp),
			_RBTree()	
		{
			while(first != last) {
				this->insert(*first);
				first++;
			}
		}
	
		map (const map& x) :
			_alloc(x._alloc),
			_comp(x._comp),
			_RBTree(x._RBTree)
		{}


 		map& 	operator= (const map& x)
		{
			if (&x == this)
				return *this;
			this->clear();
			this->insert(x.begin(), x.end());
			return *this;
		}
		
		~map()
		{ }
	
		/* ------------------------------------------------------------- */
		/* ------------------------- ITERATORS ------------------------- */	
		/* ------------------------------------------------------------- */
	
		iterator		begin()
		{
			return(_RBTree.begin());
		}
		
		const_iterator	begin() const
		{
			return(_RBTree.begin());
		}
		
		iterator		end()
		{
			return (_RBTree.end());
		}
		
		const_iterator 	end() const
		{
			return (_RBTree.end());
		}
				
		reverse_iterator	rbegin()
		{
			return (reverse_iterator(this->end()));
		}
		
		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator	rend()
		{
			return (reverse_iterator(this->begin()));
		}
		
		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}

		/* ------------------------------------------------------------- */
		/* ------------------------- CAPACITY -------------------------- */	
		/* ------------------------------------------------------------- */

		bool	empty() const
		{
			return (this->_RBTree.size() == 0);
		}
		
		size_type	size() const
		{
			return (this->_RBTree.size());
		}

		size_type	max_size() const
		{
			return (this->_RBTree.max_size());
		}

		/* ------------------------------------------------------------- */
		/* ---------------------- ELEMENT ACCESS ----------------------- */
		/* ------------------------------------------------------------- */

		mapped_type&	operator[] (const key_type& k)
		{
			iterator		i = lower_bound(k);

			i = insert(i, value_type(k, mapped_type()));
			return((*i).second);
		}

		/* ------------------------------------------------------------- */
		/* ------------------------- MODIFIERS ------------------------- */	
		/* ------------------------------------------------------------- */
	
		pair<iterator,bool>		insert (const value_type& val)
		{
			iterator	tmp;

			tmp = this->_RBTree.find_node(val);
			if (tmp != this->end())
				return (ft::make_pair<iterator, bool>(tmp, false));
			else {
				tmp = this->_RBTree.insert(val);
				return (ft::make_pair<iterator, bool>(tmp, true));
			}
		}

		iterator 	insert (iterator position, const value_type& val)
		{
			iterator	tmp;

			(void)position;
			tmp = this->_RBTree.find_node(val);
			if (tmp == this->end())
				tmp = this->_RBTree.insert(val);
			return tmp;
		}
		
		template <class InputIterator>
  		void 	insert (InputIterator first, InputIterator last)												
		{
			while(first != last)
				insert(*first++);
		}

		void 	erase (iterator position)
		{
			this->_RBTree.delete_node(*position);
		}

		size_type 	erase (const key_type& k)
		{
			iterator	tmp = this->_RBTree.find_node(k);
			if (tmp == this->end())
				return (0);
			erase(tmp);
			return (1);
		}

		void 	erase (iterator first, iterator last)
		{
			while(first != last)
				this->_RBTree.delete_node(*first++);	
		}
		
		void 	swap (map& x)
		{
			this->_RBTree.swap(x._RBTree);
		}

		void	clear()
		{
			this->_RBTree.clear();
		}

		/* ------------------------------------------------------------- */
		/* ------------------------- OBSERVERS ------------------------- */	
		/* ------------------------------------------------------------- */

		key_compare 	key_comp() const
		{
			return (key_compare());
		}

		value_compare		value_comp() const
		{
			return (value_compare(key_comp()));
		}

		/* ------------------------------------------------------------- */
		/* ------------------------- OPERATIONS ------------------------ */	
		/* ------------------------------------------------------------- */

    	iterator 	find (const key_type& k)
		{
			return (this->_RBTree.find_node(k));
		}
		
		const_iterator 		find (const key_type& k) const
		{
			return (this->_RBTree.find_node(k));
		}

		size_type 	count (const key_type& k) const
		{
			if (this->find(k) == this->end())
				return 0;
			return 1;
		}

    	iterator	 lower_bound (const key_type& k)
		{
			iterator	low = this->begin();

			while(low != this->end() && key_compare()(low->first, k))
				low++;
			return (low);
		}
		
		const_iterator 		lower_bound (const key_type& k) const
		{
			const_iterator	low = this->begin();

			while(low != this->end() && key_compare()(low->first, k))
				low++;
			return (low);
		}

		iterator 	upper_bound (const key_type& k)
		{
			iterator up = this->begin();

			while (up != this->end())
			{
				if (up->first != k && !key_compare()(up->first, k))
					return up;
				up++;
			}
			return up;
		}
		
		const_iterator 	upper_bound (const key_type& k) const
		{
			const_iterator up = this->begin();

			while (up != this->end())
			{
				if (up->first != k && !key_compare()(up->first, k))
					return up;
				up++;
			}
			return up;
		}

		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}
		
		pair<const_iterator,const_iterator> 	equal_range (const key_type& k) const
		{
			return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}
		
		
		/* ------------------------------------------------------------- */
		/* ------------------------- ALLOCATOR ------------------------- */	
		/* ------------------------------------------------------------- */

		allocator_type 	get_allocator() const
		{
			return (this->_alloc);
		}
		
		/* ------------------------------------------------------------- */
		/* ------------------ RELATIONAL OPERATORS --------------------- */
		/* ------------------------------------------------------------- */

		template<typename K1, typename T1, typename C1, typename A1>
		friend bool	operator==( const map<K1, T1, C1, A1>&,
								const map<K1, T1, C1, A1>&);
		
		template<typename K1, typename T1, typename C1, typename A1>
		friend bool	operator<( const map<K1, T1, C1, A1>&,
								const map<K1, T1, C1, A1>&);

	};

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool	operator== (	const map<Key, Tp, Compare, Alloc>& x,
								const map<Key, Tp, Compare, Alloc>& y )
	{
		return (x._RBTree == y._RBTree);
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator!=( const map<Key, Tp, Compare, Alloc>& x,
							const map<Key, Tp, Compare, Alloc>& y )
	{
		return (!(x == y));
	}
	
	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator<( const map<Key, Tp, Compare, Alloc>& x,
							const map<Key, Tp, Compare, Alloc>& y )
	{
		return (x._RBTree < y._RBTree);
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator>( const map<Key, Tp, Compare, Alloc>& x,
							const map<Key, Tp, Compare, Alloc>& y )
	{
		return (y < x);
	}
	
	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator<=( const map<Key, Tp, Compare, Alloc>& x,
							const map<Key, Tp, Compare, Alloc>& y )
	{
		return (!(y < x));
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator>=( const map<Key, Tp, Compare, Alloc>& x,
							const map<Key, Tp, Compare, Alloc>& y )
	{
		return (!(x < y));
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline void	swap( map<Key, Tp, Compare, Alloc>& x,
						map<Key, Tp, Compare, Alloc>& y )
	{
		x.swap(y);
	}

}

#endif