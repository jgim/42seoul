/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:13:53 by jgim              #+#    #+#             */
/*   Updated: 2022/01/25 23:13:54 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook phonebook;
	std::string text;
/* Implement the function of EXIT */
/* The program quits and the contacts are lost forever */

	while (42){
		std::cout << "원하는 값을 입력하세요 (EXIT, ADD, SEARCH) : ";
		getline(std::cin, text);
		if (text == "EXIT")
			break;
		else if (text == "ADD")
			phonebook.addPhoneBook();
		else if (text == "SEARCH")
			phonebook.searchPhoneBook();
		else
			std::cout << "값이 잘못 입력되었습니다. (EXIT, ADD, SEARCH)" << std::endl;
	}
	return (0);
}
