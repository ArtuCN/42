/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:12 by aconti            #+#    #+#             */
/*   Updated: 2024/01/27 20:01:45 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstlast(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack *ls;
    if (*lst == NULL)
        *lst = new;
    else
    {
        ls = ft_lstlast(*lst);
        ls -> next = new;
    }
}

void	rotate(t_stack  **lst)
{
	t_stack *first;
    t_stack *temp;

    if (*lst == NULL || (*lst)->next == NULL)
        return;

    first = *lst;
    *lst = first->next;
    first->next = NULL;

    // Aggiungi 'first' alla fine della lista
    temp = *lst;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = first;
}

void	reverse_rotate(t_stack **lst)
{
	t_stack *last;
	t_stack *first;

	if (!lst || !(*lst) || !(*lst)->next)
		return;
	last = *lst;
	while (last->next)
	{
		last->index++;
		last = last->next;
	}
	first = last->next;
	last->next = NULL;
	first->next = *lst;
	first->index = 0;
	*lst = first;
}


void	do_rotate(t_stack **a, t_stack **b, int cod)
{
	if (cod == 1)
	{
		rotate (a);
		write (1, "ra\n", 3);
	}
	else if (cod == 2)
	{
		rotate (b);
		write (1, "rb\n", 3);
	}
	else if (cod == 3)
	{
		rotate (a);
		rotate (b);
		write (1, "rr\n", 3);
	}
	else if (cod == 4)
	{
		reverse_rotate (a);
		write (1, "rra\n", 4);
	}
	else if (cod == 5)
	{
		reverse_rotate (b);
		write (1, "rrb\n", 4);
	}
	else if (cod == 6)
	{
		reverse_rotate (a);
		reverse_rotate (b);
		write (1, "rrr\n", 4);
	}
}
