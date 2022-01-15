#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
private:
	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string m_phone_number;
	std::string	m_darkest_secret;
	bool		m_creation;
public:
	Contact();
	void addContact();
	bool getCreated();
	void printPhoneBook(int i);
	void readContact();
	~Contact(){};
};

#endif
