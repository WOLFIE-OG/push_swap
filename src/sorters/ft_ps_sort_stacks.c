/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:42:16 by otodd             #+#    #+#             */
/*   Updated: 2024/03/13 16:24:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_ps_rotate_both(
	t_ctx *ctx,
	t_stack *cheapest_node,
	int direction
)
{
	while (ctx->b != cheapest_node->target
		&& ctx->a != cheapest_node)
		if (direction)
			rr(&ctx->a, &ctx->b);
	else
		rrr(&ctx->a, &ctx->b);
	ft_ps_current_index(ctx->a);
	ft_ps_current_index(ctx->b);
}

static void	ft_ps_move_a_to_b(t_ctx *ctx)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_ps_get_cheapest(ctx->a);
	if (cheapest_node->above_middle
		&& cheapest_node->target->above_middle)
		ft_ps_rotate_both(ctx, cheapest_node, 1);
	else if (!(cheapest_node->above_middle)
		&& !(cheapest_node->target->above_middle))
		ft_ps_rotate_both(ctx, cheapest_node, 0);
	ft_ps_push_prep(&ctx->a, cheapest_node, 1);
	ft_ps_push_prep(&ctx->b, cheapest_node->target, 0);
	pb(&ctx->b, &ctx->a);
}

static void	ft_ps_move_b_to_a(t_ctx *ctx)
{
	ft_ps_push_prep(&ctx->a, ctx->b->target, 1);
	pa(&ctx->a, &ctx->b);
}

static void	ft_ps_min_on_top(t_ctx *ctx)
{
	while (ctx->a->value != ft_ps_get_min(ctx->a)->value)
	{
		if (ft_ps_get_min(ctx->a)->above_middle)
			ra(&ctx->a);
		else
			rra(&ctx->a);
	}
}

void	ft_ps_sort_stacks(t_ctx *ctx)
{
	int	stack_len_a;

	stack_len_a = ft_ps_get_len(ctx->a);
	if (stack_len_a-- > 3 && !ft_ps_is_sorted(ctx->a))
		pb(&ctx->b, &ctx->a);
	if (stack_len_a-- > 3 && !ft_ps_is_sorted(ctx->a))
		pb(&ctx->b, &ctx->a);
	while (stack_len_a-- > 3 && !ft_ps_is_sorted(ctx->a))
	{
		ft_ps_init_nodes_a(ctx);
		ft_ps_move_a_to_b(ctx);
	}
	ft_ps_sort_three(ctx);
	while (ctx->b)
	{
		ft_ps_init_nodes_b(ctx);
		ft_ps_move_b_to_a(ctx);
	}
	ft_ps_current_index(ctx->a);
	ft_ps_min_on_top(ctx);
}
