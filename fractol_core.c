/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 02:45:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 02:02:24 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_colors(unsigned char o, unsigned char r, \
			unsigned char g, unsigned char b)
{
	return ((int)o << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

int 		get_color(int i, int iter_max, int color_theme)
{
	int			red;
	int			blue;
	int			green;
	double		n;

	n = (double)i / (double)iter_max;
	red = (int)(9 * (1 - n) * pow(n, 3) * 255);
	green = (int)(15 * pow((1 - n), 2) * pow(n, 2) * 255);
	blue = (int)(8.5 * pow((1 - n), 3) * n * 255);
	if (color_theme == 0)
		return (set_colors(0, red, blue, green));
	else if (color_theme == 1)
		return (set_colors(0, blue, green, red));
	else if (color_theme == 2)
		return (set_colors(0, blue, red, green));
	else if (color_theme == 3)
		return (set_colors(0, red, green, blue));
	return (0);
}

void	mandelbrot_start(t_status *status, int x)
{
	status->c_re = (status->x_min + x * status->d_re) / status->zoom;
	status->re = 0.0;
	status->im = 0.0;
	status->re2 = status->re * status->re;
	status->im2 = status->im * status->im;
}

// void	julia_start(t_status *status, int x, int y)
// {
// 	status->re = 1.5 * (x - IMG_SIZE_X / 2) / (0.5 * status->zoom * IMG_SIZE_X) + status->shift_x;
//     status->im = (y - IMG_SIZE_Y / 2) / (0.5 * status->zoom * IMG_SIZE_Y) + status->shift_y;
// 	status->re2 = status->re * status->re;
// 	status->im2 = status->im * status->im;
// }

int	iterator(t_status *status)
{
	int	i;
	i = -1;
	while (++i < status->iter_max && status->re2 + status->im2 < 4)
	{
		status->im = 2 * status->re * status->im + status->c_im;
		status->re = status->re2 - status->im2 + status->c_re;
		status->re2 = status->re * status->re;
		status->im2 = status->im * status->im;
	}
	return (i);
}

// void	julia(void *thread_data)
// {
// 	int x;
// 	int y;
// 	int i;

// 	t_status	*status;
// 	status = (t_status *)thread_data;
// 	y = status->y_start;
// 	while (++y <= status->y_end)
// 	{
// 		x = -1;
// 		while (++x < IMG_SIZE_X)
// 		{
// 			julia_start(status, x, y);
// 			i = iterator(status);
// 			status->data[IMG_SIZE_X * (y - 1) + x] = get_color(status->color_scheme, i);
// 		}
// 	}
// 	pthread_exit(0);
// }

void	mandelbrot(t_status *status)
{
	int x;
	int y;
	int i;

	status->d_re = (status->x_max - status->x_min) / IMG_SIZE_X;
	status->d_im = (status->y_max - status->y_min) / IMG_SIZE_Y;
	y = status->y_start;
	while (++y <= status->y_end)
	{
		x = -1;
		status->c_im = (status->y_max - y * status->d_im) / status->zoom;
		while (++x < IMG_SIZE_X)
		{
			mandelbrot_start(status, x);
			i = iterator(status);
			if (i >= status->iter_max)
				status->data[IMG_SIZE_X * (y - 1) + x] =
				get_color(i, status->iter_max, status->color_theme);
				// get_color(status->color_scheme, i * i * status->im / status->re);
			else
				status->data[IMG_SIZE_X * (y - 1) + x] =
				get_color(i, status->iter_max, status->color_theme);
				// get_color(status->color_scheme, i * i * status->im / status->re);
		}
	}
}

// int	sin_iterator(t_status *status)
// {
// 	int	i;
// 	i = -1;
// 	while (++i < status->iter_max && status->re2 + status->im2 < 4)
// 	{
// 		status->im = sin(status->re) * cosh(status->im) + status->c_im;
// 		status->re = cos(status->re) * sinh(status->im) + status->c_re;
// 		status->re2 = status->re * status->re;
// 		status->im2 = status->im * status->im;
// 	}
// 	return (i);
// }

// void	fractal_sin(void *thread_data)
// {
// 	int x;
// 	int y;
// 	int i;

// 	t_status	*status;
// 	status = (t_status *)thread_data;
// 	y = status->y_start;
// 		status->re = 1.5 * (x - IMG_SIZE_X / 2) / (0.5 * status->zoom * IMG_SIZE_X) + status->shift_x;
//     status->im = (y - IMG_SIZE_Y / 2) / (0.5 * status->zoom * IMG_SIZE_Y) + status->shift_y;
// 	while (++y <= status->y_end)
// 	{
// 		x = -1;
// 		while (++x < IMG_SIZE_X)
// 		{
// 			julia_start(status, x, y);
// 			i = sin_iterator(status);
// 			status->data[IMG_SIZE_X * (y - 1) + x] = get_color(status->color_scheme, i);
// 		}
// 	}
// 	pthread_exit(0);
// }