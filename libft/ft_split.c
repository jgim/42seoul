/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 02:57:34 by jgim              #+#    #+#             */
/*   Updated: 2020/11/14 11:32:19 by gimjongse        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		delimiter(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void		*free_word(char **word)
{
	int	i;
	i = -1;
	while (word[++i])
		free(word[i]);
	free(word);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**src;
	int		end;
	int		j;
	int		start;

	if (!s)
		return (0);
	if (!(src = malloc(sizeof(char *) * (delimiter(s, c) + 1))))
		return (0);
	end = 0;
	while (s[end] == c)
		++end;
	j = -1;
	while (s[end] && ++j < delimiter(s, c))
	{
		start = end;
		while (s[end] != c && s[end])
			end++;
		if (!(src[j] = ft_substr(s, start, end - start)))
			return (free_word(src));
		while (s[end] == c)
			end++;
	}
	src[j] = 0;
	return (src);
}
