#include "philosophers.h"

void	philo_fork(t_philosophers **philo, int num_philo, int i)
{
	pthread_mutex_init(philo[i]->left_fork, NULL);
	if (i == num_philo - 1)
		philo[i]->right_fork = &philo[0]->left_fork;
	else
		philo[i]->right_fork = &philo[i + 1]->left_fork;
}

void	putdown_forks(t_philosophers *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	hold_forks(t_philosophers *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	print_philo(philo);
	philo->status = EATING;
}
