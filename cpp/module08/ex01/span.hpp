/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:24:09 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 18:24:10 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <time.h>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_sp;

	public:
		Span(unsigned int N = 0);
		~Span();
		Span(const Span&);
		Span &operator=(const Span& op);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void	RandomInit();

		class SpIsFull: public std::exception
		{
			virtual const char* what() const throw()
			{ return ("Span 꽉 찼습니다.");}
		};
		class SpIsTooSmall: public std::exception
		{
			virtual const char* what() const throw()
			{return ("Span은 너무 작습니다.");}
		};
};

#endif
