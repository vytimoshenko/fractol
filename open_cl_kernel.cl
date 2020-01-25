int		get_color(int color_scheme, int grade)
{
	int		red;
	int		green;
	int		blue;

	if (color_scheme == 0)
		grade *= 10;
	if (color_scheme == 1)
		grade *= 1000;
	if (color_scheme == 2)
		grade *= 100000;
	if (color_scheme == 3)
		grade *= 1000000;
	grade *= grade;
	red = (grade * 5 >> 16) & 0xFF;
	green = (grade / 10 >> 8) & 0xFF;
	blue = (grade) & 0xFF;
	return ((red << 16) | (green << 8) | blue);
}

void	julia_start(t_view *view, int x, int y)
{
	view->re = 1.5 * (x - IMG_SIZE_X / 2) / (0.5 * view->zoom * IMG_SIZE_X) + view->shift_x;
    view->im = (y - IMG_SIZE_Y / 2) / (0.5 * view->zoom * IMG_SIZE_Y) + view->shift_y;
	view->re2 = view->re * view->re;
	view->im2 = view->im * view->im;
}

int	iterator(t_view *view)
{
	int	i;
	i = -1;
	while (++i < view->iter_max && view->re2 + view->im2 < 4)
	{
		view->im = 2 * view->re * view->im + view->c_im;
		view->re = view->re2 - view->im2 + view->c_re;
		view->re2 = view->re * view->re;
		view->im2 = view->im * view->im;
	}
	return (i);
}

void	julia(void *thread_data)
{
	int x;
	int y;
	int i;

	t_view	*view;
	view = (t_view *)thread_data;
	y = view->y_start;
	while (++y <= view->y_end)
	{
		x = -1;
		while (++x < IMG_SIZE_X)
		{
			julia_start(view, x, y);
			i = iterator(view);
			view->data[IMG_SIZE_X * (y - 1) + x] = get_color(view->color_scheme, i);
		}
	}
	pthread_exit(0);
}

