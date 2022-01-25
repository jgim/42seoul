/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:13:44 by jgim              #+#    #+#             */
/*   Updated: 2022/01/25 23:13:45 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# define MAX 8

class PhoneBook
{
private:
	Contact		_contact[MAX];
	int			_index;
public:
	PhoneBook();
	void addPhoneBook();
	void searchPhoneBook();
	void inputIndex(int max_index);
	void readContact();
	~PhoneBook(){};
};

#endif
