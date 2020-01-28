/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_put_info_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:05:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 02:35:26 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_status_1(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 390;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 70, pos_y, TEXT_COLOR,
	"STATUS");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Type:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 30, TEXT_COLOR,
	status->fractal_name);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"Iterations:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(status->iter));
	free(str);
}

void	put_status_2(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 440;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 200,
	TEXT_COLOR, "Color:");
	if (status->color_theme == 0)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 200, TEXT_COLOR,
		"Theme #1");
	else if (status->color_theme == 1)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 200, TEXT_COLOR,
		"Theme #2");
	else if (status->color_theme == 2)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 200, TEXT_COLOR,
		"Theme #3");
	else
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 200, TEXT_COLOR,
		"Theme #4");
}

void	put_status_3(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = 20;
	pos_y = WIN_SIZE_Y - 40;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR, "X:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 20, pos_y, TEXT_COLOR,
	str = ft_itoa(status->x_mouse_position));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 80, pos_y, TEXT_COLOR, "Y:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y, TEXT_COLOR,
	str = ft_itoa(status->y_mouse_position));
	free(str);
}
