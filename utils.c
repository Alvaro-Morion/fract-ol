/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:24:09 by amorion-          #+#    #+#             */
/*   Updated: 2021/09/22 12:24:11 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
double	ft_get_number(char *nbr)
{
	double	i;
	double	number;

	number = 0;
	while (*nbr <= '9' && *nbr >= '0')
	{
		number = number * 10 + *nbr - '0';
		nbr++;
	}
	if (*nbr == '.')
	{
		nbr++;
		i = -1;
		while (*nbr <= '9' && *nbr >= '0')
		{
			number = number + (*nbr - '0') * __exp10(i);
			nbr++;
			i--;
		}
	}
	return (number);
}

double	ft_str2dbl(char *nbr, double def)
{
	double	s;

	s = 1;
	while (*nbr && *nbr == ' ' && *nbr == '\t')
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			s = -1;
		nbr++;
	}
	if (*nbr <= '0' && *nbr >= '9' && *nbr != '.')
	{
		printf("Unable to convert: %s, default used: %f", nbr, def);
		return (def);
	}
	return (ft_get_number(nbr) * s);
}

void	ft_put_px(int x, int y, int col, t_mlx mlx)
{
	char	*dest;

	dest = mlx.img.addr + (y * mlx.img.llen + x * (mlx.img.bxp / 8));
	*(unsigned int *)dest = mlx_get_color_value(mlx.mlx, col);
}
