#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>

class Replace
{
	private:
		std::ifstream	_base;
		std::ofstream	_replace;
		std::string		_s1;
		std::string		_s2;
	public:
		Replace();
		~Replace();
		bool		setFile(std::string file, std::string s1, std::string s2);
		void		replaceFile();
		std::string	replace(std::string str);
};

#endif
