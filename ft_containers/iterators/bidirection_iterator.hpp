
#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "CustomTree.hpp"
#include "reverse_iterator.hpp"


#define ADD 1
#define SUBSTRACT -1

namespace ft
{
	template < class Value_type, class Key, class Compare, class Alloc, bool Const = false>
	class bidirectional_iterator
	{
		public:
			typedef typename Alloc::difference_type		difference_type;
			typedef Value_type							value_type;

		private:
			typedef ft::CustomTree<value_type, Key, Compare>									tree_type;
			typedef typename tree_type::Node													N;
		public:
			typedef ft::bidirectional_iterator_tag		iterator_category;
			typedef typename FalseXTrueY<Const, value_type&, const value_type&>::type								reference;
			typedef typename FalseXTrueY<Const, value_type*, const value_type*>::type								pointer;
			/* *******************CONSTRUCTORS & DESTRUCTORS******************* */
		public:
			/* --------------------default constructor-------------------- */
			bidirectional_iterator(N* node = NULL) : _node(node) {}

			/* --------------------copy constructor-------------------- */
			bidirectional_iterator(const bidirectional_iterator< value_type, Key, Compare, Alloc, false> & copy)
			{
				_node = copy.getElemPtr();
			}

			bidirectional_iterator(const bidirectional_iterator< ft::enable_if< Const, value_type >, Key, Compare, Alloc, true> & copy)
			{
				_node = copy.getElemPtr();
			}

			/* --------------------destructor-------------------- */
			~bidirectional_iterator() {}

			bidirectional_iterator& operator=(const bidirectional_iterator& assign)
			{
				if (this != &assign)
					_node = assign._node;
				return (*this);
			}

			/* *******************GETTER******************* */
		public:
			N* getElemPtr() const			{ return _node; }

			/* *******************OPPERATOR OVERLOAD******************* */
		public:
			reference operator*() const
			{
				return (_node->_val);
			}

			pointer operator->() const
			{
				return &_node->_val;
			}

			bidirectional_iterator& operator++()
			{
				_node = _next(_node);
				return (*this);
			}

			bidirectional_iterator& operator--()
			{
				_node = _previous(_node);
				return (*this);
			}

			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator res(*this);
				++(*this);
				return (res);
			}

			bidirectional_iterator operator--(int)
			{
				bidirectional_iterator res(*this);
				--(*this);
				return (res);
			}

			bool operator==(const bidirectional_iterator& it) const
			{
				return (it._node == _node);
			}

			bool operator!=(const bidirectional_iterator& it) const
			{
				return (it._node != _node);
			}

			/* *******************USEFUL FUNCTIONS******************* */
		protected:
			N* _next(N *node) const
			{
				if (node->right)
					return (_minKeyNode(node->right));
				else
					while (node->parent)
					{
						if (node->parent->left == node)
							return (node->parent);
						node = node->parent;
					}
				return (NULL); // TO CHANGE
			}

			N* _previous(N *node) const
			{
				if (node->left)
					return (_maxKeyNode(node->left));
				else
					while (node->parent)
					{
						if (node->parent->right == node)
							return (node->parent);
						node = node->parent;
					}
				return (NULL); // TO CHANGE
			}

			N* _minKeyNode(N* node) const
			{
				N* current = node;
				while (current->left != NULL)
					current = current->left;
				return current;
			}

			N* _maxKeyNode(N* node) const
			{
				N* current = node;
				while (current->right != NULL)
					current = current->right;
				return current;
			}

			/* *******************VARIABLES******************* */
		protected:
			N* _node;
	};
}
#endif
