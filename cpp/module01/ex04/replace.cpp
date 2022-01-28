/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:48:43 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:48:44 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(){}

Replace::~Replace(){}

bool	Replace::setFile(std::string file, std::string s1, std::string s2)
{
	_base.open(file);
	if (_base.fail())
	{
		std::cout << "[Error] Failed to open the file"  << std::endl;
		return (false);
	}
	_replace.open((file + ".replace"));
	if (_replace.fail())
	{
		std::cout << "[Error] Failed to create the .replace file"  << std::endl;
		_base.close();
		return (false);
	}
	_s1 = s1;
	_s2 = s2;
	return (true);
}

std::string	Replace::replace( std::string str )
{
	std::string result;
	int s1_length;
	int s2_length;
	int i = 0;
	size_t n;

	s1_length = _s1.length();
	s2_length = _s2.length();
	while ((n = str.find(_s1, i)) != std::string::npos)
	{
		str.erase(n, s1_length);
		str.insert(n, _s2);
		i = n + s2_length;
	}
	return (str);
}

void	Replace::replaceFile()
{
	std::string buf;
	std::string tmp;

	while (std::getline(_base, tmp))
		buf += tmp + '\n';
	_replace << replace(buf);
	_base.close();
	_replace.close();
}
