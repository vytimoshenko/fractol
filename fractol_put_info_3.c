/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_put_info_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:05:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 02:37:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	put_mouse_position(t_status *status, t_mlx *mlx)
// {
// 	int		pos_x;
// 	int		pos_y;
// 	char	*str;

// 	pos_x = IMG_INDT_X + 20;
// 	pos_y = WIN_SIZE_Y - 40;
// 	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y,
// 	TEXT_COLOR, "X:");
// 	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 20, pos_y,
// 	TEXT_COLOR, str = ft_itoa(status->x_mouse));
// 	free(str);
// 	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 80, pos_y,
// 	TEXT_COLOR, "Y:");
// 	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 100, pos_y,
// 	TEXT_COLOR, str = ft_itoa(status->y_mouse));
// 	free(str);
// }

void	put_control_keys(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 780;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 70, pos_y,
	TEXT_COLOR, "CONTROL");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 30,
	TEXT_COLOR, "Move:        W/A/S/D");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 50,
	TEXT_COLOR, "             middle mouse button");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 80,
	TEXT_COLOR, "Zoom:        +/-");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 100,
	TEXT_COLOR, "             mouse wheel scroll");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 130,
	TEXT_COLOR, "Iterations:  Page up/Page down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 160,
	TEXT_COLOR, "Color:       C");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 190,
	TEXT_COLOR, "Reset:       R");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 220,
	TEXT_COLOR, "Exit:        ESC");
}
