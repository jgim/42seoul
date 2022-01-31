/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:07:34 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 03:07:35 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

#define FHP				100
#define FEP				100
#define FAD				30

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap const& frag_trap);
		FragTrap(std::string name);

		void		highFivesGuys(void);
		void		attack(std::string const& target);

		FragTrap&	operator=(FragTrap const& frag_trap);

		~FragTrap();
};

#endif
