/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:02 by aconti            #+#    #+#             */
/*   Updated: 2024/02/08 13:13:22 by aconti           ###   ########.fr       */
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

void	sort(t_stack **a, t_stack **b, int n)
{
	int	mediat;
	int j;
	t_stack *temp;

	temp = *a;
	mediat = mid_media(*a);
	while (counter(temp) > 2)
	{
		if (temp->val < mediat)
			pb(b, a);
		else
			do_rotate(a, b, 1);
		temp = *a;
		mediat = media(*a);		
	}
	temp = *a;
	cont(a, b);
}
