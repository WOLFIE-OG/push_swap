/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:17:26 by otodd             #+#    #+#             */
/*   Updated: 2024/03/06 19:09:30 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_ps_print_node(t_stack **s, t_list *l, char *n, char *c)
{
	ft_printf("Stack:		(%s)\n", n);
	ft_printf("Cost:		%d\n", (*s)->cost);
	ft_printf("Index:		%d\n", (*s)->index);
	ft_printf("IsCheapest:	%d\n", (*s)->is_cheapest);
	ft_printf("IsAMedian:	%d\n", (*s)->is_above_med);
	ft_printf("Contents:	%L\n", l);
	ft_printf("Command:	%s\n\n", c);
}

void	ft_ps_print_stack(char *name, char *cmd, t_stack **stack)
{
	t_list	*list;
	t_list	*new_node;
	t_stack	*head;
	int		*content;

	head = *stack;
	list = NULL;
	new_node = NULL;
	content = NULL;
	while (head)
	{
		content = malloc(sizeof(int));
		*content = head->value;
		new_node = ft_lstnew(content);
		ft_lstadd_back(&list, new_node);
		head = head->next;
	}
	ft_ps_print_node(stack, list, name, cmd);
	ft_lstclear(&list, free);
	free(list);
}

static void	push_swap(t_ctx *ctx)
{
	if (!ft_ps_is_sorted(ctx->a))
	{
		if (ft_ps_get_len(ctx->a) == 2)
			sa(&ctx->a);
		else if (ft_ps_get_len(ctx->a) == 3)
			ft_ps_sort_three(ctx);
		else
			ft_ps_sort_stacks(ctx);
	}
	ft_ps_free_stack(ctx);
	free(ctx->a);
}

int	main(int arg_n, char **arg_a)
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	ctx->us = 1;
	ctx->arg_a = arg_a;
	if (arg_n < 2 && !arg_a[1])
	{
		free(ctx);
		return (EXIT_FAILURE);
	}
	else if (arg_n == 2)
	{
		ctx->arg_a = ft_split(*(ctx->arg_a + 1), ' ');
		ctx->us = 0;
	}
	ctx->arg_a += ctx->us;
	ft_ps_init_stack(ctx);
	push_swap(ctx);
	if (!ctx->us)
	{
		ft_free_array(arg_a, ft_strarraylen(arg_a));
		free(arg_a);
	}
	free(ctx);
	return (EXIT_SUCCESS);
}
