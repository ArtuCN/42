/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:47:34 by aconti            #+#    #+#             */
/*   Updated: 2024/01/10 17:37:26 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(void *param)
{   
    t_fractal *fractal = (t_fractal *)param;
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
	ft_putstr("Hai chiuso la finestra!\n");
    exit(0);
}

/*int key_()
{
    
}*/

void    events(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, 2, 53, close_window, fractal);
    mlx_hook(fractal->mlx_window, 17, 1L << 2, close_window, fractal);
}