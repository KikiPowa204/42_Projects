/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:24:38 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/18 12:24:34 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void focus_category(t_stack *stack_b, t_manager *heads)
{
	int	size;
	int	i;

	if (heads->max == 15)
		return ;
	i = 0;
	size = (heads->max) / 2;
	while (i++ < size)
		stack_b = stack_b->prev;
	if(stack_b->index > stack_b->next->index)
		to_r_or_rr(heads, heads->head_b, stack_b, 'b');
	else if (stack_b->prev->index > stack_b->next->next->index)
		to_r_or_rr(heads, heads->head_b, stack_b->prev, 'b');
	cost_to_top(heads->head_b, heads->size_b, 0);
	cost_to_top(heads->head_a, heads->size_a, 0);
	//heads->category = stack_b;
}

void order_stacks(t_manager *heads, int *path)
{
	int		i;

	i = 0;
	while ((path[i]))
	{
		if (path[i] <= 3 && path[i] >= 1)
			pick_path(heads, path[i]);
		if (path[i] >= 4 && path[i] <= 6)
			crack_safe(heads, path[i]);
		if (path[i] == 7)
			you_spin_me_round(&(heads)->head_a, heads, 'a');
		if (path[i] == 8)
			you_spin_me_round(&(heads)->head_b, heads, 'b');
		if (path[i] == 9)
			rrotate_both(heads);
		if (path[i] == 10)
			push_a(heads);
		if (path[i] == 11)
			push_b(heads);
		i++;
	}
}
