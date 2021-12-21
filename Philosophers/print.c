/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:08:27 by jgim              #+#    #+#             */
/*   Updated: 2021/12/22 08:08:29 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_error(t_data *data, char *str)
{
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
	ft_putstr_fd(str, STDOUT_FILENO);
	return (-1);
}

void	print_philo(t_philosophers *philo, t_data *data)
{
	long long current_time;

	pthread_mutex_lock(&data->mutex_print);
	current_time = get_time();
	if (data->dead || data->end)
	{
		pthread_mutex_unlock(&data->mutex_print);
		return ;
	}
	if (philo->status == FORK)
	{
		printf("%lld %d has taken a fork\n",
			(current_time - (data->base_time)), philo->index);
		philo->status = EATING;
	}
	else if (philo->status == EATING)
	{
		printf("%lld %d has taken a fork\n",
			(current_time - (data->base_time)), philo->index);
		printf("%lld %d is eating\n",
			(current_time - (data->base_time)), philo->index);
	}
	else if (philo->status == SLEEPING)
		printf("%lld %d is sleeping\n",
			(current_time - (data->base_time)), philo->index);
	else if (philo->status == THINKING)
		printf("%lld %d is thinking\n",
			(current_time - (data->base_time)), philo->index);
	pthread_mutex_unlock(&data->mutex_print);
}


void dead_time(t_data *data, int i)
{
	long long current_time;

	pthread_mutex_lock(&data->mutex_print);
	printf("%lld %d died\n", current_time - data->base_time, i + 1);
	data->dead = 1;
	pthread_mutex_unlock(&data->mutex_print);
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		ms_time;

	gettimeofday(&tv, NULL);
	ms_time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (ms_time);
}
