/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:04:07 by otodd             #+#    #+#             */
/*   Updated: 2024/03/12 17:09:51 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_ps_rotate(t_stack **node)
{
	t_stack	*tail;

	if (!*node || !(*node)->next)
		return ;
	tail = ft_ps_get_head_tail(*node, true);
	tail->next = *node;
	*node = (*node)->next;
	(*node)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
}

void	ra(t_stack **stack_a)
{
	ft_ps_rotate(stack_a);
	if (!DEBUG_PRINT)
		ft_printf("ra\n");
	else
		ft_ps_print_stack(BGRN"A"RESET, "ra", stack_a);
}

void	rb(t_stack **stack_b)
{
	ft_ps_rotate(stack_b);
	if (!DEBUG_PRINT)
		ft_printf("rb\n");
	else
		ft_ps_print_stack(BBLU"B"RESET, "rb", stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ps_rotate(stack_a);
	ft_ps_rotate(stack_b);
	if (!DEBUG_PRINT)
		ft_printf("rr\n");
	else
	{
		ft_ps_print_stack(BGRN"A"RESET, "rr", stack_a);
		ft_ps_print_stack(BBLU"B"RESET, "rr", stack_b);
	}
}
