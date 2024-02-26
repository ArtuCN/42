/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   penalty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:00:41 by aconti            #+#    #+#             */
/*   Updated: 2024/02/26 17:08:05 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	penality_r_push(t_stack *a, int t)
{
	int		pi;
	int		i;
	t_stack	*head;

	head = a;
	i = 0;
	pi = 0;
	while (i++ < counter(a) / 2)
	{
		if (head->push == t)
			break ;
		pi++;
		head = head->next;
	}
	return (pi);
}

int	penality_rr_push(t_stack *a, int t)
{
	int		pj;
	int		j;
	t_stack	*mid;
	int		tmp;
	
	mid = a;
	pj = 0;
	tmp = 0;
	while (j++ < counter(a) / 2 - 1)
		mid = mid->next;
	while (mid)
	{
		if (mid->push == t)
			tmp = pj;
		pj++;
		mid = mid->next;
	}
	return (counter(a) / 2 - tmp);
}

int	find_direction_push(t_stack *a, int push)
{
	int	pi;
	int	pj;

	pi = penality_r_push(a, push);
	pj = penality_rr_push(a, push);
	if (pj < pi)
		return (4);
	else
		return (1);
}

// int	penality_r(t_stack *a, int t)
// {
// 	int		pi;
// 	int		i;
// 	t_stack	*head;

// 	head = a;
// 	i = 0;
// 	pi = 0;
// 	while (head && head->val >= t)
// 	{
// 		head = head->next;
// 		pi++;
// 	}
// 	return (pi);
// }

// int	penality_rr(t_stack *a, int t)
// {
// 	int		pj;
// 	int		j;
// 	t_stack	*mid;

// 	mid = a;
// 	j = 0;
// 	pj = 0;
// 	while (j++ < counter(a) / 2 - 1)
// 		mid = mid->next;
// 	j = 0;
// 	while (mid)
// 	{
// 		if (mid->val <= t)
// 			j = pj;
// 		mid = mid->next;
// 		pj++;
// 	}
// 	return (counter(a) / 2 - j);
// }


// int	find_direction_med(t_stack *a, int med)
// {
// 	int	pi;
// 	int	pj;

// 	pi = penality_r(a, med);
// 	pj = penality_rr(a, med);
// 	if (pj < pi)
// 		return (4);
// 	else
// 		return (1);
// }