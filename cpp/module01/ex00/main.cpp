#include "Zombie.hpp"

int main()
{
	Zombie first_zombie = Zombie("first");
	first_zombie.announce();

	Zombie infected_zombie = Zombie();
	infected_zombie.announce();

	Zombie *mutant_zombie = newZombie("mutant");
	mutant_zombie->announce();

	randomChump("chump");

	delete mutant_zombie;
	return (0);
}
