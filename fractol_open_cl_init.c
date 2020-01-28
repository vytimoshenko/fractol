/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_open_cl_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:08:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 01:40:01 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_open_cl	*init_open_cl(void)
{
	t_open_cl	*open_cl;
	cl_int		err_code;

	err_code = 1;
	if (!(open_cl = (t_open_cl *)ft_memalloc(sizeof(t_open_cl))))
		ft_put_errno(PROGRAM_NAME);
	if ((err_code = clGetPlatformIDs(1, &(open_cl->platform_id), NULL)))
		put_open_cl_error(open_cl, "clGetPlatformIDs error", err_code);
	if ((err_code = clGetDeviceIDs(open_cl->platform_id, DEVICE, 1,
	&(open_cl->device_id), NULL)))
		put_open_cl_error(open_cl, "clGetDeviceIDs error", err_code);
	if (!(open_cl->context = clCreateContext(NULL, 1, &(open_cl->device_id),
	NULL, NULL, &err_code)))
		put_open_cl_error(open_cl, "clCreateContext error", err_code);
	if (!(open_cl->command_queue = clCreateCommandQueue(open_cl->context,
	open_cl->device_id, 0, &err_code)))
		put_open_cl_error(open_cl, "clCreateCommandQueue error", err_code);
	get_open_cl_info(open_cl);
	load_open_cl_kernel(open_cl);
	open_cl->global_work_size = IMG_SIZE_X * IMG_SIZE_Y;
	open_cl->local_work_size = LOCAL_WORK_SIZE;
	return (open_cl);
}

void	get_open_cl_info(t_open_cl *open_cl)
{
	get_device_info_1(open_cl);
	get_device_info_2(open_cl);
	get_platform_info(open_cl);
}

void	get_platform_info(t_open_cl *open_cl)
{
	size_t	info_size;
	cl_int	err_code;

	if ((err_code = clGetPlatformInfo(open_cl->platform_id, CL_PLATFORM_NAME,
	0, NULL, &info_size)))
		put_open_cl_error(open_cl, "clGetPlatformInfo error", err_code);
	if (!(open_cl->platform_name = (char *)malloc(info_size)))
		ft_put_errno(PROGRAM_NAME);
	if ((err_code = clGetPlatformInfo(open_cl->platform_id, CL_PLATFORM_NAME,
	info_size, open_cl->platform_name, NULL)))
		put_open_cl_error(open_cl, "clGetPlatformInfo error", err_code);
}

void	get_device_info_1(t_open_cl *open_cl)
{
	size_t	info_size;
	cl_int	err_code;

	if ((err_code = clGetDeviceInfo(open_cl->device_id, CL_DEVICE_NAME,
	0, NULL, &info_size)))
		put_open_cl_error(open_cl, "clGetDeviceInfo error", err_code);
	if (!(open_cl->device_name = (char *)malloc(info_size)))
		ft_put_errno(PROGRAM_NAME);
	if ((err_code = clGetDeviceInfo(open_cl->device_id, CL_DEVICE_NAME,
	info_size, open_cl->device_name, NULL)))
		put_open_cl_error(open_cl, "clGetDeviceInfo error", err_code);
	if ((err_code = clGetDeviceInfo(open_cl->device_id, CL_DRIVER_VERSION,
	0, NULL, &info_size)))
		put_open_cl_error(open_cl, "clGetDeviceInfo error", err_code);
	if (!(open_cl->driver_ver = (char *)ft_memalloc(info_size)))
		ft_put_errno(PROGRAM_NAME);
	if ((err_code = clGetDeviceInfo(open_cl->device_id, CL_DRIVER_VERSION,
	info_size, open_cl->driver_ver, NULL)))
		put_open_cl_error(open_cl, "clGetDeviceInfo error", err_code);
	if ((err_code = clGetDeviceInfo(open_cl->device_id,
	CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(open_cl->device_comp_units),
	&(open_cl->device_comp_units), NULL)))
		put_open_cl_error(open_cl, "clGetDeviceInfo error", err_code);
}

void	get_device_info_2(t_open_cl *open_cl)
{
	cl_int	err_code;

	if ((err_code = clGetDeviceInfo(open_cl->device_id,
	CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(open_cl->device_frequency),
	&(open_cl->device_frequency), NULL)))
		put_open_cl_error(open_cl, "clGetDeviceInfo error", err_code);
}
