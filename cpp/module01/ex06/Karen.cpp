/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:49:46 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:49:49 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(){}

Karen::~Karen(){}

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon"
				<< " for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
				<< std::endl << "I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money."
				<< " You don’t put enough!" << std::endl
				<< " If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
				<< std::endl << "I’ve been coming here for years"
				<< " and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now" << std::endl;
}

void	Karen::complain(std::string level)
{
	int i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (i < 4)
	{
		if (levels[i] == level)
			break;
		i++;
	}
	switch(i)
	{
		case 0:
			std::cout << std::endl;
			Karen::debug();

		case 1:
			std::cout << std::endl;
			Karen::info();

		case 2:
			std::cout << std::endl;
			Karen::warning();

		case 3:
			std::cout << std::endl;
			Karen::error();
			std::cout << std::endl;
			break;

		default:
			std::cout << std::endl;
			std::cout << "[[Error] Usage: ./[karenFilter][DEBUG / INFO / WARNING / ERROR]" << std::endl;
			std::cout << std::endl;
	}
}
