#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	int		i;
	long	num;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			ft_error();
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error();
		if (has_duplicate(*a, (int)num))
			ft_error();
		new = ft_lstnew((int)num);
		if (!new)
		{
			free_stack(a);
			ft_error();
		}
		ft_lstadd_back(a, new);
		i++;
	}
}
