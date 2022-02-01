/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:56:00 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:56:01 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain;
	std::cout << "멍멍이 생성자를 호출하였습니다." << std::endl;
}

Dog::Dog(const Dog& dog)
{
	_type = dog._type;
	_brain = new Brain;
	std::cout << "멍멍이 복사 생성자를 호출하였습니다." << std::endl;
}

Dog&	Dog::operator=(const Dog& dog)
{
	_type = dog._type;
	std::cout << "Dog 대입연산자 (" << _type << ")을 호출하였습니다." << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "왈왈" << std::endl;
}

void	Dog::printIdeas(){
	std::cout << "-------------------" << std::endl;
	std::cout << _type << "의 ";
	_brain->printIdeas();
	std::cout << "-------------------" << std::endl;
}

void	Dog::addIdea(std::string idea){
	_brain->addIdea(idea);
}

std::string	Dog::chooseIdea(){
	return _brain->chooseIdea();
}

Dog::~Dog(){
	delete _brain;
	std::cout << "멍멍이 소멸자를 호출하였습니다." << std::endl;
}
