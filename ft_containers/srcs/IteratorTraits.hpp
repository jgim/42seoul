/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:54:19 by jgim              #+#    #+#             */
/*   Updated: 2022/05/29 17:54:21 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP
# include <cstddef>
# include <limits>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template < bool B, typename T = void >
	struct enable_if
	{
	};

	template < typename T >
	struct enable_if<true, T>
	{
		typedef T	type;
	};

	template < class T >
	class is_iterator
	{
		private:
			typedef char	one;
			typedef int		two;

			template < typename C >
				static one	test(typename C::iterator_category* = 0);
			template < typename C >
				static two	test(...);

		public:
			static const bool result = sizeof(one) == sizeof(test<T>(0));
	};

	template < class Iter, bool >
	struct _iterator_traits
	{
	};

	template < class Iter >
	struct _iterator_traits<Iter, true>
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template < class Iter >
	struct iterator_traits : public _iterator_traits<Iter, is_iterator<Iter>::result>
	{
	};

	template < class T >
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef	T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template < class T >
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef	T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};
}
#endif
