/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:19:00 by aconti            #+#    #+#             */
/*   Updated: 2024/03/09 10:28:23 by aconti           ###   ########.fr       */
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

# define WAIT_TIME 100
# define END_TRANSMISSION '\0'

//server
void handle_signal(int signal);
void	send_signal(int pid, char *str);
//utils
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_strchr(char *str, char c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *arg);

#endif