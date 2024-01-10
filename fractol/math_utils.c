/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:06:50 by aconti            #+#    #+#             */
/*   Updated: 2024/01/10 17:48:37 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//map utilizzata per scalare i pixel

double map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unscaled_num) / (old_max ) + new_min;
}

t_complex calculate_iteration(t_complex t, t_complex c)
{
    t_complex result;

    result.real = t.real * t.real - t.immaginary * t.immaginary + c.real;
    result.immaginary = 2 * t.real * t.immaginary + c.immaginary;

    return (result);
}



double module(t_complex c)
{
    double realPart = c.real;
    double imagPart = c.immaginary;
    return sqrt(realPart * realPart + imagPart * imagPart);
}

int isMandelbrot(t_complex n)
{
	t_complex t;
	int iteration;
	
	t.immaginary = 0;
	t.real = 0;
	iteration = 0;
	while(iteration < MAXITERATION)
	{
		t = calculate_iteration(t, n);
		if (module(t) > 4.0)
			return (iteration);
		iteration ++;
	}
	return(iteration);
}
