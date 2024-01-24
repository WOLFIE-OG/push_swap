/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:17:26 by otodd             #+#    #+#             */
/*   Updated: 2024/01/24 18:25:28 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int arg_n, char **arg_a)
{
	t_stack_node	*a;
	t_stack_node	*b;

	(void)a;
	(void)b;
	a = NULL;
	b = NULL;
	if (arg_n == 1 || (arg_n == 2 && !arg_a[1][0]))
		return (1);
	else if (arg_n == 2)
		arg_a = split(arg_a[1], ' ');
	while (*arg_a)
		ft_printf("%s\n", *arg_a++);
	return (0);
}
