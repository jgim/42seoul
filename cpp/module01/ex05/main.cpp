#include "Karen.hpp"

int main(void)
{
	Karen karen;
	std::string levels[5] = {"EXIT", "DEBUG", "INFO", "WARNING", "ERROR"};
	int n;

	while (42)
	{
		std::cout << "-------------------------------------------------------------" << std::endl
					<< "1. May I take your order?" << std::endl
					<< "2. If you add bacon, you will have to pay extra." << std::endl
					<< "3. If you don't pay extra, you can't add bacon." << std::endl
					<< "4. Please leave. If you keep doing that, I'll call the police." << std::endl
					<< "Choose the number. (EXIT : 0) : ";
		std::cin >> n;
		std::cout << "-------------------------------------------------------------" << std::endl;
		if (std::cin.fail())
        {
			std::cout << "The value is not valid." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
		else if (n > 4)
			std::cout << "The value is not valid." << std::endl;
		else if (n == 0)
			break;
		else
			karen.complain(levels[n]);
	}
	return (0);
}
