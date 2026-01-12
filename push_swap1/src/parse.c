/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:42:18 by sofiab            #+#    #+#             */
/*   Updated: 2026/01/11 18:02:31 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
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

static int	process_number(char *str, t_stack **a)
{
	long	num;
	t_stack	*new;

	if (!is_valid_number(str))
		return (0);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (has_duplicate(*a, (int)num))
		return (0);
	new = create_node((int)num);
	if (!new)
		return (0);
	add_node_back(a, new);
	return (1);
}

static void	parse_single_arg(char *arg, t_stack **a)
{
	char	**split;
	int		i;
	int		count;

	split = ft_split(arg, ' ');
	if (!split)
		ft_error(a);
	i = 0;
	count = 0;
	while (split[i])
	{
		if (split[i][0] != '\0')
		{
			if (!process_number(split[i], a))
			{
				free_split(split);
				ft_error(a);
			}
			count++;
		}
		i++;
	}
	free_split(split);
	if (count == 0)
		ft_error(a);
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
		exit(0);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error(a);
		if (has_space(argv[i]))
			parse_single_arg(argv[i], a);
		else
			if (!process_number(argv[i], a))
				ft_error(a);
		i++;
	}
	if (!*a)
		ft_error(a);
}
