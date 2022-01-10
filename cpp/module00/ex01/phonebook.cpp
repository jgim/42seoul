#include "phonebook.hpp"

Phonebook::Phonebook(){
	m_index = 0;
};

/* Implement the function of ADD */
/* Enter values continuously */
/* first name, last name, nickname, phone number, darkest secret */
/* The PhoneBook must be represented as as an instance of a class */
/* it must contain an array of contact */

void Phonebook::addPhonebook(){
	if(m_index == MAX)
		m_index = 0;
	m_contact[m_index++].addContact();
}

/* Implement the function of SEARCH */
/* The program will display a list of the available non-empty contacts in four */
/* columns: index, first name, last name and nickname */
/* Each column must be 10 chars wide, right aligned and separated by a ’|’ character */
/* Any output longer than the columns’ width is truncated and the last displayable character is replaced by a dot (’.’) */

void Phonebook::searchPhonebook(){
	int i;

	for (i = 0; i < MAX; i++){
		if (!m_contact[i].getCreated())
			break;
		if (i == 0)
		{
			std::cout << "|-------------------------------------------|" << std::endl;
			std::cout << "|     index|first name| last name|  nickname|" << std::endl;
			std::cout << "|-------------------------------------------|" << std::endl;
		}
		m_contact[i].printPhonebook(i);
	}
	if (i == 0)
		std::cout << "빈 페이지입니다." << std::endl;
	else
		inputIndex(i);
}

void Phonebook::inputIndex(int max_index){
	int i;

	while(42){
		std::cout << "열람하실 인덱스를 입력하세요(종료 0) : ";
		std::cin >> i;
		if (std::cin.fail())
        {
			std::cout << "유효하지 않은 값입니다." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			return ;
        }
		if (i == 0)
			break;
		else if (i <= max_index)
			m_contact[i - 1].readContact();
		else
			std::cout << "유효하지 않은 인덱스입니다." << std::endl;
	}
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

