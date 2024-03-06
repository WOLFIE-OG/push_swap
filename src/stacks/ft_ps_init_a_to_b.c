/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_init_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:28 by otodd             #+#    #+#             */
/*   Updated: 2024/03/06 19:05:40 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_ps_set_target_a(t_ctx *ctx)
{
	t_stack	*current_b;
	t_stack	*target_node;
	t_stack	*head;

	head = ctx->a;
	while (head)
	{
		head->bmi = LONG_MIN;
		current_b = ctx->b;
		while (current_b)
		{
			if (current_b->value < head->value
				&& current_b->value > head->bmi)
			{
				head->bmi = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (head->bmi == LONG_MIN)
			head->target = ft_ps_get_max(ctx->b);
		else
			head->target = target_node;
		head = head->next;
	}
}

void	ft_ps_init_nodes_a(t_ctx *ctx)
{
	ft_ps_current_index(ctx->a);
	ft_ps_current_index(ctx->b);
	ft_ps_set_target_a(ctx);
	ft_ps_cost_analysis(ctx);
	ft_ps_set_cheapest(ctx->a);
}
