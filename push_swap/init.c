/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:37 by aconti            #+#    #+#             */
/*   Updated: 2024/02/26 16:21:20 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float media_array(long array[], int lunghezza)
{
	float media;
    int i;
	int somma;

    i = 0;
    if (lunghezza == 0)
        return 0;
    somma = 0;
    while (i < lunghezza)
        somma += array[i++];
	media = (float)somma / lunghezza;    
	return (media);
}

void add_push(t_stack *new_node, int size, long int *arr)
{
	float media;
	media = media_array(arr, size);

	if (new_node->val < media / 4)
			new_node->push = 1;
		else if (new_node->val < media / 3)
			new_node->push = 2;
		else if (new_node->val < media / 2)
			new_node->push = 3;
		else if (new_node->val < media / 1.5)
			new_node->push = 4;
		else if (new_node->val < media)
			new_node->push = 5;		
		else
			new_node->push = 6;
}

void array_to_stack(long int *arr, int size, t_stack **stack)
{
	t_stack *new_node;
    t_stack *temp; 
	int i; 
    
    i = size - 1;
    temp = new_node;
	while (i >= 0)
	{
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
        {
            while (*stack != NULL)
            {
                temp = *stack;
                *stack = (*stack)->next;
                free(temp);
            }
            return ;
        }
		new_node->val = arr[i];
		if (size > 50)
			add_push(new_node, size, arr);
		else
			new_node->push = 0;
		new_node->next = *stack;
		*stack = new_node;
		i--;
	}
}
