/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_error_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:46:39 by otodd             #+#    #+#             */
/*   Updated: 2024/02/08 23:53:27 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_ps_error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (1);
	if ((*str == '+' || *str == '-') && !ft_isdigit(str[1]))
		return (1);
	if (!ft_ischeck_str(str, ft_isdigit))
		return (1);
	return (0);
}

int	ft_ps_error_duplicate(t_stack *a, int n)
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

void	ft_ps_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_ps_free_errors(t_stack **a, char **arg_a, int using_split)
{
	if (!using_split)
	{
		ft_free_array(arg_a, ft_strarraylen(arg_a));
		free(arg_a);
	}
	ft_ps_free_stack(a);
	ft_printf(BRED"Error!\n"RESET);
	exit(EXIT_FAILURE);
}
