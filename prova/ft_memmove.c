/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:03:29 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 15:51:04 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = 0;
	if (!dest || !src)
		return (0);
	if (d > s)
	{
		while (len-- > 0)
		{
			d[len] = s[len];
		}
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
/*int main()
{
	char	dest[] = "dioboia";
	const char	src[] = "wild";
    printf("prima di memmove %s\n", dest);
	ft_memmove(dest, src, 0);
	printf("dopo di memmove %s\n", dest);
}*/
