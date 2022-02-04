/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:24:31 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 18:24:33 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>
# include <algorithm>

template< typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack(): std::stack<T>()
	{
	};

	virtual ~MutantStack()
	{
	};

	MutantStack(const MutantStack& origin): std::stack<T>(origin)
	{
	};

	MutantStack &operator=(const MutantStack &origin)
	{
		std::stack<T>::operator=(origin);
		return *this;
	};

	iterator begin()
	{
		return this->c.begin();
	};

	iterator end()
	{
		return this->c.end();
	};

	const_iterator begin() const
	{
		return this->c.begin();
	};

	const_iterator end() const
	{
		return this->c.end();
	};

	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	};

	reverse_iterator rend()
	{
		return this->c.rend();
	};

	const_reverse_iterator rbegin() const
	{
		return std::stack<T>::c.rbegin();
	};

	const_reverse_iterator rend() const
	{
		return std::stack<T>::c.rend();
	};
};

#endif
