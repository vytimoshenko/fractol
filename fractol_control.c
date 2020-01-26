/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 22:40:51 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_cursor_position(t_status *status, int x, int y)
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

// void	control_rotation(t_status *status, int key)
// {
// 	if (key == ARROW_DOWN && rad_to_deg(status->x_angle) < 180)
// 		status->x_angle += deg_to_rad(5);
// 	if (key == ARROW_UP && rad_to_deg(status->x_angle) > -180)
// 		status->x_angle -= deg_to_rad(5);
// 	if (key == ARROW_RIGHT && rad_to_deg(status->y_angle) < 180)
// 		status->y_angle += deg_to_rad(5);
// 	if (key == ARROW_LEFT && rad_to_deg(status->y_angle) > -180)
// 		status->y_angle -= deg_to_rad(5);
// 	if (key == CHEVRON_RIGHT && rad_to_deg(status->z_angle) < 180)
// 		status->z_angle += deg_to_rad(5);
// 	if (key == CHEVRON_LEFT && rad_to_deg(status->z_angle) > -180)
// 		status->z_angle -= deg_to_rad(5);
// }
