/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:18:01 by aconti            #+#    #+#             */
/*   Updated: 2024/03/09 14:09:07 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//SIGUSR1 = defines '1' bit
//SIGUSR2 = defines '0' bit

#include "minitalk.h"

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num <= 9)
		ft_putchar (('0' + num));
}

void	conv_txt(unsigned char *s)
{
	int		i;
	int		result;
	
	result = 0;
	i = 8;
	while (s[--i])
	{
		if (s[i] == '0' || s[i] == '1')
			result = result * 2 + (s[i] - '0');
	}	
	i = 7;
	write(1, &result, 1);
}

void	rec(int sig)
{
	static int		i = 8;
	static unsigned char	c[9];
	
	if (sig == SIGUSR1)
		c[--i] = '1';
	else if (sig == SIGUSR2)
		c[--i] = '0';
	usleep(WAIT_TIME);
	if (i == 0)
	{
		c[8] = '\0';
		i = 8;
		conv_txt(c);
	}
}

int	main(void)
{
	getpid();
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, rec);
	signal(SIGUSR2, rec);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}