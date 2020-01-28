# define IMG_SIZE_X				1890
# define IMG_SIZE_Y				1350
# define NEW 0
# define OLD 1

int		set_colors(unsigned char o, unsigned char r, \
			unsigned char g, unsigned char b)
{
	return ((int)o << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

int 		get_color(int i, int iter_max, int color_theme)
{
	int			red;
	int			blue;
	int			green;
	double		n;

	n = (double)i / (double)iter_max;
	red = (int)(9 * (1 - n) * pow(n, 3) * 255);
	green = (int)(15 * pow((1 - n), 2) * pow(n, 2) * 255);
	blue = (int)(8.5 * pow((1 - n), 3) * n * 255);
	if (color_theme == 0)
		return (set_colors(0, red, blue, green));
	else if (color_theme == 1)
		return (set_colors(0, blue, green, red));
	else if (color_theme == 2)
		return (set_colors(0, blue, red, green));
	else if (color_theme == 3)
		return (set_colors(0, red, green, blue));
	return (0);
}

kernel void draw(__global int *buf)
{
    	double	re[2];
    	double	im[2];
    	double	c_re;
    	double	c_im;
    	int     i;
        size_t  id;
        int     x;
        int     y;

		int color = 1;
		int iter = 40;
		double zoom = 150;
		double dy = 0;
		double dx = 0;
		double m_y = (double)IMG_SIZE_X / 2;
		double m_x = (double)IMG_SIZE_X / 2;

        id = get_global_id(0);
    	i = 0;
    	x = id % WIDTH;
    	y = id / HEIGHT;
    	c_re = (x - m_x) / zoom + dx;
        c_im = (y - m_y) / zoom + dy;
        re[NEW] = c_re;
        im[NEW] = c_im;
    		while (re[NEW] * re[NEW] + im[NEW] * im[NEW] < 4 && ++i < iter)
   	 		{
    			re[OLD] = re[NEW];
        		im[OLD] = im[NEW];
        		im[NEW] = 2 * im[OLD] * re[OLD] + c_im;
        	    re[NEW] = re[OLD] * re[OLD] - im[OLD] * im[OLD] + c_re;
    		}
    	if (i < iter)
    	    ((__global int *)data)[id] = get_color(i, iter, color);
    	else
            ((__global int *)data)[id] = 0;
}