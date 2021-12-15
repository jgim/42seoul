#include "philosophers.h"

int	print_error(t_data *data, char *str)
{
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
	ft_putstr_fd(STDOUT_FILENO, str);
	return (-1);
}

void	print_philo(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%lldms %d ",
		(get_time() - (philo->base_time)), philo->index);
	if (philo->status == FORK)
		write(STDOUT_FILENO, "has taken a fork\n", 18);
	else if (philo->status == EATING)
		write(STDOUT_FILENO, "is eating\n", 11);
	else if (philo->status == SLEEPING)
		write(STDOUT_FILENO, "is sleeping\n", 13);
	else if (philo->status == THINKING)
		write(STDOUT_FILENO, "is thinking\n", 13);
	pthread_mutex_unlock(&philo->data->mutex_print);
}


