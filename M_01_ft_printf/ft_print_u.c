/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:53:07 by tluanamn          #+#    #+#             */
/*   Updated: 2023/09/07 10:11:41 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_u(unsigned int nb)
{
	if (nb > 9)
		ft_print_u(nb / 10);
	ft_putchar_fd(nb % 10 + '0', 1);
}

int	ft_print_u(unsigned int nb)
{
	int	i;

	ft_put_u(nb);
	i = 1;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
