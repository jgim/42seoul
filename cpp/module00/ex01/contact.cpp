#include "PhoneBook.hpp"

Contact::Contact(){
	m_creation = false;
}

void Contact::addContact(){
	std::cout << "이름을 입력해주세요 : ";
	getline(std::cin, m_first_name);
	std::cout << "성을 입력해주세요 : ";
	getline(std::cin, m_last_name);
	std::cout << "별명을 입력해주세요 : ";
	getline(std::cin, m_nickname);
	std::cout << "전화번호를 입력해주세요 : ";
	getline(std::cin, m_phone_number);
	std::cout << "가장 어두운 비밀을 입력해주세요 : ";
	getline(std::cin, m_darkest_secret);
	m_creation = true;
}

bool Contact::getCreated(){
	return(m_creation);
}

void Contact::readContact(){
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "   이름 : " << m_first_name << std::endl;
	std::cout << "   성 : " << m_last_name << std::endl;
	std::cout << "   별명 : " << m_nickname << std::endl;
	std::cout << "   전화번호 : " << m_phone_number << std::endl;
	std::cout << "   가장 어두운 비밀 : " << m_darkest_secret << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
}

void Contact::printPhoneBook(int i){
	std::cout << "|         " << i + 1;
	if (m_first_name.length() < 10)
		std::cout << '|' << std::setw(10) << m_first_name;
	else
		std::cout << '|' << std::setw(9) << m_first_name.substr(0, 9) << '.';
	if (m_last_name.length() < 10)
		std::cout << '|' << std::setw(10) << m_last_name;
	else
		std::cout << '|' << std::setw(9) << m_last_name.substr(0, 9) << '.';
	if (m_nickname.length() < 10)
		std::cout << '|' << std::setw(10) << m_nickname << '|' << std::endl;
	else
		std::cout << '|' << std::setw(9) << m_nickname.substr(0, 9) << '.' << '|' << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}
