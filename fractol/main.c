/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:59:23 by aconti            #+#    #+#             */
/*   Updated: 2023/12/23 16:01:30 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2 && argc != 4)
	{
		ft_putstr("ERROR\nPlease write 'mandelbrot' OR 'julia'!\n");
		return (0);
	}
	if (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) != 0 && ft_strncmp(argv[1], "julia", 5) != 0))
	{
		ft_putstr("ERROR\nPlease write 'mandelbrot' OR 'julia'!\n");
		return (0);
	}

	window.mlx_connection = mlx_init();
	window.win = mlx_new_window(window.mlx_connection, WIDTH, HEIGHT, "My first window");
	mlx_hook(window.win, 17, 1L << 2, close_window, &window);
	mlx_loop(window.mlx_connection);
}