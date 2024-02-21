/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:18:01 by aconti            #+#    #+#             */
/*   Updated: 2024/02/21 10:18:07 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//SIGUSR1 = defines '1' bit
//SIGUSR2 = defines '0' bit

#include "minitalk.h"

static void handle_signal(int signal)
{
	static unsigned char	current_char;//stores the current character being recived
	static int				bit_index;//stores the index of current bit being recived
	
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == END_TRANSMISSION)
			write(1, "\n", 1);
		else
			ft_putchar_fd(current_char, 1);
		
		current_char = 0;
		bit_index = 0;
	}
	else
		current_char <<= 1;//spostamento a sinistra
}

int	main(void)
{
	int	id;
	
	id = (int)(getpid());
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		usleep(WAIT_TIME);
}
