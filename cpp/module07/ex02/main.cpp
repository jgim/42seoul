/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 02:03:01 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 02:03:02 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main()
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		std::cout << numbers[0] << std::endl;
		Array<int> tmp = numbers;
		std::cout << tmp[0] << std::endl;
		Array<int> test(tmp);
		std::cout << test[0] << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "너 뭔가 잘못된 거 같지 않아? 과제를 다시 해야겠어!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	std::cout << std::endl;
	std::cout << "      예외 테스트      " << std::endl;
	try {
		Array<char> a(5);
		a[0] = 'a';
		a[1] = 'b';
		a[5] = 'c';
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<char> a(5);
	a[0] = 'a';
	a[1] = 'b';

	Array<char> b;
	b = a;

	std::cout << "      대입연산자 테스트      " << std::endl;

	std::cout << b[0] << std::endl;

	std::cout << std::endl;
	std::cout << "      복사생성자 테스트      " << std::endl;

	Array<char> c(a);

	std::cout << c[0] << '\n' << std::endl;

	return 0;
}
