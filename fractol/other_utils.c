/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:47:51 by aconti            #+#    #+#             */
/*   Updated: 2024/01/18 15:28:55 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_color_change(int keysym, t_fractal *fractal)
{
	reset_image(fractal);
	if (keysym == G)
	{
		if (fractal->image.green)
			fractal->image.green = 0;
		else
			fractal->image.green = 1;
	}
	if (keysym == R)
	{
		if (fractal->image.red)
			fractal->image.red = 0;
		else
			fractal->image.red = 1;
	}
	if (keysym == B)
	{
		if (fractal->image.blue)
			fractal->image.blue = 0;
		else
			fractal->image.blue = 1;
	}
}
