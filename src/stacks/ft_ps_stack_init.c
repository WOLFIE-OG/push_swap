/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_stack_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:08:41 by otodd             #+#    #+#             */
/*   Updated: 2024/02/15 16:09:15 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>
static void	ft_ps_append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*node_last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	node->is_cheapest = 0;
	node->index = 0;
	node->is_above_med = 0;
	node->cost = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		node_last = ft_ps_get_last(*stack);
		node_last->next = node;
		node->prev = node_last;
	}
}

void	ft_ps_init_stack(t_stack **stack, char **arg_a, int using_split)
{
	long	n;
	char	**tmp;

	tmp = arg_a;
	while (*tmp)
	{
		if (!ft_ischeck_str(*tmp, ft_ismath))
			ft_ps_free_errors(stack, arg_a, using_split);
		n = ft_atol(*tmp);
		if (n < INT_MIN || n > INT_MAX)
			ft_ps_free_errors(stack, arg_a, using_split);
		if (ft_ps_error_duplicate(*stack, (int)n))
			ft_ps_free_errors(stack, arg_a, using_split);
		ft_ps_append_node(stack, (int)n);
		tmp++;
	}
}

void	ft_ps_push_prep(t_stack **stack, t_stack *target, int n)
{
	while (*stack != target)
	{
		if (n)
			if (target->is_above_med)
				ra(stack);
		else
			rra(stack);
		else
			if (target->is_above_med)
				rb(stack);
		else
			rrb(stack);
	}
}
