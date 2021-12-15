/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:42:53 by silim             #+#    #+#             */
/*   Updated: 2021/09/26 01:04:34 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	@file history.c
**	@description  Update and manage history statement.
*/

void	delete_str(int str_len)
{
	while(str_len--)
	{
		ft_putstr_fd("\b \b", STDOUT_FILENO);
		// ft_putstr_fd("시은이 내꺼", STDOUT_FILENO);
	}
}

int	search_history(t_history *history, char key)
{
	if (key == UP && history->up)
	{
		if (history->cmd)
			delete_str(ft_strlen(history->cmd));
		ft_putstr_fd(history->up->cmd, STDOUT_FILENO);
		history->cmd = history->up->cmd;
		history = history->up;
	}
	else if (key == DOWN && history->down)
	{
		ft_putstr_fd("its down\n", STDOUT_FILENO);
		if (history->cmd)
			delete_str(ft_strlen(history->cmd));
		ft_putstr_fd(history->down->cmd, STDOUT_FILENO);
		history = history->down;
	}
	return (0);
}

t_history	*new_history(t_history *old_history)
{
	t_history	*new_history;

	new_history = init_history();
	if (old_history)
	{
		new_history->up = old_history;
		old_history->down = new_history;
		new_history->count = old_history->count + 1;
	}
	else
		old_history = new_history;
	return (new_history);
}

t_history	*init_history(void)
{
	t_history *new_history;

	new_history = malloc(sizeof(t_history));
	new_history->cmd = NULL;
	new_history->up = NULL;
	new_history->down = NULL;
	new_history->count = 0;
	return(new_history);
}

void	expire_history(t_history *history)
{
	ft_putstr_fd("\nupdate history\n", STDOUT_FILENO);
	if (history->count >= 1)
	{
		ft_putstr_fd("\nup history exists\n", STDOUT_FILENO);
		history = history->up;
		free(history->down);
		history->down = 0;
	}
	else
	{
		ft_putstr_fd("\nno up history\n", STDOUT_FILENO);
		free(history);
		history = 0;
	}
}
