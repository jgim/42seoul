#include "replace.hpp"

int main(int argc, char **argv)
{
	Replace replace;

	if (argc != 4)
	{
		std::cerr << "[Error] Usage: ./[replace][filename][original_word][changed_word]" << std::endl;
		return (1);
	}
	else if (!argv[1][0])
	{
		std::cerr << "[Error] Empty file" << std::endl;
		return (1);
	}
	else if (!argv[2][0])
	{
		std::cout << "[Error] Empty string" << std::endl;
		return (1);
	}
	if (replace.setFile(argv[1], argv[2], argv[3]))
		replace.replaceFile();
	return (0);
}
