/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:08:26 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:08:27 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(DiamondTrap const& diamond_trap);
		DiamondTrap(std::string name);
		~DiamondTrap();

		void	whoAmI(void) const;
		void	attack(const std::string& target);

		DiamondTrap&	operator=(DiamondTrap const& diamond_trap);

	private:
		std::string		_name;
};

#endif
