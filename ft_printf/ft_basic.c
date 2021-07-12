/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:49:51 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:49:53 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (*s == 0 && *s != c)
		return (0);
	return (1);
}

void ft_putstr(t_factor *factor)
{
	if (factor->str != NULL)
	{
		factor->rtn += factor->str_len;
		if (factor->c_null == 1 && factor->minus == 1)
		{
			write(1, "\0", 1);
			write(1, factor->str, (factor->str_len) - 1);
		}
		else if (factor->c_null == 1 && factor->minus == 0)
		{
			write(1, factor->str, factor->str_len - 1);
			write(1, "\0", 1);
		}
		else
			write(1, factor->str, factor->str_len);
	}
}
