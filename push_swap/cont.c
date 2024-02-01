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


void cont(t_stack **a, t_stack **b)
{
	
	int i = counter(*b);
	t_stack *temp;
	int mediat;

	while (i >= 3)
	{
	    temp = *b;
    	mediat = media(*b);
		if (temp->val < temp->next->val)
    		check_ss(a, b);
    	if (mediat <= temp->val)
    	    pa(a, b);
	    else
        	do_rotate(a, b, 2);
	    i = counter(*b); 
	}
	
}
