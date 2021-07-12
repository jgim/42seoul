/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:50:12 by jgim              #+#    #+#             */
/*   Updated: 2021/01/05 16:50:31 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == 0 && *s != c)
		return (0);
	return ((char *)s);
}

char		*ft_strdup(const char *s1)
{
	int	i;
	int	len;
	char	*dup;

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

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;
	size_t	end;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	end = start + len;
	while (start < end && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int	s1_len;
	int	s2_len;
	char	*str;
	int	i;
	int	j;

	if (!s1 || !s2)
		return (0);
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
