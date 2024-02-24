/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:38:21 by aconti            #+#    #+#             */
/*   Updated: 2024/02/24 16:40:35 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Prima dello swap: x = %d, y = %d\n", x, y);

    ft_swap(&x, &y);

    printf("Dopo lo swap: x = %d, y = %d\n", x, y);

    return 0;
}
