#include "philosophers.h"

int main(int argc, char **argv)
{
	t_data data;

	if (check_argv(argc, argv))
		return(-1);
	data = input_data(argc, argv);
	if (init_philo(&data))
		return (-1);
	philosopy(&data);
	return (1);
}

int	philosopy(t_data *data)
{
	int	i;
	pthread_t	thread;

	i = 0;
	if (pthread_create(&data->monitor, \
		NULL, &monitor, (void *)data))
		return (write(1, "Thread creation failed\n", 24));
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
			(void *)start_philosopy, &data->philo[i++]))
			return (write(1, "Thread creation failed\n", 24));
	}
	i = 0;
	phread_join(data->monitor, NULL);
	while (i < data->num_philo)
		pthread_join(data->philo[i++].thread, NULL);
	i = 0;
	while (i <= data->num_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->philo);
	free(data->forks);
	return (0);
}

void	*monitor(void *old_data)
{
	t_data *data;
	long long current_time;
	int	i;

	data = (t_data *)old_data;
	while(1)
	{
		i = 0;
		data->dead = 0;
		while (i < data->num_philo)
		{
			current_time = get_time();
			if (data->must_eat && data->philo[i].eat_count == data->must_eat)
			{
				data->end = 1;
				return (0);
			}
			if (current_time - data->philo[i].end_eat)
			data->dead = 1;
			return (0);
		}
	}

}

int	init_philo(t_data *data)
{
	int i;

	i = 0;
	data->philo = malloc \
		(data->num_philo * sizeof(t_philosophers));
	data->forks = malloc \
		(data->num_philo * sizeof(pthread_mutex_t));
	if (!data->philo || !data->forks)
		return(print_error(data, "malloc error"));
	pthread_mutex_init(&data->mutex_print, NULL);
	while (i < data->num_philo)
	{
		data->philo[i].data = data;
		data->philo[i].index = i + 1;
		data->philo[i].base_time = 0;
		data->philo[i].eat_count = 0;
		philo_fork(&data->philo, data->num_philo, i++);
	}
	return (0);
}
