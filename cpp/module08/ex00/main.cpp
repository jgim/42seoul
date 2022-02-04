/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:23:46 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 18:23:47 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::deque<int>				deq;
	std::list<int>				li;
	std::vector<int>			vect;
	std::vector<int>::iterator	itr_vect;
	std::list<int>::iterator	itr_li;
	std::deque<int>::iterator	itr_deq;

	for (int i = 0; i < 100; i += 2)
	{	vect.push_back(i);
		li.push_back(i);
		deq.push_back(i);
	}
	int s = 0, f= 0;
	std::cout << "<   vector   >" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			std::cout << "찾을 값: " << i * i << std::endl;
			itr_vect = easyfind(vect, i * i);
			std::cout << "성공 : " << *itr_vect << std::endl;
			s++;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "실패!" << std::endl;
			f++;
		}
		std::cout << std::endl;
	}
	std::cout << "success : " << s << ", fail : " << f << std::endl;
	std::cout << std::endl << std::endl;
	s = 0, f= 0;
	std::cout << "<   list   >" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			std::cout << "찾을 값: " << i * i << std::endl;
			itr_li = easyfind(li, i * i);
			std::cout << "성공 : " << *itr_li << std::endl;
			s++;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "실패!" << std::endl;
			f++;
		}
		std::cout << std::endl;
	}
	std::cout << "success : " << s << ", fail : " << f << std::endl;
	std::cout << std::endl << std::endl;
	s = 0, f= 0;
	std::cout << "<   deque   >" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		try
		{
			std::cout << "찾을 값: " << i * i << std::endl;
			itr_deq = easyfind(deq, i * i);
			std::cout << "성공 : " << *itr_deq << std::endl;
			s++;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << "실패!" << std::endl;
			f++;
		}
		std::cout << std::endl;
	}
	std::cout << "success : " << s << ", fail : " << f << std::endl;
	std::cout << std::endl << std::endl;

	return 0;
}
