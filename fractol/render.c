/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:10:43 by aconti            #+#    #+#             */
/*   Updated: 2024/01/03 21:02:54 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void putpix(double x, double y, t_window window)
{
	t_complex	new;
	int iteration;
	int color;
	int pixel_position;
	
	new.real = map(x, 0, WIDTH, -2.0, 2.0);
	new.immaginary = map(y, HEIGHT, -1,25, 1.25);
	iteration = isMandelbrot(new);
	pixel_position = (y * window.image.line_length) + (x * (window.image.bits_per_pixel / 8));
	if (iteration != -1)
		{
			color = (iteration * 255) / MAXITERATION;
			mlx_pixel_put(window.mlx_connection, window.win, x, y, 0xFFFFFF);
		}
	else
		mlx_pixel_put(window.mlx_connection, window.win, x, y, 0x000000); // Colore Nero

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
	window.image.img_ptr = mlx_new_image(window.mlx_connection, WIDTH, HEIGHT);
	window.image.addr = mlx_get_data_addr(window.image.img_ptr, &window.image.bits_per_pixel, &window.image.line_length, &window.image.endian);
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
