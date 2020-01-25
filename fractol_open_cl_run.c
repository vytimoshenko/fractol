/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_open_cl_run.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:12:19 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 01:15:44 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_arg_open_cl_kernel(t_open_cl *open_cl)
{
	cl_int	err_code;

	if (!(open_cl->buf = clCreateBuffer(open_cl->context, CL_MEM_WRITE_ONLY,
	open_cl->global_work_size * sizeof(int), NULL, &err_code)))
		put_open_cl_error("clCreateBuffer error", err_code);
	if ((err_code = clSetKernelArg(open_cl->kernel, 0, sizeof(cl_mem),
	(void *)&(open_cl->buf))))
		put_open_cl_error("clSetKernelArg error", err_code);
}

void	execute_open_cl_kernel(t_open_cl *open_cl)
{
	cl_int	err_code;

	if ((err_code = clEnqueueNDRangeKernel(open_cl->command_queue,
	open_cl->kernel, 1, NULL, &(open_cl->global_work_size),
	&(open_cl->local_work_size), 0, NULL, NULL)))
		put_open_cl_error("clEnqueueNDRangeKernel error", err_code);
}

void	get_open_cl_result(t_open_cl *open_cl)
{
	cl_int	err_code;

	int *res = (int *)malloc(sizeof(int) * open_cl->global_work_size);
	if ((err_code = clEnqueueReadBuffer(open_cl->command_queue, open_cl->buf,
	CL_TRUE, 0, open_cl->global_work_size * sizeof(int), res, 0, NULL, NULL)))
		put_open_cl_error("clEnqueueReadBuffer error", err_code);
	int i = open_cl->global_work_size;
	while (i-- > 0)
		printf("%d\n", res[i]);
}

void	clean_open_cl(t_open_cl *open_cl)
{
	cl_int	err_code;

	if ((err_code = clFlush(open_cl->command_queue)))
		put_open_cl_error("clFlush error", err_code);
	if ((err_code = clFinish(open_cl->command_queue)))
		put_open_cl_error("clFinish error", err_code);
	if ((err_code = clReleaseKernel(open_cl->kernel)))
		put_open_cl_error("clReleaseKernel error", err_code);
	if ((err_code = clReleaseProgram(open_cl->program)))
		put_open_cl_error("clReleaseProgram error", err_code);
	if ((err_code = clReleaseMemObject(open_cl->buf)))
		put_open_cl_error("clReleaseMemObject error", err_code);
	if ((err_code = clReleaseCommandQueue(open_cl->command_queue)))
		put_open_cl_error("clReleaseCommandQueue error", err_code);
	if ((err_code = clReleaseContext(open_cl->context)))
		put_open_cl_error("clReleaseContext error", err_code);
}

void	run_open_cl(t_open_cl *open_cl)
{
	set_arg_open_cl_kernel(open_cl);
	execute_open_cl_kernel(open_cl);
	get_open_cl_result(open_cl);
	clean_open_cl(open_cl);
}
