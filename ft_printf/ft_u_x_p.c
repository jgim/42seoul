/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_x_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:51:31 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:51:32 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int p_print(unsigned long long p, t_factor *factor)
{
	char *tmp;

	//printf("test : %llu\n", p);
	//printf("p_value : %llu\n", p);
	tmp = ft_lower_x_itoa(p, factor);
	//printf("p_tmp : %s\n", factor->str);
	factor->str_len = ft_strlen(tmp);
	if (factor->prec > -1)
		factor->zero = 0;
	if (factor->prec == 0 && p == 0)
	{
		factor->str_len = 0;
		factor->str[0] = '\0';
	}
	compare_flag(factor);
	return (0);
}

int upper_x_print(unsigned int x, t_factor *factor)
{
	char *tmp;

	tmp = ft_upper_x_itoa(x, factor);
	factor->str_len = ft_strlen(tmp);
	if (factor->prec > -1)
		factor->zero = 0;
	if (factor->prec == 0 && x == 0)
	{
		factor->str_len = 0;
		factor->str[0] = '\0';
	}
	compare_flag(factor);
	return (0);
}

int lower_x_print(unsigned int x, t_factor *factor)
{
	char *tmp;

	//printf("hi\n");
	tmp = ft_lower_x_itoa(x, factor);
	//printf("%s\n", tmp);
	factor->str_len = ft_strlen(tmp);
	if (factor->prec > -1)
		factor->zero = 0;
	if (factor->prec == 0 && x == 0)
	{
		factor->str_len = 0;
		factor->str[0] = '\0';
	}
	compare_flag(factor);
	return (0);
}

int u_print(unsigned int u, t_factor *factor)
{
	char *tmp;

	tmp = ft_itoa(u, factor);
	factor->str_len = ft_strlen(tmp);
	if (factor->prec > -1)
		factor->zero = 0;
	if (factor->prec == 0 && u == 0)
	{
		factor->str_len = 0;
		factor->str[0] = '\0';
	}
	compare_flag(factor);
	return (0);
}
