/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:17:53 by silim             #+#    #+#             */
/*   Updated: 2021/09/23 17:21:23 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*is_newline(char *str)
{
	int			i;
	int			str_len;

	if (!str)
		return (0);
	i = 0;
	str_len = ft_strlen(str);
	while (i < str_len + 1)
	{
		if (str[i] == '\n')
			return (str + i);
		++i;
	}
	return (0);
}
