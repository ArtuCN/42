/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:28:57 by aconti            #+#    #+#             */
/*   Updated: 2023/12/23 13:04:11 by aconti           ###   ########.fr       */
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
