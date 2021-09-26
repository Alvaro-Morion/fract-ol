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
void	ft_check_errors(int argc,char **argv)
{
	if (argc == 1 || !((*argv[1] == 'J' || *argv[1] == 'M') && !argv[1][1]))
	{
		printf("./fract-ol [Julia = J Mandelbrot = M] [Re(z0)=0.285] [Im(z0)=-0.01]\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_mlx mlx;

	ft_check_errors(argc, argv);
	mlx.mlx = mlx_init();
	mlx.wnd = mlx_new_window(mlx.mlx, 1300, 1300, "fract-ol");
	if (*argv[1] == 'J')
		mlx_put_image_to_window(mlx.mlx, mlx.wnd, ft_julia_set(argc, argv, mlx), 0 , 0);
	if (*argv[1] == 'M')
		mlx.img.img = ft_mandelbrot_set(mlx);
	//mlx_key_hook(mlx.wnd, ft_press_key, &mlx);
	mlx_loop(mlx.mlx);
	return(0);
}