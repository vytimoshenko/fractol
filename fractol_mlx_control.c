/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 03:36:25 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

// void	control_shift(t_status *status, int key)
// {
// 	if (key == A && status->x_shift >= -IMG_SIZE_X / 2)
// 		status->x_shift -= 0.1 * IMG_SIZE_X;
// 	if (key == D && status->x_shift <= IMG_SIZE_X / 2)
// 		status->x_shift += 0.1 * IMG_SIZE_X;
// 	if (key == W && status->y_shift >= -IMG_SIZE_Y / 2)
// 		status->y_shift -= 0.1 * IMG_SIZE_X;
// 	if (key == S && status->y_shift <= IMG_SIZE_Y / 2)
// 		status->y_shift += 0.1 * IMG_SIZE_X;
// }

// void	control_mouse_shift(t_status *status, int x, int y)
// {
// 	if (status->middle_mouse_button == 1)
// 	{
// 		status->x_move = status->x_shift - x;
// 		status->y_move = status->y_shift - y;
// 		status->middle_mouse_button = 2;
// 	}
// 	if (status->middle_mouse_button == 2)
// 	{
// 		status->x_shift = status->x_move + x;
// 		status->y_shift = status->y_move + y;
// 	}
// }

void	control_shift(t_status *status, int key)
{
	if (key == ARROW_DOWN)
		status->c_im += 0.1;
	if (key == ARROW_UP)
		status->c_im -= 0.1;
	if (key == ARROW_RIGHT)
		status->c_re += 0.1;
	if (key == ARROW_LEFT)
		status->c_re -= 0.1;
	if (key == CHEVRON_RIGHT)
		status->iter += 10;
	if (key == CHEVRON_LEFT)
		status->iter -= 10;
}

void	control_zoom(t_status *status, int key)
{
	if (key == MOUSE_SCROLL_UP || key == PLUS)
		status->zoom *= 1.1;
	if (key == MOUSE_SCROLL_DOWN || key == MINUS)
		status->zoom /= 1.1;
}

void	control_colors(t_status *status)
{
	if (status->color_theme != 3)
		status->color_theme++;
	else
		status->color_theme = 0;
}
