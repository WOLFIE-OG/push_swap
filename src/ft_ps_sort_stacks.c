/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:42:16 by otodd             #+#    #+#             */
/*   Updated: 2024/02/05 19:18:01 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_ps_rotate_both(
	t_stack **stack_a,
	t_stack **stack_b,
	t_stack *cheapest_node,
	int direction
)
{
	while (*stack_b != cheapest_node->target
		&& *stack_a != cheapest_node)
		if (direction)
			rr(stack_a, stack_b);
	else
		rrr(stack_a, stack_b);
	ft_ps_current_index(*stack_a);
	ft_ps_current_index(*stack_b);
}

static void	ft_ps_move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_ps_get_cheapest(*stack_a);
	if (cheapest_node->is_above_med
		&& cheapest_node->target->is_above_med)
		ft_ps_rotate_both(stack_a, stack_b, cheapest_node, 1);
	else if (!(cheapest_node->is_above_med)
		&& !(cheapest_node->target->is_above_med))
		ft_ps_rotate_both(stack_a, stack_b, cheapest_node, 0);
	ft_ps_push_prep(stack_a, cheapest_node, 1);
	ft_ps_push_prep(stack_b, cheapest_node->target, 0);
	pb(stack_b, stack_b);
}

static void	ft_ps_move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_ps_push_prep(stack_a, (*stack_b)->target, 1);
	pa(stack_a, stack_b);
}

static void	ft_ps_min_on_top(t_stack **stack_a)
{
	while ((*stack_a)->value != ft_ps_get_min(*stack_a)->value)
	{
		if (ft_ps_get_min(*stack_a)->is_above_med)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	ft_ps_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len_a;

	stack_len_a = ft_ps_stack_len(*stack_a);
	if (stack_len_a-- > 3 && !ft_ps_is_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (stack_len_a-- > 3 && !ft_ps_is_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (stack_len_a-- > 3 && !ft_ps_is_sorted(*stack_a))
	{
		ft_ps_init_nodes_a(*stack_a, *stack_b);
		ft_ps_move_a_to_b(stack_a, stack_b);
	}
	ft_ps_sort_three(stack_a);
	while (*stack_b)
	{
		ft_ps_init_nodes_b(*stack_a, *stack_b);
		ft_ps_move_b_to_a(stack_a, stack_b);
	}
	ft_ps_current_index(*stack_a);
	ft_ps_min_on_top(stack_a);
}
