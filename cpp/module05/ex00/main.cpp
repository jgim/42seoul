/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:20:14 by jgim              #+#    #+#             */
/*   Updated: 2022/02/02 20:20:16 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat	a("abc", 150);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat	b("b", 1);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat	a("b", -1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat	b("b", 200);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
