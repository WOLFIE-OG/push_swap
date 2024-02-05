/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:35:55 by otodd             #+#    #+#             */
/*   Updated: 2024/02/05 15:45:26 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_ps_swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **stack_a)
{
	ft_ps_swap(stack_a);
	if (!DEBUG_PRINT)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	ft_ps_swap(stack_b);
	if (!DEBUG_PRINT)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_ps_swap(stack_a);
	ft_ps_swap(stack_b);
	if (!DEBUG_PRINT)
		ft_printf("ss\n");
}
