/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:42:53 by silim             #+#    #+#             */
/*   Updated: 2021/09/26 15:05:32 by silim            ###   ########.fr       */
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
		ft_putstr_fd("\b \b", STDOUT_FILENO);
}

t_history	*search_history(t_history *history, char key, int *arrow_count)
{
	if (history->cmd)
			delete_str(ft_strlen(history->cmd));
	if (key == UP && history->up)
	{
		(*arrow_count)++;
		history = history->up;
	}
	else if (key == DOWN && history->down)
	{
		(*arrow_count)--;
		history = history->down;
	}
	else if (key == DOWN && !(history->down))
		write(0, BEEP, 1);
	ft_putstr_fd(history->cmd, STDOUT_FILENO);
	return (history);
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

t_history	*expire_history(t_history *history)
{
	if (history->count >= 1)
	{
		history = history->up;
		free(history->down);
		history->down = 0;
	}
	else
	{
		free(history);
		history = 0;
	}
	return (history);
}
