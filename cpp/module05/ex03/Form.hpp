/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:05:29 by silim             #+#    #+#             */
/*   Updated: 2022/02/01 21:05:30 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const	std::string		_name;
		const	int				_sign_grade;
		const	int				_grade;
		bool					_sign;
		Form();

	public:
		Form(const std::string name, int sign_grade, int grade);
		Form(const Form& f);
		virtual ~Form();
		std::string		getName() const;
		int				getGrade() const;
		int				getSignGrade() const;
		bool			getSign() const;
		void			beSigned(const Bureaucrat& b);
		virtual void	execute(Bureaucrat& b) = 0;

		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw();
		};

		class NoSignException: public std::exception{
			public:
				const char* what() const throw();
		};

		class FileException: public std::exception{
			public:
				const char* what() const throw();
		};

		class UnknownFormException: public std::exception{
			public:
				const char* what() const throw();
		};
};
std::ostream& operator<<(std::ostream &out, Form const &f);
#endif
