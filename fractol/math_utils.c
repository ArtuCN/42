/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:06:50 by aconti            #+#    #+#             */
/*   Updated: 2023/12/29 17:37:27 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//map utilizzata per scalare i pixel

double map(double unscaled_num, double old_min, double old_max, double new_min, double new_max)
{
	return( (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

t_complex sum_complex(t_complex a, t_complex b)
{
	t_complex result;

	result.real = a.real + b.real;
	result.immaginary = a.immaginary + b.immaginary;
	return (result);
}

t_complex multiply(t_complex a, t_complex b)
{
	t_complex result;
	
	result.real = a.real * b.real - a.immaginary * b.immaginary;
	result.immaginary = a.real * b.immaginary + a.immaginary * b.real;
	return (result);
}

double	squareRoot(double n)
{
	double x = n;
	double y = 1.0;
	double epsilon = 0.000001;

	while (x - y > epsilon)
	{
		x = (x + y) / 2.0;
		y = n / x;
	}
    return (x);
}

int isMandelbrot(t_complex n)
{
	t_complex t;
	t.immaginary = 0;
	t.real = 0;
	n.iteration = 0;
	
	t = sum_complex(t, n);
	while(n.iteration < MAXITERATION)
	{
		t = sum_complex(multiply(n, n), t);
		n = t;
		if (squareRoot(t.immaginary * t.immaginary + t.real *t.real) > 2.0)
			return (n.iteration);
		n.iteration ++;
	}
	return(n.iteration);
}