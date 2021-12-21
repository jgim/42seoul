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
	DIED,
	END
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

/* philosopy */
int			philosopy(t_data *data);
void		*start_philosopy(t_philosophers *philo);
void		*monitor(void *old_data);

/*philosophers*/
void		philo_life(t_philosophers *philo);
void		meal(t_philosophers *philo);
void		think_time(t_philosophers *philo);
void		eat_time(t_philosophers *philo);
void		sleep_time(t_philosophers *philo);

/*print*/
int			print_error(t_data *data, char *str);
void		print_philo(t_philosophers *philo);
long long	get_time(void);
void 		dead_time(t_data *data, int i);

/*data_management*/
t_data		input_data(int argc, char **argv);
int			check_argv(int argc, char **argv);
int			check_valid_argument(char *str);


/*main*/
int			init(t_data *data);
void		init_philo(t_data *data);

/*utils*/
int			ft_atoi(char *str);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);

#endif
