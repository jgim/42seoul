/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:00:50 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:00:51 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	Character sam("sam");
	std::cout << "sam : ";
	sam.printSlot();

	Character sam_junior(sam);
	tmp = src->createMateria("ice");
	sam_junior.equip(tmp);
	std::cout << "sam_junior : ";
	sam_junior.printSlot();

	std::cout << "sam : ";
	sam.printSlot();

	std::cout << std::endl;


	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->printSlot();
	bob->printSlot();
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	delete me;
	delete bob;
	std::cout << std::endl;
	delete src;

	return 0;
}
