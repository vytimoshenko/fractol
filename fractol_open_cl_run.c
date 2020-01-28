/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_open_cl_run.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:12:19 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 02:52:24 by mperseus         ###   ########.fr       */
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
	cl_int	err_code;

	if (!(open_cl->buf = clCreateBuffer(open_cl->context, CL_MEM_WRITE_ONLY,
	open_cl->global_work_size * sizeof(int), NULL, &err_code)))
		put_open_cl_error(open_cl, "clCreateBuffer error", err_code);
	if ((err_code = clSetKernelArg(open_cl->kernel, 0, sizeof(cl_mem),
	&(open_cl->buf))))
		put_open_cl_error(open_cl, "clSetKernelArg error", err_code);

	err_code |= clSetKernelArg(open_cl->kernel, 1, sizeof(double), &(status->m_x));
	err_code |= clSetKernelArg(open_cl->kernel, 2, sizeof(double), &(status->m_y));
	err_code |= clSetKernelArg(open_cl->kernel, 3, sizeof(double), &(status->zoom));
	err_code |= clSetKernelArg(open_cl->kernel, 4, sizeof(double), &(status->dx));
	err_code |= clSetKernelArg(open_cl->kernel, 5, sizeof(double), &(status->dy));
	err_code |= clSetKernelArg(open_cl->kernel, 6, sizeof(int), &(status->iter));
	err_code |= clSetKernelArg(open_cl->kernel, 7, sizeof(int), &(status->fractal_type));
	err_code |= clSetKernelArg(open_cl->kernel, 8, sizeof(double), &(status->ms_x));
	err_code |= clSetKernelArg(open_cl->kernel, 9, sizeof(double), &(status->ms_y));
	err_code |= clSetKernelArg(open_cl->kernel, 10, sizeof(double), &(status->color_theme));
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
