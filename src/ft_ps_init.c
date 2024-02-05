/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:17:26 by otodd             #+#    #+#             */
/*   Updated: 2024/02/05 19:21:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_ps_is_sorted(stack_a))
	{
		if (ft_ps_stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (ft_ps_stack_len(stack_a) == 3)
			ft_ps_sort_three(&stack_a);
		else
			ft_ps_sort_stacks(&stack_a, &stack_b);
	}
	ft_ps_free_stack(&stack_a);
}

int	main(int arg_n, char **arg_a)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		offset;

	stack_a = NULL;
	stack_b = NULL;
	offset = 1;
	if (arg_n < 2 && !arg_a[1][0])
		return (1);
	else if (arg_n == 2)
		arg_a = ft_split(arg_a[1], ' ');
	if (arg_n == 2)
		offset = 0;
	ft_ps_init_stack_a(&stack_a, arg_a + offset);
	push_swap(stack_a, stack_b);
	if (offset == 0)
	{
		ft_free_char_array(arg_a);
		free(arg_a);
	}
	return (0);
}
