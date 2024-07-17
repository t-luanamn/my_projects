/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:53:18 by tluanamn          #+#    #+#             */
/*   Updated: 2023/09/07 10:11:50 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_x(unsigned int nb, char format)
{
	if (nb >= 16)
	{
		ft_put_x(nb / 16, format);
		ft_put_x(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_len(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_print_x(unsigned int nb, char format)
{
	int	i;

	i = 1;
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (i);
	}
	i = ft_len(nb);
	ft_put_x(nb, format);
	return (i);
}
