/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:21 by otodd             #+#    #+#             */
/*   Updated: 2024/02/02 15:20:41 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "colour_codes.h"
# include "../libft/include/libft.h"
# ifndef DEBUG_PRINT
#  define DEBUG_PRINT 1
# endif

// Stack Struct

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

// Init A -> B - ft_ps_init_a_to_b.c

void			ft_ps_current_index(t_stack_node *node);
void			ft_ps_set_cheapest(t_stack_node *node);
void			ft_ps_init_nodes_a(t_stack_node *a, t_stack_node *b);

// Init B -> A - ft_ps_init_b_to_a.c 

void			ft_ps_init_nodes_b(t_stack_node *a, t_stack_node *b);

// Utils - ft_ps_utils.c

size_t			ft_ps_stack_len(t_stack_node *node);
t_stack_node	*ft_ps_get_last(t_stack_node *node);
bool			ft_ps_is_sorted(t_stack_node *node);
t_stack_node	*ft_ps_get_min(t_stack_node *node);
t_stack_node	*ft_ps_get_max(t_stack_node *node);

// Error Handler - ft_ps_error_handler.c

int				ft_ps_error_syntax(char *str);
int				ft_ps_error_duplicate(t_stack_node *a, int n);
void			ft_ps_free_stack(t_stack_node **stack);
void			ft_ps_free_errors(t_stack_node **a);

// Stack Init - ft_ps_stack_init.c

void			ft_ps_init_stack_a(t_stack_node **stack, char **arg_a);
t_stack_node	*ft_ps_get_cheapest(t_stack_node *node);
void			ft_ps_push_prep(t_stack_node **s, t_stack_node *t, char n);

// Commands | Rev Rotate - ft_ps_rev_rotate.c 

void			rra(t_stack_node **stack_a);
void			rrb(t_stack_node **stack_b);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);

// Commands | Rotate - ft_ps_rotate.c 

void			ra(t_stack_node **stack_a);
void			rb(t_stack_node **stack_b);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);

// Commands | Swap - ft_ps_swap.c 

void			sa(t_stack_node **stack_a);
void			sb(t_stack_node **stack_b);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);

#endif