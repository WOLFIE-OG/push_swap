/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:23:59 by otodd             #+#    #+#             */
/*   Updated: 2024/03/05 20:15:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_ps_sort_three(t_stacks *stacks)
{
	t_stack	*b_node;

	b_node = ft_ps_get_max(stacks->a);
	if (b_node == stacks->a)
		ra(&stacks->a);
	else if (stacks->a->next == b_node)
		rra(&stacks->a);
	if (stacks->a->value > stacks->a->next->value)
		sa(&stacks->a);
}
