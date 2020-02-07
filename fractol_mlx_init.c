/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:40:25 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/08 01:54:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*init_mlx(void)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_put_errno(PROGRAM_NAME);
	if (!(mlx->mlx = mlx_init()))
		put_error_pn("mlx_init error");
	if (!(mlx->win = (void *)mlx_new_window(mlx->mlx, WIN_SIZE_X, WIN_SIZE_Y,
	PROGRAM_NAME)))
		put_error_pn("mlx_new_window error");
	if (!(mlx->img = (void *)mlx_new_image(mlx->mlx, IMG_SIZE_X, IMG_SIZE_Y)))
		put_error_pn("mlx_new_image error");
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian));
	return (mlx);
}

void	draw(t_global *global)
{
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	run_open_cl(global);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, 0, 0);
	if (!(global->status->hide_info))
		put_info_to_window(global);
}

void	mlx_hooks(t_global *global)
{
	mlx_hook(global->mlx->win, 2, 0, keyboard_key_press, global);
	mlx_hook(global->mlx->win, 4, 0, mouse_key_press, global);
	mlx_hook(global->mlx->win, 5, 0, mouse_key_release, global);
	mlx_hook(global->mlx->win, 6, 0, mouse_move, global);
	mlx_hook(global->mlx->win, 17, 0, close_window, global->open_cl);
	mlx_loop(global->mlx->mlx);
}

void	run(t_global *global)
{
	draw(global);
	mlx_hooks(global);
}
