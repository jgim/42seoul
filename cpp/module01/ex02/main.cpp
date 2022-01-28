/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:47:25 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:47:27 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string &ref = str;
	std::string *ptr = &str;

	std::cout << "&str : " << &str << std::endl;
	std::cout << "&ref : " << &ref << std::endl;
	std::cout << " ptr : " << ptr << std::endl;
	std::cout << std::endl;
	std::cout << " str : " << str << std::endl;
	std::cout << "*ptr : " << *ptr << std::endl;
	std::cout << " ref : " << ref << std::endl;

	return (0);
}
