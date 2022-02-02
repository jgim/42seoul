/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:08:47 by jgim              #+#    #+#             */
/*   Updated: 2022/02/02 22:08:48 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	std::cout << std::endl << "====Test_ShrubberyCreationForm_sign====" << std::endl;
	try
	{
		ShrubberyCreationForm scf("SCF Form");
		Bureaucrat bur("Bill",150);
		scf.beSigned(bur);
		bur.executeForm(scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "====Test_ShrubberyCreationForm_execve====" << std::endl;
	try
	{
		ShrubberyCreationForm scf("SCF Form");
		Bureaucrat bur("Bill",140);
		scf.beSigned(bur);
		bur.executeForm(scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "====Test_ShrubberyCreationForm_correct====" << std::endl;
	try
	{
		ShrubberyCreationForm scf("SCF Form");
		Bureaucrat bur("Bill",1);
		scf.beSigned(bur);
		bur.executeForm(scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "====Test_RobotomyRequestForm_correct====" << std::endl;
	try
	{
		RobotomyRequestForm rrf("RRF Form");
		Bureaucrat bur("Bill",1);
		rrf.beSigned(bur);
		bur.executeForm(rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "====Test_PresidentialPardonForm_correct====" << std::endl;
	try
	{
		PresidentialPardonForm ppf("PPF Form");
		Bureaucrat bur("Bill",1);
		ppf.beSigned(bur);
		bur.executeForm(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "====Test_copy====" << std::endl;
	{
		Bureaucrat bur("Bill",138);
		ShrubberyCreationForm scf("SCF Form");
		std::cout << scf << std::endl;
		ShrubberyCreationForm scf2("SCF Form2");
		scf2.beSigned(bur);
		std::cout << scf2 << std::endl;
		scf = scf2;
		std::cout << scf << std::endl;
	}

	return 0;
}
