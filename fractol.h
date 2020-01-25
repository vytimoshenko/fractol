/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 02:50:35 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "./libft/libft.h"
# include "mlx.h"
# include <OpenCL/opencl.h>

# define PROGRAM_NAME		"fractol"

# define WIN_SIZE_X 		2560
# define WIN_SIZE_Y			1400
# define IMG_SIZE_X			16
# define IMG_SIZE_Y			16

# define TEXT_COLOR  		0xFFFFFF
# define BACK_COLOR  		0x555555

# define SOURCE_NAME		"open_cl_test.cl"
# define KERNEL_NAME		"open_cl_test"
# define MAX_SOURCE_SIZE	8192

# define DEVICE				CL_DEVICE_TYPE_CPU
# define LOCAL_WORK_SIZE	1

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*data;

	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_mlx;

typedef struct			s_open_cl
{
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;

	char				*platform_name;
	char				*device_name;
	char				*driver_ver;
	cl_uint				device_comp_units;
	cl_uint				device_frequency;

	size_t				source_size;
	char				*source_str;

	size_t				global_work_size;
	size_t				local_work_size;

	cl_mem				buf;
}						t_open_cl;

int						main(void);

t_mlx					*init_struct_mlx(void);
void					prep_mlx(t_mlx *mlx);
t_mlx					*init_mlx(void);

int						close_window(void *param);

t_open_cl				*init_struct_open_cl(void);
void					prep_open_cl(t_open_cl *open_cl);
t_open_cl				*init_open_cl(void);

void					get_device_info_1(t_open_cl *open_cl);
void					get_device_info_2(t_open_cl *open_cl);
void					get_platform_info(t_open_cl *open_cl);
void					get_open_cl_info(t_open_cl *open_cl);

void					read_open_cl_kernel(t_open_cl *open_cl);
void					load_open_cl_kernel(t_open_cl *open_cl);
void					get_open_cl_kernel(t_open_cl *open_cl);

void					set_arg_open_cl_kernel(t_open_cl *open_cl);
void					execute_open_cl_kernel(t_open_cl *open_cl);
void					get_open_cl_result(t_open_cl *open_cl);
void					clean_open_cl(t_open_cl *open_cl);
void					run_open_cl(t_open_cl *open_cl);

void					clear_background(t_mlx *mlx);
void					redraw(t_open_cl *open_cl, t_mlx *mlx);
void					draw(t_open_cl *open_cl, t_mlx *mlx);

void					put_info_to_window(t_open_cl *open_cl, t_mlx *mlx);
void					put_open_cl_info_1(t_open_cl *open_cl, t_mlx *mlx);
void					put_open_cl_info_2(t_open_cl *open_cl, t_mlx *mlx);

void					put_control_keys(t_mlx *mlx);

void					put_error_pn(char *str);
void					put_open_cl_error(char *str, cl_int err_code);
char					*open_cl_error_interpret(cl_int err_code);
char					*open_cl_error_1(cl_int err_code);

char					*open_cl_error_2(cl_int err_code);
char					*open_cl_error_3(cl_int err_code);
char					*open_cl_error_4(cl_int err_code);
char					*open_cl_error_5(cl_int err_code);
char					*open_cl_error_6(cl_int err_code);

#endif