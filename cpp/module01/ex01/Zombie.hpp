#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
		int			_index;

	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void		announce(void);
		std::string	getName(void);
		void		setName(std::string name, int i);
};

Zombie* zombieHorde(int N, std::string name);

#endif
