/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:59:23 by aconti            #+#    #+#             */
/*   Updated: 2024/01/04 11:29:25 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
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
	fractal_render(argv);
}
