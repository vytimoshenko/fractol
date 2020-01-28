/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:25:01 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 04:06:53 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_global *global)
{
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	clear_background(global->mlx);
	// mandelbrot(global->status);
	// draw_fractal(global);
	run_open_cl(global);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, 0, 0);
	put_info_to_window(global);
}

void	clear_background(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_X * IMG_SIZE_Y)
		mlx->data[i] = BACK_COLOR;
}

void	mlx_hooks(t_global *global)
{
	mlx_hook(global->mlx->win, 2, 0, keyboard_key_press, (void *)global);
	mlx_hook(global->mlx->win, 4, 0, mouse_key_press, (void *)global);
	// mlx_hook(mlx->win, 5, 0, mouse_key_release, (void *)mlx);
	mlx_hook(global->mlx->win, 6, 0, mouse_move, (void *)global);
	mlx_hook(global->mlx->win, 17, 0, close_window, (void *)(global->open_cl));
	mlx_loop(global->mlx->mlx);
}
