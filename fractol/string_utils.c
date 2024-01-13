/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:28:57 by aconti            #+#    #+#             */
/*   Updated: 2024/01/13 11:27:52 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int	i;

	i = 0;
	while (i < n && (unsigned char)str1[i] && (unsigned char)str2[i])
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	ft_putstr(char *s)
{
	while (*s != '\0')
		write(1, s++, 1);
}

double atod(char *str)
{
	double	result;
	double	decimal;
	int 	neg;
	int		i;

	i = 0;
	result = 0;
	decimal = 0;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != '.')
		result = result * 10 + (double)(str[i++] - 48);
	if (str[i] == '.')
	{
		i++;
		while(str[i])
			decimal = decimal * 10 + (double)(str[i++] - 48);
	}
	while(decimal >= 1)
		decimal /= 10;
	return ((result + decimal) * neg);
}
