#include "philosophers.h"

void	philo_life(t_philosophers *philo)
{
	t_data *data;

	data = philo->data;
	if (philo->status == FORK && !philo->data->dead)
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
	pthread_mutex_lock(philo->left_fork);
	print_philo(philo, data);
	philo->status = EATING;
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->data->mutex_eat);
	philo->start_eat = get_time();
	eat_time(philo, data);
	pthread_mutex_unlock(&philo->data->mutex_eat);
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
	unsigned long	current_time;

	print_philo(philo, data);
	current_time = get_time();
	while(current_time - philo->start_eat < philo->data->time_to_eat)
		current_time = get_time();
	philo->end_eat = current_time;
}

void	sleep_time(t_philosophers *philo, t_data *data)
{
	unsigned long	current_time;

	print_philo(philo, data);
	while(get_time() - philo->start_sleep < philo->data->time_to_sleep)
		usleep(100);
}

