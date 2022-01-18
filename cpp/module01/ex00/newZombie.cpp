#include "Zombie.hpp"

Zombie * newZombie(std::string name)
{
	Zombie *mutant_zombie = new Zombie(name);
	return (mutant_zombie);
}
