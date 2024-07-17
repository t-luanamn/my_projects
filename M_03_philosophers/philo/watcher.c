/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:15:12 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:44:37 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	all_threads_running(pthread_mutex_t *mutex, long *thread, int philo_nb)
{
	bool	res;

	res = false;
	handle_mutex(mutex, LOCK);
	if (*thread == philo_nb)
		res = true;
	handle_mutex(mutex, UNLOCK);
	return (res);
}

void	inc_thread(pthread_mutex_t *mutex, long *value)
{
	handle_mutex(mutex, LOCK);
	(*value)++;
	handle_mutex(mutex, UNLOCK);
}

// Avoid deadlock
void	think_or_sleep(t_philo *philo)
{
	if (philo->table->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			adv_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}

static bool	is_died(t_philo *philo)
{
	long	diff;
	long	t_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	diff = gettime(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_eat_time);
	t_die = philo->table->time_to_die / 1e3;
	if (diff > t_die)
		return (true);
	return (false);
}

void	*dinner_watcher(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_mutex,
			&table->threads_running_nbr, table->philo_nbr))
		;
	while (!simulation_finished(table))
	{
		i = -1;
		while (++i < table->philo_nbr && !simulation_finished(table))
		{
			if (is_died(table->philos + i))
			{
				set_bool(&table->table_mutex, &table->end_simulation, true);
				print_status(DIED, table->philos + i);
			}
		}
	}
	return (NULL);
}
