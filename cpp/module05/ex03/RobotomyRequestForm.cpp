/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:05:53 by silim             #+#    #+#             */
/*   Updated: 2022/02/01 21:05:54 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	Form("RobotomyRequestForm", 72, 45),
	_target("Unknown")
{
	std::cout << "RobotomyRequestForm 생성자를 호출하였습니다." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form(target, 72, 45),
	_target(target)
{
	std::cout << "RobotomyRequestForm 생성자를 호출하였습니다." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f) : Form(f.getName(), 72, 45)
{
	_target = f._target;
	std::cout << "RobotomyRequestForm 복사 생성자를 호출하였습니다." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& f)
{
	_target = f._target;
	std::cout << "RobotomyRequestForm 대입 연산자를 호출하였습니다." << std::endl;
	return (*this);
}

std::string const RobotomyRequestForm::getTarget() const
{
	return _target;
}

void	RobotomyRequestForm::execute(Bureaucrat &b) {
	if (this->getSign() == false)
		throw(NoSignException());
	if (b.getGrade() > this->getGrade())
		throw(GradeTooLowException());

	std::cout << b.getName() << " 관료가 " << getName() << "을 실행하였습니다." << std::endl;
	srand(time(0));
	if (rand() % 2)
	{
		std::cout << ">> <지이이잉>  " << this->getName() << "은 성공적으로 robotomize 되었습니다." << std::endl;
	}
	else
		std::cout << ">> <지이이잉>  "<< this->getName() << "은 robotize에 실패하였습니다." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm 소멸자를 호출하였습니다." << std::endl;
}
