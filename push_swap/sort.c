/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:02 by aconti            #+#    #+#             */
/*   Updated: 2024/02/01 16:08:19 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *a)
{
	int	max;
	t_stack *t;
	int i;

	if (!a)
		return (0);
	t = a;
	max = t->val;
	while (t->next)
	{
		i++;
		t = t->next;
		if (max < t->val)
			max = t->val;
	}
	return (max);
}

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

void	little_order_min(t_stack **a)
{
	
	while ((*a)->next)
	{
		if ((*a)->val < (*a)->next->val)
			sa(a);
		(*a) = (*a)->next;
	}
}

void little_order(t_stack **a, t_stack **b)
{
    if (*a && (*a)->next && (*a)->next->next && (*a)->val > (*a)->next->val && (*a)->next->val > (*a)->next->next->val)
    {
	    sa(a);
		write (1, "sa\n", 3);
		do_rotate(a, b, 4);
    }
    else if ((*a)->next->val > (*a)->val && (*a)->next->val > (*a)->next->next->val)
    {
        do_rotate(a, b, 1);
        sa(a);
		write (1, "sa\n", 3);
    }
    else
    {
		sa(a);
		write (1, "sa\n", 3);
	}
    cont(a, b);
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

void	sort(t_stack **a, t_stack **b, int n)
{
	int	mediat;
	int j;
	t_stack *temp;
	int i;

	temp = *a;
	mediat = media(*a);
	i = 0;
	while (counter(temp) > 3)
	{
		check_ss(a, b);
		if (temp->val < mediat)
			pb(b, a);
		else
			do_rotate(a, b, 1);
		temp = *a;
		n = counter(*a);
		if (i++ >= n)
		{
			mediat = media(*a);
			i = 0;		
		}
	}
	temp = *a;
	little_order(a, b);
}
