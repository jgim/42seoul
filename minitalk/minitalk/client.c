/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:33:47 by jgim              #+#    #+#             */
/*   Updated: 2021/08/31 02:45:38 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_msg(int pid, char *str)
{
	int		i;
	int		bit;
	int		len;

	ft_putstr(YELLOW"Sending a message to the server...\n"RESET);
	i = -1;
	len = ft_strlen(str);
	while (++i <= len)
	{
		bit = 1 << 7;
		while (bit)
		{
			if ((str[i] & bit && kill(pid, SIGUSR1) == -1)
				|| (!(str[i] & bit) && kill(pid, SIGUSR2) == -1))
			{
				ft_putstr(RED"This server doesn't exist\n"RESET);
				exit(1);
			}
			bit >>= 1;
			usleep(100);
		}
	}
}

int	check_pid(char *num)
{
	int	i;
	int	pid;

	i = -1;
	while (num[++i])
		if (num[i] < '0' && num[i] > '9')
			return (1);
	pid = ft_atoi(num);
	if (pid < 100 || pid > 99998)
		return (1);
	return (0);
}

static	void	end_handler(int signum)
{
	ft_putstr(PURPLE"Perfect Sending\n"RESET);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_putstr(RED"Usage: [./client][pid][message]\n"RESET);
	else if (check_pid(argv[1]))
		ft_putstr(RED"Invalid PID"RESET);
	else
	{
		signal(SIGUSR2, &end_handler);
		send_msg(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
