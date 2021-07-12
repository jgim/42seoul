/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 09:59:12 by jgim              #+#    #+#             */
/*   Updated: 2020/11/12 21:28:38 by gimjongse        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int num)
{
	size_t		i;

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

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nbr;

	nbr = n;
	len = n_len(nbr);
	if (nbr == 0)
		return (ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	else
	{
		str[len--] = '\0';
		if (nbr < 0)
		{
			str[0] = '-';
			nbr *= -1;
		}
	}
	while (nbr)
	{
		str[len--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}
