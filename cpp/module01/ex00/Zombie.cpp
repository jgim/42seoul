/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:46:22 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:46:24 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "zombie is created" << std::endl;
	_name = "zombie";
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << _name << " is created" << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<" << _name << ">";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}

std::string	Zombie::getName()
{
	return (_name);
}
