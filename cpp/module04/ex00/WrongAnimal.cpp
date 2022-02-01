/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:54:51 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:54:52 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	_type = "(null)";
	std::cout << "WrongAnimal 생성자를 호출하였습니다." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrong_animal){
	_type = wrong_animal._type;
	std::cout << "WrongAnimal 복사 생성자를 호출하였습니다." << std::endl;
}

void	WrongAnimal::makeSound() const{
	std::cout << "이름 모를 생명체가 울고 있습니다." << std::endl;
}

std::string	WrongAnimal::getType() const{
	return _type;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const &wrong_animal){
	_type = wrong_animal._type;
	std::cout << "WrongAnimal 대입연산자 (" << _type << ")을 호출하였습니다." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal 소멸자를 호출하였습니다." << std::endl;
}
