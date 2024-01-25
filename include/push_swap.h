/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:21 by otodd             #+#    #+#             */
/*   Updated: 2024/01/25 18:18:46 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "../libft/include/libft.h"

typedef struct s_stack_node
{
	int					value;
	size_t				index;
	int					cost;
	bool				is_above_med;
	bool				is_cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char			**split(char *str, char c);

void			current_index(t_stack_node *node);
void			set_cheapest(t_stack_node *node);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
// Utils

size_t			stack_len(t_stack_node *node);
t_stack_node	*get_last(t_stack_node *node);
bool			is_sorted(t_stack_node *node);
t_stack_node	*get_min(t_stack_node *node);
t_stack_node	*get_max(t_stack_node *node);

#endif