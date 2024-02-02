/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:04:07 by otodd             #+#    #+#             */
/*   Updated: 2024/02/01 18:31:58 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*node_last;

	if (!*stack || !*stack->next)
		return ;
	node_last = ft_ps_get_last(*stack);
	node_last->next = *stack;
	*stack = *stack->next;
	*stack->prev = NULL;
	node_last->next->prev = node_last;
	node_last->next->next = NULL;
}

void	ra(t_stack_node **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_printf("rr\n");
}