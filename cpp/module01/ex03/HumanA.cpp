#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ): _name(name), _weapon(weapon){}

HumanA::~HumanA()
{
	std::cout << _name << " 님이 사망하였습니다." << std::endl;
}

void HumanA::attack(void)
{
	std::cout << _name <<"님이 " << _weapon.getType() << "으로 공격하였습니다."<< std::endl;
}
