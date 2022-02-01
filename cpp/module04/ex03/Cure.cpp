/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:00:35 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:00:36 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria::AMateria("cure")
{
	std::cout << "Cure 생성자를 호출하였습니다." << std::endl;
}

Cure::Cure(const Cure &cure): AMateria::AMateria(cure)
{
	*this = cure;
	std::cout << "Cure 복사 생성자를 호출하였습니다." << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure 소멸자를 호출하였습니다." << std::endl;
}

Cure	&Cure::operator=(const Cure &cure)
{
	_type = cure._type;
	std::cout << "Cure 대입 연산자를 호출하였습니다." << std::endl;
	return *this;
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter& target)
{
	std::cout << "~~~~~~~~  "<< target.getName() << "의 상처를 치료했습니다!  ~~~~~~~~" << std::endl;
}
