#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, 1);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
