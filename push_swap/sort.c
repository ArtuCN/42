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
	mediat = mid_media(*a);
	i = 0;
	while (counter(temp) > 2)
	{
		if (temp->val < mediat)
			pb(b, a);
		else
			do_rotate(a, b, 1);
		temp = *a;
		n = counter(*a);
		mediat = media(*a);
		if (i++ >= n)
			i = 0;		
	}
	temp = *a;
	cont(a, b);
}
