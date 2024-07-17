/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:21:53 by tluanamn          #+#    #+#             */
/*   Updated: 2024/01/07 17:28:32 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
Scale the set to fit the screen
(new_max-new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min
	*** old_min = 0 *** So, it can skip when passing arg
*/
double	scale(double unscaled_num, double new_min, double new_max,
			double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0)
		+ new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2.0 * z.x * z.y;
	return (result);
}

t_complex	mandelbar_square(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = -2.0 * z.x * z.y;
	return (result);
}
