#ifndef vECTOR_HPP
#define vECTOR_HPP

#include <iostream>
#include <memory>
#include "iterators/iterator_traits.hpp"
#include "iterators/random_access_iterator.hpp"
#include "algorithm/equal.hpp"
#include "algorithm/lexicographical_compare.hpp"
#include "utils/is_integral.hpp"
#include "utils/is_enable_if.hpp"
#include "iterators/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T														value_type;
		typedef Allocator												allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename allocator_type::size_type						size_type;
		typedef typename allocator_type::difference_type				difference_type;


		typedef ft::random_access_iterator<value_type>					iterator;
		typedef ft::random_access_iterator<const value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

	private:
		pointer			_array;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;

/**
*	--------------------------------------------------------	*
*						canonical form							*
*	--------------------------------------------------------	*
**/

	public:
		// vector default constructor
		explicit vector(const allocator_type& alloc = allocator_type())
				: _array(NULL),_size(0), _capacity(0), _alloc(alloc){}

		// vector constructor with size
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
						: _array(NULL), _size(n), _capacity(n), _alloc(alloc)
		{
			if (n > max_size())
				throw std::length_error("< Error: the capacity is full >");
			this->_array = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_array + i, val);
		}

		// vector constructor with range
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
			InputIterator>::type* = NULL)
			: _array(NULL), _size(0), _capacity(0), _alloc(alloc)
		{
			size_type range = static_cast<size_type>(std::distance(first, last));
			this->_size = range;
			this->_capacity = range;
			this->_array = _alloc.allocate(range);
			for (int i = 0; first != last; ++last, ++i)
				_alloc.construct(_array + i, *first);
		}

		// vector copy constructor
		vector(const vector& vec) : _array(0), _size(0), _capacity(0), _alloc(vec._alloc)
		{ *this = vec; }

		vector& operator=(const vector& vec)
		{
			clear();
			this->_array = _alloc.allocate(size());
			this->_size = vec.size();
			this->_alloc = vec.alloc();
			this->_capacity = vec.capacity();
			for (size_type i = 0; i < size(); i++)
				_alloc.construct(_array + i, vec._array[i]);
			return *this;
		}

		//vector destructor
		~vector()
		{
			clear();
			_alloc.deallocate(_array, _capacity);
		}

		// vector assignment operator
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					InputIterator>::type* = NULL)
		{
			clear();
			size_type n = static_cast<size_type>(last - first);
			if (n > capacity())
				reserve(n);
			for (size_type i = 0; first != last; ++first, ++i)
				_alloc.construct(_array + i, *first);
			_size = n;
		}

		void assign(size_type n, const value_type& value)
		{
			if (n > capacity())
				reserve(n);
			for (size_type i = 0; i < n; ++i)
				_alloc.construct(_array + i, value);
			_size = n;
		}

/**
*	--------------------------------------------------------	*
*						Access element							*
*	--------------------------------------------------------	*
**/
		reference at(size_type n)
		{
			if (n >= size())
				throw std::out_of_range("< Error : out of range >");
			return this->_array[n];
		}
		const_reference at(size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("< Error : out of range >");
			return this->_array[n];
		}

		reference operator[](size_type n)
		{ return this->_array[n]; }
		const_reference operator[](size_type n) const
		{ return this->_array[n]; }

		reference front()
		{ return this->_array[0]; }
		const_reference front() const
		{ return this->_array[0]; }

		reference back()
		{ return _array[this->_size - 1]; }
		const_reference back() const
		{ return _array[this->_size - 1]; }

/**
*	--------------------------------------------------------	*
*							iterator							*
*	--------------------------------------------------------	*
**/

		iterator begin()
		{ return iterator(_array); }
		const_iterator begin() const
		{ return const_iterator(_array); }

		iterator end()
		{ return iterator(_array + _size); }
		const_iterator end() const
		{ return const_iterator(_array + _size); }

		reverse_iterator rbegin()
		{ return reverse_iterator(_array + _size - 1); }
		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(_array + _size - 1); }

		reverse_iterator rend()
		{ return reverse_iterator(_array - 1); }
		const_reverse_iterator rend() const
		{ return const_reverse_iterator(_array - 1); }

/**
*	--------------------------------------------------------	*
*							space							*
*	--------------------------------------------------------	*
**/

		bool empty() const
		{ return size() == 0; }

		size_type max_size() const
		{ return this->_alloc.max_size(); }

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
				_alloc.construct(tmp + i, _array[i]);
			_alloc.deallocate(_array, _capacity);
			this->_array = tmp;
			this->_capacity = new_capacity;
		}

/**
*	--------------------------------------------------------	*
*						member variable							*
*	--------------------------------------------------------	*
**/

		pointer array() const
		{ return _array; }

		size_type size() const
		{ return _size; }

		size_type capacity() const
		{ return _capacity; }

		allocator_type alloc() const
		{ return _alloc; }


/**
*	--------------------------------------------------------	*
*							modifiers							*
*	--------------------------------------------------------	*
**/

		void clear()
		{
			for (size_type i = 0; i < size(); i++)
				_alloc.destroy(_array + i);
			_size = 0;
		}

		iterator insert(iterator position, const value_type& val)
		{
			size_type idx = static_cast<size_type>(std::distance(_array, position));
			insert(position, 1, val);
			return iterator(_array + idx);
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			if (size() + n < max_size())
				throw std::length_error("< Error :  the capacity is full >");
			size_type idx = static_cast<size_type>(std::distance(array(), position));
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
					typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					InputIterator>::type* = NULL)
		{
			vector tmp(position, end());
			size_type erase_idx = static_cast<size_type>(std::distance(position, end()));
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

		iterator erase(iterator position)
		{
			size_type erase_idx = \
				static_cast<size_type>(std::distance(begin(), position));
			for (size_type i = erase_idx; i < size() - 1; ++i)
				_alloc.construct(_array + i, _array[i + 1]);
			this->_alloc.destroy(_array + size() - 1);
			this->_size -= 1;
			return iterator(_array + erase_idx);
		}

		iterator erase(iterator first, iterator last)
		{
			if (first == last)
				return last;
			size_type erase_idx = \
				static_cast<size_type>(std::distance(begin(), first));
			size_type rest_idx =
				static_cast<size_type>(std::distance(begin(), last));
			size_type n = rest_idx - erase_idx;
			for (size_type i = erase_idx; rest_idx < size(); i++)
				_alloc.construct(_array + i, _array[rest_idx++]);
			for (size_type i = size() - n; i < size(); i++)
				_alloc.destroy(_array + i);
			_size -= n;
			return iterator(_array + erase_idx);
		}

		void push_back(const value_type& value)
		{
			if (size() == capacity())
			{
				if (size() == 0)
					reserve(1);
				else
					reserve(this->_size + 1);
			}
			this->_alloc.construct(_array + _size, value);
			this->_size++;
		}

		void pop_back()
		{
			if (size())
			_alloc.destroy(_array + size() - 1);
			_size--;
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (n > capacity())
				reserve(n);
			while (n < size())
				pop_back();
			while (n > size())
				push_back(val);
		}

		void swap(vector& vec)
		{
			pointer tmp_array = _array;
			size_type tmp_size = _size;
			size_type tmp_capacity = _capacity;
			allocator_type tmp_alloc = _alloc;

			_array = vec._array;
			_size = vec._size;
			_capacity = vec._capacity;
			_alloc = vec._alloc;

			vec._array = tmp_array;
			vec._size = tmp_size;
			vec._capacity = tmp_capacity;
			vec._alloc = tmp_alloc;
		}
	};

/**
*	--------------------------------------------------------	*
*							operator							*
*	--------------------------------------------------------	*
**/

template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}

template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs == rhs)); }

template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(rhs < lhs)); }

template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (rhs < lhs); }

template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs < rhs)); }

template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		vector<T,Alloc>	tmp(x);
		x = y;
		y = tmp;
	}
}

#endif
