/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:20:32 by silim             #+#    #+#             */
/*   Updated: 2022/05/24 22:55:12 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include "../vector.hpp"

template <typename T>
void display_vector(const ft::vector<T>& vec)
{
	std::cout << "vector capacity: " << vec.capacity() << std::endl;
	std::cout << "The vector contains " << vec.size () << " elements" << std::endl;
	std::cout << "vector: " << std::endl;
	for (typename ft::vector<T>::const_iterator element = vec.begin(); element != vec.end(); ++element )
		std::cout << *element << ' ';
	std::cout << std::endl << std::endl;
}

void test_vector()
{
	clock_t start;
	clock_t end;
	clock_t elapsed_time;

std::cout << "VECTORS :\n";

	std::fstream fs;

	/* Constructors */
	{
		ft::vector <int> v1, v2;
		v1.push_back(1);
		v1.push_back( 2 );
		v1.push_back( 3 );
		v1.pop_back();
		v2.push_back( 1 );

		display_vector( v1 );
		display_vector( v2 );

		v1.reserve(6);
		display_vector( v1 );
		if ( v1 != v2 )
			std::cout << "Vectors not equal." << std::endl;
		else
			std::cout << "Vectors equal." << std::endl;
	}

	start = clock();
	end = clock();
	elapsed_time = end - start;
	std::cout << "[VECTOR] Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;
}
