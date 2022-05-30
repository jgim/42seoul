/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:55:14 by jgim              #+#    #+#             */
/*   Updated: 2022/05/29 18:02:18 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "test_intra.hpp"
# include "test_ft.hpp"
# include "test_stl.hpp"

#define FT -1
#define STL -2
#define BOTH 0

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << " FT   : -1" << std::endl;
		std::cerr << " STL  : -2" << std::endl;
		std::cerr << "Intra : Int " << std::endl;
		return 0;
	}
	int n = atoi(argv[1]);
	if (n == FT)
		test_ft();
	else if (n == STL)
		test_stl();
	else if (n == BOTH)
	{
		test_ft();
		test_stl();
	}
	else
		test_intra(argv);
	return 0;
}
