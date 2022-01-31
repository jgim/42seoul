/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:05:55 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:05:57 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
		_name("unknown"),
		_hit_points(HP),
		_energy_points(EP),
		_attack_damage(AD)
{
	std::cout << "ClapTrap 생성자를 불러왔습니다." << std::endl;
}

ClapTrap::ClapTrap(std::string name):
		_name(name),
		_hit_points(HP),
		_energy_points(EP),
		_attack_damage(AD)
{
	std::cout << "ClapTrap 생성자를 호출하였습니다." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & clap_trap)
{
	*this = clap_trap;
	std::cout << "ClapTrap 복사생성자를 호출하였습니다." << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & clap_trap)
{
	_name = clap_trap._name;
	_hit_points = clap_trap._hit_points;
	_energy_points = clap_trap._energy_points;
	_attack_damage = clap_trap._attack_damage;
	std::cout << "ClapTrap 복사생성자를 호출하였습니다." << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap 소멸자를 호출하였습니다." << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << _name << "은 " << target << "에게 " << _attack_damage << "의 피해를 입혔습니다." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (amount < _hit_points)
	{
		 _hit_points -= amount;
		std::cout << "ClapTrap " << _name << "은 " << amount << "의 피해를 입었습니다." << std::endl;
		std::cout << "ClapTrap " << _name << "의 체력은 "<<  _hit_points << "이 남았습니다. " << std::endl;
	}
	else if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " 은 이미 사망하였습니다." << std::endl;
	}
	else
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << "은 " << amount << "의 피해를 입었습니다." << std::endl;
		std::cout << "ClapTrap " << _name << " 은 사망하였습니다." << std::endl;
	}
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hit_points)
	{
		_hit_points = amount;
		std::cout << "ClapTrap " << _name << "은 " << amount << "의 체력으로 부활했습니다." << std::endl;
	}
	else
	{
		if (_hit_points + amount >= 10)
		{
			_hit_points = HP;
			std::cout << "ClapTrap " << _name << "은 체력이 " << HP << "으로 완전히 회복되었습니다."<< std::endl;
		}
		else
		{
			_hit_points += amount;
			std::cout << "ClapTrap " << _name << "은 " << amount << "만큼 체력이 회복되어 현재 체력은" << _hit_points << "이 되었습니다." << std::endl;
		}
	}
}

std::string	ClapTrap::getName( void ) const
{
	return (_name);
}

unsigned int	ClapTrap::getHitpoints( void ) const
{
	return (_hit_points);
}

unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	return (_energy_points);
}

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return (_attack_damage);
}
