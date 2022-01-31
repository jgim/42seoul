/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:09:07 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:09:08 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a("A");

	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;

	{
		DiamondTrap b("B");
		DiamondTrap c("C");


		std::cout << std::endl;

		b.whoAmI();
		c.whoAmI();
		c.highFivesGuys();

		std::cout << std::endl;

		b.attack("C");
		c.takeDamage(b.getAttackDamage());

		std::cout << std::endl;

		b.attack("C");
		c.takeDamage(b.getAttackDamage());

		std::cout << std::endl;

		b.guardGate();

		std::cout << std::endl;
	}

	std::cout << std::endl;

	DiamondTrap d;

	std::cout << std::endl;

	d.whoAmI();

	std::cout << std::endl;

	d = a;

	std::cout << std::endl;

	d.whoAmI();

	std::cout << std::endl;
	return (0);
}
