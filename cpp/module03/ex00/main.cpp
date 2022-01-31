/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:06:19 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:06:21 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("미니언");
	ClapTrap	b;
	ClapTrap	c("원거리 미니언");
	ClapTrap	d(c);

	std::cout << std::endl;
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());
	d.attack(b.getName());
	b.takeDamage(b.getAttackDamage());
	std::cout << std::endl;
	a.attack(d.getName());
	d.takeDamage(a.getAttackDamage());
	std::cout << std::endl;
	a.beRepaired(20);
	std::cout << std::endl;
	return (0);
}
