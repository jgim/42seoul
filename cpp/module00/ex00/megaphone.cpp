#include <iostream>
#include <string>
#include <cctype>

void print_upper(std::string str){
	int i;
	int len = str.length();

	for (i = 0; i < len; i++)
		std::cout << (char)toupper(str[i]);
}

int main(int argc, char **argv){
	int i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (i = 1; i < argc; i++)
		print_upper(argv[i]);
	std::cout << std::endl;
	return 0;
}
