/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:48:01 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:48:02 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanB();
		HumanB(std::string name);
		~HumanB(void);

		void	attack(void);
		void 	setWeapon(Weapon& weapon);
};

#endif
