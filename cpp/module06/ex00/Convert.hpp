#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>
# include <iostream>
# include <math.h>
# include <limits>
# include <ctype.h>

class Convert
{
	private:
		std::string	_input;
		bool		checkType(std::string str);

	public:
		Convert();
		Convert(std::string str);
		Convert(const Convert& convert);
		Convert& operator=(const Convert& convert);
		~Convert();

		char	toChar() const;
		float	toFloat() const;
		int		toInt() const;
		double	toDouble() const;

		void	printConvert();
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();

	class WrongInput: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
