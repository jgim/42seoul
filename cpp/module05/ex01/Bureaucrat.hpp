/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:02:39 by jgim              #+#    #+#             */
/*   Updated: 2022/02/02 22:02:40 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat{

	private:
		const	std::string		_name;
		int						_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(int	grade);
		Bureaucrat(std::string name, int grade);

		Bureaucrat& operator=(const Bureaucrat& bureaucrat);
		Bureaucrat(const Bureaucrat& bureaucrat);

		std::string		getName() const;
		int				getGrade() const;
		void			setGrade(int grade);

		void			incrementGrade();
		void			decrementGrade();
		void			signForm(Form& form);


		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw();
		};

		~Bureaucrat();
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
