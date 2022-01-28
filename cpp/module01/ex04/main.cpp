/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:48:54 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:48:55 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

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
