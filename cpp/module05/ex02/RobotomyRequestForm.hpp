/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:06:22 by jgim              #+#    #+#             */
/*   Updated: 2022/02/02 22:06:23 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <stdlib.h>
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(const RobotomyRequestForm& f);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& f);

	std::string const	getTarget() const;
	void				execute(Bureaucrat &b);

	~RobotomyRequestForm();
};

#endif
