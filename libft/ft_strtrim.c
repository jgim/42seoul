/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 02:57:34 by jgim              #+#    #+#             */
/*   Updated: 2020/11/08 20:34:35 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	char	*str;
	int		len;

	start = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr((char *)set, s1[start]))
		start++;
	while (len && ft_strchr((char *)set, s1[len]))
		len--;
	if (start >= len)
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len - start + 2))))
		return (0);
	ft_strlcpy(str, s1 + start, len - start + 2);
	return (str);
}
