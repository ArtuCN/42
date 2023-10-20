/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:37 by aconti            #+#    #+#             */
/*   Updated: 2023/10/14 18:25:30 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;

	if (start >= strlen(s))
		return (0);
	i = 0;
	sb = malloc(len + 1);
	if (sb == 0)
		return (0);
	while (i < len && s[start])
	{
		sb[i] = s[start];
		i++;
		start++;
	}
	sb[i] = '\0';
	return (sb);
}
/*int main()
{
	const char	*p = "se ni mondo esistesse un po di bene";
	unsigned int	i;
	size_t	l;

	i = 10;
	l = 10;
	printf("mia: %s \n", ft_substr(p, 6, 65));
    //printf("sua: %d \n", substr(p, 11, 10));

}*/
