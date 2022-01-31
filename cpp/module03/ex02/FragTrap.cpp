/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:07:29 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:07:31 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "Unknown";
	_hit_points = FHP;
	_energy_points = FEP;
	_attack_damage = FAD;
	std::cout << "FragTrap 생성자를 불러왔습니다." << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hit_points = FHP;
	_energy_points = FEP;
	_attack_damage = FAD;
	std::cout << "FragTrap 생성자를 불러왔습니다." << std::endl;
}

FragTrap::FragTrap(const FragTrap & frag_trap)
{
	*this = frag_trap;
	std::cout << "FragTrap 복사생성자를 불러왔습니다." << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap 소멸자를 불러왔습니다." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap & frag_trap) {
    _name = frag_trap._name;
    _hit_points= frag_trap._hit_points;
    _energy_points = frag_trap._energy_points;
    _attack_damage = frag_trap._attack_damage;
	std::cout << "FragTrap operator = (" << _name << ") called" << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << "님이 하이파이브를 요청하였습니다." << std::endl;
}

void	FragTrap::attack(std::string const& target)
{
	std::cout << "FragTrap " << _name << "은 " << target << "에게 " << _attack_damage << "의 피해를 입혔습니다." << std::endl;
}
