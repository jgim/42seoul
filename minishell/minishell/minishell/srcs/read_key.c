/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:06:52 by silim             #+#    #+#             */
/*   Updated: 2021/09/25 16:46:23 by silim            ###   ########.fr       */
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

	write(STDOUT_FILENO, &key, 1);
	if (key == BACKSPACE)
		delete_key(history->cmd);
	if (key == '\n')
		return (1);
	else if (key >= 32 && key < 127)
	{
		dummy_cmd = history->cmd;
		history->cmd = ft_strcjoin(dummy_cmd, key);
		free(dummy_cmd);
	}
	return (0);
}

int	read_key(t_history *history)
{
	char	key[3];

	while (read(0, &key, sizeof(key)))
	{
		if (key[0] == ESC && key[1] == KEYBOARD)
			search_history(history, key[2]);
		else if (read_general_key(key[0], history))
			break;
	}
	if (!history->cmd)
		return (0);
	return (1);
}
