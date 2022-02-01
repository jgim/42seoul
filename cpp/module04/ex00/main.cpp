/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:55:30 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:55:32 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	WrongAnimal* wrong_animal = new WrongAnimal();
	WrongAnimal* wrong_cat = new WrongCat();
	WrongCat* wrong_cat2 = new WrongCat();
	std::cout << wrong_animal->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	wrong_animal->makeSound();
	wrong_cat->makeSound();
	wrong_cat2->makeSound();
	delete wrong_cat, delete wrong_animal, delete wrong_cat2;

	std::cout << std::endl << "--------------------------------" << std::endl;

	Animal* animal = new Animal();
	Animal* cat = new Cat();
	Animal* dog = new Dog();
	std::cout << animal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	delete cat, delete dog, delete animal;

	std::cout << std::endl << "--------------------------------" << std::endl;

	return (0);
}
