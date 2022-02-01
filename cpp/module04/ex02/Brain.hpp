/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:57:35 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:57:36 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

# define BRAIN_SIZE 100

class Brain{
	private:
		std::string _ideas[BRAIN_SIZE];
		int			_num;
	public:
		Brain();
		Brain(const Brain& brain);
		Brain& operator=(const Brain& brain);

		void		printIdeas();
		void		addIdea(std::string idea);
		std::string	chooseIdea();
		std::string	getBrain();

		~Brain();
};

#endif
