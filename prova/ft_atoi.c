/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:47:42 by aconti            #+#    #+#             */
/*   Updated: 2023/10/13 18:55:56 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	r;

	r = 0;
	neg = 1;
	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	return (r * neg);
}
/*int main()
{
	const char	c[]= "	\t \n \v \f \r  +00324a8";
	
	printf("atoi :%d \n", atoi(c));
	printf("ft_atoi : %d", ft_atoi(c));
}*/
