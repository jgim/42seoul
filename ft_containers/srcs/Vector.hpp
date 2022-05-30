/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:55:05 by jgim              #+#    #+#             */
/*   Updated: 2022/05/30 17:17:08 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "RandomAccessIterator.hpp"
# include "ReverseIterator.hpp"
# include "IteratorTraits.hpp"
# include "Utils.hpp"
# include <memory>
# include <cstddef>
# include <stdexcept>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;

			typedef RandomAccessIterator<T, T*, T&>					iterator;
			typedef RandomAccessIterator<T, const T*, const T&>		const_iterator;
			typedef ReverseIterator<iterator>						reverse_iterator;
			typedef ReverseIterator<const_iterator>					const_reverse_iterator;

			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		private:
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			pointer			_array;

/**
*	-----------------------------------------------------------------------------	*
*									canonical form									*
*	-----------------------------------------------------------------------------	*
**/

		public:
			explicit vector(const allocator_type &alloc = allocator_type()) :
				_alloc(alloc), _size(0), _capacity(0), _array(0) {}

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _array(0)
			{
				if (n > max_size())
					throw std::length_error("< Error: the capacity is full >");
				this->_array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_array + i, val);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0,
				const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0), _array(0)
			{
				size_type range = static_cast<size_type>(ft::distance(first, last));
				this->_size = range;
				this->_capacity = range;
				this->_array = _alloc.allocate(range);
				for (int i = 0; first != last; ++first, ++i)
					_alloc.construct(_array + i, *first);
			}

			vector(const vector &x) : _size(0), _capacity(0), _array(0)
			{ *this = x; }

			~vector()
			{
				clear();
				this->_alloc.deallocate(this->_array, this->_capacity);
			}

/**
*	-----------------------------------------------------------------------------	*
*									member function									*
*	-----------------------------------------------------------------------------	*
**/

			vector	&operator=(const vector &vec)
			{
				assign(vec.begin(), vec.end());
				return *this;
			}

/**
*	-----------------------------------------------------------------------------	*
*										iterators									*
*	-----------------------------------------------------------------------------	*
**/


			iterator begin()
			{ return (iterator(this->_array)); }
			const_iterator begin() const
			{ return (const_iterator(this->_array)); }

			iterator end()
			{ return (iterator(&this->_array[this->_size])); }
			const_iterator end() const
			{ return (const_iterator(&this->_array[this->_size])); }

			reverse_iterator rbegin()
			{ return (reverse_iterator(&this->_array[this->_size - 1])); }
			const_reverse_iterator rbegin() const
			{ return (const_reverse_iterator(&this->_array[this->_size - 1])); }

			reverse_iterator rend()
			{ return (reverse_iterator(_array - 1)); }
			const_reverse_iterator rend() const
			{ return (const_reverse_iterator(_array - 1)); }

/**
*	-----------------------------------------------------------------------------	*
*									capacity										*
*	-----------------------------------------------------------------------------	*
**/

			size_type size() const
			{ return (this->_size); }

			size_type max_size() const
			{ return (this->_alloc.max_size()); }

			void resize(size_type n, value_type val= value_type())
			{
				reserve(n);
				while (this->_size > n)
					pop_back();
				while (this->_size < n)
					push_back(val);
			}

			size_type capacity() const
			{ return (this->_capacity); }

			bool empty() const
			{ return (this->_size == 0); }

			void reserve(size_type new_capacity)
			{
				if (new_capacity > max_size())
					throw std::length_error("< Error :  the capacity is full >");
				if (new_capacity <= this->_capacity)
					return;
				else if (new_capacity > this->_capacity * 2)
					reallocate(new_capacity);
				else
					reallocate(this->_capacity * 2);
			}

			void reallocate (size_type new_capacity)
			{
				if (new_capacity <= capacity())
					return;
				if (new_capacity > max_size())
					throw std::length_error("< Error :  the capacity is full >");
				pointer tmp = _alloc.allocate(new_capacity);
				for (size_type i = 0; i < _size; ++i)
				{
					this->_alloc.construct(tmp + i, _array[i]);
					this->_alloc.destroy(&_array[i]);
				}
				_alloc.deallocate(_array, _capacity);
				this->_array = tmp;
				this->_capacity = new_capacity;
			}

/**
*	-----------------------------------------------------------------------------	*
*									Element access									*
*	-----------------------------------------------------------------------------	*
**/

			reference operator[](size_type n)
			{ return (this->_array[n]); }
			const_reference	operator[](size_type n) const
			{ return (this->_array[n]); }

			reference at(size_type n)
			{
				if (n >= this->_size)
					throw (std::out_of_range("< Error : out of range >"));
				return (this->_array[n]);
			}
			const_reference at(size_type n) const
			{
				if (n >= this->_size)
					throw (std::out_of_range("< Error : out of range >"));
				return (this->_array[n]);
			}

			reference front()
			{ return (this->_array[0]); }
			const_reference	front() const
			{ return (this->_array[0]); }

			reference back()
			{ return (this->_array[this->_size - 1]); }
			const_reference	back() const
			{ return (this->_array[this->_size - 1]); }

/**
*	-----------------------------------------------------------------------------	*
*									Modifiers										*
*	-----------------------------------------------------------------------------	*
**/

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
						typename ft::iterator_traits<InputIterator>::iterator_category* = 0)
			{
				clear();
				reserve(ft::distance(first, last));
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void assign(size_type n, const value_type &val)
			{
				clear();
				reserve(n);
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			void push_back(const value_type &val)
			{
				if (size() == capacity())
				{
					if (size() == 0)
						reserve(1);
					else
						reserve(this->_size + 1);
				}
				this->_alloc.construct(_array + size(), val);
				this->_size++;
			}

			void pop_back()
			{
				this->_size--;
				this->_alloc.destroy(&this->_array[this->_size]);
			}

			iterator insert(iterator position, const value_type& val)
			{
				size_type idx = static_cast<size_type>(ft::distance(_array, position));
				insert(position, 1, val);
				return iterator(_array + idx);
			}


			void insert(iterator position, size_type n, const value_type& val)
			{
				if (size() + n < max_size())
					throw std::length_error("< Error :  the capacity is full >");
				size_type idx = static_cast<size_type>(ft::distance(begin(), position));
				if (size() + n > capacity())
					reserve(size() + n);
				if (empty())
					assign(n, val);
				else
				{
					for (size_type i = _size + n; i > (idx + n); --i)
						_alloc.construct(_array + i, _array[i - n]);
					for (size_type i = 0; i < n; ++i)
						_alloc.construct(_array + idx++, val);
					_size += n;
				}
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
										typename ft::iterator_traits<InputIterator>::iterator_category* = 0)
			{
				vector tmp(position, end());
				size_type erase_idx = static_cast<size_type>(ft::distance(position, end()));
				this->_size -= erase_idx;
				while (first != last)
				{
					push_back(*first);
					++first;
				}
				iterator it = tmp.begin();
				while (it != tmp.end())
				{
					push_back(*it);
					++it;
				}
			}

			iterator erase(iterator pos)
			{ return (erase(pos, pos + 1)); }

			iterator erase(iterator first, iterator last)
			{
				if (first == last)
					return last;
				size_type erase_idx = \
					static_cast<size_type>(ft::distance(begin(), first));
				size_type rest_idx =
					static_cast<size_type>(ft::distance(begin(), last));
				size_type n = rest_idx - erase_idx;
				for (size_type i = erase_idx; rest_idx < size(); i++)
					_alloc.construct(_array + i, _array[rest_idx++]);
				for (size_type i = size() - n; i < size(); i++)
					_alloc.destroy(_array + i);
				_size -= n;
				return iterator(_array + erase_idx);
			}

			void swap(vector &x)
			{
				size_type		tmpSize = this->_size;
				size_type		tmpCapacity = this->_capacity;
				pointer			tmpData = this->_array;

				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_array = x._array;
				x._size = tmpSize;
				x._capacity = tmpCapacity;
				x._array = tmpData;
			}

			void clear()
			{
				while (this->_size)
					pop_back();
			}

/**
*	-----------------------------------------------------------------------------	*
*										Allocator									*
*	-----------------------------------------------------------------------------	*
**/

			allocator_type	get_allocator() const
			{ return (this->_alloc); }

	};

/**
*	-----------------------------------------------------------------------------	*
*								Non-member function overloads						*
*	-----------------------------------------------------------------------------	*
**/

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(rhs < lhs); }

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(lhs < rhs); }

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{ x.swap(y); }
};

#endif
