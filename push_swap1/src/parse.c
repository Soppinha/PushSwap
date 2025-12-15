#include "../includes/push_swap.h"

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

static void	process_number(char *str, t_stack **a)
{
	long	num;
	t_stack	*new;

	if (!is_valid_number(str))
		ft_error();
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		ft_error();
	if (has_duplicate(*a, (int)num))
		ft_error();
	new = create_node((int)num);
	if (!new)
	{
		free_stack(a);
		ft_error();
	}
	add_node_back(a, new);
}

static void	parse_single_arg(char *arg, t_stack **a)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		ft_error();
	i = 0;
	while (split[i])
	{
		if (split[i][0] != '\0')
			process_number(split[i], a);
		i++;
	}
	free_split(split);
}

static int	has_space(char *s)
{
	while (*s)
	{
		if (*s == ' ' || (*s >= 9 && *s <= 13))
			return (1);
		s++;
	}
	return (0);
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	int	i;

	if (argc < 2)
		ft_error();
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error();
		if (has_space(argv[i]))
			parse_single_arg(argv[i], a);
		else
			process_number(argv[i], a);
		i++;
	}
	if (!*a)
		ft_error();
}
