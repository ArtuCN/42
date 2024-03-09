/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:30:40 by aconti            #+#    #+#             */
/*   Updated: 2024/03/09 15:12:50 by aconti           ###   ########.fr       */
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

int	ft_check(int ac, char **av)
{
	int	i;
	
	if (ac != 3)
		return (1);
	i = -1;
	while (av[1][++i])
	{
		if (!ft_strchr("0123456789", av[1][i]))
			return (1);
	}
	return (0);
}

void	send_signal(int pid, char *str)
{
	int		i;
	char	c;
	char	send[8];
	int j = -1;

	while (str[++j])
	{	
		i = -1;
		while (send[++i])
			send[i] = '0';
		i = 8;
		c = str[j];
		while (--i >= 0)
		{
			if (c % 2)
				send[i] = '1';
			else
				send[i] = '0';
			c /= 2;
		}
		while (send[++i])
		{
			if (send[i] == '1')
			{
				
				if (kill(pid, SIGUSR1) == -1)
					printf("problem: %d\n", i);
				else
					printf("send: %d\n", i);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					printf("problem: %d\n", i);
				else
					printf("send: %d\n", i);
			}
			usleep(WAIT_TIME);
		}
	}
}



int main (int ac, char **av)
{
	int		pid;
	char	*str_to_send;

	if (ft_check(ac, av))
		return (-1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (-1);
	str_to_send = av[2];
	send_signal(pid, str_to_send);
	return (0);
}