/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:29:44 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:43:30 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_status status, t_philo *philo)
{
	long	diff;

	diff = gettime(MILLISECOND) - philo->table->start_simulation;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	handle_mutex(&philo->table->print_mutex, LOCK);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& !simulation_finished(philo->table))
		printf(W"%-6ld"B"Philo %d has taken a fork\n"RST, diff, philo->id);
	else if ((status == RETURN_FIRST_FORK || status == RETURN_SECOND_FORK)
		&& !simulation_finished(philo->table))
		printf(W"%-6ld"G"Philo %d has return a fork\n"RST, diff, philo->id);
	else if (status == EATING && !simulation_finished(philo->table))
		printf(W"%-6ld"C"Philo %d is eating\n"RST, diff, philo->id);
	else if (status == SLEEPING && !simulation_finished(philo->table))
		printf(W"%-6ld"Y"Philo %d is sleeping\n"RST, diff, philo->id);
	else if (status == THINKING && !simulation_finished(philo->table))
		printf(W"%-6ld"M"Philo %d is thinking\n"RST, diff, philo->id);
	else if (status == DIED)
		printf(R"%-6ldPhilo %d died\n"RST, diff, philo->id);
	handle_mutex(&philo->table->print_mutex, UNLOCK);
}
