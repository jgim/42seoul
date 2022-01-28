/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:47:37 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:47:39 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon &weapon): _name("Unknown"), _weapon(weapon){}

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon){}

HumanA::~HumanA()
{
	std::cout << _name << " 님이 사망하였습니다." << std::endl;
}

void HumanA::attack(void)
{
	std::cout << _name <<"님이 " << _weapon.getType() << "으로 공격하였습니다."<< std::endl;
}
