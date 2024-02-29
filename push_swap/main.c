/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:11:23 by aconti            #+#    #+#             */
/*   Updated: 2024/02/28 14:20:59 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sign(char av)
{
	if (av == '+')
		return (1);
	else if (av == '-')
		return (-1);
	else
		return (0);
}

long int	extract_number(char *str, int *index)
{
	long int	num;

	num = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		num = num * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (num);
}

int	process_string(char *str, long int *nums)
{
	int			j;
	int			n;
	int			sign;
	long int	num;

	j = 0;
	n = 0;
	sign = 1;
	while (str[j])
	{
		if (is_sign(str[j]) == 1 || is_sign(str[j]) == -1)
		{
			sign = is_sign(str[j]);
			j++;
		}
		num = extract_number(str, &j);
		nums[n++] = sign * num;
		while (str[j] == ' ')
			j++;
	}
	return (n);
}

int	ft_atoi(char **nptr, long int *nums)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (nptr[i])
	{
		n += process_string(nptr[i], nums + n);
		i++;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			n;
	long int	*nums;

	stack_a = NULL;
	stack_b = NULL;
	n = count_num(argv);
	nums = malloc(sizeof(long int ) * n);
	if (!nums)
		return (write(1, "Error", 5));
	ft_atoi(argv, nums);
	if (ft_check(nums, n) == 0 || argc < 2)
		return (write(1, "Error", 5));
	if (n == 1 || is_sorted(nums, n))
		return (0);
	array_to_stack(nums, n, &stack_a);
	sort(&stack_a, &stack_b, n);
	free_stack(stack_a);
	free(nums);
	return (0);
}
