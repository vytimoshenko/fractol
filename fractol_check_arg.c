/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_status_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 19:12:39 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			check_argument(char *arg)
{
	int fractal_type;

	fractal_type = 0;
	if (!(ft_strcmp(arg, (char *)"mandelbrot")))
			fractal_type = 1;
	else if (!(ft_strcmp(arg, (char *)"julia")))
			fractal_type = 2;
	// else if (!(ft_strcmp(arg, (char *)"sin")))
	// 		flag = 3;
	return (fractal_type);
}

void		error_wrong_argument(void)
{
	ft_putendl("usage: fractol mandelbrot / julia");
	ft_putendl("example: fractol mandelbrot");
	exit(1);
}
