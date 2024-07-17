/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:12:19 by tluanamn          #+#    #+#             */
/*   Updated: 2024/01/07 17:24:18 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <OpenGL/gl.h>
# include "./minilibx_opengl/mlx.h"
# include "./Libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR_MESSAGE "Error: Please enter the correct fractol\n"

//Window size
# define WIDTH	800
# define HEIGHT	800

//Colours
# define BLACK				0x000000
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BLUE				0x0000FF
# define MAGENTA_BURST		0xFF00FF
# define LIME_SHOCK			0xCCFF00
# define NEON_ORANGE		0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM			0x33CCCC
# define HOT_PINK			0xFF66B2
# define ELECTRIC_BLUE		0x0066FF
# define LAVA_RED			0xFF3300

//Key MacOS
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78
# define MAIN_PAD_ESC		53
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27

//Complex number
//x = real;
//y = imag;
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		size_line;
}	t_img;
typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;

// Controls
int			key_handler(int key, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			julia_motion(int x, int y, t_fractol *fractol);

// Main
void		fractol_init(t_fractol *fractol);
void		fractol_render(t_fractol *fractol);

//Math
double		scale(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
t_complex	mandelbar_square(t_complex z);

//Utils
double		ft_atodbl(char *s);

#endif
