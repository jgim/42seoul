/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 02:48:25 by jgim              #+#    #+#             */
/*   Updated: 2022/01/29 02:48:26 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{

	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();

		const std::string	&getType(void);
		void		setType(std::string type);
};

#endif
