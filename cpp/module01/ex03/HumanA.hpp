/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:47:43 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:47:44 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
private:
	std::string _name;
	Weapon		&_weapon;
	HumanA();

public:
	HumanA(Weapon &weapon);
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void);
};

#endif
