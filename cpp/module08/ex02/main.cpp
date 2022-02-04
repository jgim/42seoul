/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:24:20 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 18:24:21 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
    std::cout << "<   MUTANTSTACK  >" << std::endl;

	MutantStack<int>	mutantstack;

	mutantstack.push(5);
	mutantstack.push(10);
	mutantstack.push(17);

	std::cout << "mstack.top():\t" << mutantstack.top() << std::endl;

	mutantstack.pop();

	std::cout << "mstack.size():\t" << mutantstack.size() << std::endl;

	mutantstack.push(3);
	mutantstack.push(5);
	mutantstack.push(737);
	mutantstack.push(0);

	MutantStack<int>::iterator it = mutantstack.begin();
	MutantStack<int>::iterator ite = mutantstack.end();

	++it;
	--it;
	std::cout << "mstack print:" << std::endl;
	while (it != ite)
	{
		std::cout << "\t" << *it << std::endl;
		++it;
	}
	std::stack<int> s = mutantstack;

    std::cout << std::endl << "=== MUTANTSTACK reverse === " << std::endl;
	MutantStack<int>::reverse_iterator it_r = mutantstack.rbegin();
	MutantStack<int>::reverse_iterator ite_r = mutantstack.rend();

	std::cout << "mstack.size():\t" << mutantstack.size() << std::endl;
	it_r++;
	it_r--;
	std::cout << "mstack reverse print:" << std::endl;
	while (it_r != ite_r)
	{
		std::cout << "\t" << *it_r << std::endl;
		++it_r;
	}

    std::cout << std::endl << "=== MUTANTSTACK copy === " << std::endl;
	MutantStack<int>	mstack1;
	mstack1 = mutantstack;

	std::cout << "mstack1.size():\t" << mstack1.size() << std::endl;

	MutantStack<int>::iterator it1 = mstack1.begin();
	MutantStack<int>::iterator ite1 = mstack1.end();

	it1++;
	it1--;
	std::cout << "mstack copy print:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << "\t" << *it1 << std::endl;
		++it1;
	}


	return 0;
}
