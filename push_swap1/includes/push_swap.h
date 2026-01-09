/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiab <sofiab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:05:33 by sofiab            #+#    #+#             */
/*   Updated: 2026/01/09 20:05:34 by sofiab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				best_match;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	parse_args(int argc, char **argv, t_stack **a);

void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

int		is_sorted(t_stack *stack);
int		has_duplicate(t_stack *stack, int num);
void	sort_three(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);

void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	min_on_top(t_stack **a);
void	current_index(t_stack *stack);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	prep_for_push(t_stack **stack, t_stack *top, char stack_name);

t_stack	*create_node(int value);
void	add_node_back(t_stack **stack, t_stack *new);
int		get_stack_size(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);
void	free_stack(t_stack **stack);

t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

void	ft_error(void);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
long	ft_atol(const char *str);

char	**ft_split(char const *s, char c);
void	free_split(char **split);

#endif