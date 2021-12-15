/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:06:52 by silim             #+#    #+#             */
/*   Updated: 2021/09/26 14:51:10 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_key(char *str)
{
	size_t str_len;

	if (!str)
		return;
	str_len = ft_strlen(str);
	if (str_len)
	{
		ft_putstr_fd("\b \b", STDOUT_FILENO);
		str[--str_len] = '\0';
	}
}

int		read_general_key(char key, t_history *history)
{
	char *dummy_cmd;

	if (key == BACKSPACE)
		delete_key(history->cmd);
	if (key == '\n')
	{
		write(STDOUT_FILENO, &key, 1);
		return (1);
	}
	else if (key >= 32 && key < 127)
	{
		write(STDOUT_FILENO, &key, 1);
		dummy_cmd = history->cmd;
		history->cmd = ft_strcjoin(dummy_cmd, key);
		free(dummy_cmd);
	}
	return (0);
}

int	read_key(t_history *history)
{
	char	key[3];
	char	*temp;
	int		arrow_count;

	arrow_count = 0;
	while (read(0, &key, sizeof(key)))
	{
		if (key[0] == ESC && key[1] == KEYBOARD)
			history = search_history(history, key[2], &arrow_count);
		else if (read_general_key(key[0], history))
		{
			if(arrow_count)
			{
				temp = history->cmd;
				while(arrow_count--)
					history = history->down;
				history->cmd = ft_strdup(temp);
			}
			break;
		}
	}
	if (!history->cmd)
		return (0);
	return (1);
}
