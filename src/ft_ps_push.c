/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:22:44 by otodd             #+#    #+#             */
/*   Updated: 2024/02/05 14:09:10 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_ps_push(t_stack_node **stack_dst, t_stack_node **stack_src)
{
	t_stack_node	*node_push;

	if (!*stack_src)
		return ;
	node_push = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	node_push->prev = NULL;
	if (!*stack_dst)
	{
		*stack_dst = node_push;
		node_push->next = NULL;
	}
	else
	{
		node_push->next = *stack_dst;
		node_push->next->prev = node_push;
		*stack_dst = node_push;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_ps_push(stack_a, stack_b);
	if (!DEBUG_PRINT)
		ft_printf("pa\n");
}

void	pb(t_stack_node **stack_b, t_stack_node **stack_a)
{
	ft_ps_push(stack_b, stack_a);
	if (!DEBUG_PRINT)
		ft_printf("pb\n");
}
