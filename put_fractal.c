#include "fract_ol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void    ft_put_fractal(int argc,char **argv, t_mlx mlx)
{
    if (!ft_strcmp(argv[1], "J"))
        ft_julia_set(argc, argv, mlx);
    if (!ft_strcmp(argv[1], "M"))
        ft_mandelbrot_set(mlx);
}