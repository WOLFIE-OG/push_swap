/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_init_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:28 by otodd             #+#    #+#             */
/*   Updated: 2024/03/06 19:05:49 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_ps_set_target_b(t_ctx *ctx)
{
	t_stack	*current_a;
	t_stack	*target_node;
	t_stack	*head;

	head = ctx->b;
	while (head)
	{
		head->bmi = LONG_MAX;
		current_a = ctx->a;
		while (current_a)
		{
			if (current_a->value > head->value
				&& current_a->value < head->bmi)
			{
				head->bmi = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (head->bmi == LONG_MAX)
			head->target = ft_ps_get_min(ctx->a);
		else
			head->target = target_node;
		head = head->next;
	}
}

void	ft_ps_init_nodes_b(t_ctx *ctx)
{
	ft_ps_current_index(ctx->a);
	ft_ps_current_index(ctx->b);
	ft_ps_set_target_b(ctx);
}
