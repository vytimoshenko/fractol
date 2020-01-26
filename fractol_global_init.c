/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_global_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:14:26 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 19:25:16 by mperseus         ###   ########.fr       */
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
	status->fractal_type = check_argument(argv[1]);
	if (!(status->fractal_name = ft_strdup((const char *)argv[1])))
		ft_put_errno(PROGRAM_NAME);
	return (status);
}

t_open_cl	*init_open_cl(void)
{
	t_open_cl	*open_cl;
	cl_int		err_code;

	err_code = 1;
	if (!(open_cl = (t_open_cl *)ft_memalloc(sizeof(t_open_cl))))
		ft_put_errno(PROGRAM_NAME);
	if ((err_code = clGetPlatformIDs(1, &(open_cl->platform_id), NULL)))
		put_open_cl_error("clGetPlatformIDs error", err_code);
	if ((err_code = clGetDeviceIDs(open_cl->platform_id, DEVICE, 1,
	&(open_cl->device_id), NULL)))
		put_open_cl_error("clGetDeviceIDs error", err_code);
	if (!(open_cl->context = clCreateContext(NULL, 1, &(open_cl->device_id),
	NULL, NULL, &err_code)))
		put_open_cl_error("clCreateContext error", err_code);
	if (!(open_cl->command_queue = clCreateCommandQueue(open_cl->context,
	open_cl->device_id, 0, &err_code)))
		put_open_cl_error("clCreateCommandQueue error", err_code);
	get_open_cl_info(open_cl);
	load_open_cl_kernel(open_cl);
	open_cl->global_work_size = IMG_SIZE_X * IMG_SIZE_Y;
	open_cl->local_work_size = LOCAL_WORK_SIZE;
	return (open_cl);
}

t_mlx		*init_mlx(void)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_put_errno(PROGRAM_NAME);
	if (!(mlx->mlx_ptr = mlx_init()))
		put_error_pn("mlx_init error");
	if (!(mlx->win_ptr = (void *)mlx_new_window(mlx->mlx_ptr, WIN_SIZE_X,
	WIN_SIZE_Y, PROGRAM_NAME)))
		put_error_pn("mlx_new_window error");
	if (!(mlx->img_ptr = (void *)mlx_new_image(mlx->mlx_ptr, IMG_SIZE_X,
	IMG_SIZE_Y)))
		put_error_pn("mlx_new_image error");
	mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian));
	return (mlx);
}

t_global	*init_global(int argc, char **argv)
{
	t_global *global;

	if (!(global = (t_global *)ft_memalloc(sizeof(t_global))))
		ft_put_errno(PROGRAM_NAME);
	global->status = init_status(argc, argv);
	global->open_cl = init_open_cl();
	global->mlx = init_mlx();
	return (global);
}
