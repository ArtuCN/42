/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:47:34 by aconti            #+#    #+#             */
/*   Updated: 2024/01/13 13:34:32 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(t_fractal *fractal)
{    
    mlx_destroy_image(fractal->mlx_connection,
					fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
						fractal->mlx_window);
	mlx_destroy_display(fractal-> mlx_connection);
	free(fractal-> mlx_connection);
    ft_putstr("\nFinestra chiusa! :)");
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 65307)
		close_window(fractal);
	if (keysym == LEFT)
		fractal->shift_x -= (0.5 * fractal->zoom);	
	else if (keysym == RIGHT)
		fractal->shift_x += (0.5 * fractal->zoom);	
	else if (keysym ==  UP)
		fractal->shift_y += (0.5 * fractal->zoom);	
	else if (keysym == DOWN)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (!ft_strncmp(fractal->name, "julia", 5) && keysym == L)
		fractal->julia_x -= (0.25 * fractal->zoom);
	else if (!ft_strncmp(fractal->name, "julia", 5) && keysym == K)
		fractal->julia_x += (0.25 * fractal->zoom);
	else if (!ft_strncmp(fractal->name, "julia", 5) && keysym == N)
		fractal->julia_y -= (0.25 * fractal->zoom);
	else if (!ft_strncmp(fractal->name, "julia", 5) && keysym == M)
		fractal->julia_y += (0.25 * fractal->zoom);
	else if (keysym == J)
		fractal->name = "julia";
	else if (keysym == F)
		fractal->name = "mandelbrot";
	fractal_render(fractal);
	return (0);
}

void    events(t_fractal *fractal)
{
    mlx_key_hook(fractal->mlx_window, key_handler, fractal);
    mlx_hook(fractal->mlx_window, 17, 1L << 2, close_window, fractal);
    mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
}