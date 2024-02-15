/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:21 by otodd             #+#    #+#             */
/*   Updated: 2024/02/15 13:41:22 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
# ifndef DEBUG_PRINT
#  define DEBUG_PRINT 0
# endif

// Stack Struct

typedef struct s_stack
{
	int					value;
	size_t				index;
	int					cost;
	int					is_above_med;
	int					is_cheapest;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

// Commands | Push - ft_ps_push.c

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

// Commands | Rev Rotate - ft_ps_rev_rotate.c 

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Commands | Rotate - ft_ps_rotate.c 

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// Commands | Swap - ft_ps_swap.c 

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// Eco Utils - ft_ps_eco_utils.c

void	ft_ps_cost_analysis(t_stack *stack_a, t_stack *stack_b);
void	ft_ps_set_cheapest(t_stack *node);
void	ft_ps_current_index(t_stack *node);

// Error Handler - ft_ps_error_handler.c

int		ft_ps_error_duplicate(t_stack *stack_a, int n);
void	ft_ps_free_stack(t_stack **stack);
void	ft_ps_free_errors(t_stack **stack_a, char **arg_a, int using_split);

// Get Utils - ft_ps_get_utils.c

t_stack	*ft_ps_get_min(t_stack *node);
t_stack	*ft_ps_get_max(t_stack *node);
t_stack	*ft_ps_get_last(t_stack *node);
size_t	ft_ps_get_len(t_stack *node);
t_stack	*ft_ps_get_cheapest(t_stack *node);

// Is Utils - ft_ps_is_utils.c

int		ft_ps_is_sorted(t_stack *node);

// Sorters | Sort Stacks - ft_ps_sort_stacks.c

void	ft_ps_sort_stacks(t_stack **stack_a, t_stack **stack_b);

// Sorters | Sort Three - ft_ps_sort_three.c

void	ft_ps_sort_three(t_stack **stack_a);

// Stack Init - ft_ps_stack_init.c

void	ft_ps_init_stack(t_stack **stack, char **arg_a, int using_split);
void	ft_ps_push_prep(t_stack **stack, t_stack *target, int n);

// Init A -> B - ft_ps_init_a_to_b.c

void	ft_ps_init_nodes_a(t_stack *stack_a, t_stack *stack_b);

// Init B -> A - ft_ps_init_b_to_a.c 

void	ft_ps_init_nodes_b(t_stack *a, t_stack *b);

// Debug - ft_ps_program.c

void	ft_ps_print_stack(char *name, char *cmd, t_stack **stack);

#endif