/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:54:58 by jgim              #+#    #+#             */
/*   Updated: 2022/05/29 17:54:59 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "IteratorTraits.hpp"
# include <cstddef>

namespace ft
{
	template < typename T >
	struct is_integral
	{ static const bool value; };

	template < typename T >
	const bool is_integral<T>::value = std::numeric_limits<T>::is_integer;

	template <typename T>
	bool isEqual(T const &first, T const &second)
	{ return (first == second); }

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class T>
	void swap(T &a, T &b)
	{
		T c(a);
		a = b;
		b = c;
	}

	template <class InputIt1, class InputIt2>
	bool	 lexicographical_compare(InputIt1 first1, InputIt1 last1,
				InputIt2 first2, InputIt2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template<class Iterator>
	typename ft::iterator_traits<Iterator>::difference_type
	do_distance(Iterator first, Iterator last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<Iterator>::difference_type result = 0;

		while (first != last)
		{
			++first;
			++result;
		}
		return (result);
	}

	template<class Iterator>
	typename ft::iterator_traits<Iterator>::difference_type
	do_distance(Iterator first, Iterator last, ft::random_access_iterator_tag)
	{
		return (last - first);
	}

	template <class Iterator>
	typename ft::iterator_traits<Iterator>::difference_type
	distance(Iterator first, Iterator last)
	{
		return (ft::do_distance(first, last, typename ft::iterator_traits<Iterator>::iterator_category()));
	}
}

#endif
