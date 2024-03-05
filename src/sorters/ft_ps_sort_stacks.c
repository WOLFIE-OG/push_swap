/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:42:16 by otodd             #+#    #+#             */
/*   Updated: 2024/03/05 20:19:35 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_ps_rotate_both(
	t_stacks *stacks,
	t_stack *cheapest_node,
	int direction
)
{
	while (stacks->b != cheapest_node->target
		&& stacks->a != cheapest_node)
		if (direction)
			rr(&stacks->a, &stacks->b);
	else
		rrr(&stacks->a, &stacks->b);
	ft_ps_current_index(stacks->a);
	ft_ps_current_index(stacks->b);
}

static void	ft_ps_move_a_to_b(t_stacks *stacks)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_ps_get_cheapest(stacks->a);
	if (cheapest_node->is_above_med
		&& cheapest_node->target->is_above_med)
		ft_ps_rotate_both(stacks, cheapest_node, 1);
	else if (!(cheapest_node->is_above_med)
		&& !(cheapest_node->target->is_above_med))
		ft_ps_rotate_both(stacks, cheapest_node, 0);
	ft_ps_push_prep(stacks->a, cheapest_node, 1);
	ft_ps_push_prep(stacks->b, cheapest_node->target, 0);
	pb(&stacks->b, &stacks->a);
}

static void	ft_ps_move_b_to_a(t_stacks *stacks)
{
	ft_ps_push_prep(stacks->a, stacks->b->target, 1);
	pa(&stacks->a, &stacks->b);
}

static void	ft_ps_min_on_top(t_stacks *stacks)
{
	while (stacks->a->value != ft_ps_get_min(stacks->a)->value)
	{
		if (ft_ps_get_min(stacks->a)->is_above_med)
			ra(&stacks->a);
		else
			rra(&stacks->a);
	}
}

void	ft_ps_sort_stacks(t_stacks *stacks)
{
	int	stack_len_a;

	stack_len_a = ft_ps_get_len(stacks->a);
	if (stack_len_a-- > 3 && !ft_ps_is_sorted(stacks->a))
		pb(&stacks->b, &stacks->a);
	if (stack_len_a-- > 3 && !ft_ps_is_sorted(stacks->a))
		pb(&stacks->b, &stacks->a);
	while (stack_len_a-- > 3 && !ft_ps_is_sorted(stacks->a))
	{
		ft_ps_init_nodes_a(stacks->a, stacks->b);
		ft_ps_move_a_to_b(stacks);
	}
	ft_ps_sort_three(stacks);
	while (stacks->b)
	{
		ft_ps_init_nodes_b(stacks->a, stacks->b);
		ft_ps_move_b_to_a(stacks);
	}
	ft_ps_current_index(stacks->a);
	ft_ps_min_on_top(stacks);
}
