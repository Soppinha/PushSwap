#include "push_swap.h"

static t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->best_match)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*b != cheapest->target && *a != cheapest)
			rr(a, b, 1);
		current_index(*a);
		current_index(*b);
	}
	else if (!(cheapest->above_median)
		&& !(cheapest->target->above_median))
	{
		while (*b != cheapest->target && *a != cheapest)
			rrr(a, b, 1);
		current_index(*a);
		current_index(*b);
	}
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target, 'b');
	pb(a, b, 1);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	move_nodes(a, b);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, 1);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	current_index(*a);
	while ((*a)->value != min->value)
	{
		if (min->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
