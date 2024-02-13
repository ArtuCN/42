/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:59:14 by aconti            #+#    #+#             */
/*   Updated: 2024/02/13 16:03:12 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int night_function(t_stack **a, t_stack **b)
{
	int next;
	t_stack *temp;
	long t;

	temp = *a;
	temp = temp->next;
	t = INT_MAX;
	while (temp)
	{
		t = temp->val - (*a)->val;
		if (t < 0)
			t = INT_MAX;
		if (t < next)
			next = temp->val;
		temp = temp->next;
	}
	return (next);
}

void little_check_while(t_stack **a, t_stack **b, int i)
{
    while (i-- > 0)
    {
        if ((*b)->val == night_function(a, b))
        {
			pa(a, b);
			check_ss(a, b);
			i++;
		}
		reverse_rotate(a);  
		write(1, "rra\n", 4);
    }
}

void little_check(t_stack **a, t_stack **b)
{
	int i;
	int rot_b;
	
	i = 0;
	if (!a || !(*a) || !b || !(*b))
		return ;
	if (!(*a)->next || !(*b)->next)
		return ;
	while (counter(*b) > 1)
	{
		rot_b = type_rot_b(b);
		if (rot_b <= 0)
		{
			while ((*b)->val != max(b))
			{
				reverse_rotate(b);
				write(1, "rrb\n", 4);
			}
			pa(a, b);
		}
		else if (rot_b > 0)
		{
			while ((*b)->val != max(b))
			{
				rotate(b);
				write(1, "rb\n", 3);
			}
			pa(a, b);
		}
	}
}

void cont(t_stack **a, t_stack **b)
{
	int i = counter(*b);
	t_stack *temp;
	int mediat;
	
	little_check(a, b);
	check_ss(a, b);
	pa(a, b);
	pa(a, b);
}

