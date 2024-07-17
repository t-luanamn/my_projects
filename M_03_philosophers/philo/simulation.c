/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:27:27 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:43:48 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, bool status)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!status)
		print_status(THINKING, philo);
	if (philo->table->philo_nbr % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	adv_usleep(t_think * 0.50, philo->table);
}

void	*alone(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	waiting_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_eat_time, gettime(MILLISECOND));
	inc_thread(&philo->table->table_mutex,
		&philo->table->threads_running_nbr);
	print_status(TAKE_FIRST_FORK, philo);
	while (!simulation_finished(philo->table))
		adv_usleep(200, philo->table);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	handle_mutex(&philo->first_fork->fork, LOCK);
	print_status(TAKE_FIRST_FORK, philo);
	handle_mutex(&philo->second_fork->fork, LOCK);
	print_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_eat_time, gettime(MILLISECOND));
	philo->eat_count++;
	print_status(EATING, philo);
	adv_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&& philo->eat_count == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	handle_mutex(&philo->first_fork->fork, UNLOCK);
	print_status(RETURN_FIRST_FORK, philo);
	handle_mutex(&philo->second_fork->fork, UNLOCK);
	print_status(RETURN_SECOND_FORK, philo);
}

static void	*dinner_simulation(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	waiting_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_eat_time, gettime(MILLISECOND));
	inc_thread(&philo->table->table_mutex,
		&philo->table->threads_running_nbr);
	think_or_sleep(philo);
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		print_status(SLEEPING, philo);
		adv_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo, false);
	}
	return (NULL);
}

void	simulation(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		handle_thread(&table->philos[0].thread_id, alone,
			&table->philos[0], CREATE);
	else
		while (++i < table->philo_nbr)
			handle_thread(&table->philos[i].thread_id, dinner_simulation,
				&table->philos[i], CREATE);
	handle_thread(&table->watcher, dinner_watcher, table, CREATE);
	table->start_simulation = gettime(MILLISECOND);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->philo_nbr)
		handle_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&table->table_mutex, &table->end_simulation, true);
	handle_thread(&table->watcher, NULL, NULL, JOIN);
}
