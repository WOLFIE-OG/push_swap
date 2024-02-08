/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:58:25 by otodd             #+#    #+#             */
/*   Updated: 2024/02/08 15:31:23 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	ft_ps_stack_len(t_stack *node)
{
	size_t	c;

	if (!node)
		return (0);
	c = 0;
	while (node)
	{
		node = node->next;
		c++;
	}
	return (c);
}

t_stack	*ft_ps_get_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

bool	ft_ps_is_sorted(t_stack *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

t_stack	*ft_ps_get_min(t_stack *node)
{
	long	min;
	t_stack	*min_node;

	if (!node)
		return (NULL);
	min = LONG_MAX;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

t_stack	*ft_ps_get_max(t_stack *node)
{
	long	max;
	t_stack	*max_node;

	if (!node)
		return (NULL);
	max = LONG_MIN;
	while (node)
	{
		if (node->value > max)
		{
			max = node->value;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}
