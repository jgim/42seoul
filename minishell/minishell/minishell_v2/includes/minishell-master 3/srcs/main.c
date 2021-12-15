/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:12:30 by silim             #+#    #+#             */
/*   Updated: 2021/09/30 20:42:08 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned char	g_status = 0;

void	minishell_loop(char **envp)
{
	t_envlist		*elst;
	t_execdata		*data;
	char			*line;

	elst = create_envlist(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			line = ft_custom_strdup("exit");
		if (line[0] != '\0')
		{
			data = parse_cmd(line, elst);
			execute_start(data);
			elst = data->elst;
			clear_execdata(data);
			add_history(line);
		}
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	custom_signal(SIGINT, signal_handler);
	custom_signal(SIGQUIT, SIG_IGN);
	minishell_loop(envp);
	(void)argc;
	(void)argv;
	return (g_status);
}
