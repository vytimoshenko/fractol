/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_check_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/30 02:30:57 by mperseus         ###   ########.fr       */
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

void	reset_status(t_status *status)
{
	status->color_theme = 0;
	status->iter = 50;
	status->zoom = 300;
	status->x_shift = 0;
	status->y_shift = 0;
	status->julia_x = 0;
	status->julia_y = 0;
	// status->julia_x = (double)IMG_SIZE_X / 2;
	// status->julia_y = (double)IMG_SIZE_X / 2;
	status->pause = 1;
	if (status->fractal_type == MANDELBROT)
		status->fractal_name = "Mandelbrot";
	else if (status->fractal_type == JULIA)
		status->fractal_name = "Julia";
	else if (status->fractal_type == BURNING_SHIP)
		status->fractal_name = "Burning ship";
	else if (status->fractal_type == SPIDER)
		status->fractal_name = "Spider";
	else if (status->fractal_type == SIN)
		status->fractal_name = "Sin";
}

void	check_argument(t_status *status, char *argv)
{
	if (ft_atoi(argv) == MANDELBROT)
		status->fractal_type = 1;
	else if (ft_atoi(argv) == JULIA)
		status->fractal_type = 2;
	else if (ft_atoi(argv) == BURNING_SHIP)
		status->fractal_type = 3;
	else if (ft_atoi(argv) == SPIDER)
		status->fractal_type = 4;
	else if (ft_atoi(argv) == SIN)
		status->fractal_type = 5;
	else
		error_wrong_argument();
}

void	error_wrong_argument(void)
{
	ft_putendl("usage:");
	ft_putendl("\tmandelbrot\t1");
	ft_putendl("\tjulia\t\t2");
	ft_putendl("\tburning ship\t3");
	ft_putendl("\tspider\t\t4");
	ft_putendl("\tsin\t\t5");
	exit(1);
}
