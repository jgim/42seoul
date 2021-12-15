/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:21:28 by silim             #+#    #+#             */
/*   Updated: 2021/09/25 16:01:57 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char *str, char c)
{
	char	*new_str;
	size_t	i;
	
	if (!str)
	{
		new_str = malloc(sizeof(char) * 2);
		new_str[0] = c;
		new_str[1] = '\0';
	}
	else
	{
		if (!(new_str = malloc(sizeof(char) * (ft_strlen(str) + 2))))
			return (0);
		i = -1;
		while (++i < ft_strlen(str))
			new_str[i] = str[i];
		new_str[i++] = c;
		new_str[i] = '\0';
	}
	return (new_str);
}
