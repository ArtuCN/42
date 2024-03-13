/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:18:01 by aconti            #+#    #+#             */
/*   Updated: 2024/03/13 11:56:26 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//SIGUSR1 = defines '1' bit
//SIGUSR2 = defines '0' bit

#include "minitalk.h"

void	conv_txt(unsigned char *s)
{
	int		i;
	int		result;
	static char	*str;
	static int	j = 0;
	
	result = 0;
	i = 8;
	while (s[--i])
	{
		if (s[i] == '0' || s[i] == '1')
			result = result * 2 + (s[i] - '0');
	}
	str[j] = result;
	if (str[j] == '\0')
		write(1, &result, j);
	else
		j++;
}

void	reciv(int sig)
{
	static int		i = 8;
	static unsigned char	c[9];
	
	printf("ricevuto");
	if (sig == SIGUSR1)
		c[--i] = '1';
	else if (sig == SIGUSR2)
		c[--i] = '0';
	usleep(WAIT_TIME);
	if (i == 0)
	{
		c[8] = '\0';
		i = 8;
		printf("entrato");
		conv_txt(c);
	}
}

// void	pid_g(int sig)
// {
	
// }

int	main(void)
{
	//getpid();
	ft_putnbr(getpid());
	write(1, "\n", 1);	
	// signal(SIGUSR1, pid_g);
	// signal(SIGUSR2, pid_g);
	// while (1)
	// 	usleep(WAIT_TIME);
	signal(SIGUSR1, reciv);
	signal(SIGUSR2, reciv);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}