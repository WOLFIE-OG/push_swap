/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:17:26 by otodd             #+#    #+#             */
/*   Updated: 2024/01/30 17:05:52 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int arg_n, char **arg_a)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	(void)stack_b;
	stack_a = NULL;
	stack_b = NULL;
	if (arg_n < 2 && !arg_a[1][0])
		return (1);
	else if (arg_n == 2)
		arg_a = ft_split(arg_a[1], ' ');
	ft_ps_init_stack_a(&stack_a, arg_a + 1);
	ft_printf("%d", ft_ps_stack_len(stack_a));
	free(stack_a);
	return (0);
}
