#include "philosophers.h"

int	philosopy(t_data *data)
{
	int	i;
	pthread_t	thread;

	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
			(void *)start_philosopy, &data->philo[i]))
			return (write(1, "Thread creation failed\n", 24));
	}
	monitor((void *)data);
	i = 0;
	pthread_join(data->monitor, NULL);
	while (i < data->num_philo)
	{
		pthread_mutex_unlock(&data->forks[i]);
		pthread_join(data->philo[i++].thread, NULL);
	}
	i = 0;
	while (i <= data->num_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->philo);
	free(data->forks);
	return (0);
}

void	*start_philosopy(t_philosophers *philo)
{
	int i;

	i = 0;
	philo->base_time = get_time();
	if (!philo->end_eat)
		philo->end_eat = philo->base_time;
	philo->status = FORK;
	if (philo->index % 2 == 0)
		while (get_time()
			- philo->base_time < philo->data->time_to_eat)
			usleep(1000);
	while (philo->eat_count < philo->data->must_eat
		|| (philo->data->must_eat == 0 && philo->data->dead == 0))
		philo_life(philo);
	return (0);
}

void	*monitor(void *old_data)
{
	t_data *data;
	long long current_time;
	int	i;
	int end;

	data = (t_data *)old_data;
	while(1)
	{
		i = -1;
		end = 0;
		while (++i < data->num_philo)
		{
			current_time = get_time();
			if (data->must_eat && data->philo[i].eat_count == data->must_eat)
				if (++end == data->num_philo)
				{
					data->end = 1;
					return (0);
				}
			if (current_time - data->philo[i].end_eat > data->time_to_die)
			{
				dead_time(data, i);
				return (0);
			}
		}
	}
}