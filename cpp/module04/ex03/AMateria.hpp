/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:00:29 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:00:30 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(std::string const& type);
		AMateria(const AMateria& materia);
		AMateria& operator = (const AMateria& materia);

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		virtual ~AMateria();
};

#endif
