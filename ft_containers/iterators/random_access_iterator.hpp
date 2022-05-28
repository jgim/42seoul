#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <cstddef>

namespace ft
{
	template <class T> class random_access_iterator
	{
		public:
			typedef random_access_iterator<T>			iterator;
			typedef std::random_access_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::ptrdiff_t						difference_type;
			typedef random_access_iterator<const T>		const_iterator;

		private:
			pointer		_ptr;

		public:

			random_access_iterator() : _ptr(NULL) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(const random_access_iterator& instance) { *this = instance; }
			~random_access_iterator() {}

			random_access_iterator& operator=(const random_access_iterator& rhs)
			{
				this->_ptr = rhs._ptr;
				return *this;
			}

			pointer base(void) const{ return _ptr; }

			// convertion to const
			operator const_iterator() const
			{ return const_iterator(_ptr); }

			// compare operators
			bool operator<(const iterator& rhs)
			{ return this->_ptr < rhs._ptr; }

			bool operator>(const iterator& rhs)
			{ return this->_ptr > rhs._ptr; }

			bool operator<=(const iterator& rhs)
			{ return this->_ptr <= rhs._ptr; }

			bool operator>=(const iterator& rhs)
			{ return this->_ptr >= rhs._ptr; }

			bool operator==(const iterator& rhs)
			{ return this->_ptr == rhs._ptr; }

			bool operator!=(const iterator& rhs)
			{ return this->_ptr != rhs._ptr; }

			// increment and decrement
			iterator& operator++(void)
			{
				this->_ptr++;
				return (*this);
			}

			iterator& operator--(void)
			{
				this->_ptr--;
				return (*this);
			}

			iterator& operator++(int)
			{
				iterator copy(*this);
				this->_ptr++;
				return (copy);
			}

			iterator& operator--(int)
			{
				iterator copy(*this);
				this->_ptr--;
				return copy;
			}

			// arithmetic operators
			iterator operator+(const difference_type& rhs)
			{ return iterator(this->_ptr + rhs); }

			iterator operator-(const difference_type& rhs)
			{ return iterator(this->_ptr - rhs);}

			iterator& operator+=(const difference_type& rhs)
			{
				this->_ptr += rhs;
				return (*this);
			}

			iterator& operator-=(const difference_type& rhs)
			{
				this->_ptr -= rhs;
				return (*this);
			}

			difference_type operator-(const iterator& rhs)
			{ return this->_ptr - rhs._ptr; }
			iterator operator+(const iterator& rhs)
			{ return this->_ptr + rhs._ptr; }

			// subscript operator
			reference operator[](const difference_type& rhs) const
			{ return *(this->_ptr + rhs); }

			// dereference operator
			reference operator*(void) const
			{ return *this->_ptr; }
			pointer operator->(void)
			{ return this->_ptr; }
	};

		//non-member functions
		//comparison by iterators
		template <class T>
		bool operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{ return lhs.base() < rhs.base(); }

		template <class T>
		bool operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{ return lhs.base() > rhs.base(); }
		template <class T>
		bool operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{ return lhs.base() <= rhs.base(); }

		template <class T>
		bool operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{ return lhs.base() >= rhs.base(); }

		template <class T>
		bool operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{ return lhs.base() == rhs.base(); }

		template <class T>
		bool operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
		{ return lhs.base() != rhs.base(); }

		//comparison by reverse and const_reverse_iterator
		template <class T_lhs, class T_rhs>
		bool operator<(const random_access_iterator<T_lhs>& lhs, const random_access_iterator<T_rhs>& rhs)
		{ return lhs.base() < rhs.base(); }

		template <class T_lhs, class T_rhs>
		bool operator>(const random_access_iterator<T_lhs>& lhs, const random_access_iterator<T_rhs>& rhs)
		{ return lhs.base() > rhs.base(); }

		template <class T_lhs, class T_rhs>
		bool operator<=(const random_access_iterator<T_lhs>& lhs, const random_access_iterator<T_rhs>& rhs)
		{ return lhs.base() <= rhs.base(); }

		template <class T_lhs, class T_rhs>
		bool operator>=(const random_access_iterator<T_lhs>& lhs, const random_access_iterator<T_rhs>& rhs)
		{ return lhs.base() >= rhs.base(); }

		template <class T_lhs, class T_rhs>
		bool operator==(const random_access_iterator<T_lhs>& lhs, const random_access_iterator<T_rhs>& rhs)
		{ return lhs.base() == rhs.base(); }

		template <class T_lhs, class T_rhs>
		bool operator!=(const random_access_iterator<T_lhs>& lhs, const random_access_iterator<T_rhs>& rhs)
		{ return lhs.base() != rhs.base(); }

}

#endif
