#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosophers t_philosophers;


enum	e_status
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
};

typedef struct	s_data
{
	int time_to_die;
	int num_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int end;
	int	dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	t_philosophers	*philo;
	pthread_t	monitor;
}				t_data;

typedef struct s_philosophers
{
	int	index;
	int	eat_count;
	int	check_time;
	int	status;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data	*data;
	unsigned long	base_time;
	unsigned long 	start_eat;
	unsigned long	end_eat;
	unsigned long	start_sleep;
	unsigned long	start_think;
}	t_philosophers;


#endif

/* eat */
void		philo_fork(t_philosophers **philo, int num_philo, int i);
void		putdown_forks(t_philosophers *philo);
void		hold_forks(t_philosophers *philo);
void		putdown_forks(t_philosophers *philo);
void		hold_forks(t_philosophers *philo);

/*philosophers*/
void		*start_philosopy(t_philosophers *philo);
void		philo_life(t_philosophers *philo);
void		think_time(t_philosophers *philo);
void		eat_time(t_philosophers *philo);
void		sleep_time(t_philosophers *philo);

/*print*/
int			print_error(t_data *data, char *str);
void		print_philo(t_philosophers *philo);
long long	get_time(void);

/*time*/
long long	get_time(void);

/*data_management*/
t_data		input_data(int argc, char **argv);
int			check_argv(int argc, char **argv);
int			check_valid_argument(char *str);


/*main*/
int			philosopy(t_data *data);
void		*monitor(t_data *data);
void		print_philo(t_philosophers *philo);
int			init_philo(t_data *data);
