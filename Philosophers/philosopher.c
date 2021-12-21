#include "philosophers.h"

void	philo_life(t_philosophers *philo)
{
	if (philo->status == FORK && !philo->data->dead)
	{
		meal(philo);
		philo->eat_count += 1;
		philo->status = SLEEPING;
		usleep(100);
	}
	else if (philo->status == SLEEPING)
	{
		philo->start_sleep = get_time();
		sleep_time(philo);
		philo->status = THINKING;
	}
	else if (philo->status == THINKING)
		think_time(philo);
}

void	meal(t_philosophers *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_philo(philo);
	philo->status = EATING;
	pthread_mutex_lock(philo->right_fork);
	philo->start_eat = get_time();
	eat_time(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	think_time(t_philosophers *philo)
{
	print_philo(philo);
	philo->status = FORK;
	usleep(100);
}

void	eat_time(t_philosophers *philo)
{
	unsigned long	current_time;

	print_philo(philo);
	current_time = get_time();
	while(current_time - philo->start_eat < philo->data->time_to_eat)
		current_time = get_time();
	philo->end_eat = current_time;
}

void	sleep_time(t_philosophers *philo)
{
	unsigned long	current_time;

	print_philo(philo);
	while(get_time() - philo->start_sleep < philo->data->time_to_sleep)
		usleep(100);
}

