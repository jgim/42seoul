/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:20:32 by silim             #+#    #+#             */
/*   Updated: 2022/05/25 17:29:37 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include "../container/Map.hpp"

void test_map()
{
	clock_t start;
	clock_t end;
	clock_t elapsed_time;

std::cout << "MAPS :\n";

	std::fstream fs;

	/* Constructors */
	{
		ft::map<char,int>	first;
		//first['a'] = 10;
		//first['b'] = 30;
		//first['c'] = 50;
	}

	start = clock();
	end = clock();
	elapsed_time = end - start;
	std::cout << "[MAP] Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;
}
