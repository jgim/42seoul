/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:45:05 by silim             #+#    #+#             */
/*   Updated: 2021/09/24 20:49:56 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	@file main.c
**	@description  If there is a new command, show a prompt.
*/

/*
**	@description  Initialize environment variables in a shell structure.
**	@param  A Shell structure and environment variable arrays.
*/

static void	init_envp(t_shell *shell, char **envp)
{
	int	count;
	int	index;

	count = 0;
	while (envp[count])
		count++;
	shell->env = (char **)malloc(sizeof(char *) * (count + 1));
	if (!shell->env)
		exit(0);
	index = -1;
	while(envp[++index])
		shell->env[index] = ft_strdup(envp[index]);
	shell->env[index] = 0;
	shell->env_size = count;
}

/*
**	@description  Initializes a shell struct to run a shell.
**	@param  A Shell structure pointer and environment variable arrays.
*/

static void	init_shell(t_shell	*new_shell, char **envp)
{
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	init_envp(new_shell, envp);
	new_shell->status = SUCCESS;
	new_shell->history = NULL;
}

/*
**	@description  If the environment variable does not exist, exits with builtin-exit, and if there is, a new prompt window is opened.
**	@return 0
**	@param  Since // 문자열에 공백, <, >는 계속 올 수 있는데 그리고 |가 오면 에러'ac' and 'av' are not used, these are void. 'envp' an array of pointers to environment variables.
*/

int	main(int ac, char **av, char **envp)
{
	t_shell	new_shell;

	(void)ac, (void)av;
	init_shell(&new_shell, envp);
	run_shell(&new_shell);
	return (0);
}
