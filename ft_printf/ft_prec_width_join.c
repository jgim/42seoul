/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_width_join.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:48:32 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:48:36 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void join_zero_blank(int i, char *zb, t_factor *factor)
{
	while (i-- > 0)
	{
		if (factor->minus == 0)
			factor->str = ft_strjoin_left(zb, factor->str);
		else
			factor->str = ft_strjoin_right(factor->str, zb);
		factor->str_len++;
	}
}

void join_width(t_factor *factor)
{
	int i;

	if (factor->sign == 1)
		factor->str_len++;
	if (factor->type == 'p')
		factor->str_len += 2;
	i = factor->width - factor->str_len;
	if (factor->zero == 1)
		join_zero_blank(i, "0", factor);
	if (factor->sign == 1)
		factor->str = ft_strjoin_left("-", factor->str);
	if (factor->type == 'p')
	{
		factor->str = ft_strjoin_left("0x", factor->str);
	}
	if (factor->zero == 0)
	{
		i = factor->width - factor->str_len;
		join_zero_blank(i, " ", factor);
	}
}

void join_prec(t_factor *factor)
{
	int i;

	i = factor->prec - factor->str_len;
	while (i-- > 0)
	{
		factor->str = ft_strjoin_left("0", factor->str);
		factor->str_len++;
	}
}

void compare_flag(t_factor *factor)
{
	if (factor->prec > factor->str_len && factor->prec > factor->width)
		factor->width = 0;
	else if (factor->str_len >= factor->prec && factor->str_len >= factor->width)
	{
		factor->prec = -1;
		factor->width = 0;
	}
	else if (factor->width > factor->str_len)
		if (factor->str_len >= factor->prec)
			factor->prec = -1;
	if (factor->prec > 0)
		join_prec(factor);
}
