/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:04:19 by aconti            #+#    #+#             */
/*   Updated: 2023/10/13 17:46:36 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	char	*b;

	i = 0;
	while (big[i] && len > i)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && (i + j) < len)
		{
			j++;
		}
		if (!little[j])
		{
			b = (char *)&big[i];
			return (b);
		}
		i++;
	}
	return (0);
}
