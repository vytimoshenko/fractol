/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/28 22:04:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "./libft/libft.h"
# include "mlx.h"
# include <OpenCL/opencl.h>
# include "math.h"

# define PROGRAM_NAME			"fractol"

# define WIN_SIZE_X 			2560
# define WIN_SIZE_Y				1400
# define IMG_SIZE_X				1000
# define IMG_SIZE_Y				1000

# define TEXT_COLOR  			0xFFFFFF
# define BACK_COLOR  			0x555555

# define SOURCE_NAME			"fractol.cl"
# define KERNEL_NAME			"fractal"
# define MAX_SOURCE_SIZE		8192

# define DEVICE					CL_DEVICE_TYPE_GPU
# define LOCAL_WORK_SIZE		8

# define MIDDLE_MOUSE_BUTTON	3
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5
# define C						8
# define R						15
# define RETURN					36
# define CHEVRON_LEFT			43
# define CHEVRON_RIGHT			47
# define SPACE					49
# define ESC					53
# define PLUS					69
# define MINUS					78
# define PAGE_UP				116
# define PAGE_DOWN				121
# define ARROW_LEFT				123
# define ARROW_RIGHT			124
# define ARROW_DOWN				125
# define ARROW_UP				126

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
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
	char				*program_build_log;

	size_t				global_work_size;
	size_t				local_work_size;

	cl_mem				buf;
}						t_open_cl;

typedef struct			s_status
{
	int					fractal_type;
	char				*fractal_name;

	int					*data;

	double				zoom;
	float				zoom_init;
	double				color_theme;

	int					iter;

	int					y_start;
	int					y_end;

	float				re;
	float				im;
	float				re2;
	float				im2;
	float				c_re;
	float				c_im;

	float				d_re;
	float				d_im;
	float				x_min;
	float				x_max;
	float				y_min;
	float				y_max;

	int					x_mouse_position;
	int					y_mouse_position;

	int					shift_x;
	int					shift_y;
	// int				x_move;
	// int				y_move;
	// int				middle_mouse_button;

	double				dy;
	double				dx;
	double				ms_y;
	double				ms_x;
	int					pause;
	double				m_y;
	double				m_x;

}						t_status;

typedef struct			s_global
{
	t_status			*status;
	t_mlx				*mlx;
	t_open_cl			*open_cl;
}						t_global;

typedef struct			s_kernel_arg
{
	double				m_x;
	double				m_y;
	double				zoom;
	double				dx;
	double				dy;
	int					iter;
	int					type;
	double				ms_x;
	double				ms_y;
	double				color;
}						t_kernel_arg;

int						main(int argc, char **argv);

t_status				*init_status(int argc, char **argv);
t_mlx					*init_mlx(void);
t_global				*init_global(int argc, char **argv);

int						check_argument(char *arg);
void					error_wrong_argument(void);
void					assign_fractal(t_status *status);

void					clear_background(t_mlx *mlx);
void					mlx_hooks(t_global *global);
void					draw(t_global *global);

int						mouse_move(int x, int y, void *param);
int						mouse_key_press(int key, int x, int y, void *param);
int						keyboard_key_press(int key, void *param);
int						close_window(void *param);

void					get_mouse_position(t_status *status, int x, int y);
void					control_shift(t_status *status, int key);
void					control_zoom(t_status *status, int key);
void					control_colors(t_status *status);

void					put_info_to_window(t_global *global);
void					put_control_keys(t_mlx *mlx);
void					put_open_cl_info_1(t_open_cl *open_cl, t_mlx *mlx);
void					put_open_cl_info_2(t_open_cl *open_cl, t_mlx *mlx);

void					put_status_1(t_status *status, t_mlx *mlx);
void					put_status_2(t_status *status, t_mlx *mlx);
void					put_status_3(t_status *status, t_mlx *mlx);

t_open_cl				*init_open_cl(void);
void					read_open_cl_kernel(t_open_cl *open_cl);
void					load_open_cl_kernel(t_open_cl *open_cl);

void					get_open_cl_info(t_open_cl *open_cl);
void					get_device_info_1(t_open_cl *open_cl);
void					get_device_info_2(t_open_cl *open_cl);
void					get_platform_info(t_open_cl *open_cl);
void					get_program_build_log(t_open_cl *open_cl);

void					run_open_cl(t_global *global);
void					set_arg_open_cl_kernel(t_status *status,
						t_open_cl *open_cl);
void					pack_arg_to_struct(t_status *status,
						t_kernel_arg *kernel_arg);
void					execute_open_cl_kernel(t_open_cl *open_cl);
void					get_open_cl_result(t_open_cl *open_cl, t_mlx *mlx);

void					clean_open_cl(t_open_cl *open_cl);
void					clean_open_cl_1(t_open_cl *open_cl);
void					clean_open_cl_2(t_open_cl *open_cl);

void					put_error_pn(char *str);
void					put_open_cl_error(t_open_cl *open_cl, char *str,
						cl_int err_code);
char					*open_cl_error_interpret(cl_int err_code);
char					*open_cl_error_1(cl_int err_code);

char					*open_cl_error_2(cl_int err_code);
char					*open_cl_error_3(cl_int err_code);
char					*open_cl_error_4(cl_int err_code);
char					*open_cl_error_5(cl_int err_code);
char					*open_cl_error_6(cl_int err_code);

#endif
