#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*array;
	int	*index;
	int	size;
}	t_stack;

/* ==================== PARSING ==================== */
int		parse_arguments(int argc, char **argv, t_stack *stack);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
int		ft_atoi(const char *str);
void	error_exit(void);

/* ==================== OPERATIONS - PUSH ==================== */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/* ==================== OPERATIONS - SWAP ==================== */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* ==================== OPERATIONS - ROTATE ==================== */
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

/* ==================== OPERATIONS - REVERSE ROTATE ==================== */
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* ==================== INDEXING ==================== */
void	index_stack(t_stack *stack);
int		find_index_position(t_stack *stack, int target_index);

/* ==================== SORT SMALL ==================== */
int		is_sorted(t_stack *stack);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);

/* ==================== CHUNK UTILS ==================== */
void	bring_to_top(t_stack *stack, int position, char stack_name);
int		get_chunk_size(int total_size);
int		find_max_index_pos(t_stack *stack);

/* ==================== CHUNK ALGORITHM ==================== */
void	chunk_algorithm(t_stack *a, t_stack *b);

/* ==================== UTILS ==================== */
void	free_stack(t_stack *stack);
void	init_stacks(t_stack *a, t_stack *b, int argc);

#endif