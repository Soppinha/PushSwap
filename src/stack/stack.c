/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiab <sofiab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:42:03 by sofiab            #+#    #+#             */
/*   Updated: 2026/01/09 18:42:04 by sofiab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->push_cost = 0;
	new->above_median = 0;
	new->best_match = 0;
	new->target = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_node_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	last = get_last_node(*stack);
	last->next = new;
	new->prev = last;
	new->next = NULL;
}
