/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:17:15 by jgim              #+#    #+#             */
/*   Updated: 2020/11/08 20:26:49 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (!dst || !src)
		return (0);
	i = ft_strlen(src);
	if (!dst)
		return (ft_strlen(src));
	if (dstsize)
	{
		len = (i >= dstsize) ? dstsize - 1 : i;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (i);
}
