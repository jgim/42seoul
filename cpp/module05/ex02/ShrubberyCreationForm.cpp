/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:06:28 by jgim              #+#    #+#             */
/*   Updated: 2022/02/02 22:06:29 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	Form("ShrubberyCreationForm", 145, 137)
{
	_target = "Unknown";
	std::cout << "ShrubberyCreationForm 생성자를 호출하였습니다." << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	std::cout << "ShrubberyCreationForm 생성자를 호출하였습니다." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f):
	Form(f.getName(), 145, 137)
{
	_target = f._target;
	std::cout << "ShrubberyCreationForm 복사 생성자를 호출하였습니다." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& f)
{
	_target = f._target;
	std::cout << "ShrubberyCreationForm 대입 연산자를 호출하였습니다." << std::endl;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat &b) {
	if (this->getSign() == false)
		throw(NoSignException());
	if (b.getGrade() > this->getGrade())
		throw(GradeTooLowException());
	std::ofstream	writeFile(b.getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (writeFile.is_open() == false)
		throw(FileException());
	std::cout << b.getName() << " 관료가 " << getName() << "을 실행하였습니다." << std::endl;
	std::string	shrubbery = "    oxoxoo    ooxoo\n"
							"  ooxoxo oo  oxoxooo\n"
							" oooo xxoxoo ooo ooox\n"
							" oxo o oxoxo  xoxxoxo\n"
							"  oxo xooxoooo o ooo\n"
							"    ooo\\oo\\  /o/o\n"
							"        \\  \\/ /\n"
							"         |   /\n"
							"         |  |\n"
							"         | D|\n"
							"         |  |\n"
							"         |  |\n"
							"  ______/____\\____\n";
	writeFile << shrubbery;
	writeFile.close();
}

std::string ShrubberyCreationForm::getTarget() const{
	return _target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm 소멸자를 호출하였습니다." << std::endl;
}
