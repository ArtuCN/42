/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:30:40 by aconti            #+#    #+#             */
/*   Updated: 2024/03/13 12:32:52 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int		j;

	j = -1;
	while (str[++j])
	{	 
		i = 0;
		while (send[i] && i < 9)
		{
			send[i] = '0';
			i++;
		}
		i = 8;
		c = str[j];
		while (--i >= 0)
		{
			if (c % 2 != 0)
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
					exit(write(1,"problem\n", 8));
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(write(1,"problem\n", 8));
			}
			usleep(WAIT_TIME);
		}
	}
}



void	client_handler(int sig)
{
	if (sig == SIGUSR2)
		exit(write(1, "end of string\n", 14));
	else if(sig == SIGUSR1)
		return (0);
}

int main (int ac, char **av)
{
	int					server;
	char				*str_to_send;
	struct sigaction	client;

	// n = getpid();
	// client = ft_itoa(n);
	// printf("%s\n", client);
	if (ft_check(ac, av))
		return (-1);
	sigempyset(&client.sa_mask);
	client.sa_flags = 0;
	client.sa_handler = client_handler;
	server = ft_atoi(av[1]);
	if (server <= 0)
		return (-1);
	//send_signal(server, client);
	//usleep(WAIT_TIME);
	str_to_send = av[2];
	send_signal(server, str_to_send);
	return (0);
}