/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:08:10 by jgim              #+#    #+#             */
/*   Updated: 2022/01/27 10:58:13 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init(t_data *data)
{
	data->dead = 0;
	init_sema(data);
	init_philo(data);
	return (0);
}

void	init_sema(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/eat_check");
	data->forks = sem_open("/forks", O_RDONLY | \
					O_CREAT, 0664, data->num_philo);
	if (data->forks == SEM_FAILED)
		print_error("semaphore error");
	data->print = sem_open("/print", O_RDONLY | \
					O_CREAT, 0664, 1);
	if (data->print == SEM_FAILED)
		print_error("semaphore error");
	data->eat_check = sem_open("/eat_check", O_RDONLY | \
					O_CREAT, 0664, 1);
	if (data->eat_check == SEM_FAILED)
		print_error("semaphore error");
}

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		data->philo[i].data = data;
		data->philo[i].index = i + 1;
		data->philo[i].eat_count = 0;
		data->philo[i].eat_time = 0;
		data->philo[i].start_sleep = 0;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_argv(argc, argv))
		return (-1);
	input_data(&data, argc, argv);
	if (init(&data))
		return (-1);
	if (philosopy(&data))
		return (write(1, "Invalid number of arguments\n", 29));
	return (1);
}
