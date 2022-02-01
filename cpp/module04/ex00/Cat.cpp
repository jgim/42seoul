/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:55:09 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:55:10 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "야옹이 생성자를 호출하였습니다." << std::endl;
}

Cat::Cat(const Cat& cat)
{
	*this = cat;
	std::cout << "야옹이 복사 생성자를 호출하였습니다." << std::endl;
}

Cat&	Cat::operator=(const Cat& cat){
	_type = cat._type;
	std::cout << "Cat 대입연산자 (" << _type << ")을 호출하였습니다." << std::endl;
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "야옹" << std::endl;
}

Cat::~Cat(){
	std::cout << "야옹이 소멸자를 호출하였습니다." << std::endl;
}
