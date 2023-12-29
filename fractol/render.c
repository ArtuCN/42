/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:10:43 by aconti            #+#    #+#             */
/*   Updated: 2023/12/29 17:45:00 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void putpix(double x, double y, t_window window)
{
	t_complex	new;
	int iteration;
	int color;
	
	new.real = map(x, 0, WIDTH, -2.0, 2.0);
	new.immaginary = map(y, HEIGHT, -1,25, 1.25);
	iteration = isMandelbrot(new);
	if (iteration == MAXITERATION)
		mlx_pixel_put(window.mlx_connection, window.win, x, y, 0x000000);
	else
		{
			color = (iteration * 255) / MAXITERATION;
			mlx_pixel_put(window.mlx_connection, window.win, x, y, color * 0x010000 + color * 0x000100 + color * 0x000001);
		}
}

int	fractal_render(int argc)
{
	t_window	window;
	double x;
	double	y;
	
	x = 0;
	y = HEIGHT;
	window.mlx_connection = mlx_init();
	window.win = mlx_new_window(window.mlx_connection, WIDTH, HEIGHT, "My first window");
	mlx_hook(window.win, 17, 1L << 2, close_window, &window);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
			putpix (x, y++, window);
		x++; // Passa alla prossima colonna
	}
	mlx_loop(window.mlx_connection);
	return (argc);
}