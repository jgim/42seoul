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

int	print_error(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(0);
}

void	print_philo(t_philosophers *philo, t_data *data)
{
	sem_wait(data->print);
	if (data->dead)
	{
		sem_post(data->print);
		return ;
	}
	if (philo->status == FORK)
		printf("%lld %d has taken a fork\n",
			(get_time() - (data->base_time)), philo->index);
	else if (philo->status == EATING)
	{
		printf("%lld %d is eating\n",
			(get_time() - (data->base_time)), philo->index);
	}
	else if (philo->status == SLEEPING)
		printf("%lld %d is sleeping\n",
			(get_time() - (data->base_time)), philo->index);
	else if (philo->status == THINKING)
		printf("%lld %d is thinking\n",
			(get_time() - (data->base_time)), philo->index);
	sem_post(data->print);
}

void	dead_time(t_philosophers *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->print);
	printf("%lld %d died\n", \
			get_time() - data->base_time, philo->index);
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		ms_time;

	gettimeofday(&tv, NULL);
	ms_time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (ms_time);
}
