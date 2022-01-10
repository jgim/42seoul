#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# define MAX 8

class Phonebook
{
private:
	Contact		m_contact[MAX];
	int			m_index;
public:
	Phonebook();
	void addPhonebook();
	void searchPhonebook();
	void inputIndex(int max_index);
	void readContact();
	~Phonebook(){};
};

#endif
