/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:51:23 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:51:25 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void factor_set(t_factor *factor)
{
	factor->minus = 0;
	factor->zero = 0;
	factor->width = 0;
	factor->prec = -1;
	factor->dot = 0;
	factor->type = 0;
	factor->sign = 0;
	factor->str_len = 0;
	factor->c_null = 0;
	factor->str = NULL;
}

int check_printf(t_factor *factor)
{
	int rtn;

	rtn = 0;
	while (*(factor->format) != '\0')
	{
		while (*(factor->format) != '%' && *(factor->format) != '\0')
			rtn += ft_putchar(*(factor->format)++);
		if (*(factor->format) == '%')
		{
			factor_set(factor);
			while (*++(factor->format) != '\0' && !(ft_strchr(TYPE, *(factor->format))))
				signal_printf(factor, *(factor->format));
			if (*(factor->format) && (ft_strchr(TYPE, *(factor->format))) == 1)
				factor->type = *(factor->format)++;
			rtn += refine_type(factor);
		}
	}
	free(factor);
	return (rtn);
}

int ft_printf(const char *format, ...)
{
	int rtn;
	t_factor *factor;

	factor = NULL;
	if (!format)
		return (-1);
	if (!(factor = malloc(sizeof(t_factor))))
		return (0);
	factor->format = (char *)format;
	va_start(factor->v_args, format);
	rtn = check_printf(factor);
	va_end(factor->v_args);
	return (rtn);
}
