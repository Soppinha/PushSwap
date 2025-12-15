#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
