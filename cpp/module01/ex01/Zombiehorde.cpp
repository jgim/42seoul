/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombiehorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:47:01 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:47:02 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

char	to_char(int num)
{
	char c;

	c = (char)(num + 48);
	return (c);
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombie[i].setName(name + to_char(i));
		std::cout << zombie[i].getName() << " is created" << std::endl;

	}
	return (zombie);
}
