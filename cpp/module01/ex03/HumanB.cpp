#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = 0;
}

HumanB::~HumanB()
{
	std::cout << _name << " 님이 사망하였습니다." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << "님이 "<< _weapon->getType() << "으로 공격하였습니다." << std::endl;
	else
		std::cout << _name << "님이 주먹으로 공격하였습니다." << std::endl;
}
