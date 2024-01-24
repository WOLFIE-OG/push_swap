/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:21 by otodd             #+#    #+#             */
/*   Updated: 2024/01/24 18:14:37 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "../libft/include/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					cost;
	bool				above_med;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char	**split(char *str, char c);

#endif