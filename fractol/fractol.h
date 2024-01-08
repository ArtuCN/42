/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:41:53 by aconti            #+#    #+#             */
/*   Updated: 2024/01/08 16:05:47 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 500
#define MAXITERATION 1000

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red


typedef struct s_complex
{
	double real;
	double immaginary;
}t_complex;

typedef struct s_image
{
	void *img_ptr;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image image;
	double	escape_value;
	int		iteration_def;
	double	shift_y;
	double	shift_x;
	double	zoom;
	double	julia_x;
	double	julia_y;
} t_fractal;

int		ft_strncmp(const char *str1, const char *str2, int n);
void	fractal_render(t_fractal *fractal);
int		close_window(void *param);
void	ft_putstr(char *s);
double map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	squareComplex(t_complex a);
int isMandelbrot(t_complex n);
void	fractal_init(t_fractal *fractal);
void    events(t_fractal *fractal);
void data_init(t_fractal *fractal);
void handle_pix(int x, int y, t_fractal *fractal);
double module(t_complex c);
void malloc_error(void);


#endif