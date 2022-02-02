/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:05:32 by silim             #+#    #+#             */
/*   Updated: 2022/02/01 21:05:32 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern()
{
	for (int i = 0; i < 3; i++)
	{
		if (_forms[i])
			delete (_forms[i]);
	}
}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}
Intern &Intern::operator=(Intern const &intern)
{
	(void)intern;
	return (*this);
}

Form *Intern::makeForm(std::string const &form, std::string const &target)
{
	_forms[0] = new PresidentialPardonForm(target);
	_forms[1] = new RobotomyRequestForm(target);
	_forms[2] = new ShrubberyCreationForm(target);

	std::string form_string[3] = \
		{"robotomy request", \
		"presidential pardon", \
		"shrubbery creation"};
	for (int i = 0; i < 3; i++)
		if (form_string[i] == form)
			return (_forms[i]);
	throw Form::UnknownFormException();
	return (NULL);
}

std::ostream &operator<<(std::ostream &o, Intern const &intern)
{
	(void)intern;
	o << "인턴은 노예에요...";
	return (o);
}
