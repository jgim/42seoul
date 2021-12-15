/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:12:18 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:47:19 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Receive stream node (contains filename) and do the following.
** 1 Expand environment valiables.
** 2 Clear quotation.
** 3 If there are spaces before and after string, remove spaces.
** 4 If there are spaces between strings
**   (or string is empty after expanded), put error.
*/

static size_t	pass_space_idx(char *filename, char *filequot)
{
	size_t	i;

	i = 0;
	while (filename[i] && \
		ft_isspace(filename[i]) && filequot[i] == '0')
		i++;
	return (i);
}

static size_t	get_filename_len(char *filename, char *filequot)
{
	size_t	i;

	i = 0;
	while (filename[i] && \
		(!ft_isspace(filename[i]) || filequot[i] != '0'))
		i++;
	return (i);
}

static char	*rm_isspace(char *filename, char *filequot)
{
	size_t	start;
	size_t	len;
	size_t	back;
	char	*clear_name;

	start = 0;
	len = 0;
	back = 0;
	start = pass_space_idx(filename, filequot);
	len = get_filename_len(filename + start, filequot + start);
	back = pass_space_idx(filename + start + len, filequot + start + len);
	if (filename[start + len + back])
		clear_name = NULL;
	else
		clear_name = ft_custom_substr(filename, start, len);
	free(filename);
	return (clear_name);
}

static int	check_filename(t_stream *stream, \
				char *filename, char *filequot, int is_null)
{
	filename = rm_isspace(filename, filequot);
	if (!filename || is_null)
	{
		ft_puterror(stream->str, "ambiguous redirect", NULL);
		free(filename);
		free(filequot);
		return (-1);
	}
	free(stream->str);
	free(stream->quot);
	stream->str = filename;
	stream->quot = filequot;
	return (0);
}

int	expand_filename(t_stream *stream, t_envlist *envlist)
{
	char		*doll_ptr;
	char		*filename;
	char		*filequot;
	int			is_null;
	size_t		len;

	filename = ft_custom_strdup(stream->str);
	filequot = get_quot_flag(filename);
	is_null = 0;
	doll_ptr = ft_strdoll(filename, filequot, filename);
	while (doll_ptr)
	{
		len = expansion_key_io(&filename, envlist, doll_ptr);
		free(filequot);
		filequot = get_quot_flag(filename);
		doll_ptr = ft_strdoll(filename + len, filequot, filename);
	}
	if (filename[0] == '\0')
		is_null++;
	if (ft_strchr(filequot, '1') || ft_strchr(filequot, '2'))
		clear_quot_filename(&filename, &filequot);
	return (check_filename(stream, filename, filequot, is_null));
}
