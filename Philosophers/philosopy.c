/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:08:52 by jgim              #+#    #+#             */
/*   Updated: 2021/12/22 08:08:53 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philosopy(t_data *data)
{
	int			i;
	pthread_t	thread;

	i = -1;
	data->base_time = get_time();
	while (++i < data->num_philo)
	{
		data->philo[i].eat_time = get_time();
		if (pthread_create(&data->philo[i].thread, NULL,\
		(void *)start_philosopy, &data->philo[i]))
			return (write(1, "Thread creation failed\n", 24));
	}
	monitor((void *)data);
	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_unlock(&data->forks[i]);
	i = -1;
	while (++i < data->num_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		pthread_mutex_destroy(&data->forks[i++]);
	}
	free(data->philo);
	free(data->forks);
	return (0);
}

void	*start_philosopy(t_philosophers *philo)
{
	int	i;

	i = 0;
	philo->status = FORK;
	if (philo->index % 2)
		while (get_time() - philo->eat_time < philo->data->time_to_eat)
			usleep(100);
	while (philo->eat_count < philo->data->must_eat
		|| (philo->data->must_eat == 0 && philo->data->dead == 0))
		philo_life(philo);
	return (0);
}

void	*monitor(void *old_data)
{
	t_data		*data;
	long long	current_time;
	int			i;
	int			end;

	data = (t_data *)old_data;
	while (1)
	{
		i = -1;
		end = 0;
		while (++i < data->num_philo)
		{
			if (data->must_eat && data->philo[i].eat_count == data->must_eat)
			{
				if (++end == data->num_philo)
				{
					data->end = 1;
					return (0);
				}
			}
			current_time = get_time();
			if (current_time - data->philo[i].eat_time > data->time_to_die)
			{
				dead_time(data, i);
				return (0);
			}
		}
	}
}
