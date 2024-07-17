/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:31:56 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:44:25 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	waiting_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		;
}

void	handle_thread(pthread_t *thread, void *(*routine)(void *),
		void *data, t_status status)
{
	if (status == CREATE)
		pthread_create(thread, NULL, routine, data);
	else if (status == JOIN)
		pthread_join(*thread, NULL);
	else if (status == DETACH)
		pthread_detach(*thread);
	else
		error_exit("Wrong status for handle_thread.");
}

void	handle_mutex(pthread_mutex_t *mutex, t_status status)
{
	if (status == LOCK)
		pthread_mutex_lock(mutex);
	else if (status == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (status == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (status == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		error_exit("Wrong status for handle_mutex.");
}
