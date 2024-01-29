/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:27 by aconti            #+#    #+#             */
/*   Updated: 2024/01/24 16:47:27 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lstadd_front(t_stack** lst, t_stack* new)
{
    t_stack *tmp;
    if (*lst == NULL)
        *lst = new;
    else
    {
        tmp = *lst;
        *lst = new;
        new->next = tmp;
    }
}

void    reverse(t_stack **lst) {
    t_stack *last;
    t_stack *slast;

    if (*lst == NULL || (*lst)->next == NULL)
        return ;
    last = *lst;
    slast = NULL;
    while (last->next != NULL)
    {
        slast = last;
        last = last->next;
    }
    ft_lstadd_front(lst, last);
    if (slast != NULL)
        slast->next = NULL;
}

