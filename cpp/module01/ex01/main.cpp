#include "Zombie.hpp"
#define N 10

int	main(void)
{
	Zombie	*zombie = zombieHorde(N, "zombie");
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete [] zombie;
	return (0);
}
