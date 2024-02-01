/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:02 by aconti            #+#    #+#             */
/*   Updated: 2024/01/29 18:02:04 by aconti           ###   ########.fr       */
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

void	little_order(t_stack **a, t_stack **b, int i)
{
	t_stack *temp;
	int j;

	j = 0;
	temp = *a;
	while (j < i)
	{
		if (temp->val < temp->next->val)
			sa(a);
		else
			do_rotate(a, b, 1);
		temp = (*a)->next;
		j++;
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
	int	t;
	int j;
	t_stack *temp;
	int i;

	temp = *a;
	t = media(*a) / 2;
	j = 0;
	i = 0;
	while (counter(*a) > 3)
	{
		if (temp->val < t)
			pb(b, a);
		else
			do_rotate(a, b, 1);
		if (!(temp->val < t))
			j++;
		temp = *a;
		if (i >= n)
			t = media(*a);
		if (i++ >= n)
			i = 0;				
	}
	temp = *a;
	little_order(*a, *b, i);
}