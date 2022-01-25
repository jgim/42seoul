/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:12:59 by jgim              #+#    #+#             */
/*   Updated: 2022/01/25 23:13:01 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(){
	_creation = false;
}

void Contact::addContact(){
	std::cout << "이름을 입력해주세요 : ";
	getline(std::cin, _first_name);
	std::cout << "성을 입력해주세요 : ";
	getline(std::cin, _last_name);
	std::cout << "별명을 입력해주세요 : ";
	getline(std::cin, _nickname);
	std::cout << "전화번호를 입력해주세요 : ";
	getline(std::cin, _phone_number);
	std::cout << "가장 어두운 비밀을 입력해주세요 : ";
	getline(std::cin, _darkest_secret);
	_creation = true;
}

bool Contact::getCreated(){
	return(_creation);
}

void Contact::readContact(){
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "   이름 : " << _first_name << std::endl;
	std::cout << "   성 : " << _last_name << std::endl;
	std::cout << "   별명 : " << _nickname << std::endl;
	std::cout << "   전화번호 : " << _phone_number << std::endl;
	std::cout << "   가장 어두운 비밀 : " << _darkest_secret << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
}

void Contact::printPhoneBook(int i){
	std::cout << "|         " << i + 1;
	if (_first_name.length() < 10)
		std::cout << '|' << std::setw(10) << _first_name;
	else
		std::cout << '|' << std::setw(9) << _first_name.substr(0, 9) << '.';
	if (_last_name.length() < 10)
		std::cout << '|' << std::setw(10) << _last_name;
	else
		std::cout << '|' << std::setw(9) << _last_name.substr(0, 9) << '.';
	if (_nickname.length() < 10)
		std::cout << '|' << std::setw(10) << _nickname << '|' << std::endl;
	else
		std::cout << '|' << std::setw(9) << _nickname.substr(0, 9) << '.' << '|' << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}
