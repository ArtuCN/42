/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:57 by aconti            #+#    #+#             */
/*   Updated: 2024/02/01 11:24:04 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_num(char **nptr)
{
    int n = 0;
    int i = 1;
    int j;
    while (nptr[i]) {
        j = 0;
        while (nptr[i][j])
        {
            if (nptr[i][j] >= '0' && nptr[i][j] <= '9')
            {
                while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
                    j++;
                n++;
            }
            else
                j++;
        }
        i++;
    }
    return n;
}

int is_sign(char av)
{
    if (av == '+')
        return (1);
    else if(av == '-')
        return (-1);
    else
        return (0);
}

int all_num(char **nptr)
{
    int i = 1;
    int j;
    while (nptr[i])
    {
        j = 0;
        while (nptr[i][j])
        {
            if((nptr[i][j] >= '0' && nptr[i][j] <= '9'|| nptr[i][j] == ' ' || is_sign(nptr[i][j]) != 0))
                j++;
            else
                return 0;
        }
        i++;
    }
    return 1;
}

int ft_atoi(char **nptr, long int *nums)
{
    int i = 1;
    long int num = 0;
    int n = 0;
    while (nptr[i])
    {
        int sign = 1;
        int j = 0;
        while (nptr[i][j])
        {
            if (is_sign(nptr[i][j]) == 1 || is_sign(nptr[i][j]) == -1)
            {
                sign = is_sign(nptr[i][j]);
                j++;
            }
            while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
            {
                num = num * 10 + (nptr[i][j] - '0');
                if (nptr[i][j + 1] == ' ' || nptr[i][j + 1] == '\0')
                {
                    nums[n] = sign * num;
                    num = 0;
                    n++;
                    if(nptr[i][j + 1] == '\0')
                        break;
                }
                j++;
            }
            j++;
        }
        i++;
    }
    return n;
}

int ft_check(long int *nums, int i)
{
    int j;
    i--;
    while (i >= 0)
    {
        j = 0;
        if(nums[i] > 2147483647 || nums[i] < -2147483648)
            return 0;
        while (j < i)
        {
            if((int)nums[i] == (int)nums[j])
                return 0;
            j++;
        }
        i--;
    }
    return (1);
}

void print_stack(t_stack *stack)
{
    while (stack != NULL) {
        printf("Value: %ld, Index: %d\n", stack->val, stack->index);
        stack = stack->next;
    }
    printf("\n");
}

void array_to_stack(long int *arr, int size, t_stack **stack)
{
	t_stack *new_node;
	int i = size - 1;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->val = arr[i];
		new_node->index = i;
		new_node->next = *stack;
		*stack = new_node;
		i--;
	}
}

