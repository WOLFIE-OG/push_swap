/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:17:26 by otodd             #+#    #+#             */
/*   Updated: 2024/02/08 15:35:31 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static void	print_stack(t_stack **stack)
{
	t_list	*list;
	t_list	*new_node;
	t_stack	*head;
	char 	*content;

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
	ft_printf("Stack (Base 10): 	     %L\n", list);
	ft_printf("Stack (Base 16): 	     %La\n", list);
	ft_printf("Stack (Base 16 (Uppercase)): %LA\n", list);
	ft_printf("Stack (Base 2):              %Lb\n", list);
	ft_printf("Stack (Base 8):              %Lo\n", list);
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
		arg_a = ft_split(*(arg_a + 1), ' ');
	if (arg_n == 2)
		offset = 0;
	ft_ps_init_stack_a(&stack_a, arg_a + offset);
	if (!DEBUG_PRINT)
		print_stack(&stack_a);
	push_swap(stack_a, stack_b);
	if (!DEBUG_PRINT)
		print_stack(&stack_a);
	if (offset == 0)
	{
		ft_free_array(arg_a, ft_strarraylen(arg_a));
		free(arg_a);
	}
	ft_ps_free_stack(&stack_a);
	return (0);
}
