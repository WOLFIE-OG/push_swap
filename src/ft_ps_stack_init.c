/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_stack_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:08:41 by otodd             #+#    #+#             */
/*   Updated: 2024/01/31 18:58:02 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_ps_append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*node_last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!*stack)
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

void	ft_ps_init_stack_a(t_stack_node **stack, char **arg_a)
{
	long	n;
	int		i;
	
	i = 0;
	while (arg_a[i])
	{
		if (ft_ps_error_syntax(arg_a[i]))
			ft_ps_free_errors(stack);
		n = ft_atol(arg_a[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_ps_free_errors(stack);
		if (ft_ps_error_duplicate(*stack, (int)n))
			ft_ps_free_errors(stack);
		ft_ps_append_node(stack, (int)n);
		i++;
	}
}

t_stack_node	*ft_ps_get_cheapest(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->is_cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	ft_ps_prep_push(t_stack_node **stack, t_stack_node *t_node, char s_name)
{
	while (*stack != t_node)
	{
		if (s_name == 'a')
		{
			if (t_node->is_above_med)
				// ra
				continue ;
			else
				// rra
				continue ;
		}
		else if (s_name == 'b')
		{
			if (t_node->is_above_med)
				// rb
				continue ;
			else
				// rrb
				continue ;
		}
	}
}