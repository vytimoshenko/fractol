/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:44:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 21:01:39 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	get_cursor_position(global->status, x, y);
	// control_mouse_shift(global->status, x, y);
	redraw(global);
	return (0);
}

// int		mouse_key_press(int key, int x, int y, void *param)
// {
// 	t_global	*global;

// 	(void)x;
// 	(void)y;
// 	global = (t_global *)param;
// 	if (key == MIDDLE_MOUSE_BUTTON)
// 		global->status->middle_mouse_button = 1;
// 	if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
// 		control_scale(global->status, key);
// 	redraw(global);
// 	return (0);
// }

// int		mouse_key_release(int key, int x, int y, void *param)
// {
// 	t_global	*global;

// 	(void)x;
// 	(void)y;
// 	global = (t_global *)param;
// 	if (key == MIDDLE_MOUSE_BUTTON)
// 		global->status->middle_mouse_button = 0;
// 	return (0);
// }

int		keyboard_key_press(int key, void *param)
{
	(void)param;
	// t_global	*global;

	// global = (t_global *)param;
	// control_shift(global->status, key);
	// control_rotation(global->status, key);
	// control_scale(global->status, key);
	// control_z_scale(global->status, key);
	// control_projections(global->status, key);
	// control_perspective(global->status, key);
	// if (key == C)
	// 	control_colors(global->map, global->status);
	// if (key == R)
	// 	full_reset(global->map, global->status);
	// redraw(global);
	if (key == ESC)
		exit(0);
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
}
