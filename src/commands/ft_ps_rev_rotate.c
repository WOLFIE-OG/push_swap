/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:04:07 by otodd             #+#    #+#             */
/*   Updated: 2024/03/12 15:19:02 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_ps_rev_rotate(t_stack **stack)
{
	t_stack	*node_last;

	if (!*stack || !(*stack)->next)
		return ;
	node_last = ft_ps_get_head_tail(*stack, true);
	node_last->prev->next = NULL;
	node_last->next = *stack;
	node_last->prev = NULL;
	*stack = node_last;
	node_last->next->prev = node_last;
}

void	rra(t_stack **stack_a)
{
	ft_ps_rev_rotate(stack_a);
	if (!DEBUG_PRINT)
		ft_printf("rra\n");
	else
		ft_ps_print_stack(BGRN"A"RESET, "rra", stack_a);
}

void	rrb(t_stack **stack_b)
{
	ft_ps_rev_rotate(stack_b);
	if (!DEBUG_PRINT)
		ft_printf("rrb\n");
	else
		ft_ps_print_stack(BBLU"B"RESET, "rrb", stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ps_rev_rotate(stack_a);
	ft_ps_rev_rotate(stack_b);
	if (!DEBUG_PRINT)
		ft_printf("rrr\n");
	else
	{
		ft_ps_print_stack(BGRN"A"RESET, "rrr", stack_a);
		ft_ps_print_stack(BBLU"B"RESET, "rrr", stack_b);
	}
}
