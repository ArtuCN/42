/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:59:14 by aconti            #+#    #+#             */
/*   Updated: 2024/02/01 16:10:59 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void little_check(t_stack **a, t_stack **b)
{
	int i;
	
	i = 0;
	if (!a || !(*a) || !b || !(*b))
    	return ;
	if (!(*a)->next || !(*b)->next)
		return ;	
	while ((*a)->val < (*b)->val && *b && (*b)->next)
	{
		rotate(a);
		write(1, "ra\n", 3);
		i++;
	}
	pa(a, b);
	while (i-- > 0)
	{
		reverse_rotate(a);	
		write (1, "rra\n", 4);
	}
}

void cont(t_stack **a, t_stack **b)
{
	int i = counter(*b);
	t_stack *temp;
	int mediat;
	while (i >= 3)
	{
	    temp = *b;
		if (!temp->next || !temp || !b || !(*b) || !(*b)->next || !(*a)->next)
			break ;
    	mediat = media(*b);
		while (temp->val < temp->next->val || (*a)->val > (*a)->next->val)
			check_ss(a, b);
    	if (mediat < temp->val)
			little_check(a, b);
	    else
        	do_rotate(a, b, 2);
	    i = counter(*b); 
	}
	check_ss(a, b);
	pa(a, b);
	pa(a, b);
	//final(a, b);
}


int mid_media(t_stack *a)
{
	int med;
	int res;
	t_stack *temp;
	int i;

	i = 0;
	temp = a;
	res = 0;
	med = media(a);
	while(temp != NULL)
	{
		if (temp->val <= med)
		{
			res += temp->val;
			i++;
		}
		temp = temp->next;
	}
	return (res / i);
}
