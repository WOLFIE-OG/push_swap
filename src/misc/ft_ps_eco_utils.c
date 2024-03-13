/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_eco_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:58:25 by otodd             #+#    #+#             */
/*   Updated: 2024/03/13 16:23:44 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_ps_cost_analysis(t_ctx *ctx)
{
	size_t	len_a;
	size_t	len_b;
	t_stack	*head;

	head = ctx->a;
	len_a = ft_ps_get_len(head);
	len_b = ft_ps_get_len(ctx->b);
	while (head)
	{
		head->cost = head->index;
		if (!head->above_middle)
			head->cost = len_a - (head->index);
		if (head->target->above_middle)
			head->cost += head->target->index;
		else
			head->cost += len_b - (head->target->index);
		head = head->next;
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
	cheapest_n->is_cheapest = true;
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
			node->above_middle = true;
		else
			node->above_middle = false;
		node = node->next;
		index++;
	}
}
