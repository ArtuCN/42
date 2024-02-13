/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:12 by aconti            #+#    #+#             */
/*   Updated: 2024/02/13 20:24:58 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void rotate(t_stack **lst)
{
    if (*lst == NULL || (*lst)->next == NULL)
        return;

    t_stack *first = *lst;
    *lst = first->next;
    first->next = NULL;

    t_stack *temp = *lst;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = first;
}

void reverse_rotate(t_stack **lst)
{
    t_stack *second_last = NULL;
    t_stack *last = *lst;

    if (!lst || !(*lst) || !(*lst)->next)
        return;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    last->next = *lst;
    second_last->next = NULL;
    *lst = last;
}

void do_rotate(t_stack **a, t_stack **b, int cod)
{
    if (cod == 1 && a && *a && (*a)->next)
    {
        rotate(a);
        write(1, "ra\n", 3);
    }
    else if (cod == 2 && b && *b && (*b)->next)
    {
        rotate(b);
        write(1, "rb\n", 3);
    }
    else if (cod == 3 && a && *a && (*a)->next && b && *b && (*b)->next)
    {
        rotate(a);
        rotate(b);
        write(1, "rr\n", 3);
    }
    else if (cod == 4 && a && *a && (*a)->next)
    {
        reverse_rotate(a);
        write(1, "rra\n", 4);
    }
    else if (cod == 5 && b && *b && (*b)->next)
    {
        reverse_rotate(b);
        write(1, "rrb\n", 4);
    }
    else if (cod == 6 && a && *a && (*a)->next && b && *b && (*b)->next)
    {
        reverse_rotate(a);
        reverse_rotate(b);
        write(1, "rrr\n", 4);
    }
}
