/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:56:43 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:56:44 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Bird.hpp"

int main()
{
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	std::cout << "-------------------" << std::endl;

	dog->addIdea("잠자기");
	dog->addIdea("먹기");
	dog->addIdea("뛰어놀기");
	dog->addIdea("물기");
	dog->addIdea("달리기");
	dog->addIdea("재롱부리기");
	dog->printIdeas();
	dog->chooseIdea();
	dog->makeSound();

	std::cout << "-------------------" << std::endl;
	cat->addIdea("잠자기");
	cat->addIdea("먹기");
	cat->addIdea("뛰어놀기");
	cat->addIdea("할퀴기");
 	cat->printIdeas();
 	cat->chooseIdea();
	cat->makeSound();

	std::cout << "-------------------" << std::endl;
	delete dog;
	delete cat;
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
