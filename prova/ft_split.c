/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:19:39 by aconti            #+#    #+#             */
/*   Updated: 2023/10/17 10:19:42 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	free_split(char **r)
{
	int	i;

	if (r)
	{
		i = 0;
		while (r[i] == NULL)
		{
			free(r[i]);
			i++;
		}
		free (r);
	}
}

int	controllo(char **r)
{
	if (r)
		return (1);
	free_split(r);
	return (0);
}

int	k(char const *s, char c)
{
	int	z;
	int	t;
	int	x;

	z = 0;
	t = 0;
	x = 0;
	while (s[z])
	{
		while (s[z])
			z++;
		if (!s[z])
			break ;
		t = 0;
		while (s[z + t] != c && s[z + t])
		{
			t++;
		}
		x++;
		z += t;
	}
	return (x);
}

char	**a(char const *s, char c, int x, int z)
{
	char	**r;
	int		t;
	int		i;

	r = (char **)malloc((x + 1) * sizeof(char *));
	if (controllo(r) == 0)
		return (NULL);
	while (s[z])
	{
		while (s[z] == c)
			z++;
		t = 0;
		while (s[z + t] != c && s[z + t])
			t++;
		r[x] = (char *)malloc(t + 1);
		i = 0;
		while (i < t)
		{
			r[x][i] = s[z + i];
			i++;
		}
		r[x][i] = '\0';
		z += t;
		x++;
	}
	r[x] = NULL;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	int			x;
	char		**r;
	int			z;

	z = 0;
	if (s == NULL || *s == '\0')
		return (NULL);
	x = k(s, c);
	r = (char **)malloc((x + 1) * sizeof(char *));
	if (r == NULL)
	{
		free_split(r);
		return (NULL);
	}
	r = a(s, c, x, z);
	return (r);
}

/*int main() {
    char const *s = "ciao a tutti ";
    char d = ' ';

    char **result = ft_split(s, d);

    int i = 0;
    while (result[i]) {
        printf("Substring %d: %s\n", i, result[i]);
        i++;
    }
	
    return 0;
}*/
