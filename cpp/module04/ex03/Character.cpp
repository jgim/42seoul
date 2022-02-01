/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:00:56 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:00:57 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("unknown")
{
	for (int i = 0; i < SLOT_SIZE; i++)
		_slot[i] = NULL;
	std::cout << _name << " 캐릭터가 생성되었습니다." << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < SLOT_SIZE; i++)
		_slot[i] = NULL;
	std::cout << _name << " 캐릭터가 생성되었습니다." << std::endl;
}

Character::Character(const Character& character) : _name(character._name)
{
	for (int i = 0; i < SLOT_SIZE; i++)
		_slot[i] = character._slot[i];
	std::cout << _name << " 캐릭터가 복사되었습니다." << std::endl;
}

Character& Character::operator = (const Character &character)
{
	if (this == &character)
		return (*this);
	std::cout << _name << "가 "<<std::endl;
	_name = character._name;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (character._slot[i])
			_slot[i] = character._slot[i];
		else
			_slot[i] = NULL;
	}
	std::cout << _name << "의 능력을 가져왔습니다." << std::endl;
	return (*this);
}

std::string const& Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* materia)
{
	if (_slot[3])
		std::cout << "더 이상 넣을 수 없습니다." << std::endl;
	else
		for (int i = 0; i < SLOT_SIZE; i++)
			if (!_slot[i])
			{
				_slot[i] = materia;
				break;
			}
}

void	Character::unequip(int index)
{
	if (!_slot[index])
		std::cout << "비어있는 칸입니다." << std::endl;
	else
	{
		std::cout << _slot[index]->getType() << "을 해제하였습니다." << std::endl;
		_slot[index] = NULL;
	}
}

void	Character::use(int index, ICharacter& target){
	if (index < 0 || index >= SLOT_SIZE || !_slot[index])
		return ;
	std::cout << _name << "이 ";
	_slot[index]->use(target);
}

void	Character::printSlot()
{
	int flag = 0;

	std::cout << " << "<< _name <<"'s slot"<< " >> " << std::endl;
	std::cout << "|" ;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (_slot[i])
		{
			std::cout << std::setw(6) << _slot[i]->getType() << " | ";
			flag = 1;
		}
		else
			std::cout << std::setw(6) << "(null)" << " | ";
	}
	std::cout << std::endl;
	if (flag == 0)
		std::cout << std::endl;
}


Character::~Character(){
	for (int i = 0; i < SLOT_SIZE; i++)
		delete _slot[i];
	std::cout << _name << " 캐릭터 소멸자를 호출하였습니다." << std::endl;
}
