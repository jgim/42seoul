/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:48:08 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:48:15 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_prec(t_factor *factor, char flag)
{
	if (flag == '*')
	{
		factor->prec = va_arg(factor->v_args, int);
		//	printf("hi\n");
	}
	else
	{
		factor->prec = factor->prec * 10 + (flag - '0');
		//	printf("atoi : %d\n", factor->prec);
	}
	if (factor->prec < 0)
		factor->prec = -1;
	//printf("flag_prec value : %d\n", factor->prec);
}

void flag_width(t_factor *factor, char flag)
{
	//printf("hi, i'm here\n");
	/*printf(">2 %d<\n", factor->width);*/
	if (flag == '*')
	{
		factor->width = va_arg(factor->v_args, int);
		if (factor->width < 0)
		{
			factor->minus = 1;
			factor->width *= -1;
			factor->zero = 0;
		}
	}
	else
		factor->width = factor->width * 10 + (flag - '0');
}

void flag_zero_minus(t_factor *factor, char flag)
{
	if (flag == '0' && (factor->minus == 0))
		factor->zero = 1;
	if (flag == '-')
	{
		factor->minus = 1;
		factor->zero = 0;
	}
}

void signal_printf(t_factor *factor, char flag)
{
	if (flag == '.')
	{
		factor->dot = 1;
		factor->prec = 0;
		// 문자열 처리를 할 때, .만 오는 경우를 해결하기 위해서 0으로 다시 초기화
	}
	//printf("%c\n", flag);
	if (ft_strchr("-", flag) != 0 && factor->dot == 0)
		flag_zero_minus(factor, flag);
	else if (ft_strchr("0", flag) != 0 && factor->dot == 0 && factor->width == 0)
		flag_zero_minus(factor, flag);
	else if (ft_strchr(WIDTH, flag) != 0 && factor->dot == 0)
		flag_width(factor, flag);
	else if (ft_strchr(PREC, flag) != 0 && factor->dot == 1)
	{
		flag_prec(factor, flag);
		//printf("prec value : %d\n", factor->prec);
	}
	//printf("prec value : %d\n", factor->prec);
}
