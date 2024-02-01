/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:06 by aconti            #+#    #+#             */
/*   Updated: 2024/02/01 15:56:27 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	t;
	
	if ((*a)->next == NULL || a == NULL)
		return ;
	t = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = t;
}

void	sb(t_stack **a)
{
	int	t;
	
	if ((*a)->next == NULL || a == NULL)
		return ;
	t = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = t;

}

void ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write (1, "ss\n", 3);
}

void check_ss(t_stack **a, t_stack **b)
{
	if ((*a) != NULL && (*a)->next != NULL && (*b) != NULL && (*b)->next != NULL)
	{
		if ((*a)->val > (*a)->next->val && (*b)->val < (*b)->next->val)
			ss(a, b);
	}
	if ((*a)->val > (*a)->next->val)
	{
		write(1, "sa\n", 3);
		sa(a);	
	}
	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	else if ((*b)->val < (*b)->next->val)
	{
		write(1, "sb\n", 3);
		sb(b);	
	}
}
