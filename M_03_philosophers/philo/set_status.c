/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:20:49 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:43:38 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	handle_mutex(mutex, LOCK);
	*dest = value;
	handle_mutex(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	res;

	handle_mutex(mutex, LOCK);
	res = *value;
	handle_mutex(mutex, UNLOCK);
	return (res);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	res;

	handle_mutex(mutex, LOCK);
	res = *value;
	handle_mutex(mutex, UNLOCK);
	return (res);
}

void	set_long(pthread_mutex_t *mutex, long *dst, long value)
{
	handle_mutex(mutex, LOCK);
	*dst = value;
	handle_mutex(mutex, UNLOCK);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
