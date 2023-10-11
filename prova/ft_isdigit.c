/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:24:36 by aconti            #+#    #+#             */
/*   Updated: 2023/10/09 11:27:16 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg >= '9')
		return (1);
	return (0);
}
/*int main()
{
	printf("l is -> %d\n", isdigit('l'));
	printf("l is -> %d\n", isdigit(5));
	printf("l is -> %d\n", isdigit('1'));
}*/
