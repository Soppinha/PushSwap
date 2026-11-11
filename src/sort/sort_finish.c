/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiab <sofiab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:41:04 by sofiab            #+#    #+#             */
/*   Updated: 2026/01/09 18:41:05 by sofiab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
