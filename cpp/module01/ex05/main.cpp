/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:49:36 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:49:37 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(void)
{
	Karen karen;

	std::cout << std::endl;
	karen.complain("DEBUG");
	std::cout << std::endl;
	karen.complain("INFO");
	std::cout << std::endl;
	karen.complain("WARNING");
	std::cout << std::endl;
	karen.complain("ERROR");
	std::cout << std::endl;

	return (0);
}
