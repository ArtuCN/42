/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:14:57 by aconti            #+#    #+#             */
/*   Updated: 2024/03/13 11:55:02 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include  <limits.h>
#include <stdlib.h>
#include <string.h>
# include "libft/libft.h" // ft_atoi(), ft_strlen(), ft_putstr(), ft_putnbr()

# define WAIT_TIME 100
size_t	ft_strlen(const char *arg);
int		cancel(const char str);
int		ft_atoi(const char *str);
int 	ft_strchr(char *str, char c);
int		ft_check(int ac, char **av);
void	send_signal(int pid, char *str);

void		ft_putchar(int c);
void		ft_putnbr(int n);
int			ft_strchr(char *str, char c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *arg);

typedef struct s_minitalk
{
	int 	bits;
	int		data;
	int		flag;
	char	*str;
}	t_minitalk;

#endif