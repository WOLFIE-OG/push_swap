/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_init_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:28 by otodd             #+#    #+#             */
/*   Updated: 2024/01/30 16:35:20 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ps_current_index(t_stack_node *node)
{
	size_t	index;
	size_t	med;

	index = 0;
	if (!node)
		return ;
	med = ft_ps_stack_len(node);
	while (node)
	{
		node->index = index;
		if (index <= med)
			node->is_above_med = true;
		else
			node->is_above_med = false;
		node = node->next;
		index++;
	}
}

static void	ft_ps_set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = ft_ps_get_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	ft_ps_cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_ps_stack_len(a);
	len_b = ft_ps_stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!a->is_above_med)
			a->cost = len_a - a->index;
		if (a->target->is_above_med)
			a->cost += a->target->index;
		else
			a->cost += len_b - a->target->index;
		a = a->next;
	}
}

void	ft_ps_set_cheapest(t_stack_node *node)
{
	long			cheapest_v;
	t_stack_node	*cheapest_n;

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
	cheapest_n->is_cheapest = true;
}

void	ft_ps_init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	ft_ps_current_index(a);
	ft_ps_current_index(b);
	ft_ps_set_target_a(a, b);
	ft_ps_cost_analysis_a(a, b);
	ft_ps_set_cheapest(a);
}
