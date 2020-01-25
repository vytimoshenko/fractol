/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:25:01 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 02:40:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_background(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_X * IMG_SIZE_Y)
		mlx->data[i] = BACK_COLOR;
}

void	redraw(t_open_cl *open_cl, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	clear_background(mlx);
	// draw_image(mlx, open_cl);
	put_info_to_window(open_cl, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	draw(t_open_cl *open_cl, t_mlx *mlx)
{
	// mlx_hook(mlx->win_ptr, 2, 0, keyboard_key_press, (void *)mlx);
	// mlx_hook(mlx->win_ptr, 4, 0, mouse_key_press, (void *)mlx);
	// mlx_hook(mlx->win_ptr, 5, 0, mouse_key_release, (void *)mlx);
	// mlx_hook(mlx->win_ptr, 6, 0, mouse_move, (void *)mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, (void *)mlx);
	redraw(open_cl, mlx);
	mlx_loop(mlx->mlx_ptr);
}
