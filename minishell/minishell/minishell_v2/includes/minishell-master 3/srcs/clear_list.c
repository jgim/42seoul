/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:10:46 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:56 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Clear lists that is defined in minishell.h
*/

void	clear_envlist(t_envlist *envlist)
{
	t_envlist	*next;

	while (envlist)
	{
		next = envlist->next;
		free(envlist->key);
		free(envlist->value);
		free(envlist);
		envlist = next;
	}
}

void	clear_tokenlist(t_token *list)
{
	t_token	*next;

	while (list)
	{
		next = list->next;
		free(list->str);
		free(list);
		list = next;
	}
}

static void	clear_cmdlist(t_cmdlist *list)
{
	t_cmdlist	*next;

	while (list)
	{
		next = list->next;
		free(list->str);
		free(list->quot);
		free(list);
		list = next;
	}
}

static void	clear_stream(t_stream *list)
{
	t_stream	*next;

	while (list)
	{
		next = list->next;
		xclose(list->open_fd);
		free(list->str);
		free(list->quot);
		free(list);
		list = next;
	}
}

void	clear_execdata(t_execdata *data)
{
	t_execdata	*next;

	while (data)
	{
		next = data->next;
		clear_cmdlist(data->clst);
		clear_stream(data->iolst);
		free_2d_array(data->cmdline);
		free(data);
		data = next;
	}
}
