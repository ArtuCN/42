/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:57 by aconti            #+#    #+#             */
/*   Updated: 2024/01/27 18:41:10 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sign(char av)
{
	if (av == '+')
		return (1);
    else if ( av == '-')
        return(-1);
	else 
		return (0);
}

int	ft_check_a(t_stack **a)
{
	t_stack    *tmp;

	while (*a)
	{
		tmp = (*a)->next;
		while (tmp)
		{
			if ((*a)->val == tmp->val)
			{
				printf("Errore nell'inserimento!\n");
				return (0);
			}
			tmp = tmp->next;
		}
		*a = (*a)->next;
	}
	return (1);
}

t_stack *add_stack(t_stack **a, int num, int j)
{
    if (num > 2147483647 || num < -2147483648)
        return NULL;

    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return NULL;
    new_node->val = num;
    new_node->index = j;
    new_node->next = *a; // Link the new node to the existing list
    return new_node;
}


