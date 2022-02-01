/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:55:51 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:55:52 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	_num = 0;
	std::cout << "뇌 생성자를 호출하였습니다." << std::endl;
}

Brain::~Brain()
{
	std::cout << "뇌 소멸자를 호출하였습니다." << std::endl;
}


void Brain::printIdeas()
{
	std::cout << "학습 목록" << std::endl;
	if(_ideas[0].empty())
		std::cout << "- 비어있음 -" << std::endl;
	else
	{
		for (int i = 0; i < BRAIN_SIZE; i++)
		{
			if (_ideas[i].empty())
				break ;
			std::cout << "    " << _ideas[i] << std::endl;
		}
	}
}

void Brain::addIdea(std::string idea)
{
	if (_num < BRAIN_SIZE)
		_ideas[_num++] = idea;
	else
		std::cout << "더 이상 배울 수 없습니다." << std::endl;
}

std::string	Brain::chooseIdea()
{
	if (_num == 0)
		return ("가만히 있습니다.");
	return(_ideas[std::rand() % _num]);
}

Brain& Brain::operator=(Brain const &brain) {
	for(int i=0; i<100; i++) {
		_ideas[i] = brain._ideas[i];
	}
	_num = brain._num;
	std::cout << "Brain 대입연산자를 호출하였습니다." << std::endl;
	return *this;
}

std::string	Brain::getBrain(){
	return _ideas[0];
}
