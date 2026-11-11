/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 21:30:00 by svaladar          #+#    #+#             */
/*   Updated: 2026/11/10 21:30:00 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

int	read_op(char *buf)
{
	int		len;
	ssize_t	bytes;
	char	c;

	len = 0;
	bytes = read(0, &c, 1);
	while (bytes > 0 && c != '\n')
	{
		if (len == OP_MAX)
			return (-1);
		buf[len++] = c;
		bytes = read(0, &c, 1);
	}
	buf[len] = '\0';
	if (bytes < 0 || (bytes == 0 && len > 0))
		return (-1);
	if (bytes == 0)
		return (0);
	return (1);
}

static int	apply_swap_push(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(op, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(op, "ss"))
		ss(a, b, 0);
	else if (!ft_strcmp(op, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(op, "pb"))
		pb(a, b, 0);
	else
		return (0);
	return (1);
}

static int	apply_rotate(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(op, "rb"))
		rb(b, 0);
	else if (!ft_strcmp(op, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(op, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(op, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(op, "rrr"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	apply_op(char *op, t_stack **a, t_stack **b)
{
	if (apply_swap_push(op, a, b))
		return (1);
	return (apply_rotate(op, a, b));
}
