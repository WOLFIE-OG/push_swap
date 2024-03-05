/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:46:39 by otodd             #+#    #+#             */
/*   Updated: 2024/03/05 19:40:04 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_ps_error_duplicate(t_stack *stack_a, int n)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->value == n)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	ft_ps_free_stack(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stacks->a)
		return ;
	current = stacks->a;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	stacks->a = NULL;
}

void	ft_ps_free_errors(t_stacks *stacks, char **arg_a)
{
	if (!stacks->us)
	{
		ft_free_array(arg_a, ft_strarraylen(arg_a));
		free(arg_a);
	}
	ft_ps_free_stack(stacks);
	ft_printf(BRED"Error!\n"RESET);
	exit(EXIT_FAILURE);
}
