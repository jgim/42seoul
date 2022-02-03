/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:58:54 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 01:58:55 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void iter(T *array, size_t array_size, void(*f)(T const &))
{
	for (size_t i = 0; i < array_size; i++)
		f(array[i]);
}

template <typename T>
void print(T const & x)
{
	std::cout << x << std::endl;
	return;
}

#endif
