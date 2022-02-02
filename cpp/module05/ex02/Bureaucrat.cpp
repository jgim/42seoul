/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:04:27 by silim             #+#    #+#             */
/*   Updated: 2022/02/01 21:04:28 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unknown"), _grade(150)
{
	std::cout << _name << " 관료 생성자를 호출하였습니다." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << _name << " 관료 생성자를 호출하였습니다." << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("Unknown"), _grade(grade)
{
	if (_grade > 150)
		throw(GradeTooLowException());
	else if (_grade < 1)
		throw(GradeTooHighException());
	std::cout << _name << " 관료 생성자를 호출하였습니다." << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade > 150)
		throw(GradeTooLowException());
	else if (_grade < 1)
		throw(GradeTooHighException());
	std::cout << _name << " 관료 생성자를 호출하였습니다." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	*(const_cast<std::string*>(&_name)) = bureaucrat._name;
	_grade = bureaucrat._grade;
	if (_grade > 150)
		throw(GradeTooLowException());
	else if (_grade < 1)
		throw(GradeTooHighException());
	std::cout << _name << " 관료 연산자(=)를 호출하였습니다." << std::endl;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): _name(b._name), _grade(b.getGrade())
{
	if (_grade > 150)
		throw(GradeTooLowException());
	else if (_grade < 1)
		throw(GradeTooHighException());
}

std::string		Bureaucrat::getName() const
{
	return _name;
}
int				Bureaucrat::getGrade() const
{
	return _grade;
}

void			Bureaucrat::setGrade(int grade)
{
	_grade = grade;
}

void			Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void			Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;

}

void	Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " 관료가 " << form.getName() << "에 서명을 하였습니다." << std::endl;
	} catch(std::exception& e) {
		std::cout << _name << " 관료가 " << form.getName() << "에 서명을 할 수 없습니다." << std::endl;
	}
}

void	Bureaucrat::executeForm(Form& form)
{
	try {
		form.execute(*this);
	} catch(std::exception& e) {
		std::cout << _name << " 관료가 " << form.getName() << "을 실행할 수 없습니다." << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << " 관료 소멸자를 호출하였습니다." << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("이미 최상위 등급입니다.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("이미 최하위 등급입니다.");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", 관료 등급 " << bureaucrat.getGrade() << std::endl;
	return out;
}
