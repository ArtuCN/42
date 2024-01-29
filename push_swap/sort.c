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

void	little_order(t_stack **a, int i)
{
	t_stack *temp;
	int j;

	j = 0;
	temp = *a;
	printf("little_order");
	while (j < i)
	{
		if ((*a)->val < (*a)->next->val)
		{
			temp = (*a)->next;
			sa(a);
		}
		j++;
	}
}

void	sort(t_stack **a, t_stack **b, int n)
{
	int	t;
	int j;
	t_stack *temp;

	temp = *a;
	t = media(*a);
	j = 0;
	printf("media :%d  n elementi:%d\n", t, n);
	int i = 0;
	while (i < n)
	{
		if (temp->val < t)
		{
			pb(b, a);
			printf("\n\n");
			print_stack(*a);
			printf("b: \n");
			print_stack(*b);
		}
		else
		{
			do_rotate(a, b, 1);
			printf("\n\n");
			print_stack(*a);
			j++;
		}
		temp = *a;
		printf ("\n counter :%d\n", i++);
	}
	temp = *a;
	t = media(*a);
	i = 0;
	int x;
	while (i < j)
	{
		if (temp->val < t)
		{
			pb(b, a);
			printf("\n\n");
			print_stack(*a);
			printf("b: \n");
			print_stack(*b);
		}
		else
		{
			do_rotate(a, b, 1);
			printf("\n\n");
			print_stack(*a);
			x++;
		}
		temp = *a;
		printf ("\n counter :%d\n", i++);
	}	
	printf("\na \n");
	print_stack(*a);
	printf("b\n");
	print_stack(*b);

}
