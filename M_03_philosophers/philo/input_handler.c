/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:52:55 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 13:43:04 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("Only positive values accepted.");
	if (!is_digit(*str))
		error_exit("Only a correct digit accepted.");
	number = str;
	while (is_digit(*str))
	{
		++len;
		++str;
	}
	if (len == 0 || *str != '\0')
		error_exit("Invalid input. Only a correct digit is accepted.");
	if (len > 10)
		error_exit("INT_MAX is the limit.");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
		error_exit("INT_MAX is the limit.");
	return (num);
}

// 1e3 = 1000
// 6e4 = 60000
void	handle_input(t_table *table, char **av)
{
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
}
