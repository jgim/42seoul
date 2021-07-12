/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_s_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:51:37 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:51:38 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int d_print(int d, t_factor *factor)
{
	char *tmp;

	if (d < 0)
	{
		factor->sign = 1;
		d = -d;
	}
	tmp = ft_itoa(d, factor);
	factor->str_len = ft_strlen(tmp);
	if (factor->prec > -1)
		factor->zero = 0;
	if (factor->prec == 0 && d == 0)
	{
		factor->str_len = 0;
		factor->str[0] = '\0';
	}
	compare_flag(factor);
	return (0);
}

int s_print(char *s, t_factor *factor)
{
	if (s == NULL)
	{
		s = "(null)";
		factor->str_len = 6;
	}
	else
		factor->str_len = ft_strlen(s);
	if (factor->prec != -1 && factor->prec < factor->str_len)
		factor->str_len = factor->prec;
	if (!(factor->str = malloc(sizeof(char) * (factor->str_len + 1))))
		return (1);
	ft_strlcpy(factor->str, s, factor->str_len + 1);
	return (0);
}

int c_print(int c, t_factor *factor)
{
	if (!(factor->str = malloc(sizeof(char) * 2)))
		return (1);
	factor->str[0] = c;
	factor->str[1] = '\0';
	factor->str_len = 1;
	if (c == '\0')
		factor->c_null = 1;
	return (0);
}
