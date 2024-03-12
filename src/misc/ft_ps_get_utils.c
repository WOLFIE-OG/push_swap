/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_get_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:08:45 by otodd             #+#    #+#             */
/*   Updated: 2024/03/12 15:26:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_ps_get_min(t_stack *node)
{
	long	min;
	t_stack	*min_node;
	t_stack	*head;

	head = node;
	if (!head)
		return (NULL);
	min = LONG_MAX;
	while (head)
	{
		if (head->value < min)
		{
			min = head->value;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}

t_stack	*ft_ps_get_max(t_stack *node)
{
	long	max;
	t_stack	*max_node;
	t_stack	*head;

	head = node;
	if (!head)
		return (NULL);
	max = LONG_MIN;
	while (head)
	{
		if (head->value > max)
		{
			max = head->value;
			max_node = head;
		}
		head = head->next;
	}
	return (max_node);
}

t_stack	*ft_ps_get_head_tail(t_stack *node, bool end)
{
	t_stack	*head;

	head = node;
	if (!head)
		return (NULL);
	if (end)
		while (head->next)
			head = head->next;
	else
		while (head->prev)
			head = head->prev;
	return (head);
}

size_t	ft_ps_get_len(t_stack *node)
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

t_stack	*ft_ps_get_cheapest(t_stack *node)
{
	t_stack	*head;

	head = node;
	while (head)
	{
		if (head->is_cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}
