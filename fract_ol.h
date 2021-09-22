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
# include<stdlib.h>
# include<math.h> 
# include<mlx.h>
typedef struct s_complex
{
    double   x;
    double   y;
} t_complex;

void	ft_putstr_fd(char *str, int fd);

#endif
