/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:53:36 by jgim              #+#    #+#             */
/*   Updated: 2022/05/29 17:53:37 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>

namespace ft
{
	template < class Category, class T, class Distance = ptrdiff_t,
			 class Pointer = T*, class Reference = T& >
	class Iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;

			Iterator() : _ptr(0)
			{}

			Iterator(pointer ptr) : _ptr(ptr)
			{}

			~Iterator()
			{}

			Iterator(Iterator const &src)
			{
				*this = src;
			}

			Iterator    &operator=(Iterator const &src)
			{
				this->_ptr = src._ptr;
				return (*this);
			}

		protected:
			pointer		_ptr;
	};
}

#endif
