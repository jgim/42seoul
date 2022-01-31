/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:06:49 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:06:50 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "Unknown";
	_hit_points = SHP;
	_energy_points = SEP;
	_attack_damage = SAD;
	std::cout << "ScavTrap 생성자를 호출하였습니다." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_hit_points = SHP;
	_energy_points = SEP;
	_attack_damage = SAD;
	std::cout << "ScavTrap 생성자를 호출하였습니다." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & scav_trap)
{
	*this = scav_trap;
	std::cout << "ScavTrap 복사생성자를 호출하였습니다." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap 소멸자를 호출하였습니다." << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap & scav_trap) {
    _name = scav_trap._name;
    _hit_points= scav_trap._hit_points;
    _energy_points = scav_trap._energy_points;
    _attack_damage = scav_trap._attack_damage;
	std::cout << "ScavTrap 대입 연산자를 호출하였습니다." << std::endl;
	return *this;
}

void	ScavTrap::attack(std::string const& target)
{
	std::cout << "ScavTrap " << _name << "은 " << target << "에게 " << _attack_damage << "의 피해를 입혔습니다." << std::endl;
}

void	ScavTrap::guardGate(void){
		std::cout << "ScavTrap "<< _name << "가 Gate keeper mode에 진입하였습니다." << std::endl;

}
