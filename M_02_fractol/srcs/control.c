/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 19:14:14 by tluanamn          #+#    #+#             */
/*   Updated: 2024/01/07 17:25:01 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection,
		fractol->img.pixels_ptr);
	mlx_clear_window(fractol->mlx_connection,
		fractol->mlx_window);
	mlx_destroy_window(fractol->mlx_connection,
		fractol->mlx_window);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractol *fractal)
{
	if (keysym == MAIN_PAD_ESC)
		close_handler(fractal);
	if (keysym == ARROW_LEFT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == ARROW_RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == ARROW_UP)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == ARROW_DOWN)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == MAIN_PAD_PLUS || keysym == NUM_PAD_PLUS)
		fractal->iterations_defintion += 10;
	else if (keysym == MAIN_PAD_MINUS || keysym == NUM_PAD_MINUS)
		fractal->iterations_defintion -= 10;
	fractol_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = scale(x, -2, 2, WIDTH) * fractol->zoom + fractol->shift_x;
	mouse_y = scale(y, 2, -2, HEIGHT) * fractol->zoom + fractol->shift_y;
	if (button == MOUSE_SCROLL_UP)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		fractol->zoom *= 1.05;
	}
	fractol->shift_x = mouse_x - scale(x, -2, 2, WIDTH) * fractol->zoom;
	fractol->shift_y = mouse_y - scale(y, 2, -2, HEIGHT) * fractol->zoom;
	fractol_render(fractol);
	return (0);
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "julia"))
	{
		fractol->julia_x = (scale(x, -2, +2, WIDTH) * fractol->zoom)
			+ fractol->shift_x;
		fractol->julia_y = (scale(y, +2, -2, HEIGHT) * fractol->zoom)
			+ fractol->shift_y;
		fractol_render(fractol);
	}
	return (0);
}
