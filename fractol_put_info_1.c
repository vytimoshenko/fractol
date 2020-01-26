/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_put_info_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 21:59:02 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_info_to_window(t_global *global)
{
	put_control_keys(global->mlx);
	put_open_cl_info_1(global->open_cl, global->mlx);
	put_open_cl_info_2(global->open_cl, global->mlx);
	put_status_1(global->status, global->mlx);
	// put_status_2(status, mlx);
	// put_status_3(status, mlx);
	put_mouse_position(global->status, global->mlx);
}

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

void	put_open_cl_info_1(t_open_cl *open_cl, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_X - 550;
	pos_y = WIN_SIZE_Y - 200;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 100, pos_y,
	TEXT_COLOR, "OPEN_CL HARDWARE SUMMARY");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 30,
	TEXT_COLOR, "Platform:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 130, pos_y + 30,
	TEXT_COLOR, open_cl->platform_name);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 50,
	TEXT_COLOR, "Device:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 130, pos_y + 50,
	TEXT_COLOR, open_cl->device_name);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 80,
	TEXT_COLOR, "Driver:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 130, pos_y + 80,
	TEXT_COLOR, open_cl->driver_ver);
}

void	put_open_cl_info_2(t_open_cl *open_cl, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_X - 550;
	pos_y = WIN_SIZE_Y - 200;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 110,
	TEXT_COLOR, "Cores:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 130, pos_y + 110,
	TEXT_COLOR, str = ft_itoa((int)(open_cl->device_comp_units)));
	free(str);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 130,
	TEXT_COLOR, "Frequency:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 130, pos_y + 130,
	TEXT_COLOR, str = ft_itoa((int)(open_cl->device_frequency)));
	free(str);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 170, pos_y + 130,
	TEXT_COLOR, "MHz");
}

void	put_status_1(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 390;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 70, pos_y,
	TEXT_COLOR, "STATUS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 30,
	TEXT_COLOR, "Type:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 130, pos_y + 30,
	TEXT_COLOR, status->fractal_name);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x, pos_y + 60,
	TEXT_COLOR, "Iterations:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, pos_x + 130, pos_y + 60,
	TEXT_COLOR, str = ft_itoa(status->iter_max));
	free(str);
}

// void	put_status_5(t_status *status, t_view *view)
// {
// 	int		pos_x;
// 	int		pos_y;

// 	pos_x = WIN_SIZE_X - 340;
// 	pos_y = 440;
// 	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 200,
// 	TEXT_COLOR, "Color:");
// 	if (status->color_scheme == 0)
// 		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 200,
// 		TEXT_COLOR, "Map");
// 	else if (status->color_scheme == 1)
// 		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 200,
// 		TEXT_COLOR, "Gradient #1");
// 	else if (status->color_scheme == 2)
// 		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 200,
// 		TEXT_COLOR, "Gradient #2");
// 	else if (status->color_scheme == 3)
// 		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 200,
// 		TEXT_COLOR, "Mono Cyan");
// 	else
// 		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 200,
// 		TEXT_COLOR, "Mono Green");
// }
