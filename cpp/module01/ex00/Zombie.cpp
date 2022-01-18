#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "zombie is created" << std::endl;
	_name = "zombie";
}

Zombie::Zombie(std::string name)
{
	std::cout << name << " is created" << std::endl;
	_name = name;
}

void	Zombie::announce()
{
	std::cout << "<" << _name << ">";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}

std::string	Zombie::getName()
{
	return (_name);
}
