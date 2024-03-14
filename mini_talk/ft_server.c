/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:18:01 by aconti            #+#    #+#             */
/*   Updated: 2024/03/14 13:39:40 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//SIGUSR1 = defines '1' bit
//SIGUSR2 = defines '0' bit

#include "minitalk.h"

void	end_str(t_minitalk *server, int *i, int client)
{
	if (server->bits == 8 && server->flag == 1)
	{
		server->str[*i] = server->data;
		(*i)++;
		if (server->data == '\0')
		{
			ft_putstr_fd(server->str, 1);
			free(server->str);
			server->str = NULL;
			server->flag = 0;
			*i = 0;
			send_bit(client, 1, 0);
		}
		server->bits = 0;
	}
}

void	end_len(t_minitalk *server)
{
	if (server->bits == sizeof(int) * 8 && server->flag == 0)
	{
		server->flag = 1;
		server->str = ft_calloc(server->data + 1, sizeof(char));
		if (server->str == NULL)
			exit(0);
		server->bits = 0;
	}
}

void	reciv(int sig, siginfo_t *info, void *context)
{
	static int			i;
	static t_minitalk 	server;
	
	usleep(WAIT_TIME);
	(void)info;
	(void)context;
	if (server.bits == 0)
		server.data = 0;
	if (sig == SIGUSR2 && server.flag == 0)
		server.data |= 1 << (((sizeof(int) * 8) - 1) - server.bits);
	else if (sig == SIGUSR2 && server.flag == 1)
		server.data |= 1 << (((sizeof(char) * 8) - 1) - server.bits);
	server.bits++;
	end_len(&server);
	if (server.flag == 1)
		end_str(&server, &i, info->si_pid);
	send_bit(info->si_pid, 0, 0);
}


int	main(void)
{
	struct sigaction	server;

	sigemptyset(&server.sa_mask);
	server.sa_sigaction = reciv;
	server.sa_flags = SA_SIGINFO | SA_RESTART;
	config(&server);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);	
	while (1)
		pause();
	return (0);
}