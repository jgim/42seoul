/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:13:27 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:44 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	size_t	i;

	str = (char *)s;
	ch = (char)c;
	i = ft_strlen(str);
	while (1)
	{
		if (str[i] == ch)
			return (&str[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
