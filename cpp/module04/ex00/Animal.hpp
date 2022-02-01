/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:54:37 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:54:39 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal& animal);
		Animal&	operator=(Animal const &animal);

		virtual void	makeSound() const;
		std::string		getType() const;

		virtual ~Animal();
};

#endif
