/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:55:26 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:55:27 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& wrong_animal);
		WrongAnimal&	operator=(WrongAnimal const &wrong_animal);

		void	makeSound() const;
		std::string		getType() const;

		~WrongAnimal();
};

#endif
