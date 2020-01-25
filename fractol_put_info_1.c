/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_put_info_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 02:33:21 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_info_to_window(t_open_cl *open_cl, t_mlx *mlx)
{
	put_control_keys(mlx);
	put_open_cl_info_1(open_cl, mlx);
	put_open_cl_info_2(open_cl, mlx);
	// put_status_1(status, mlx);
	// put_status_2(status, mlx);
	// put_status_3(status, mlx);
	// put_mouse_position(status, mlx);
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
