/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:28:23 by aconti            #+#    #+#             */
/*   Updated: 2024/02/27 07:55:06 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	long		val;
	int			push;
	struct s_stack	*next;
}t_stack;
//init
float	media_array(long array[], int lunghezza);
void	add_push(t_stack *new_node, int size, long int *arr);
void	array_to_stack(long int *arr, int size, t_stack **stack);
//check
int		count_num(char **nptr);
int		is_sign(char av);
int		ft_atoi(char **nptr, long int *nums);
int		ft_check(long int *nums, int i);
//push
void	pa(t_stack **add, t_stack **take);
void	pb(t_stack **add, t_stack **take);
void	remove_first(t_stack **stack);
//rotate
void	rotate(t_stack  **lst);
void	reverse_rotate(t_stack **lst);
void	do_rotate(t_stack **a, t_stack **b, int cod);
//sort
double	media(t_stack *a);
int		counter(t_stack *a);
void	sort(t_stack **a, t_stack **b, int n);
void	pre_order(t_stack **a, t_stack **b);
int		check_push(t_stack **a, int i);
//swap
void	sa(t_stack **a);
void	sb(t_stack **a);
void	ss(t_stack **a, t_stack **b);
//cont
void	cont(t_stack **a, t_stack **b);
void	little_check(t_stack **a, t_stack **b);
//some utils
int		max(t_stack **stack);
int 	type_rot_b(t_stack **stack);
void	free_stack(t_stack *head);
//penalty
int		penality_r_push(t_stack *a, int t);
int		penality_rr_push(t_stack *a, int t);
int		find_direction_push(t_stack *a, int push);
int		find_direction_med(t_stack *a, int med);

# endif
