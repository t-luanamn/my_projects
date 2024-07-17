/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:13:03 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:41:59 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include <limits.h>

# define RST	"\033[0m"
# define R		"\033[1;31m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"
# define B		"\033[1;34m"
# define M		"\033[1;35m"
# define C		"\033[1;36m"
# define W		"\033[1;37m"

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	bool			full;
	long			last_eat_time;
	pthread_t		thread_id;
	pthread_mutex_t	philo_mutex;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_table			*table;
}	t_philo;

struct s_table
{
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limit_meals;
	long			philo_nbr;
	long			start_simulation;
	bool			end_simulation;
	bool			all_threads_ready;
	long			threads_running_nbr;
	pthread_t		watcher;
	t_fork			*forks;
	t_philo			*philos;
	pthread_mutex_t	table_mutex;
	pthread_mutex_t	print_mutex;
};

// Use enum instead of macro
typedef enum e_status
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	RETURN_FIRST_FORK,
	RETURN_SECOND_FORK,
	DIED,
}	t_status;

typedef enum e_time_code
{
	MILLISECOND,
	MICROSECOND,
}	t_time_code;

void	initialise(t_table *table);
void	simulation(t_table *table);
void	thinking(t_philo *philo, bool status);

void	clean(t_table *table);
void	error_exit(const char *msg);
void	print_status(t_status status, t_philo *philo);

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
long	get_long(pthread_mutex_t *mutex, long *value);
void	set_long(pthread_mutex_t *mutex, long *dst, long value);
bool	simulation_finished(t_table *table);
time_t	gettime(int time_code);
void	adv_usleep(long usec, t_table *table);

void	handle_input(t_table *table, char **av);
void	handle_thread(pthread_t *thread, void *(*routine)(void *),
			void *data, t_status status);
void	handle_mutex(pthread_mutex_t *mutex, t_status status);
void	waiting_threads(t_table *table);

void	*dinner_watcher(void *data);
void	think_or_sleep(t_philo *philo);
void	inc_thread(pthread_mutex_t *mutex, long *value);
bool	all_threads_running(pthread_mutex_t *mutex, long *thread, int philo_nb);

#endif
