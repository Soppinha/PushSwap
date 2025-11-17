
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*array;// Números originais
	int	*index;// Índices simplificados (0 = menor)
	int	size;// Tamanho atual
}	t_stack;

// Parsing
int		parse_arguments(int argc, char **argv, t_stack *stack);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
void	error_exit(void);

// Operações básicas
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Indexação
void	index_stack(t_stack *stack);
int		find_index_position(t_stack *stack, int target_index);

// Algoritmos pequenos
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
int		is_sorted(t_stack *stack);

// Chunk Algorithm
void	chunk_algorithm(t_stack *a, t_stack *b);

// Utils
void	free_stack(t_stack *stack);
int		ft_atoi(const char *str);

#endif