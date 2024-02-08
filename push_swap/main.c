/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:11:23 by aconti            #+#    #+#             */
/*   Updated: 2024/02/07 18:17:54 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack = NULL;
	t_stack *b = NULL;
	int n = count_num(argv);
	long int nums[n];
	ft_atoi(argv, nums);
	if (ft_check(nums, n) == 0)
		return(write(1, "Error", 5));
	//for (int i = 0; i < n; i++)
	//	printf("%ld \n", nums[i]);
	array_to_stack(nums, n, &stack);
    //printf("A: \n");
	//print_stack(stack);
    //printf("END MAIN \n");
	sort(&stack, &b, n);
	//print_stack(b);
	return (0);
}