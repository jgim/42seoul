/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:08:21 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:08:23 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	_name = "Unknown";
	ClapTrap::_name = _name + "_clap_name";
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap 생성자를 불러왔습니다." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap 생성자를 호출하였습니다." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & diamond_trap): ClapTrap(diamond_trap)
{
	std::cout << "DiamondTrap 복사생성자를 호출하였습니다." << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap 소멸자를 호출하였습니다." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap & diamond_trap)
{
	_name = diamond_trap.getName();
	_hit_points = diamond_trap.getHitpoints();
	_energy_points = diamond_trap.getEnergyPoints();
	_attack_damage = diamond_trap.getAttackDamage();
	std::cout << "diamondTrap 대입연산자를 호출하였습니다." << std::endl;
	return *this;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "이 DiamondTrap의 이름은 " << _name << "이고 이 ClapTrap의 이름은 " << ClapTrap::_name << "입니다." << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
};
