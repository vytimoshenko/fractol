/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:13:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/11 05:13:01 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_hooks(t_global *global)
{
	draw(global);
	mlx_hook(global->mlx->win, 2, 0, keyboard_key_press, global);
	mlx_hook(global->mlx->win, 4, 0, mouse_key_press, global);
	mlx_hook(global->mlx->win, 5, 0, mouse_key_release, global);
	mlx_hook(global->mlx->win, 6, 0, mouse_move, global);
	mlx_hook(global->mlx->win, 17, 0, close_window, global);
	mlx_loop(global->mlx->mlx);
}

void	draw(t_global *global)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	run_open_cl(global->status, global->open_cl, global->mlx->data);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, 0, 0);
	if (!(global->status->hide_info))
		put_info_to_window(global);
	gettimeofday(&end, NULL);
	count_frames(global, start, end);
}

void	update_info_only(t_global *global)
{
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, 0, 0);
	if (!(global->status->hide_info))
		put_info_to_window(global);
}

void	put_info_to_window(t_global *global)
{
	put_status_1(global->mlx);
	put_status_2(global->status, global->mlx);
	put_status_3(global->status, global->mlx);
	put_status_4(global->status, global->mlx);
	put_status_5(global->status, global->mlx);
	put_open_cl_info(global->open_cl, global->mlx);
	put_render_info_1(global->mlx);
	put_render_info_2(global->mlx);
	put_control_keys_1(global->status, global->mlx);
	put_control_keys_2(global->mlx);
}

void	count_frames(t_global *global, struct timeval start, struct timeval end)
{
	++global->mlx->frames;
	global->mlx->frame_time = (double)(end.tv_usec - start.tv_usec) / 1000 +
	(double)(end.tv_sec - start.tv_sec) * 1000;
	global->mlx->fps = 1000 / global->mlx->frame_time;
}
