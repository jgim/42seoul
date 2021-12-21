/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:08:44 by jgim              #+#    #+#             */
/*   Updated: 2021/12/22 08:08:45 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_life(t_philosophers *philo)
{
	t_data	*data;

	data = philo->data;
	if (philo->status == FORK)
	{
		meal(philo, data);
		philo->eat_count += 1;
		philo->status = SLEEPING;
	}
	else if (philo->status == SLEEPING)
	{
		philo->start_sleep = get_time();
		sleep_time(philo, data);
		philo->status = THINKING;
	}
	else if (philo->status == THINKING)
		think_time(philo, data);
}

void	meal(t_philosophers *philo, t_data *data)
{
	if (philo->index % 2 == 0)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	print_philo(philo, data);
	if (philo->index % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	eat_time(philo, data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	think_time(t_philosophers *philo, t_data *data)
{
	print_philo(philo, data);
	philo->status = FORK;
	usleep(100);
}

void	eat_time(t_philosophers *philo, t_data *data)
{
	print_philo(philo, data);
	philo->eat_time = get_time();
	while (get_time() - philo->eat_time < philo->data->time_to_eat)
		usleep(100);
}

void	sleep_time(t_philosophers *philo, t_data *data)
{
	long long	current_time;

	print_philo(philo, data);
	while (get_time() - philo->start_sleep < philo->data->time_to_sleep)
		usleep(100);
}
