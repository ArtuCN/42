/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:59:23 by aconti            #+#    #+#             */
/*   Updated: 2023/12/21 17:43:03 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(void *param) {
    t_window *window = (t_window *)param;
    mlx_destroy_window(window->mlx_connection, window->win);
	printf("Hai chiuso la finestra!\n");
    exit(0);
}

int main(int argc, char **argv)
{
	//t_complex a;
	//a.complex = 2.0;
    //printf("Complex Number: %.2f + %.2fi\n", a.real, a.complex);
	t_window	window;
	
	window.mlx_connection = mlx_init();
	window.win = mlx_new_window(window.mlx_connection, WIDTH, HEIGHT, "My first window");
	mlx_hook(window.win, 17, 1L << 2, close_window, &window);
	mlx_loop(window.mlx_connection);
}