/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:22:37 by tluanamn          #+#    #+#             */
/*   Updated: 2024/01/07 17:28:02 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	assign_fractol_value(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "julia"))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.x = (scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (scale(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	assign_fractol_value(&z, &c, fractol);
	while (++i < fractol->iterations_defintion)
	{
		if (!ft_strcmp(fractol->name, "mandelbar"))
			z = sum_complex(mandelbar_square(z), c);
		else
			z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = scale(i, BLACK, WHITE, fractol->iterations_defintion);
			put_pixel(x, y, &fractol->img, color);
			return ;
		}
	}
	put_pixel(x, y, &fractol->img, WHITE);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection,
		fractol->mlx_window, fractol->img.img_ptr, 0, 0);
}
