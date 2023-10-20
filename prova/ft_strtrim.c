/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:58:06 by aconti            #+#    #+#             */
/*   Updated: 2023/10/16 14:58:12 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

size_t	ft_strlen(const char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		i++;
	}
	return (i);
}

int	cont(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] == set[i])
	{
		i++;
		if (s1[i] == 0 && set[i] == 0)
			return (0);
	}
	return (1);
}

int	checks(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] == set[i])
		i++;
	return (i);
}

int	checke(char const *s1, char const *set, int j)
{
	int	x;

	x = 0;
	while (s1[j] == set[x])
	{
		j--;
		x++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		i;
	int		j;
	int		y;

	if (cont(s1, set) == 0)
		return (0);
	y = 0;
	if (*s1 == 0)
		return (0);
	i = checks(s1, set);
	j = ft_strlen(s1) - 1;
	j = checke (s1, set, j);
	r = (char *)malloc(j - i + 1);
	if (r == 0)
		return (0);
	while (i <= j)
	{
		r[y] = s1[i];
		i++;
		y++;
	}
	r[y] = '\0';
	return (r);
}
/*int main()
{
	printf("ciuccia :%s", ft_strtrim("babbo", "babbo"));
}*/
