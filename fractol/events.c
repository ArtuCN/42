/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:47:34 by aconti            #+#    #+#             */
/*   Updated: 2024/01/04 12:28:32 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(void *param)
{   
    t_window *window = (t_window *)param;
    mlx_destroy_window(window->mlx_connection, window->win);
	ft_putstr("Hai chiuso la finestra!\n");
    exit(0);
}