/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:02 by aconti            #+#    #+#             */
/*   Updated: 2024/02/27 07:55:23 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


double	media(t_stack *a)
{
	int i;
	t_stack *temp;
	double val;

	i = 0;
	temp = a;
	val = 0;
	while (temp != NULL)
	{
		i++;
		val +=temp->val;
		temp = temp->next;
	}
	return (val/i);
}

int	counter(t_stack *a)
{
	int n;
	t_stack *temp;

	n = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}

int check_push(t_stack **a, int i)
{
	t_stack *temp;

	temp = *a;
	while (temp)
	{
		if (temp->push == i)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void pre_order(t_stack **a, t_stack **b)
{
    int i;

    i = 1;
    while (i < 6)
    {
        if ((*a)->push == i)
            pb(b, a);
        else if(*b && (*b)->next && (*b)->val < (*b)->next->val )
            do_rotate(a, b, 3);
        else
            do_rotate(a, b, find_direction_push(*a, i));
        if (!check_push(a, i))
            i++;
    }
}

void	sort(t_stack **a, t_stack **b, int n)
{
	int	mediat;
	int j;

	if ((*a)->push != 0)
		pre_order(a, b);
	while (counter(*a) > 2)
	{
		mediat = media(*a);		
		if ((*a)->val < mediat)
			pb(b, a);
		else if (*b && (*b)->next && (*b)->val < (*b)->next->val)
			do_rotate(a, b, 3);
		else
			do_rotate(a, b, 1);
	}
	if ((*a)->val > (*a)->next->val)
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	cont(a, b);
}
