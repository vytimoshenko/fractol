/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_global_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:14:26 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 03:04:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_status	*init_status(int argc, char **argv)
{
	t_status		*status;

	if (argc != 2)
		error_wrong_argument();
	if (!(check_argument(argv[1])))
		error_wrong_argument();
	if (!(status = (t_status *)ft_memalloc(sizeof(t_status))))
		ft_put_errno(PROGRAM_NAME);
	// status->fractal_type = check_argument(argv[1]);
	if (!(status->fractal_name = ft_strdup((const char *)argv[1])))
		ft_put_errno(PROGRAM_NAME);
	assign_fractal(status);
	return (status);
}

t_mlx		*init_mlx(void)
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

t_global	*init_global(int argc, char **argv)
{
	t_global *global;

	if (!(global = (t_global *)ft_memalloc(sizeof(t_global))))
		ft_put_errno(PROGRAM_NAME);
	global->status = init_status(argc, argv);
	global->mlx = init_mlx();
	global->open_cl = init_open_cl();
	global->status->data = global->mlx->data;
	return (global);
}
