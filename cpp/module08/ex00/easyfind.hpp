/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:23:40 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 18:23:42 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	iter;

	iter = find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::runtime_error(std::string("The value ") +
          std::to_string(value) +
          std::string(" was not found"));
	return iter;
}

#endif
