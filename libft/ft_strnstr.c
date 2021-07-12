/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:26:49 by jgim              #+#    #+#             */
/*   Updated: 2020/11/12 21:40:01 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *stack, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	if (!*src)
		return ((char *)stack);
	if (len == 0)
		return (0);
	src_len = ft_strlen(src);
	i = 0;
	while (stack[i] != '\0' && i <= len - src_len)
	{
		j = 0;
		while (stack[i + j] == src[j])
		{
			if (j + 1 == src_len)
				return ((char *)&stack[i]);
			j++;
		}
		i++;
	}
	return (0);
}
