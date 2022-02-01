/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:56:51 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:56:52 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	_type = "(null)";
	std::cout << "Animal 생성자를 호출하였습니다." << std::endl;
}

Animal::Animal(const Animal& animal){
	_type = animal._type;
	std::cout << "Animal 복사 생성자를 호출하였습니다." << std::endl;
}

void	Animal::makeSound() const{
	std::cout << "이름 모를 생명체가 울고 있습니다." << std::endl;
}

std::string	Animal::getType() const{
	return _type;
}

Animal &	Animal::operator=(const Animal &animal){
	_type = animal._type;
	std::cout << "Animal 대입연산자 (" << _type << ")을 호출하였습니다." << std::endl;
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal 소멸자를 호출하였습니다." << std::endl;
}
