/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:36:33 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 17:36:36 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == 0)
	{
		while (dest[i])
			i++;
		return (i);
	}
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i);
}
/*int main()
{
	const char src[] = "bo";
	char dest[] = "parola";
	size_t s;
	
	s = 1;
	printf("s: %zu \n", ft_strlcat(dest, src, s));
	printf("dest: %s \n", dest);
}*/
