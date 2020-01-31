/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_control_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/31 23:20:53 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	control_type(t_status *status)
{
	if (status->fractal_type != 5)
		status->fractal_type++;
	else
		status->fractal_type = 1;
	reset_status(status);
}

void	control_iteration(t_status *status, int key)
{
	if (key == CHEVRON_RIGHT && status->iter < 1000)
		status->iter += 10;
	else if (key == CHEVRON_LEFT && status->iter > 10)
		status->iter -= 10;
}

void	control_colors(t_status *status)
{
	if (status->color_theme != 3)
		status->color_theme++;
	else
		status->color_theme = 0;
}

void	control_hide_info(t_status *status)
{
	if (status->hide_info == 0)
		status->hide_info++;
	else
		status->hide_info = 0;
}

void	control_device(t_global *global)
{
	if (global->status->device == 0)
		global->status->device++;
	else
		global->status->device = 0;
	clean_open_cl(global->open_cl);
	global->open_cl = init_open_cl(global->status->device);
}
