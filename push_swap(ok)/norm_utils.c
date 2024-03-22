/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:23:59 by aconti            #+#    #+#             */
/*   Updated: 2024/03/22 16:37:44 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_atoi(char **argv, long int *nums, int n)
{
	if (!ft_atoi(argv, nums, n) || ft_check(nums, n) == 0)
	{
		free(nums);
		exit (write(1, "Error", 5));
	}
}
