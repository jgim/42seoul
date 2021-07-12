/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:01:02 by jgim              #+#    #+#             */
/*   Updated: 2020/11/12 21:42:44 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*str;
	unsigned char	alpha;
	size_t			i;

	i = 0;
	str = ptr;
	alpha = value;
	while (i < num)
	{
		str[i] = alpha;
		i++;
	}
	return (str);
}
