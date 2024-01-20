/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:10:43 by aconti            #+#    #+#             */
/*   Updated: 2024/01/13 12:33:34 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//4:800 = x : 500
// in map no old min for normie

void my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;
	
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) 
	{
		offset = (y * image->line_length	+ x * (image->bits_per_pixel / 8));
		if (image->green)
			image->addr[offset + 1] = color;
		if (image->blue)
			image->addr[offset] = color;
		if (image->red)
			image->addr[offset + 2] = color;
	}
}

void handle_pix(int x, int y, t_fractal *fractal)
{
	t_complex	new;
	int iteration;
	int color;
	int pixel_position;
	double smooth;

	new.real = (map(x, pianox, pianoX, WIDTH) * fractal->zoom + fractal->shift_x);
	new.immaginary = (map(y, pianoY, pianoy, HEIGHT) * fractal->zoom + fractal->shift_y);
	if (!ft_strncmp(fractal->name, "julia", 5))
		iteration = isJulia(new, fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		iteration = isMandelbrot(new, fractal);
	//else
	//{
		//iteration = spiral_iteration(new);
		//handle_bonus(x, y, fractal, iteration);
		//return ;
	//}
	smooth = (double)iteration / (MAXITERATION + fractal->mod);
	pixel_position = (y * fractal->image.line_length) + (x * (fractal->image.bits_per_pixel / 8));
	if (iteration != MAXITERATION + fractal->mod)
	{
		color = (smooth * 10000);
		my_pixel_put(x + fractal->shift_x, y + fractal->shift_y, &fractal->image, color);
	}
	else
		my_pixel_put(x + fractal->shift_x, y + fractal->shift_y, &fractal->image, WHITE);
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
}

void	reset_image(t_fractal *fractal)
{
	int y;
	int x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			my_pixel_put(x + fractal->shift_x, y + fractal->shift_y, &fractal->image, BLACK);
	}
}
