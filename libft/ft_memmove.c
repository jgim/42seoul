/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:08:23 by jgim              #+#    #+#             */
/*   Updated: 2020/11/08 21:15:06 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (src >= dst)
		while (i < size)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	else if (src < dst)
		while (size)
		{
			size--;
			((unsigned char *)dst)[size] = ((unsigned char*)src)[size];
		}
	return (dst);
}
