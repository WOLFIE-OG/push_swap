/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:04:07 by otodd             #+#    #+#             */
/*   Updated: 2024/02/02 15:15:51 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_ps_rev_rotate(t_stack_node **stack)
{
	t_stack_node	*node_last;

	if (!*stack || !(*stack)->next)
		return ;
	node_last = ft_ps_get_last(*stack);
	node_last->prev->next = NULL;
	node_last->next = *stack;
	node_last->prev = NULL;
	*stack = node_last;
	node_last->next->prev = node_last;
}

void	rra(t_stack_node **stack_a)
{
	ft_ps_rev_rotate(stack_a);
	if (!DEBUG_PRINT)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b)
{
	ft_ps_rev_rotate(stack_b);
	if (!DEBUG_PRINT)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_ps_rev_rotate(stack_a);
	ft_ps_rev_rotate(stack_b);
	if (!DEBUG_PRINT)
		ft_printf("rrr\n");
}