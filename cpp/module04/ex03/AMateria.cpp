/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:59:57 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:59:58 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type){
	_type = type;
	std::cout << "AMateria 생성자를 호출하였습니다." << std::endl;
}

AMateria::AMateria(const AMateria& materia){
	_type = materia._type;
	std::cout << "AMateria 복사 생성자를 호출하였습니다." << std::endl;
}

AMateria& AMateria:: operator=(const AMateria& materia){
	_type = materia._type;
	std::cout << "AMateria 대입 연산자를 호출하였습니다." << std::endl;
	return *this;
}

std::string const&	AMateria::getType() const{
	return _type;
}

void		AMateria::use(ICharacter& target){
	std::cout << "AMateria " << target.getName() << "을 사용하였습니다." << std::endl;
}

AMateria::~AMateria(){
	 std::cout << "AMateria 소멸자를 호출하였습니다." << std::endl;
}
