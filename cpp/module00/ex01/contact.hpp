/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:13:05 by jgim              #+#    #+#             */
/*   Updated: 2022/01/25 23:13:07 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string _phone_number;
	std::string	_darkest_secret;
	bool		_creation;
public:
	Contact();
	void addContact();
	bool getCreated();
	void printPhoneBook(int i);
	void readContact();
	~Contact(){};
};

#endif
