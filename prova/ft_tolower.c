/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:22:54 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 19:23:25 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
