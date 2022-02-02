/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:04:46 by silim             #+#    #+#             */
/*   Updated: 2022/02/01 21:04:47 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	Form("Presidential Pardon", 150, 150)
{
	_target = "Unknown";
	std::cout << "PresidentialPardonForm 생성자를 호출하였습니다." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target):
	Form("Presidential Pardon", 25, 5)
{
	_target = target;
	std::cout << "PresidentialPardonForm 생성자를 호출하였습니다." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f):
	Form(f.getName(), 25, 5)
{
	_target = f._target;
	std::cout << "PresidentialPardonForm 복사 생성자를 호출하였습니다." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& f)
{
	_target = f._target;
	std::cout << "PresidentialPardonForm 대입 연산자를 호출하였습니다." << std::endl;
	return (*this);
}

std::string const PresidentialPardonForm::getTarget() const
{
	return _target;
}

void	PresidentialPardonForm::execute(Bureaucrat &b) {
	if (this->getSign() == false)
		throw(NoSignException());
	if (b.getGrade() > this->getGrade())
		throw(GradeTooLowException());
	std::cout << b.getName() << " 관료가 " << getName() << "을 실행하였습니다." << std::endl;
	std::cout << ">>  " << this->getName() << "이 죄수를 사면하였습니다." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm 소멸자를 호출하였습니다." << std::endl;
}
