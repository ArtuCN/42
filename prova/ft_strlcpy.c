/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:49:04 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 15:51:29 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] && i < s - 1)
	{
		dest[i] = src[i];
		i++;
	}
	j = i;
	while (j < s)
	{
		dest[j] = 0;
		j++;
	}
	return (i);
}
/*int main()
{
	const char src[] = "porcodio";
	char dest[] = "widucemadonnacane";
	size_t s;
	
	s = 5;
	printf("size: %zu \n", ft_strlcpy(dest, src, 5));
	printf("dest: %s", dest);
    return 0;
}*/
