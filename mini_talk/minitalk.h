/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:19:00 by aconti            #+#    #+#             */
/*   Updated: 2024/02/21 09:47:58 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

# define WAIT_TIME 100
# define END_TRANSMISSION '\0'

//server
static void	handle_signal(int signal);
//client
//utils
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_strchr(char *str, char c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *arg);

#endif