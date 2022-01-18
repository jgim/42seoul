#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon(void)
{
	std::cout << getType() << "이 파괴되었습니다." << std::endl;
	std::cout << std::endl;
}

const std::string	&Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
