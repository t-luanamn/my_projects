/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:27:43 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:42:41 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*adv_malloc(size_t bytes)
{
	void	*res;

	res = malloc(bytes);
	if (res == NULL)
		error_exit("Error with malloc");
	return (res);
}

static void	fork_init(t_philo *philo, t_fork *forks,
		int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->eat_count = 0;
		handle_mutex(&philo->philo_mutex, INIT);
		philo->table = table;
		fork_init(philo, table->forks, i);
	}
}

void	initialise(t_table *table)
{
	int		i;

	i = -1;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->threads_running_nbr = 0;
	table->philos = adv_malloc(table->philo_nbr * sizeof(t_philo));
	table->forks = adv_malloc(table->philo_nbr * sizeof(t_fork));
	handle_mutex(&table->print_mutex, INIT);
	handle_mutex(&table->table_mutex, INIT);
	while (++i < table->philo_nbr)
	{
		handle_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}
