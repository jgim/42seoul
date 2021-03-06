/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:11:11 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:42:08 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Execute built-in commands.
** - unset
** - env
** - exit
*/

void	builtin_unset(t_execdata *data)
{
	size_t	i;

	i = 1;
	while (data->cmdline[i])
	{
		data->elst = ft_unsetenv(data->elst, data->cmdline[i]);
		i++;
	}
	g_status = 0;
}

void	builtin_env(t_execdata *data)
{
	t_envlist	*move;

	move = data->elst;
	while (move)
	{
		if (move->value)
			printf("%s=%s\n", move->key, move->value);
		move = move->next;
	}
	g_status = 0;
}

void	builtin_exit(t_execdata *data)
{
	bool	nonnum_check;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (data->cmdline[1])
	{
		g_status = (unsigned char)ft_atol(data->cmdline[1], &nonnum_check);
		if (nonnum_check)
		{
			ft_puterror("exit", data->cmdline[1], \
							"numeric argument required");
			g_status = 2;
		}
		else if (data->cmdline[2])
		{
			ft_puterror("exit", "too many arguments", NULL);
			g_status = 1;
			return ;
		}
	}
	exit(g_status);
}
