/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_open_cl_kernel.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 23:26:21 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 01:39:02 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		read_open_cl_kernel(t_open_cl *open_cl)
{
	int		fd;

	if ((fd = open(SOURCE_NAME, O_RDONLY)) < 0)
		ft_put_errno(PROGRAM_NAME);
	if ((read(fd, NULL, 0)) == -1)
		ft_put_errno(PROGRAM_NAME);
	if (!(open_cl->source_str = (char *)ft_memalloc(sizeof(char)
	* (MAX_SOURCE_SIZE + 1))))
		ft_put_errno(PROGRAM_NAME);
	if ((open_cl->source_size = read(fd, open_cl->source_str,
	MAX_SOURCE_SIZE)) <= 0)
		put_error_pn("OpenCL source file reading error");
	if (read(fd, open_cl->source_str, MAX_SOURCE_SIZE))
		put_error_pn("max OpenCL source file size exceed");
	close(fd);
}

void		load_open_cl_kernel(t_open_cl *open_cl)
{
	cl_int	err_code;

	err_code = 1;
	read_open_cl_kernel(open_cl);
	if (!(open_cl->program = clCreateProgramWithSource(open_cl->context, 1,
	(const char **)&(open_cl->source_str),
	(const size_t *)&(open_cl->source_size), &err_code)))
		put_open_cl_error(open_cl, "clCreateProgramWithSource error", err_code);
	free(open_cl->source_str);
	if ((err_code = clBuildProgram(open_cl->program, 1, &(open_cl->device_id),
	NULL, NULL, NULL)))
		put_open_cl_error(open_cl, "clBuildProgram error", err_code);
	if (!(open_cl->kernel = clCreateKernel(open_cl->program, KERNEL_NAME,
	&err_code)))
		put_open_cl_error(open_cl, "clCreateKernel error", err_code);
}
