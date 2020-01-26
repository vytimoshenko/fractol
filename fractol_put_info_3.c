/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_put_info_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:05:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 20:49:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_mouse_position(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = 20;
	pos_y = WIN_SIZE_Y - 40;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y,
	TEXT_COLOR, "X:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 20, pos_y,
	TEXT_COLOR, str = ft_itoa(status->x_mouse_position));
	free(str);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 80, pos_y,
	TEXT_COLOR, "Y:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 100, pos_y,
	TEXT_COLOR, str = ft_itoa(status->y_mouse_position));
	free(str);
}
