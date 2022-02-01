/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:57:22 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:57:25 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal& animal);
		Animal&	operator=(const Animal &animal);

		std::string				getType() const;
		virtual void			makeSound() const = 0;
		virtual void			printIdeas() = 0;
		virtual void			addIdea(std::string idea) = 0;
		virtual	std::string		chooseIdea() = 0;

		virtual ~Animal();
};

#endif
