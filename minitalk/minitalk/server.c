/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:33:54 by jgim              #+#    #+#             */
/*   Updated: 2021/08/22 18:33:55 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	end_message(void)
{
	ft_putstr("\n");
	ft_putstr(GREEN"\n       ...( ﾟ▽ﾟ)/...      \n"RESET);
	ft_putstr(GREEN"\n...received the message...\n"RESET);
	ft_putstr("\n");
}

void	convert_signal(int sig_num, siginfo_t *info, void *value)
{
	static int		c = 0;
	static int		bit = 0;
	static int		i = 0;

	(void)value;
	if (i == 0)
	{
		ft_putstr(GREEN"\n_____ start chatting _____\n"RESET);
		ft_putstr("\n");
		i++;
	}
	if (sig_num == SIGUSR1)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR2);
			end_message();
		}
		c = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_action;
	int					pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr("server PID : "YELLOW);
		ft_putnbr(pid);
		ft_putstr("\n"RESET);
		sig_action.sa_flags = SA_SIGINFO;
		sig_action.sa_sigaction = convert_signal;
		while (1)
		{
			sigaction(SIGUSR2, &sig_action, NULL);
			sigaction(SIGUSR1, &sig_action, NULL);
			pause();
		}
	}
	else
	{
		ft_putstr(RED"Invalid argument\n");
		ft_putstr("Usage: [./server]\n"RESET);
	}
	return (0);
}
