#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
		_name = "noname";
		_hit_points = 10;
		_energy_points = 10;
		_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name):
		_name(name),
		_hit_points(10),
		_energy_points(10),
		_attack_damage(0)
{
	std::cout << "생성자를 불러왔습니다." << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "소멸자를 불러왔습니다." << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage" << std::endl;
	if (amount < _energy_points)
	{
		 _energy_points -= amount;
		std::cout << "ClapTrap " << _name << "'s energy points is now " <<  _energy_points << std::endl;
	}
	else
	{
		_energy_points = 0;
		std::cout << "ClapTrap " << _name << " died" << std::endl;
	}
};

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energy_points)
	{
		_energy_points = amount;
		std::cout << "ClapTrap " << _name << " has been repaired and is back to life with " << amount << " energy points" << std::endl;
	}
	else
	{
		_energy_points += amount;
		std::cout << "ClapTrap " << _name << " has been repaired of " << amount << " energy points. It has now " << _energy_points << " energy points" << std::endl;
	}
}
