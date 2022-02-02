/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:05:47 by silim             #+#    #+#             */
/*   Updated: 2022/02/01 21:05:48 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	~PresidentialPardonForm();

	PresidentialPardonForm(const PresidentialPardonForm& f);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& f);

	std::string const	getTarget() const;
	void				execute(Bureaucrat &b);
};

#endif
