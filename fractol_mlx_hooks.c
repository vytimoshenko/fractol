/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:44:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/09 02:26:24 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_global *global)
{
	get_mouse_position(global->status, x, y);
	if (global->status->fractal_type == JULIA && !global->status->pause)
		set_julia(global->status, x, y);
	control_mouse_shift(global->status, x, y);
	draw(global);
	return (0);
}

int		mouse_key_press(int key, int x, int y, t_global *global)
{
	if (key == MIDDLE_MOUSE_BUTTON)
		global->status->middle_mouse_button = 1;
	if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		control_mouse_zoom(global->status, x, y, key);
	draw(global);
	return (0);
}

int		mouse_key_release(int key, int x, int y, t_global *global)
{
	(void)x;
	(void)y;
	if (key == MIDDLE_MOUSE_BUTTON)
		global->status->middle_mouse_button = 0;
	draw(global);
	return (0);
}

int		keyboard_key_press(int key, t_global *global)
{
	if (key == ESC)
		close_window(global);
	if (key == SPACE)
		global->status->pause = global->status->pause ? 0 : 1;
	if (key == RETURN)
		control_type(global->status);
	if (key == C)
		control_colors(global->status);
	if (key == H)
		global->status->hide_info = global->status->hide_info ? 0 : 1;
	if (key == R)
		reset_status(global->status);
	if (key == D)
		control_device(global);
	control_iteration(global->status, key);
	control_zoom(global->status, key);
	control_shift(global->status, key);
	draw(global);
	return (0);
}

int		close_window(t_global *global)
{
	clean_open_cl(global->open_cl);
	clean_mlx(global->mlx);
	exit(0);
}
