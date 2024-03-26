/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:49:35 by aconti            #+#    #+#             */
/*   Updated: 2024/03/26 12:00:12 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_atoi(char **argv, long int *nums, int n)
{
	if (!ft_atoi(argv, nums, n) || ft_check(nums, n) == 0)
	{
		free(nums);
		write(STDERR_FILENO, "Error\n", 6);
		exit (0);
	}
}
