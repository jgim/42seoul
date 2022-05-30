/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:53:51 by jgim              #+#    #+#             */
/*   Updated: 2022/05/29 17:53:53 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "Vector.hpp"
# include <cstddef>

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type		c;

/**
*	-----------------------------------------------------------------------------	*
*									canonical form									*
*	-----------------------------------------------------------------------------	*
**/

		public:
			explicit stack(const container_type &con = container_type()) : c(con) {}

			stack(const stack &other) : c(other.c) {}

			~stack() {}

/**
*	-----------------------------------------------------------------------------	*
*									member function									*
*	-----------------------------------------------------------------------------	*
**/

			stack &operator=(const stack &other)
			{
				this->c = other.c;
				return (*this);
			}

			bool empty() const
			{ return (this->c.empty()); }

			size_type size() const
			{ return (this->c.size()); }

			value_type &top()
			{ return (this->c.back()); }
			const value_type &top() const
			{ return (this->c.back()); }

			void push(const value_type &val)
			{ this->c.push_back(val); }

			void pop()
			{ this->c.pop_back(); }

		template <class T1, class Container1>
		friend bool operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

		template <class T1, class Container1>
		friend bool operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
	};

/**
*	-----------------------------------------------------------------------------	*
*								Non-member function overloads						*
*	-----------------------------------------------------------------------------	*
**/

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.c == rhs.c); }

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return !(lhs == rhs); }

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.c < rhs.c); }

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return !(rhs < lhs); }

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (rhs < lhs); }

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return !(lhs < rhs); }
}

#endif
