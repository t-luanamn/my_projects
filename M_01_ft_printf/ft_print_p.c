/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:52:28 by tluanamn          #+#    #+#             */
/*   Updated: 2023/09/07 10:11:14 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(size_t ptr)
{
	char	*hex_char;
	char	buffer[20];
	int		len;
	int		i;

	hex_char = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	len = 2;
	if (ptr == 0)
		return (ft_putchar_fd('0', 1), len + 1);
	i = 0;
	while (ptr)
	{
		buffer[i++] = hex_char[ptr % 16];
		ptr /= 16;
	}
	while (--i >= 0)
	{
		ft_putchar_fd(buffer[i], 1);
		len++;
	}
	return (len);
}
