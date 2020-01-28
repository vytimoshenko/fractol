/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_check_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 21:55:50 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void		assign_fractal(t_status *status)
// {
// 	status->iter_max = 20;
// 	status->x_min = -2.5;
// 	status->x_max = 2.4;
// 	status->y_min = -1.5;
// 	status->y_max = 1.5;
// 	status->c_re = -0.70176;
//     status->c_im = -0.3842;
// 	status->y_start = 0;
// 	status->y_end = IMG_SIZE_Y;
// 	// if (status->fractal_type == 3)
// 	// {
// 	// 	status->c_re = 1.17462;
//     // 	status->c_im = 0.427525;
// 	// }
// 	status->zoom = 1;
// }

void		assign_fractal(t_status *status)
{
	status->color_theme = 0;
	status->iter = 40;
	status->zoom = 150;
	status->dy = 0;
	status->dx = 0;
	status->ms_y = 0;
	status->ms_x = 0;
	status->pause = 1;
	status->m_y = (double)IMG_SIZE_X / 2;
	status->m_x = (double)IMG_SIZE_X / 2;
}

int			check_argument(char *arg)
{
	int fractal_type;

	fractal_type = 0;
	if (!(ft_strcmp(arg, (char *)"mandelbrot")))
		fractal_type = 1;
	else if (!(ft_strcmp(arg, (char *)"julia")))
		fractal_type = 2;
	else if (!(ft_strcmp(arg, (char *)"spider")))
		fractal_type = 3;
	else if (!(ft_strcmp(arg, (char *)"sin")))
		fractal_type = 4;
	return (fractal_type);
}

void		error_wrong_argument(void)
{
	ft_putendl("usage: fractol mandelbrot / julia / spider / sin");
	ft_putendl("example: fractol spider");
	exit(1);
}
