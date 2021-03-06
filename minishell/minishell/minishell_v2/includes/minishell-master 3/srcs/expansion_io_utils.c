/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_io_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:12:14 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:42:08 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	expansion_key_io(char **line, \
		t_envlist *envlist, char *doll_ptr)
{
	char	*key;
	char	*value;
	char	*front_key;
	char	*back_key;
	size_t	len;

	len = 1;
	while (!is_delimiter(doll_ptr[len]))
		len++;
	front_key = ft_custom_substr(*line, 0, doll_ptr - *line);
	key = ft_custom_substr(doll_ptr, 1, len - 1);
	back_key = ft_custom_substr(doll_ptr + len, 0, ft_strlen(doll_ptr + len));
	value = ft_getenv(envlist, key);
	free(*line);
	*line = ft_strjoin_three(front_key, value, back_key);
	len = ft_strlen(front_key) + ft_strlen(value);
	free(front_key), free(key), free(back_key);
	return (len);
}

void	clear_quot_filename(char **filename, char **filequot)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new_str = ft_custom_calloc(\
			ft_strlen_excluded_quot(*filename, *filequot) + 1, \
			sizeof(char));
	while ((*filename)[i])
	{
		if (is_delimiter_quot((*filename)[i], (*filequot)[i]))
		{
			i++;
			continue ;
		}
		new_str[j++] = (*filename)[i++];
	}
	free(*filename);
	*filename = new_str;
	*filequot = get_removed_endflag(filequot, '1');
	*filequot = get_removed_endflag(filequot, '2');
}
