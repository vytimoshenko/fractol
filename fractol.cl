# define NEW		0
# define OLD		1
# define HEIGHT 1000
# define WIDTH 1000
# define MANDELBROT	1
# define JULIA		2
# define SPIDER		3
# define SIN		4

typedef struct			s_kernel_arg
{
double 					m_x;
double 					m_y;
double 					zoom;
double 					dx;
double 					dy;
int 					iter;
int 					type;
double 					ms_x;
double 					ms_y;
double					color;
}						t_kernel_arg;

int 	choose_color(int i, int max, int color);
int		set_colors(unsigned char o, unsigned char r, unsigned char g, unsigned char b);

int		set_colors(unsigned char o, unsigned char r, unsigned char g, unsigned char b)
{
	return ((int)o << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

int 		choose_color(int i, int max, int color)
{
	int			red;
	int			blue;
	int			green;
	double		n;

	n = (double)i / (double)max;
	red = (int)(9 * (1 - n) * pow(n, 3) * 255);
	green = (int)(15 * pow((1 - n), 2) * pow(n, 2) * 255);
	blue = (int)(8.5 * pow((1 - n), 3) * n * 255);
	if (color == 1)
		return (set_colors(0, red, blue, green));
	else if (color == 0)
		return (set_colors(0, blue, green, red));
	else if (color == 2)
		return (set_colors(0, blue, red, green));
	else if (color == 3)
		return (set_colors(0, red, green, blue));
	return (0);
}

__kernel void fractal(__global char *data, t_kernel_arg kernel_arg)
{
    	double	re[2];
    	double	im[2];
    	double	c_re;
    	double	c_im;
    	int     i;
        size_t  id;
        int     x;
        int     y;

        id = get_global_id(0);
    	i = 0;
    	x = id % WIDTH;
    	y = id / HEIGHT;
    	c_re = (x - kernel_arg.m_x) / kernel_arg.zoom + kernel_arg.dx;
        c_im = (y - kernel_arg.m_y) / kernel_arg.zoom + kernel_arg.dy;
        re[NEW] = c_re;
        im[NEW] = c_im;
        if (kernel_arg.type == MANDELBROT)
        {
    		while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < kernel_arg.iter)
   	 		{
    			re[OLD] = re[NEW];
        		im[OLD] = im[NEW];
        		im[NEW] = 2 * im[OLD] * re[OLD] + c_im;
        	    re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
    		}
    	}
    	else if (kernel_arg.type == JULIA)
    	{
    		while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < kernel_arg.iter)
   	 		{
    			re[OLD] = re[NEW];
        		im[OLD] = im[NEW];
        		im[NEW] = 2 * im[OLD] * re[OLD] + kernel_arg.ms_y;
        	    re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + kernel_arg.ms_x;
    		}
    	}
		else if (kernel_arg.type == SPIDER)
		{
			while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < kernel_arg.iter)
			{
				re[OLD] = re[NEW];
				im[OLD] = im[NEW];
				re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
				im[NEW] = 2.0 * re[OLD] * im[OLD] + c_im;
				c_im = c_im / 2 + im[NEW];
				c_re = c_re / 2 + re[NEW];
			}
		}
    	if (i < kernel_arg.iter)
    	    ((__global int *)data)[id] = choose_color(i, kernel_arg.iter, kernel_arg.color);
    	else
            ((__global int *)data)[id] = 0;
}