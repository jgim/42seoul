/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:07:00 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:07:01 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("a");
	ScavTrap	b("b");
	ScavTrap	c;

	std::cout << std::endl;
	a.attack(b.getName());
	b.takeDamage(20);

	std::cout << std::endl;

	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());

	std::cout << std::endl;

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());

	std::cout << std::endl;

	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());

	std::cout << std::endl;

	b.guardGate();

	std::cout << std::endl;
	return (0);
}
