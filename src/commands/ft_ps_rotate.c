/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:04:07 by otodd             #+#    #+#             */
/*   Updated: 2024/03/12 15:30:40 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_ps_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;

	if (!*stack || !(*stack)->next)
		return ;
	tail = ft_ps_get_head_tail(*stack, true);
	head = ft_ps_get_head_tail(*stack, false);
	tail->next = *stack;
    (*stack)->prev = tail;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    head->prev = tail;
    tail->next = NULL;
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
