/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiab <sofiab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:41:15 by sofiab            #+#    #+#             */
/*   Updated: 2026/01/09 18:41:16 by sofiab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b, 1);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b, 1);
	current_index(*a);
	current_index(*b);
}
