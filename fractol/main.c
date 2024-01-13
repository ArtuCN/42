/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:59:23 by aconti            #+#    #+#             */
/*   Updated: 2024/01/13 13:28:30 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
ac 2 = mandelbrot
ac 4 = julia (a.out, julia, n, n)

name = mandelbrot || julia

*/

#include "fractol.h"

int main(int ac, char **av)
{
	t_fractal	fractal;
	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		|| ((4 == ac) && !ft_strncmp(av[1], "julia", 5)))
		{
			fractal.name = av[1];
			if (!ft_strncmp(av[1], "julia", 5))
			{
				fractal.julia_x = atod(av[2]);
				fractal.julia_y = atod(av[3]);
			}
			fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_loop(fractal.mlx_connection);
		}
	else
		ft_putstr(INPUT_ERROR);
}
