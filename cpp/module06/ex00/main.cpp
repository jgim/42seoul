#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "잘못된 형식이 입력 되었습니다 : ./convert [ char / int / float / double ]" << std::endl;
		return 1;
	}
	try
	{
		Convert num(argv[1]);
		num.printConvert();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
