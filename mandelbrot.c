/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:43:29 by amorion-          #+#    #+#             */
/*   Updated: 2021/09/26 16:43:31 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_colour_m(double x, double y)
{
	t_complex z;
    t_complex c;
	double tmp;
    int iter;

    z.x = 0;
    z.y = 0;
    c.x = x;
	c.y = y;
	iter = 0;
	while(iter < 10000 && z.x* z.x + z.y*z.y < 4)
	{
        tmp = z.x;
		z.x = z.x*z.x - z.y*z.y + c.x;
		z.y = 2 * tmp * z.y + c.y;
		iter++;
	}
	if (iter == 10000)
		return(0);
	if (iter == 0)
		return(255255255);
	return(fmax(255255155 * iter/ 10000, 40));
}

void    *ft_mandelbrot_set(t_mlx mlx)
{
	int	x;
	int y;

	mlx.img.img = mlx_new_image(mlx.mlx, 1300, 1300);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bxp, &mlx.img.llen,
			&mlx.img.end);
	y = 0;
	while (y < 1300)
	{
		x = 0;
		while (x < 1300)
		{
			ft_put_px(x, y, ft_colour_m(4 * x / 1300. - 2, 4 * y / 1300. - 2), mlx);
			x++;
		}
		y++;
	}
    mlx_put_image_to_window(mlx.mlx, mlx.wnd, mlx.img.img, 0, 0);
	return(mlx.img.img);
}