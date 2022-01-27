/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:08:52 by jgim              #+#    #+#             */
/*   Updated: 2022/01/27 10:57:09 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philosopy(t_data *data)
{
	int				i;
	t_philosophers	*philo;

	i = -1;
	philo = data->philo;
	data->base_time = get_time();
	while (++i < data->num_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == -1)
			return (-1);
		if (!philo[i].pid)
			start_philosopy(&philo[i]);
		usleep(100);
	}
	remove_philo(data);
	return (0);
}

void	remove_philo(t_data *data)
{
	int	i;
	int	wait;

	i = 0;
	while (i++ < data->num_philo)
	{
		waitpid(-1, &wait, 0);
		if (wait)
		{
			i = -1;
			while (++i < data->num_philo)
				kill(data->philo[i].pid, 15);
			break ;
		}
	}
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->eat_check);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/eat_check");
}

void	*start_philosopy(t_philosophers *philo)
{
	int		i;
	t_data	*data;

	i = 0;
	data = philo->data;
	philo->status = FORK;
	philo->eat_time = get_time();
	if (pthread_create(&philo->monitor, \
			NULL, &monitor, philo))
	{
		write(1, "Thread creation failed\n", 24);
		exit(1);
	}
	if (philo->index % 2)
		usleep(15000);
	while (!data->dead)
	{
		philo_life(philo);
		if (philo->eat_count >= data->must_eat && data->must_eat)
			break ;
	}
	pthread_join(philo->monitor, NULL);
	if (data->dead)
		exit(1);
	exit(0);
}

void	*monitor(void *old_philo)
{
	t_philosophers	*philo;
	t_data			*data;

	philo = (t_philosophers *)old_philo;
	data = philo->data;
	while (42)
	{
		sem_wait(data->eat_check);
		if (get_time() - philo->eat_time > data->time_to_die)
		{
			data->dead = 1;
			dead_time(philo);
			exit(1);
		}
		sem_post(data->eat_check);
		if (data->dead)
			break ;
		usleep(1000);
		if (data->must_eat && \
			philo->eat_count >= data->must_eat)
			break ;
	}
	return (0);
}
