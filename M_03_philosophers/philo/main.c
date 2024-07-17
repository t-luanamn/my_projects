/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:12:55 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:43:14 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
test1:The philosopher should not eat and should die.
		./philo 1 800 200 200
test2:No philosopher should die.
		./philo 5 800 200 200
test3:No philosopher should die and the simulation should stop 
	when every philosopher has eaten at least 7 times.
		./philo 5 800 200 200 7
test4:No philosopher should die.
		./philo 4 410 200 200
test5:One philosopher should die?.
		./philo 4 310 200 100
*/
int	main(int ac, char **av)
{
	t_table	table;

	if (5 == ac || 6 == ac)
	{
		handle_input(&table, av);
		initialise(&table);
		simulation(&table);
		clean(&table);
	}
	else
	{
		error_exit("Wrong input");
	}
}
