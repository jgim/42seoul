#include "Karen.hpp"

Karen::Karen()
{
	std::cout << "나는 생성자다" << std::endl;
}

Karen::~Karen()
{
	std::cout << "나는 소멸자다" << std::endl;
}

void	Karen::debug(void)
{
	std::cout << "[debug]" << std::endl;
	std::cout << "I love to get extra bacon"
				<< " for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
				<< std::endl << "I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[info]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money."
				<< " You don’t put enough!" << std::endl
				<< " If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[warning]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
				<< std::endl << "I’ve been coming here for years"
				<< " and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[error]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now" << std::endl;
}

void	Karen::complain(std::string level)
{
	int i = 0;
	void (Karen::*f[4])() =
	{
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (levels[i] == level)
			(this->*f[i])();
		i++;
	}
}
