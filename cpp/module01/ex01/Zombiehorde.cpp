#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::cout << name << i << " is created" << std::endl;
		zombie[i].setName(name, i);
	}
	return (zombie);
}
