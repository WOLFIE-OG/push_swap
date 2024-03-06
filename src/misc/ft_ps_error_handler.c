/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:46:39 by otodd             #+#    #+#             */
/*   Updated: 2024/03/06 19:04:12 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	ft_ps_error_duplicate(t_ctx *ctx, int n)
{
	t_stack	*head;

	head = ctx->a;
	if (!head)
		return (0);
	while (head)
	{
		if (head->value == n)
			return (true);
		head = head->next;
	}
	return (false);
}

void	ft_ps_free_stack(t_ctx *ctx)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!ctx->a)
		return ;
	current = ctx->a;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	ctx->a = NULL;
}

void	ft_ps_free_errors(t_ctx *ctx)
{
	if (!ctx->us)
	{
		ft_free_array(ctx->arg_a, ft_strarraylen(ctx->arg_a));
		free(ctx->arg_a);
	}
	ft_ps_free_stack(ctx);
	free(ctx);
	ft_printf(BRED"Error!\n"RESET);
	exit(EXIT_FAILURE);
}
