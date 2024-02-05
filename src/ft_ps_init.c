/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:17:26 by otodd             #+#    #+#             */
/*   Updated: 2024/02/05 15:00:07 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int arg_n, char **arg_a)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (arg_n < 2 && !arg_a[1][0])
		return (1);
	else if (arg_n == 2)
		arg_a = ft_split(arg_a[1], ' ');
	ft_ps_init_stack_a(&stack_a, arg_a + 1);
	stack_b = stack_a;
	while (stack_b)
	{
		ft_printf("%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	if (!ft_ps_is_sorted(stack_a))
	{
		if (ft_ps_stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (ft_ps_stack_len(stack_a) == 3)
			ft_ps_sort_three(&stack_a);
	}
	ft_printf("\n\n\n\n\n");
	stack_b = stack_a;
	while (stack_b)
	{
		ft_printf("%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	// free(arg_a);
	return (0);
}
