/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:00:02 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:00:04 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <string>
# include <iomanip>
# include "ICharacter.hpp"

# define SLOT_SIZE 4

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria	*_slot[SLOT_SIZE];

	public:
		Character();
		Character(std::string const &name);
		Character(const Character &character);
		Character& operator=(const Character &character);

		std::string const& getName() const;
		void	equip(AMateria* materia);
		void	unequip(int index);
		void	use(int index, ICharacter& target);
		void	printSlot();

		~Character();
};

#endif
