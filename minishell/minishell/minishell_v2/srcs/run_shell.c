/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:24:27 by silim             #+#    #+#             */
/*   Updated: 2021/09/26 02:06:02 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	@file run_shell.c
**	@description  Define functions to run a shell.
*/

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_putstr_fd("\npogning_shell > ", STDOUT_FILENO);
	else if (signo == SIGQUIT)
	{
		if (global.pid > 0)
		{
			ft_putstr_fd("[1]    ", STDOUT_FILENO);
			ft_putnbr_fd(global.pid, STDOUT_FILENO);
			ft_putstr_fd(" quit", STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd("Quit\b\b\b\b", STDERR_FILENO);
		}
	}
}

t_history	*prompt(t_history *history)
{
	ft_putstr_fd("pogning_shell > ", STDOUT_FILENO);
	history = new_history(history);
	if (!read_key(history))
		history = expire_history(history);
	signal(SIGINT, (void *)sig_handler);
	signal(SIGQUIT, (void *)sig_handler);
	return(history);
}

/*v
**	@description  Initialize environment variables in a shell structure.
**	@param  A Shell structure and environment variable arrays.
*/

void	run_shell(t_shell *shell)
{
	while (shell->status != INTERNAL_ERROR)
	{
		shell->history = prompt(shell->history);
		//if (check_syntax(shell, cmd) != ARG_ERROR
		//	&& parse_cmd(shell, cmd) != ARG_ERROR)
		//	execute_cmd(shell);
		//free(cmd);
	}
	//ft_exit(shell, cmd);
}

//void	execute_cmd(t_shell **shell)
//{

//}

//void	parse_argument()
//{

//}
