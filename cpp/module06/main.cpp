#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "값은 하나만 입력할 수 있습니다." << std::endl;
		return (1);
	}
	try
	{
		Convert num(argv[1]);
		num.print_all();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
