/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:41:53 by aconti            #+#    #+#             */
/*   Updated: 2024/01/03 18:46:41 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 500
#define MAXITERATION 1000

// Define colors using RGB values
#define RED       255, 0, 0
#define GREEN     0, 255, 0
#define BLUE      0, 0, 255
#define YELLOW    255, 255, 0
#define MAGENTA   255, 0, 255
#define CYAN      0, 255, 255
#define WHITE     255, 255, 255
#define BLACK		000000;
#define ORANGE    255, 165, 0
#define PURPLE    128, 0, 128
#define PINK      255, 192, 203
#define LIME      0, 255, 0
#define GRAY      128, 128, 128
#define BROWN     165, 42, 42
#define MAROON    128, 0, 0
#define NAVY      0, 0, 128
#define TEAL      0, 128, 128
#define OLIVE     128, 128, 0


typedef struct s_complex
{
	double real;
	double immaginary;
	int		iteration;
}t_complex;

typedef struct s_image {
	void *img_ptr;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_image;

typedef struct s_window{
	void	*mlx_connection;
	void	*win;
	t_image image;
} t_window;

int		ft_strncmp(const char *str1, const char *str2, int n);
int	fractal_render(int argc);
int		close_window(void *param);
void	ft_putstr(char *s);
double map(double unscaled_num, double old_min, double old_max, double new_min, double new_max);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	multiply(t_complex a, t_complex b);
int isMandelbrot(t_complex n);
void putpix(double x, double y, t_window window);



#endif