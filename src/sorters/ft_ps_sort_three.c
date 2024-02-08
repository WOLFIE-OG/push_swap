/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:23:59 by otodd             #+#    #+#             */
/*   Updated: 2024/02/08 15:31:28 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_ps_sort_three(t_stack **stack_a)
{
	t_stack	*b_node;

	b_node = ft_ps_get_max(*stack_a);
	if (b_node == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == b_node)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
