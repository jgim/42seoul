/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:08:33 by jgim              #+#    #+#             */
/*   Updated: 2021/12/22 08:08:34 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_valid_argument(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if ('0' > *str || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

t_data	input_data(int argc, char **argv)
{
	t_data	data;

	data.num_philo = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.must_eat = 0;
	if (argc == 6)
		data.must_eat = ft_atoi(argv[5]);
	return (data);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 6)
		if (!ft_atoi(argv[5]))
			return (1);
	if (argc == 5)
		if (!ft_atoi(argv[1]))
			return (1);
	if (!(argc == 5 || argc == 6))
		return (write(1, "Invalid number of arguments\n", 29));
	while (argv[++i])
	{
		if (check_valid_argument(argv[i]))
			return (write(1, "Invalid argument\n", 18));
	}
	return (0);
}
