/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:12:25 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:42:08 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_delimiter(char c)
{
	if (!(ft_isalnum(c) || c == '_'))
		return (true);
	else
		return (false);
}

char	*ft_strjoin_three(char *str1, char *str2, char *str3)
{
	char	*tmp;
	char	*ret;

	tmp = ft_custom_strjoin(str1, str2);
	ret = ft_custom_strjoin(tmp, str3);
	free(tmp);
	return (ret);
}

size_t	ft_strlen_excluded_quot(char *str, char *quot)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && quot[i] == '1')
			|| (str[i] == '\"' && quot[i] == '2'))
		{
			i++;
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

bool	is_delimiter_quot(char c, char flag)
{
	if (((c == '\'' && (flag == '1' || flag == 'S'))
			|| (c == '\"' && (flag == '2' || flag == 'D'))))
	{
		return (true);
	}
	else
		return (false);
}

size_t	get_space_idx(t_cmdlist *clist)
{
	size_t	i;

	i = 0;
	while (clist->str[i]
		&& (!ft_isspace(clist->str[i]) || clist->quot[i] != '0'))
		i++;
	return (i);
}
