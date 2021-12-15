#include "philosophers.h"

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
		|| philo->data->must_eat == 0)
		philo_life(philo);
}

void	philo_life(t_philosophers *philo)
{
	if (philo->status == FORK)
	{
		hold_forks(philo);
		philo->start_eat = get_time();
		eat_time(philo);
		putdown_forks(philo);
		philo->eat_count += 1;
		philo->end_eat = get_time();
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
	philo->eat_count++;
	while(current_time - philo->start_eat < philo->data->time_to_eat)
		current_time = get_time();
}

void	sleep_time(t_philosophers *philo)
{
	unsigned long	current_time;

	print_philo(philo);
	while(get_time() - philo->start_sleep < philo->data->time_to_sleep)
		usleep(100);
}

