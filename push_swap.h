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

/* ==================== PARSING ==================== */
void	parse_args(int argc, char **argv, t_stack **a);

/* ==================== OPERATIONS - PUSH ==================== */
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

/* ==================== OPERATIONS - SWAP ==================== */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

/* ==================== OPERATIONS - ROTATE ==================== */
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

/* ==================== OPERATIONS - REVERSE ROTATE ==================== */
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* ==================== SORT ==================== */
int		is_sorted(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);

/* ==================== TURK ALGORITHM ==================== */
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top, char stack_name);

/* ==================== LIST UTILS ==================== */
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *stack);
t_stack	*ft_lstlast(t_stack *stack);
void	free_stack(t_stack **stack);

/* ==================== FIND UTILS ==================== */
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

/* ==================== UTILS ==================== */
void	ft_error(void);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
long	ft_atoi(const char *str);

#endif