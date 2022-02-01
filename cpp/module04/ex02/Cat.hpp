/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:57:40 by jgim              #+#    #+#             */
/*   Updated: 2022/02/01 21:57:41 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat& cat);
		Cat& operator=(const Cat& cat);

		virtual void				makeSound() const;
		virtual void				printIdeas();
		virtual void				addIdea(std::string idea);
		virtual std::string			chooseIdea();

		virtual ~Cat();
};

#endif
