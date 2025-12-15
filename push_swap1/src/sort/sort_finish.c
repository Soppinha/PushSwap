#include "../../includes/push_swap.h"

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
