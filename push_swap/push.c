/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:18:57 by aconti            #+#    #+#             */
/*   Updated: 2024/02/13 22:37:28 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack **add, t_stack **take)
{
	t_stack *g;

	if (!*take || !take)
		return ;
	g = malloc(sizeof(t_stack));
	if (!g)
	{
		free_stack(g);
		return ;
	}
	g->val = (*take)->val;
	g->next = *add;
	*add = g;
	*take = (*take)->next;
	write(1, "pa\n", 3);
}

void pb(t_stack **add, t_stack **take)
{
	t_stack *g;

	if (!*take || !take)
		return ;
	g = malloc(sizeof(t_stack));
	if (!g)
	{
		free_stack(g);
		return ;
	}
	g->val = (*take)->val;
	g->next = *add;
	*add = g;
	*take = (*take)->next;
	write(1, "pb\n", 3);
}

/*int main()
{
    // Example usage
    t_stack *stackA = (t_stack *)malloc(sizeof(t_stack));
    t_stack *nodeB = (t_stack *)malloc(sizeof(t_stack));
    stackA->index = 31;
    nodeB->index = 42;
    push(&stackA, nodeB);
    printf("%d\n",stackA->index);
        printf("%d",stackA->next->index);
    // Cleanup: Free allocated memory
    while (stackA)
    {
        t_stack *temp = stackA;
        stackA = stackA->next;
        free(temp);
    }
    free(nodeB);
    return 0;
}*/