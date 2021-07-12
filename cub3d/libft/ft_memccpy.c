/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 22:40:45 by jgim              #+#    #+#             */
/*   Updated: 2020/11/12 21:42:26 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	word;
	size_t			i;

	a = dst;
	b = (unsigned char *)src;
	word = c;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (a[i] == word)
			return (a + (i + 1));
		i++;
	}
	return (0);
}
