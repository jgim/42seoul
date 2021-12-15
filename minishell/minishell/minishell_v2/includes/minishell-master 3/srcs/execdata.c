/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:11:47 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:44:56 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Split tokenlist by pipe, and create execdata list.
** execdata has cmdlist, stream, and envlist.
** stream has the token related redirect.
** cmdlist has other token.
*/

static t_stream	*get_iolst(t_token *start, t_token *cur_token)
{
	t_stream	head;
	t_stream	*cur;

	head.next = NULL;
	cur = &head;
	while (start != cur_token)
	{
		if (!is_cmd(start))
		{
			cur = new_iolst(cur, start);
			if (cur->c_type >= IN_REDIRECT && cur->c_type <= APPEND_REDIRECT
				&& ft_isdigit(cur->str[0]))
			{
				cur = delimit_fd(cur);
			}
		}
		start = start->next;
	}
	return (head.next);
}

static t_cmdlist	*get_clst(t_token *start, t_token *cur_token)
{
	t_cmdlist	head;
	t_cmdlist	*cur;

	head.next = NULL;
	cur = &head;
	while (start != cur_token)
	{
		if (is_cmd(start))
		{
			cur = new_clst(cur, start);
		}
		start = start->next;
	}
	return (head.next);
}

static t_execdata	*new_execdata(t_execdata *cur, t_token *start,
		t_token *cur_token, t_envlist *envlist)
{
	t_execdata	*new;

	new = (t_execdata *)ft_custom_calloc(1, sizeof(*new));
	new->cmdline = NULL;
	new->std_fd[ORIGINAL_IN] = -42;
	new->std_fd[ORIGINAL_OUT] = -42;
	new->std_fd[ORIGINAL_ERR] = -42;
	new->clst = get_clst(start, cur_token);
	new->iolst = get_iolst(start, cur_token);
	new->elst = envlist;
	cur->next = new;
	return (new);
}

/*
** @(tokenlist)
**  command list splited by space or other operater like pipe.
** @(envlist)
**  list that has environment variable's key and value
** Create execdata from token list. Return the execdata.
*/

t_execdata	*create_execdata(t_token *tokenlist, t_envlist *envlist)
{
	t_execdata	head;
	t_execdata	*cur;
	t_token		*start;

	cur = &head;
	start = tokenlist;
	while (tokenlist)
	{
		if (tokenlist->special == PIPE)
		{
			cur = new_execdata(cur, start, tokenlist, envlist);
			start = tokenlist->next;
		}
		tokenlist = tokenlist->next;
	}
	cur = new_execdata(cur, start, tokenlist, envlist);
	return (head.next);
}
