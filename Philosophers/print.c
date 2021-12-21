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

void	print_philo(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	if (philo->data->dead || philo->data->end)
	{
		pthread_mutex_unlock(&philo->data->mutex_print);
		return ;
	}
	if (philo->status == FORK)
	{
		printf("%lldms %d has taken a fork\n",
			(get_time() - (philo->base_time)), philo->index);
	}
	else if (philo->status == EATING)
	{
		printf("%lldms %d has taken a fork\n",
			(get_time() - (philo->base_time)), philo->index);
		printf("%lldms %d is eating\n",
			(get_time() - (philo->base_time)), philo->index);
	}
	else if (philo->status == SLEEPING)
		printf("%lldms %d is sleeping\n",
			(get_time() - (philo->base_time)), philo->index);
	else if (philo->status == THINKING)
		printf("%lldms %d is thinking\n",
			(get_time() - (philo->base_time)), philo->index);
	pthread_mutex_unlock(&philo->data->mutex_print);
}


void dead_time(t_data *data, int i)
{
	long long current_time;

	pthread_mutex_lock(&data->mutex_print);
	printf("%lld %d died\n", current_time - data->philo[i].base_time, i + 1);
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
