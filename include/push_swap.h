/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:21 by otodd             #+#    #+#             */
/*   Updated: 2024/01/30 16:33:15 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "colour_codes.h"
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

char			**ft_ps_split(char *str, char c);

void			ft_ps_current_index(t_stack_node *node);
void			ft_ps_set_cheapest(t_stack_node *node);
void			ft_ps_init_nodes_a(t_stack_node *a, t_stack_node *b);
void			ft_ps_init_nodes_b(t_stack_node *a, t_stack_node *b);

// Utils

size_t			ft_ps_stack_len(t_stack_node *node);
t_stack_node	*ft_ps_get_last(t_stack_node *node);
bool			ft_ps_is_sorted(t_stack_node *node);
t_stack_node	*ft_ps_get_min(t_stack_node *node);
t_stack_node	*ft_ps_get_max(t_stack_node *node);

// Error Handler

int				ft_ps_error_syntax(char *str);
int				ft_ps_error_duplicate(t_stack_node *a, int n);
void			ft_ps_free_stack(t_stack_node **stack);
void			ft_ps_free_errors(t_stack_node **a);

#endif