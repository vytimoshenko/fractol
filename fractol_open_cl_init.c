/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_open_cl_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:10:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 01:13:04 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_open_cl	*init_struct_open_cl(void)
{
	t_open_cl	*open_cl;

	if (!(open_cl = (t_open_cl *)ft_memalloc(sizeof(t_open_cl))))
		ft_put_errno(PROGRAM_NAME);
	return (open_cl);
}

void		prep_open_cl(t_open_cl *open_cl)
{
	cl_int	err_code;

	err_code = 1;
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
	open_cl->global_work_size = IMG_SIZE_X * IMG_SIZE_Y;
	open_cl->local_work_size = LOCAL_WORK_SIZE;
}

t_open_cl	*init_open_cl(void)
{
	t_open_cl	*open_cl;

	open_cl = init_struct_open_cl();
	prep_open_cl(open_cl);
	get_open_cl_info(open_cl);
	get_open_cl_kernel(open_cl);
	return (open_cl);
}
