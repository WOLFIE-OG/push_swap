/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:46:39 by otodd             #+#    #+#             */
/*   Updated: 2024/01/30 16:32:11 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (1);
	if ((*str == '+' || *str == '-') && !ft_isdigit(str[1]))
		return (1);
	if (!ft_ischeck_str(str, ft_isdigit))
		return (1);
}

int	ft_ps_error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_ps_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = NULL;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_ps_free_errors(t_stack_node **a)
{
	ft_ps_free_stack(a);
	ft_printf(BRED"Error!\n"RESET);
	exit(EXIT_FAILURE);
}
