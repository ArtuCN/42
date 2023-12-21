/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:41:53 by aconti            #+#    #+#             */
/*   Updated: 2023/12/21 17:41:12 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include <stdlib.h>


#define WIDTH 800
#define HEIGHT 500

typedef struct{
	double real;
	double complex;
}t_complex;

typedef struct s_window{
	void	*mlx_connection;
	void	*win;
} t_window;

#endif