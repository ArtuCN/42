/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:30:40 by aconti            #+#    #+#             */
/*   Updated: 2024/03/14 12:49:50 by aconti           ###   ########.fr       */
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

void	send_str(int pid, char *str)
{
	int	i;
	
	i = -1;
	send_num(pid, ft_strlen(str));
	ft_putstr_fd("sent length\n", 1);
	while (str[++i] != '\0')
		send_char(pid, str[i]);
	ft_putstr_fd("sent string\n", 1);
	send_char(pid, '\0');
	ft_putstr_fd("sent end of string\n", 1);
}

void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("ACK signal received from server\n", 1);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("end of message signal received from server\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int main (int ac, char **av)
{
	int					server;
	char				*str_to_send;
	struct sigaction	client;

	if (ft_check(ac, av))
		return (write(1, "error\n", 7));
	sigemptyset(&client.sa_mask);
	client.sa_flags = SA_RESTART;
	client.sa_handler = client_handler;
	config(&client);
	server = ft_atoi(av[1]);
	if (server <= 0)
		return (-1);
	//send_signal(server, client);
	//usleep(WAIT_TIME);
	str_to_send = av[2];
	send_str(server, str_to_send);
	return (0);
}