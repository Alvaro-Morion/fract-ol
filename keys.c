/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:59:00 by amorion-          #+#    #+#             */
/*   Updated: 2021/09/26 17:59:03 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void ft_close(t_mlx mlx)
{
    mlx_destroy_window(mlx.mlx, mlx.wnd);
    exit(0);
}

int ft_press_key(int key, t_mlx *mlx)
{
    if (key == 53)
        ft_close(*mlx);
    return (0);
}

void ft_zoom_in(t_mlx *mlx)
{
    mlx->img.xmax = 0.99 * mlx->img.xmax;
    mlx->img.ymax = 0.99 * mlx->img.xmax;
    ft_julia_set(mlx->argc, mlx->argv, *mlx);
}
int ft_mouse(int mouse, t_mlx *mlx)
{
    if (mouse == 5)
        ft_zoom_in(mlx);
    /*if (mouse == 4)
        ft_zoom_out(*mlx);*/
    return(0);
}