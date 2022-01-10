#include "phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string text;
/* Implement the function of EXIT */
/* The program quits and the contacts are lost forever */

	while (42){
		std::cout << "원하는 값을 입력하세요 (EXIT, ADD, SEARCH) : ";
		getline(std::cin, text);
		if (text == "EXIT")
			break;
		else if (text == "ADD")
			phonebook.addPhonebook();
		else if (text == "SEARCH")
			phonebook.searchPhonebook();
		else
			std::cout << "값이 잘못 입력되었습니다. (EXIT, ADD, SEARCH)" << std::endl;
	}
	return (0);
}
