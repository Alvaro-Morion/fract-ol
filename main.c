/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:32:18 by amorion-          #+#    #+#             */
/*   Updated: 2021/09/19 14:32:20 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_check_errors(int argc, char **argv)
{
	if (argc == 1 || !((*argv[1] == 'J' || *argv[1] == 'M') && !argv[1][1]))
	{
		printf("./fract-ol [Julia = J Mandelbrot = M] ");
		printf("[Re(z0)=0.285] [Im(z0)=-0.01]\n");
		exit(0);
	}
}

void	leaks(void)
{
	system("leaks fract-ol");
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	atexit(leaks);
	ft_check_errors(argc, argv);
	mlx = malloc(sizeof(t_mlx));
	mlx->argc = argc;
	mlx->argv = argv;
	mlx->mlx = mlx_init();
	mlx->wnd = mlx_new_window(mlx->mlx, 1300, 1300, "fract-ol");
	mlx->img.img = mlx_new_image(mlx->mlx, 1300, 1300);
	mlx->img.xmax = 2;
	mlx->img.ymax = 2;
	ft_put_fractal(mlx->argc, mlx->argv, *mlx);
	mlx_key_hook(mlx->wnd, ft_press_key, mlx);
	mlx_mouse_hook(mlx->wnd, ft_mouse, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
