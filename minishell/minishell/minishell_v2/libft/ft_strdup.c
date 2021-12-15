/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:46:21 by silim             #+#    #+#             */
/*   Updated: 2021/09/26 02:13:41 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_mem;
	size_t	len;

	len = 0;
	new_mem = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new_mem)
		return (0);
	while (s[len])
	{
		new_mem[len] = s[len];
		len++;
	}
	new_mem[len] = '\0';
	return (new_mem);
}
