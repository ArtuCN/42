/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:41:53 by aconti            #+#    #+#             */
/*   Updated: 2023/12/23 16:01:15 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 500

typedef struct
{
	double real;
	double immaginary;
}t_complex;

typedef struct s_window{
	void	*mlx_connection;
	void	*win;
} t_window;

int		ft_strncmp(const char *str1, const char *str2, int n);
int		close_window(void *param);
void	ft_putstr(char *s);
double	map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	multiply(t_complex a, t_complex b);

#endif