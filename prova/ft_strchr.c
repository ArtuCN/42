/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:07:06 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 20:32:34 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char		*result;
	int			i;

	i = 0;
	if (c == 0)
		return ("\0");
	while (s[i])
	{
		result = 0;
		if (s[i] == (char)c)
		{
			result = (char *)&s[i];
			return (result);
		}
		i++;
	}
	return (result);
}

/*int main()
{
    const char *str = "adsasd";
    const char *str2 = "adsasd";
	
    printf("funzione mia %s \n", ft_strchr(str, 'z'));
    printf("funzione vera %s \n", strchr(str2, 'z'));

    return 0;
}*/
