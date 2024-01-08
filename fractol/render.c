/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:10:43 by aconti            #+#    #+#             */
/*   Updated: 2024/01/08 16:36:16 by aconti           ###   ########.fr       */
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
	image->addr[offset] = color;
}

int isMandelbrot(t_complex n)
{
	t_complex t;
	int iteration;
	
	t.immaginary = 0;
	t.real = 0;
	iteration = 0;
	while(iteration < MAXITERATION)
	{
		t = sum_complex(t, squareComplex(n));
		if (module(t) > 4.0)
			return (iteration);
		iteration ++;
	}
	return(iteration);
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
			color = (iteration * 255) / MAXITERATION;
			my_pixel_put(x, y, &fractal->image, iteration);
		}
	else
		my_pixel_put(x, y, &fractal->image, 0x000000);
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
