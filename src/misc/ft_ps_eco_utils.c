/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_eco_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:58:25 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 17:21:24 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_ps_cost_analysis(t_stack *stack_a, t_stack *stack_b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_ps_get_len(stack_a);
	len_b = ft_ps_get_len(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->is_above_med))
			stack_a->cost = len_a - (stack_a->index);
		if (stack_a->target->is_above_med)
			stack_a->cost += stack_a->target->index;
		else
			stack_a->cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	ft_ps_set_cheapest(t_stack *node)
{
	long	cheapest_v;
	t_stack	*cheapest_n;

	if (!node)
		return ;
	cheapest_v = LONG_MAX;
	while (node)
	{
		if (node->cost < cheapest_v)
		{
			cheapest_v = node->cost;
			cheapest_n = node;
		}
		node = node->next;
	}
	cheapest_n->is_cheapest = 1;
}

void	ft_ps_current_index(t_stack *node)
{
	size_t	index;
	size_t	med;

	index = 0;
	if (!node)
		return ;
	med = ft_ps_get_len(node) / 2;
	while (node)
	{
		node->index = index;
		if (index <= med)
			node->is_above_med = 1;
		else
			node->is_above_med = 0;
		node = node->next;
		index++;
	}
}
