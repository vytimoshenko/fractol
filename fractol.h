/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/12 19:56:26 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <OpenCL/opencl.h>
# include <sys/time.h>

# define PROGRAM_NAME			"fractol"

# define WIN_SIZE_W 			2560
# define WIN_SIZE_H				1400
# define IMG_SIZE_W				2560
# define IMG_SIZE_H				1400

# define TEXT_COLOR  			0xFFFFFF
# define BACK_COLOR  			0x555555

# define CPU					0
# define GPU					1

# define SOURCE_NAME			"fractol.cl"
# define KERNEL_NAME			"fractol"
# define MAX_SOURCE_SIZE		8192
# define LOCAL_WORK_SIZE		64

# define MANDELBROT				1
# define JULIA					2
# define BURNING_SHIP			3
# define SPIDER					4
# define SIN					5

# define MIDDLE_MOUSE_BUTTON	3
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5

# define D						2
# define H						4
# define C						8
# define R						15
# define PLUS					24
# define MINUS					27
# define RETURN					36
# define LESS					43
# define MORE					47
# define SPACE					49
# define ESC					53
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

	int					frames;
	int					fps;
	float				frame_time;
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

	int					execution_time;
}						t_open_cl;

typedef struct			s_status
{
	int					device;
	int					fractal_type;

	int					hide_info;
	int					color_theme;
	int					iter;
	int					pause;
	double				zoom;

	double				x_center;
	double				y_center;
	double				x_shift;
	double				y_shift;

	int					x_mouse_position;
	int					y_mouse_position;

	int					middle_mouse_button;
	double				x_move;
	double				y_move;

	double				x_julia;
	double				y_julia;
}						t_status;

typedef struct			s_global
{
	t_status			*status;
	t_mlx				*mlx;
	t_open_cl			*open_cl;
}						t_global;

typedef struct			s_kernel_arg
{
	int					img_size_x;

	int					fractal_type;

	int					color_theme;
	int					iter;
	int					pause;
	double				zoom;

	double				x_center;
	double				y_center;
	double				x_shift;
	double				y_shift;

	double				x_julia;
	double				y_julia;
}						t_kernel_arg;

int						main(int argc, char **argv);

t_status				*init_status(int argc, char **argv);
void					check_argument(t_status *status, char *arg);
void					error_wrong_argument(void);
void					reset_status(t_status *status);

t_mlx					*init_mlx(void);
void					reset_render_status(t_mlx *mlx);
void					clean_mlx(t_mlx *mlx);
void					put_mlx_error(t_mlx *mlx, char *str);

void					loop(t_global *global);
void					draw(t_global *global);
void					update_info_only(t_global *global);
void					put_info_to_window(t_global *global);
void					count_frames(t_mlx *mlx, struct timeval start,
						struct timeval end);

int						mouse_move(int x, int y, t_global *global);
int						mouse_key_press(int key, int x, int y,
						t_global *global);
int						mouse_key_release(int key, int x, int y,
						t_global *global);
int						keyboard_key_press(int key, t_global *global);
int						close_window(t_global *global);

void					get_mouse_position(t_status *status, int x, int y);
void					control_zoom(t_status *status, int key);
void					control_mouse_zoom(t_status *status, int x, int y,
						int key);
void					control_shift(t_status *status, int key);
void					control_mouse_shift(t_status *status, int x, int y);

void					control_type(t_status *status, t_mlx *mlx);
void					control_iteration(t_status *status, int key);
void					control_colors(t_status *status);
void					control_device(t_global *global);
void					set_julia(t_status *status, int x, int y);

void					put_status_1(t_mlx *mlx);
void					put_status_2(t_status *status, t_mlx *mlx);
void					put_status_3(t_status *status, t_mlx *mlx);
void					put_status_4(t_status *status, t_mlx *mlx);
void					put_status_5(t_status *status, t_mlx *mlx);

void					put_open_cl_info(t_open_cl *open_cl, t_mlx *mlx);
void					put_render_info_1(t_mlx *mlx);
void					put_render_info_2(t_mlx *mlx);
void					put_control_keys_1(t_status *status, t_mlx *mlx);
void					put_control_keys_2(t_mlx *mlx);

t_open_cl				*init_open_cl(int device);
void					get_device(t_open_cl *open_cl, int device);
void					read_open_cl_kernel(t_open_cl *open_cl);
void					load_open_cl_kernel(t_open_cl *open_cl);

void					get_open_cl_info(t_open_cl *open_cl);
void					get_device_info(t_open_cl *open_cl);
void					get_platform_info(t_open_cl *open_cl);

void					run_open_cl(t_status *status, t_open_cl *open_cl,
						int *res);
void					set_arg_open_cl_kernel(t_status *status,
						t_open_cl *open_cl);
void					pack_arg_to_struct(t_status *status,
						t_kernel_arg *kernel_arg);
void					get_execution_time(t_open_cl *open_cl, cl_event event);

void					clean_open_cl(t_open_cl *open_cl);
void					clean_open_cl_1(t_open_cl *open_cl);
void					clean_open_cl_2(t_open_cl *open_cl);
void					clean_open_cl_info(t_open_cl *open_cl);

void					pfn_notify(const char *errinfo,
						const void *private_info, size_t cb, void *user_data);
void					put_error_pn(char *str);
void					put_open_cl_error(t_open_cl *open_cl, char *str);

#endif
