#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator								iterator_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;

	protected:
		iterator_type	_cur;

	public:
		//canonical form
		reverse_iterator() : _cur() {};
		explicit reverse_iterator(iterator_type iter) : _cur(iter) {};
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& iter) : _cur(iter.base()) {};
		~reverse_iterator() {};

		iterator_type base(void) const
		{ return _cur; }

		//increment and decrement
		reverse_iterator& operator++()
		{
			--_cur;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			--_cur;
			return tmp;
		}

		reverse_iterator& operator--()
		{
			++_cur;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++_cur;
			return tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{ return reverse_iterator(base() - n); }

		reverse_iterator operator-(difference_type n) const
		{ return reverse_iterator(base() + n);}

		reverse_iterator& operator+=(difference_type n)
		{
			_cur -= n;
			return *this;
		}

		reverse_iterator& operator-=(difference_type n)
		{
			_cur += n;
			return *this;
		}

		//dereference operator
		reference operator[] (difference_type n) const
		{ return (base()[n - 1]); }

		reference operator*() const
		{ return *(base()); }

		pointer operator->() const
		{ return &(operator*()); }
	};

	//non-member functions
	//comparison by iterators
	template <class T>
	bool operator<(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() > rhs.base(); }

	template <class T>
	bool operator>(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() < rhs.base(); }

	template <class T>
	bool operator<=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() >= rhs.base(); }

	template <class T>
	bool operator>=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() <= rhs.base(); }

	template <class T>
	bool operator==(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() == rhs.base(); }

	template <class T>
	bool operator!=(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs)
	{ return lhs.base() != rhs.base(); }

	template <class T_lhs, class T_rhs>
	bool operator==(const reverse_iterator<T_lhs>& lhs, const reverse_iterator<T_rhs>& rhs)
	{ return lhs.base() == rhs.base(); }

	template <class T_lhs, class T_rhs>
	bool operator!=(const reverse_iterator<T_lhs>& lhs, const reverse_iterator<T_rhs>& rhs)
	{ return lhs.base() != rhs.base(); }

	template <class T_lhs, class T_rhs>
	bool operator<(const reverse_iterator<T_lhs>& lhs, const reverse_iterator<T_rhs>& rhs)
	{ return lhs.base() > rhs.base(); }

	template <class T_lhs, class T_rhs>
	bool operator>(const reverse_iterator<T_lhs>& lhs, const reverse_iterator<T_rhs>& rhs)
	{ return lhs.base() < rhs.base(); }

	template <class T_lhs, class T_rhs>
	bool operator<=(const reverse_iterator<T_lhs>& lhs, const reverse_iterator<T_rhs>& rhs)
	{ return lhs.base() >= rhs.base(); }

	template <class T_lhs, class T_rhs>
	bool operator>=(const reverse_iterator<T_lhs>& lhs, const reverse_iterator<T_rhs>& rhs)
	{ return lhs.base() <= rhs.base(); }

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename Iterator::difference_type n, const reverse_iterator<Iterator>& iter)
	{ return reverse_iterator<Iterator>(iter.base() - n); }

	template <class Iterator>
	reverse_iterator<Iterator> operator-(typename Iterator::difference_type n, const reverse_iterator<Iterator>& iter)
	{ return reverse_iterator<Iterator>(iter.base() + n); }
}


#endif
