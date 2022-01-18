#include "Zombie.hpp"

Zombie::Zombie()
{
	_name = "zombie";
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout << "<" << _name << _index << ">";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << _index << " is dead" << std::endl;
}

std::string	Zombie::getName()
{
	return (_name);
}

void	Zombie::setName(std::string name, int i)
{
	_name = name;
	_index = i;
}
