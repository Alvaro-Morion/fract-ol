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
    printf("%d\n", key);
    if (key == 53)
        ft_close(*mlx);
    return (0);
}