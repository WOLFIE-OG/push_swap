/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:17:26 by otodd             #+#    #+#             */
/*   Updated: 2024/02/12 11:53:33 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_ps_print_node(t_stack **s, t_list *l, char *n, char *c)
{
	ft_printf("Stack:		(%s)\n", n);
	ft_printf("Cost:		%d\n", (*s)->cost);
	ft_printf("Index:		%d\n", (*s)->index);
	ft_printf("IsCheapest:	%d\n", (*s)->is_cheapest);
	ft_printf("IsAMedian:	%d\n", (*s)->is_above_med);
	ft_printf("Contents:	%L\n", l);
	ft_printf("Command:	%s\n\n", c);
}

void	ft_ps_print_stack(char *name, char *cmd, t_stack **stack)
{
	t_list	*list;
	t_list	*new_node;
	t_stack	*head;
	int		*content;

	head = *stack;
	list = NULL;
	new_node = NULL;
	content = NULL;
	while (head)
	{
		content = malloc(sizeof(int));
		*content = head->value;
		new_node = ft_lstnew(content);
		ft_lstadd_back(&list, new_node);
		head = head->next;
	}
	ft_ps_print_node(stack, list, name, cmd);
	ft_lstclear(&list, free);
	free(list);
}

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
	free(stack_a);
}

int	main(int arg_n, char **arg_a)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		using_split;

	stack_a = NULL;
	stack_b = NULL;
	using_split = 1;
	if (arg_n < 2 && !arg_a[1])
		return (1);
	else if (arg_n == 2)
		arg_a = ft_split(*(arg_a + 1), ' ');
	if (arg_n == 2)
		using_split = 0;
	ft_ps_init_stack_a(&stack_a, arg_a + using_split, using_split);
	push_swap(stack_a, stack_b);
	if (using_split == 0)
	{
		ft_free_array(arg_a, ft_strarraylen(arg_a));
		free(arg_a);
	}
	return (0);
}
