/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:15:27 by aconti            #+#    #+#             */
/*   Updated: 2023/10/13 16:28:28 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	if (!s)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s2[i] == (char)c)
			return (s2 + i);
		i++;
	}
	return (0);
}
