/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:44:25 by aconti            #+#    #+#             */
/*   Updated: 2024/02/21 10:15:56 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

static int	cancel(const char str)
{
	if (str == 32 || (str >= '\t' && str <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	r;

	r = 0;
	neg = 1;
	while (cancel(*str) == 1)
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0' && *str <= '9') && *str)
	{
		r *= 10;
		r += (*str - 48);
		str++;
	}
	return (r * neg);
}

int ft_strchr(char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + 48;
	write(fd, &c, 1);
}