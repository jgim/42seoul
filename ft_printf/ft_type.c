/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:48:49 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:48:52 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int refine_type(t_factor *factor)
{
	int i;

	i = 0;
	if (factor->type == 'c')
		i = c_print(va_arg(factor->v_args, int), factor);
	if (factor->type == '%')
		i = c_print('%', factor);
	if (factor->type == 's')
		i = s_print(va_arg(factor->v_args, char *), factor);
	if (factor->type == 'd' || factor->type == 'i')
		i = d_print(va_arg(factor->v_args, int), factor);
	if (factor->type == 'u')
		i = u_print(va_arg(factor->v_args, unsigned int), factor);
	if (factor->type == 'x')
		i = lower_x_print(va_arg(factor->v_args, unsigned int), factor);
	if (factor->type == 'X')
		i = upper_x_print(va_arg(factor->v_args, unsigned int), factor);
	if (factor->type == 'p')
		i = p_print(va_arg(factor->v_args, unsigned long long), factor);
	if (i == 1 || factor->type == 0)
		return (-1);
	join_width(factor);
	ft_putstr(factor);
	return (factor->str_len);
}
