/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:29:57 by aconti            #+#    #+#             */
/*   Updated: 2023/10/14 15:40:05 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int	ft_strlen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*copia;
	size_t	l;
	size_t	i;

	i = 0;
	l = (size_t)ft_strlen((char *)src);
	copia = (char *)malloc(l + 1);
	if (copia == 0)
	{
		return (0);
	}
	while (src[i])
	{
		copia[i] = (char)src[i];
		i++;
	}
	return (copia);
}
/*int main()
{
	const char c[] = "comunisti al rogo";
	printf("mia: %s\n", ft_strdup(c));
	printf("sua: %s\n", strdup(c));
		
}*/
