/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 01:34:33 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*init_struct_mlx(void)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_put_errno(PROGRAM_NAME);
	return (mlx);
}

void		prep_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		put_error_pn("mlx_init error");
	if (!(mlx->win_ptr = (void *)mlx_new_window(mlx->mlx_ptr, WIN_SIZE_X,
	WIN_SIZE_Y, PROGRAM_NAME)))
		put_error_pn("mlx_new_window error");
	if (!(mlx->img_ptr = (void *)mlx_new_image(mlx->mlx_ptr, IMG_SIZE_X,
	IMG_SIZE_Y)))
		put_error_pn("mlx_new_image error");
	mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian));
}

t_mlx	*init_mlx(void)
{
	t_mlx		*mlx;

	mlx = init_struct_mlx();
	prep_mlx(mlx);
	return (mlx);
}
