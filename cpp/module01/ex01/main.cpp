/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:47:06 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:47:08 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define N 10

int	main(void)
{
	Zombie	*zombie = zombieHorde(N, "zombie");
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete [] zombie;
	return (0);
}
