/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:01:00 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:01:02 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure();
		Cure(const Cure &cure);
		Cure& operator=(const Cure &cure);

		virtual AMateria* clone() const;
		virtual void use(ICharacter &target);

		~Cure();
};

#endif
