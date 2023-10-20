/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:00:18 by aconti            #+#    #+#             */
/*   Updated: 2023/10/18 14:07:43 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	len(int n)
{
	int	lunghezza;

	if (n < 0)
	{
		n = -n;
	}
	lunghezza = 0;
	if (n == 0)
	{
		lunghezza++;
		return (lunghezza);
	}
	while (n > 0)
	{
		n = n / 10;
		lunghezza++;
	}
	return (lunghezza);
}

char	*ret(char *r, int l, int n)
{
	if (r[0] == '-')
	{
		r[l + 1] = '\0';
		while (n > 0 && l > 0)
		{
			r[l] = n % 10 + 48;
			l--;
			n = n / 10;
		}
	}
	else
	{
		r[l] = '\0';
		while (n >= 0 && l >= 0)
		{
			r[l - 1] = n % 10 + 48;
			l--;
			n = n / 10;
		}
	}
	return (r);
}

char	*z(char *r)
{
	if (!r)
		return (NULL);
	r[0] = 48;
	r[1] = 0;
	return (r);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		l;

	l = len(n);
	if (n < 0)
	{
		n = -n;
		r = (char *)malloc(l + 2);
		if (!r)
			return (NULL);
		else
			r[0] = '-';
	}
	else
	{
		r = (char *)malloc(l + 1);
		if (!r)
			return (NULL);
	}
	ret(r, l, n);
	return (r);
}

/*int main()
{
	printf("eiaeiaellala: %s", ft_itoa(-10));
}*/
