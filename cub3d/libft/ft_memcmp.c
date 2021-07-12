/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:13:31 by jgim              #+#    #+#             */
/*   Updated: 2020/10/01 20:57:54 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *word1;
	unsigned char *word2;

	word1 = (unsigned char *)s1;
	word2 = (unsigned char *)s2;
	while (n--)
	{
		if (*word1 != *word2)
			return (*word1 - *word2);
		word1++;
		word2++;
	}
	return (0);
}
