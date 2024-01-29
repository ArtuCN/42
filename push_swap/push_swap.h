/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:28:23 by aconti            #+#    #+#             */
/*   Updated: 2024/01/29 17:52:39 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


typedef struct s_stack
{
	int			index;
	long		val;
	struct s_stack	*next;
}t_stack;


void print_stack(t_stack *stack);

//check
int		ft_check_a(t_stack **a);
t_stack *add_stack(t_stack **a, int num, int j);
int ft_atoi(char **nptr, long int *nums);
int		is_sign(char av);
void	push(t_stack **add, t_stack *take);

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
double	count_elements(t_stack *a);
void	little_order_min(t_stack **a);
void	little_order(t_stack **a, int i);
void	sort(t_stack **a, t_stack **b, int n);
//reverse
void    reverse(t_stack **lst);
void ft_lstadd_front(t_stack** lst, t_stack* new);
//swap
void	sa(t_stack **a);
void	sb(t_stack **a);
void ss(t_stack **a, t_stack **b);

# endif
