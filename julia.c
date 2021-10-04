/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:12:49 by amorion-          #+#    #+#             */
/*   Updated: 2021/09/22 13:12:51 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_colour_j(double x, double y, t_complex c)
{
	double iter;
	t_complex z;
	double tmp;
	z.x = x;
	z.y = y;
	iter = 0;
	while(iter < 500 && hypot(z.x, z.y) <= 2)
	{
		tmp = z.x;
		z.x = z.x*z.x - z.y*z.y + c.x;
		z.y = 2 * tmp * z.y + c.y;
		iter++;
	}
	if (iter == 500)
		return(0);
	if (iter == 0)
		return(255255255);
	return(255255255 * iter / 500);
}

void    ft_julia_set(int argc, char **argv, t_mlx mlx)
{
	t_complex c;
	int	x;
	int y;

	c.x = 0.285;
	c.y = -0.01;
	if (argc > 2)
		c.x = ft_str2dbl(argv[2], c.x);
	if (argc > 3)
		c.y = ft_str2dbl(argv[3], c.y);
	mlx.img.img = mlx_new_image(mlx.mlx, 1300, 1300);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bxp, &mlx.img.llen,
			&mlx.img.end);
	y = 0;
	while (y < 1300)
	{
		x = 0;
		while (x < 1300)
		{
			ft_put_px(x, y, ft_colour_j(2*mlx.img.xmax * x / 1300. - mlx.img.xmax, 2 * mlx.img.ymax * y / 1300. - mlx.img.xmax, c), mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.wnd, mlx.img.img, 0,0);
}
