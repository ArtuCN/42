/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:06:50 by aconti            #+#    #+#             */
/*   Updated: 2024/01/08 13:13:13 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//map utilizzata per scalare i pixel

double map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unscaled_num) / (old_max ) + new_min;
}

t_complex sum_complex(t_complex a, t_complex b)
{
	t_complex result;

	result.real = a.real + b.real;
	result.immaginary = a.immaginary + b.immaginary;
	return (result);
}

t_complex	squareComplex(t_complex a)
{
	t_complex result;

	result.real = a.real * a.real - a.immaginary * a.immaginary;
	result.immaginary = 2 * a.real * a.immaginary;
	return (result);
}

double module(t_complex c)
{
    double realPart = c.real;
    double imagPart = c.immaginary;
    return sqrt(realPart * realPart + imagPart * imagPart);
}
