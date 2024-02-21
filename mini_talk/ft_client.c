/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:30:40 by aconti            #+#    #+#             */
/*   Updated: 2024/02/21 10:32:07 by aconti           ###   ########.fr       */
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

void	send_signal(int pid, unsigned char character)
{
	int	i;
	unsigned char temp;
	
	i = 7;
	temp = character;
	while (i >= 0)
	{
		temp = character >> i;
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(WAIT_TIME);
		i--;
	}
}

int main (int ac, char **av)
{
	int		pid;
	char	*str_to_send;
	int		len;
	int		i;

	if (ft_check(ac, av))
		return (-1);
	pid = ft_atoi(av[2]);
	if (pid <= 0)
		return (-1);
	str_to_send = av[2];
	len = (int)ft_strlen(str_to_send);
	i = -1;
	while (str_to_send[++i])
		send_signal(pid, str_to_send[i]);
	return (0);
}