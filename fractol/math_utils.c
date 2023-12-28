/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:06:50 by aconti            #+#    #+#             */
/*   Updated: 2023/12/23 14:48:57 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//map utilizzata per scalare i pixel

double map(double unscaled_num, double new_min, double new_max, double old_max)
{
    return (new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min;
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