/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:03:27 by jgim              #+#    #+#             */
/*   Updated: 2022/02/03 17:03:29 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert( void ){}

Convert::Convert(std::string str)
{
	if (!checkType(str))
		throw Convert::WrongInput();
	_input = str;
}

Convert::Convert(const Convert& convert)
{
	*this = convert;
}

Convert& Convert::operator=(const Convert& convert)
{
	this->_input = convert._input;
	return *this;
}

bool	Convert::checkType(std::string str)
{
	char *p;
	double tmp;

	if (str.length() == 1 && isascii(str[0]))
		return true;
	tmp = strtod(str.c_str(), &p);
	if (*p == 0 || (*p == 'f' && *(p + 1) == 0))
		return true;
	return false;
}

const char*	Convert::WrongInput::what() const throw()
{
	return "char / int / float / double 이 필요합니다.";
}

Convert::~Convert( void )
{
}

char	Convert::toChar() const
{
	return static_cast<char>(toDouble());
}

float	Convert::toFloat() const
{
	return static_cast<float>(toDouble());
}

int	Convert::toInt() const
{
	return static_cast<int>(toDouble());
}

double	Convert::toDouble() const
{
	if(_input.length() == 1 && !isdigit(_input[0]))
		return static_cast<double>(_input[0]);
	else
		return atof(_input.c_str());
}

void	Convert::printChar( void )
{
	if (!isnan(toFloat()) && !isinf(toFloat()) && !isprint(toChar()) && isascii(toFloat()))
		std::cout << "char\t: Non displayable" << std::endl;
	else if (isprint(toChar()) && isascii(toFloat()))
		std::cout << "char\t: '" << toChar() << "'" << std::endl;
	else
		std::cout << "char\t: impossible" << std::endl;
}

void	Convert::printInt( void )
{
	if (isnan(toFloat()) || toDouble() >= std::numeric_limits<int>::max() \
		|| toDouble() <= std::numeric_limits<int>::min())
		std::cout << "int\t: impossible" << std::endl;
	else
		std::cout << "int\t: " << toInt() << std::endl;
}

void	Convert::printFloat( void )
{
	if (toFloat() - toInt() == 0)
		std::cout << "Float\t: " << toFloat() << ".0f" << std::endl;
	else
		std::cout << "Float\t: " << toFloat() << "f" << std::endl;
}

void	Convert::printDouble( void )
{
	if (toFloat() - toInt() == 0)
		std::cout << "Double\t: " << toDouble() << ".0" << std::endl;
	else
		std::cout << "Double\t: " << toDouble() << std::endl;
}

void	Convert::printConvert( void )
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}
