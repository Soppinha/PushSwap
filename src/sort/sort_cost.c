/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiab <sofiab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:41:01 by sofiab            #+#    #+#             */
/*   Updated: 2026/01/09 19:32:32 by sofiab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	combined_cost(t_stack *node, int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = len_a - node->index;
	if (node->above_median)
		cost_a = node->index;
	cost_b = len_b - node->target->index;
	if (node->target->above_median)
		cost_b = node->target->index;
	if (node->above_median != node->target->above_median)
		return (cost_a + cost_b);
	if (cost_a > cost_b)
		return (cost_a);
	return (cost_b);
}

void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(a);
	len_b = get_stack_size(b);
	while (a)
	{
		a->push_cost = combined_cost(a, len_a, len_b);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;
	t_stack	*temp;

	if (!stack)
		return ;
	temp = stack;
	while (temp)
	{
		temp->best_match = 0;
		temp = temp->next;
	}
	cheapest_value = LONG_MAX;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->best_match = 1;
}
