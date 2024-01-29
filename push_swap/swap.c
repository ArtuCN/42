/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:06 by aconti            #+#    #+#             */
/*   Updated: 2024/01/27 17:59:22 by aconti           ###   ########.fr       */
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
}
