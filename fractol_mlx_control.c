/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/31 21:31:33 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	control_zoom(t_status *status, int key)
{
	if (key == PLUS)
		status->zoom *= 1.25;
	else if (key == MINUS)
		status->zoom /= 1.25;
}

void	control_mouse_zoom(t_status *status, int x, int y, int key)
{
	double	tmp;
	
	tmp = status->zoom;
	if (key == MOUSE_SCROLL_UP)
		status->zoom *= 1.25;
	else if (key == MOUSE_SCROLL_DOWN)
		status->zoom /= 1.25;
	if (tmp < status->zoom)
	{
		status->x_shift -= (status->m_x - x) * 1.25 / status->zoom;
		status->y_shift -= (status->m_y - y) * 1.25 / status->zoom;
	}
	else
	{
		status->x_shift -= (status->m_x - x) / 1.25 / status->zoom;
		status->y_shift -= (status->m_y - y) / 1.25 / status->zoom;
	}
	status->m_x = x;
	status->m_y = y;
}

void	get_mouse_position(t_status *status, int x, int y)
{
	status->x_mouse_position = x;
	status->y_mouse_position = y;
	if (x < 0 || y < 0 || x > IMG_SIZE_X || y > IMG_SIZE_Y)
	{
		status->x_mouse_position = 0;
		status->y_mouse_position = 0;
	}
}

void	control_shift(t_status *status, int key)
{
	if (key == ARROW_DOWN)
		status->y_shift -= 20 / status->zoom;
	else if (key == ARROW_UP)
		status->y_shift += 20 / status->zoom;
	else if (key == ARROW_RIGHT)
		status->x_shift -= 20 / status->zoom;
	else if (key == ARROW_LEFT)
		status->x_shift += 20 / status->zoom;
}

void	control_mouse_shift(t_status *status, int x, int y)
{
	if (status->middle_mouse_button == 1)
	{
		status->x_move = status->x_shift + x / status->zoom;
		status->y_move = status->y_shift + y / status->zoom;
		status->middle_mouse_button = 2;
	}
	if (status->middle_mouse_button == 2)
	{
		status->x_shift = status->x_move - x / status->zoom;
		status->y_shift = status->y_move - y / status->zoom;
	}
}

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
