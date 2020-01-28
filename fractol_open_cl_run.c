/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_open_cl_run.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:12:19 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 21:54:37 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	run_open_cl(t_global *global)
{
	set_arg_open_cl_kernel(global->status, global->open_cl);
	execute_open_cl_kernel(global->open_cl);
	get_open_cl_result(global->open_cl, global->mlx);
}

void	set_arg_open_cl_kernel(t_status *status, t_open_cl *open_cl)
{
	cl_int			err_code;
	t_kernel_arg	kernel_arg;

	if (!(open_cl->buf = clCreateBuffer(open_cl->context, CL_MEM_WRITE_ONLY,
	open_cl->global_work_size * sizeof(int), NULL, &err_code)))
		put_open_cl_error(open_cl, "clCreateBuffer error", err_code);
	if ((err_code = clSetKernelArg(open_cl->kernel, 0, sizeof(cl_mem),
	&(open_cl->buf))))
		put_open_cl_error(open_cl, "clSetKernelArg error", err_code);
	pack_arg_to_struct(status, &kernel_arg);
	if ((err_code = clSetKernelArg(open_cl->kernel, 1, sizeof(kernel_arg),
	&kernel_arg)))
		put_open_cl_error(open_cl, "clSetKernelArg error", err_code);
}

void	pack_arg_to_struct(t_status *status, t_kernel_arg *kernel_arg)
{
	kernel_arg->m_x = status->m_x;
	kernel_arg->m_y = status->m_y;
	kernel_arg->zoom = status->zoom;
	kernel_arg->dx = status->dx;
	kernel_arg->dy = status->dy;
	kernel_arg->iter = status->iter;
	kernel_arg->type = status->fractal_type;
	kernel_arg->ms_x = status->ms_x;
	kernel_arg->ms_x = status->ms_y;
	kernel_arg->color = status->color_theme;
}

void	execute_open_cl_kernel(t_open_cl *open_cl)
{
	cl_int	err_code;

	if ((err_code = clEnqueueNDRangeKernel(open_cl->command_queue,
	open_cl->kernel, 1, NULL, &(open_cl->global_work_size),
	&(open_cl->local_work_size), 0, NULL, NULL)))
		put_open_cl_error(open_cl, "clEnqueueNDRangeKernel error", err_code);
}

void	get_open_cl_result(t_open_cl *open_cl, t_mlx *mlx)
{
	cl_int	err_code;

	if ((err_code = clEnqueueReadBuffer(open_cl->command_queue, open_cl->buf,
	CL_TRUE, 0, open_cl->global_work_size * sizeof(int), mlx->data, 0, NULL,
	NULL)))
		put_open_cl_error(open_cl, "clEnqueueReadBuffer error", err_code);
}
