/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:46:54 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:46:55 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void		announce(void);
		std::string	getName(void);
		void		setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
