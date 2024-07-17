/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:02:54 by tluanamn          #+#    #+#             */
/*   Updated: 2023/09/07 10:12:08 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_print_c(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		i += ft_print_id(va_arg(args, int));
	else if (format == 'p')
		i += ft_print_p(va_arg(args, size_t));
	else if (format == '%')
		i += ft_print_percent();
	else if (format == 's')
		i += ft_print_s(va_arg(args, char *));
	else if (format == 'u')
		i += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		i += ft_print_x(va_arg(args, unsigned int), format);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			i += ft_format(args, *format);
		}
		else
			i += ft_print_c(*format);
		format++;
	}
	va_end(args);
	return (i);
}
