/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:12:47 by jgim              #+#    #+#             */
/*   Updated: 2022/01/25 23:12:49 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
