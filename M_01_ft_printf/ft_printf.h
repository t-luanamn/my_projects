/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:03:07 by tluanamn          #+#    #+#             */
/*   Updated: 2023/09/07 10:12:16 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//help function
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//printf function
int		ft_printf(const char *format, ...);
int		ft_print_c(char c);
int		ft_print_id(int nb);
int		ft_print_p(size_t ptr);
int		ft_print_percent(void);
int		ft_print_s(char *s);
int		ft_print_u(unsigned int nb);
int		ft_print_x(unsigned int nb, char format);

#endif
