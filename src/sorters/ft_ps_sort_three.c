/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:23:59 by otodd             #+#    #+#             */
/*   Updated: 2024/03/06 19:11:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_ps_sort_three(t_ctx *ctx)
{
	t_stack	*b_node;

	b_node = ft_ps_get_max(ctx->a);
	if (b_node == ctx->a)
		ra(&ctx->a);
	else if (ctx->a->next == b_node)
		rra(&ctx->a);
	if (ctx->a->value > ctx->a->next->value)
		sa(&ctx->a);
}
