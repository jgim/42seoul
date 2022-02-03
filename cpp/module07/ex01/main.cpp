/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:58:59 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 01:59:00 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int tab[] = {0, 1, 2, 3};
	std::cout << "Origin: " << "< 0, 1, 2, 3 >" << std::endl;
	iter(tab, sizeof(*tab), print);
	std::cout << std::endl;

	std::string str = "test array iterator";
	std::cout << "Origin: <" << str << '>' << std::endl;
	iter(str.c_str(), str.length(), print);
	std::cout << std::endl;

	return 0;
}
