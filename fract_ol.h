/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:24:35 by amorion-          #+#    #+#             */
/*   Updated: 2021/09/22 12:24:38 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h> 
# include<mlx.h>

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bxp;
	int		llen;
	int		end;
	double	xmax;
	double	ymax;
}	t_img;
typedef struct s_mlx
{
	void	*mlx;
	void	*wnd;
	t_img	img;
	int		argc;
	char	**argv;
}	t_mlx;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

double	ft_str2dbl(char *nbr, double def);
void	ft_put_px(int x, int y, int col, t_mlx mlx);
void	ft_julia_set(int argc, char **argv, t_mlx mlx);
void	ft_mandelbrot_set(t_mlx mlx);
void	ft_put_fractal(int argc, char **argv, t_mlx mlx);
int		ft_press_key(int key, t_mlx *params);
int		ft_mouse(int mouse, int x, int y, t_mlx *mlx);
#endif
