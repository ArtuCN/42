/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:42:50 by aconti            #+#    #+#             */
/*   Updated: 2024/02/24 16:48:16 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main() {
    unsigned char test_value = 10; // Valore di prova

    printf("Valore in binario di %d: \n", test_value);
    print_bits(test_value);
    printf("\n");

    return 0;
}