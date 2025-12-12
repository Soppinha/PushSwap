#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
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

void	ft_error(void);
long	ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
long int ft_atol(const char *str);

t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *stack);
t_stack	*ft_lstlast(t_stack *stack);
void	free_stack(t_stack **stack);

t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

void	parse_args(int argc, char **argv, t_stack **a);
int		is_sorted(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);

void	current_index(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top, char stack_name);
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

#endif