/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:09:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 02:49:31 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_mlx		*mlx;
	t_open_cl	*open_cl;

	mlx = init_mlx();
	open_cl = init_open_cl();

	printf("This program uses OpenCL %s driver\n", open_cl->driver_ver);
	printf("Platform: %s\n", open_cl->platform_name);
	printf("Device: %s\n", open_cl->device_name);
	printf("Compute units max: %u\n", open_cl->device_comp_units);
	printf("Clock frequency max: %u\n", open_cl->device_frequency);
	
	run_open_cl(open_cl);

	draw(open_cl, mlx);
	exit(0);
}
