/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 21:30:00 by svaladar          #+#    #+#             */
/*   Updated: 2026/11/10 21:30:00 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

static void	checker_error(t_stack **a, t_stack **b)
{
	free_stack(b);
	ft_error(a);
}

static void	run_ops(t_stack **a, t_stack **b)
{
	char	op[OP_MAX + 1];
	int		status;

	status = read_op(op);
	while (status == 1)
	{
		if (!apply_op(op, a, b))
			checker_error(a, b);
		status = read_op(op);
	}
	if (status == -1)
		checker_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	run_ops(&a, &b);
	if (!b && is_sorted(a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
