/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiab <sofiab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:41:37 by sofiab            #+#    #+#             */
/*   Updated: 2026/01/09 19:32:01 by sofiab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = get_stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b, 1);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b, 1);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
