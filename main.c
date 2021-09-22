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
		ft_putstr_fd("Usage: ./fract-ol [Julia\'s set = J/Mandelbrot\'s set = M] [Re(c)=0] [Im(c)=0]", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	void    *mlx_ptr;
	void	*img_ptr;
	void	*wnd_ptr;

	ft_check_errors(argc, argv);
	mlx_ptr = mlx_init();
	if (*argv[1] == 'J')
		img_ptr = ft_julia_set(argv);
	if (*argv[1] == 'M')
		img_ptr = ft_mandelbrot_set();
	wnd_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fract-ol");
	mlx_put_image_to_window(mlx_ptr, wnd_ptr, img_ptr, 1000, 1000);
	mlx_loop(mlx_ptr);
	return(0);
}