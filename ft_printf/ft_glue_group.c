/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glue_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:51:10 by jgim              #+#    #+#             */
/*   Updated: 2021/02/26 18:51:16 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void *ft_memcpy(void *dst, const void *src, size_t num)
{
	unsigned char *dest;
	unsigned char *source;
	size_t i;

	if (!dst && !src)
		return (0);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

char *ft_strdup(const char *s1)
{
	int i;
	int len;
	char *dup;

	len = 0;
	while (s1[len])
		len++;
	dup = malloc(len + 1);
	if (dup)
	{
		i = 0;
		while (s1[i])
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

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

char *ft_strjoin_left(char const *s1, char const *s2)
{
	int s1_len;
	int s2_len;
	char *str;
	int i;
	int j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char *ft_strjoin_right(char const *s1, char const *s2)
{
	int s1_len;
	int s2_len;
	char *str;
	int i;
	int j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = -1;
	if (!(str = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	free((char *)s1);
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
