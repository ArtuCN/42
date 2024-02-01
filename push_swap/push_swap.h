/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:28:23 by aconti            #+#    #+#             */
/*   Updated: 2024/02/01 15:32:29 by aconti           ###   ########.fr       */
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
	int			index;
	long		val;
	struct s_stack	*next;
}t_stack;


void print_stack(t_stack *stack);

//check
int	count_num(char **nptr);
int	is_sign(char av);
int	all_num(char **nptr);
int	ft_atoi(char **nptr, long int *nums);
int	ft_check(long int *nums, int i);
void	array_to_stack(long int *arr, int size, t_stack **stack);

//push
void	pa(t_stack **add, t_stack **take);
void	pb(t_stack **add, t_stack **take);
//rotate
t_stack	*ft_lstlast(t_stack *lst);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
void	rotate(t_stack  **lst);
void	reverse_rotate(t_stack **lst);
void	do_rotate(t_stack **a, t_stack **b, int cod);
//sort
int	mid(t_stack *a);
double	media(t_stack *a);
int	counter(t_stack *a);
void	little_order_min(t_stack **a);
void	little_order(t_stack **a, t_stack **b,int i);
void	sort(t_stack **a, t_stack **b, int n);
//reverse
void    reverse(t_stack **lst);
void ft_lstadd_front(t_stack** lst, t_stack* new);
//swap
void	sa(t_stack **a);
void	sb(t_stack **a);
void ss(t_stack **a, t_stack **b);
void check_ss(t_stack **a, t_stack **b);
//cont
void	cont(t_stack **a, t_stack **b);
# endif
