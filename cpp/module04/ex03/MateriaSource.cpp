/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:01:14 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:01:15 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < MATERIASOURCE_SIZE; i++)
		_type[i] = NULL;
	std::cout << "MateriaSource 생성자를 호출하였습니다." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src){
	for (int i = 0; i < MATERIASOURCE_SIZE; i++){
		delete _type[i];
		_type[i] = src._type[i]->clone();
	}

	std::cout << "MateriaSource 복사 생성자를 호출하였습니다." << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src){
	for (int i = 0; i < MATERIASOURCE_SIZE; i++){
		delete _type[i];
		_type[i] = src._type[i]->clone();
	}
	std::cout << "MateriaSource 대입 연산자를 호출하였습니다." << std::endl;
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* materia){
	if (_type[MATERIASOURCE_SIZE - 1] == NULL){
		for (int i = 0; i < MATERIASOURCE_SIZE; i++)
			if (_type[i] == NULL){
				_type[i] = materia;
				break ;
			}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & materia){
	for(int i = 0; i < 4; i++) {
		if (_type[i] && _type[i]->getType() == materia)
			return _type[i]->clone();
	}
	return 0;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < MATERIASOURCE_SIZE; i++)
	{
		if(_type[i] != NULL)
			delete _type[i];
	}
	std::cout << "MateriaSource 소멸자를 호출하였습니다." << std::endl;
}
