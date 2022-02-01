/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:01:07 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:01:08 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria::AMateria("ice")
{
	std::cout << "Ice 생성자를 호출하였습니다." << std::endl;
}

Ice::Ice(const Ice &ice): AMateria::AMateria(ice)
{
	*this = ice;
	std::cout << "Ice 복사 생성자를 호출하였습니다." << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice 소멸자를 호출하였습니다." << std::endl;
}

Ice	&Ice::operator=(const Ice &ice)
{
	_type = ice._type;
	std::cout << "Ice 대입 연산자를 호출하였습니다." << std::endl;
	return *this;
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter& target)
{
	std::cout << "---*---*  "<< target.getName() << "에게 아이스 볼트를 쐈습니다!  *---*---" << std::endl;
}
