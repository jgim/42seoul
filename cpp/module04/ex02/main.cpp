/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:59:38 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:59:40 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Bird.hpp"

int main()
{
	//Animal test;
	Animal* animal[2];
	animal[0] = new Dog();
	animal[1] = new Cat();
	std::cout << "-------------------" << std::endl;

	animal[0]->addIdea("잠자기");
	animal[0]->addIdea("먹기");
	animal[0]->addIdea("뛰어놀기");
	animal[0]->addIdea("물기");
	animal[0]->addIdea("달리기");
	animal[0]->addIdea("재롱부리기");
	animal[0]->printIdeas();
	animal[0]->chooseIdea();
	animal[0]->makeSound();

	std::cout << "-------------------" << std::endl;
	animal[1]->addIdea("잠자기");
	animal[1]->addIdea("먹기");
	animal[1]->addIdea("뛰어놀기");
	animal[1]->addIdea("할퀴기");
 	animal[1]->printIdeas();
 	animal[1]->chooseIdea();
	animal[1]->makeSound();

	std::cout << "-------------------" << std::endl;
	delete animal[0];
	delete animal[1];
	std::cout << "-------------------" << std::endl;
	std::cout << "-------------------" << std::endl;

	Dog basic;
	basic.addIdea("이건 테스트용입니다~");
	basic.printIdeas();
	Dog tmp = basic;
	tmp.printIdeas();

	std::cout << "-------------------" << std::endl;

	Animal *bird = new Bird();
	bird->makeSound();
	bird->printIdeas();
	delete bird;
	std::cout << "-------------------" << std::endl;
	std::cout << "-------------------" << std::endl;

	return 0;
}
