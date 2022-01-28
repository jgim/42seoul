/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:46:48 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:46:49 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	_name = "zombie";
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout << "<" << _name << ">";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}

std::string	Zombie::getName()
{
	return (_name);
}

void	Zombie::setName(std::string name)
{
	_name = name;
}
