/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:50:03 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:50:05 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen karen;

	if (argc == 2)
		karen.complain(argv[1]);
	else
		std::cout << "Usage: ./[karenFilter][DEBUG / INFO / WARNING / ERROR]" << std::endl;
	return (0);
}
