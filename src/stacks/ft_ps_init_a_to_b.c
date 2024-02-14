/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_init_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:28 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 17:06:19 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_ps_set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target = ft_ps_get_max(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

void	ft_ps_init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_ps_current_index(stack_a);
	ft_ps_current_index(stack_b);
	ft_ps_set_target_a(stack_a, stack_b);
	ft_ps_cost_analysis(stack_a, stack_b);
	ft_ps_set_cheapest(stack_a);
}
