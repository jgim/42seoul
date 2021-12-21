#include "philosophers.h"

int	init(t_data *data)
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
		pthread_mutex_init(&data->forks[i++], NULL);
	data->dead = 0;
	data->end = 0;
	init_philo(data);
	return (0);
}

void	init_philo(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philo)
	{
		data->philo[i].data = data;
		data->philo[i].index = i + 1;
		data->philo[i].base_time = 0;
		data->philo[i].eat_count = 0;
		data->philo[i].end_eat = get_time();
		data->philo[i].left_fork = &data->forks[i];
		if (i + 1 == data->num_philo)
			data->philo[i].right_fork = &data->forks[0];
		else
			data->philo[i].right_fork = &data->forks[i + 1];
	}
}

int main(int argc, char **argv)
{
	t_data data;

	if (check_argv(argc, argv))
		return(-1);
	data = input_data(argc, argv);
	if (init(&data))
		return (-1);
	philosopy(&data);
	return (1);
}
