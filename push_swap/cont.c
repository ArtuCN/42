/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:59:14 by aconti            #+#    #+#             */
/*   Updated: 2024/02/26 16:21:39 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				do_rotate(a, b, 5);
			pa(a, b);
		}
		else
		{
			while ((*b)->val != max(b))
				do_rotate(a, b, 2);
			pa(a, b);
		}
	}
}

void cont(t_stack **a, t_stack **b)
{
	little_check(a, b);
	pa(a, b);
	free_stack(*b);
}

