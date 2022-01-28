/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:51:51 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:51:53 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie first_zombie = Zombie("first");
	first_zombie.announce();

	Zombie infected_zombie = Zombie();
	infected_zombie.announce();

	Zombie *mutant_zombie = newZombie("mutant");
	mutant_zombie->announce();

	randomChump("chump");

	delete mutant_zombie;
	return (0);
}
