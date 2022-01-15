#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# define MAX 8

class PhoneBook
{
private:
	Contact		m_contact[MAX];
	int			m_index;
public:
	PhoneBook();
	void addPhoneBook();
	void searchPhoneBook();
	void inputIndex(int max_index);
	void readContact();
	~PhoneBook(){};
};

#endif
