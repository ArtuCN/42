/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:10:43 by aconti            #+#    #+#             */
/*   Updated: 2024/01/10 17:49:04 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//4:800 = x : 500
// in map no old min for normie

void my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = y * image->line_length
		+ x * (image->bits_per_pixel / 8);
	image->addr[offset] = color; //blu
	//image->addr[offset + 1] = color; //verde
	image->addr[offset + 2] = color; //rosso
}

void handle_pix(int x, int y, t_fractal *fractal)
{
	t_complex	new;
	int iteration;
	int color;
	int pixel_position;
	
	new.real = map(x, -2, +2, WIDTH);
	new.immaginary = map(y, 1.25, -1.25, HEIGHT);
	iteration = isMandelbrot(new);
	pixel_position = (y * fractal->image.line_length) + (x * (fractal->image.bits_per_pixel / 8));
	if (iteration != MAXITERATION)
		{
			color = (iteration * 10000) / MAXITERATION;
			my_pixel_put(x, y, &fractal->image, color);
		}
	else
	{
		color = (iteration * 10000) / MAXITERATION;
		my_pixel_put(x, y, &fractal->image, 0x000000);
	}		
}

void	fractal_render(t_fractal *fractal)
{
	int x;
	int	y;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pix (x, y, fractal); 
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img_ptr, 0, 0);
	mlx_loop(fractal->mlx_connection);
}
