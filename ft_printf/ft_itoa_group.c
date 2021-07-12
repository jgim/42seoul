/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:51:45 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:51:47 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t n_len(unsigned int num)
{
	size_t i;

	i = 0;
	if (num < 0)
		i = 1;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

size_t x_n_len(unsigned long long num)
{
	size_t i;

	i = 0;
	if (num < 0)
		i = 1;
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char *ft_itoa(unsigned int n, t_factor *factor)
{
	size_t len;
	long nbr;

	nbr = n;
	len = n_len(nbr);
	if (nbr == 0)
	{
		factor->str = ft_strdup("0");
		return (factor->str);
	}
	if (!(factor->str = malloc(sizeof(char) * (len + 1))))
		return (0);
	factor->str[len--] = '\0';
	while (nbr)
	{
		factor->str[len--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (factor->str);
}

char *ft_upper_x_itoa(unsigned long long n, t_factor *factor)
{
	size_t len;
	unsigned long long nbr;

	nbr = n;
	len = x_n_len(nbr);
	if (nbr == 0)
	{
		factor->str = ft_strdup("0");
		return (factor->str);
	}
	if (!(factor->str = malloc(sizeof(char) * (len + 1))))
		return (0);
	factor->str[len--] = '\0';
	while (nbr)
	{
		factor->str[len--] = "0123456789ABCDEF"[nbr % 16];
		nbr /= 16;
	}
	return (factor->str);
}

char *ft_lower_x_itoa(unsigned long long n, t_factor *factor)
{
	size_t len;
	unsigned long long nbr;

	//printf("int n value : %llu\n", n);
	nbr = n;
	len = x_n_len(nbr);
	if (nbr == 0)
	{
		factor->str = ft_strdup("0");
		return (factor->str);
	}
	if (!(factor->str = malloc(sizeof(char) * (len + 1))))
		return (0);
	factor->str[len--] = '\0';
	while (nbr)
	{
		factor->str[len--] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	//printf("itoa : %s\n", factor->str);
	return (factor->str);
}
