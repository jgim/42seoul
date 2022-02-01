/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:00:18 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 22:00:19 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:

	Ice();
	Ice(const Ice &ice);
	~Ice();

	Ice	&operator=(const Ice &ice);

	virtual AMateria	*clone() const ;
	virtual void		use(ICharacter& target);
};

#endif
