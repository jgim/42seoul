/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 08:08:20 by jgim              #+#    #+#             */
/*   Updated: 2021/12/22 08:08:22 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data	t_data;

enum	e_status
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	END
};

typedef struct s_philosophers
{
	pid_t			pid;
	int				index;
	int				eat_count;
	int				check_time;
	int				status;
	pthread_t		monitor;
	long long		eat_time;
	long long		start_sleep;
	long long		start_think;
	t_data			*data;
}					t_philosophers;

typedef struct s_data
{
	int				time_to_die;
	int				num_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				end;
	int				dead;
	long long		base_time;
	sem_t			*eat_check;
	sem_t			*forks;
	sem_t			*print;
	t_philosophers	philo[200];
}					t_data;

/* philosopy */
int			philosopy(t_data *data);
void		remove_philo(t_data *data);
void		*start_philosopy(t_philosophers *philo);
void		*monitor(void *philo);

/*philosophers*/
void		philo_life(t_philosophers *philo);
void		meal(t_philosophers *philo, t_data *data);
void		think_time(t_philosophers *philo, t_data *data);
void		eat_time(t_philosophers *philo, t_data *data);
void		sleep_time(t_philosophers *philo, t_data *data);

/*print*/
int			print_error(char *str);
void		print_philo(t_philosophers *philo, t_data *data);
long long	get_time(void);
void		dead_time(t_philosophers *philo);

/*data_management*/
void		input_data(t_data *data, int argc, char **argv);
int			check_argv(int argc, char **argv);
int			check_valid_argument(char *str);

/*main*/
int			init(t_data *data);
void		init_sema(t_data *data);
void		init_philo(t_data *data);

/*utils*/
int			ft_atoi(char *str);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);

#endif
