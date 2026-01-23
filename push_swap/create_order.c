/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:24:38 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/22 10:14:49 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stacks(t_manager *heads, int *path)
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
			rrotate(&(heads)->head_a, heads, 'a');
		if (path[i] == 8)
			rrotate(&(heads)->head_b, heads, 'b');
		if (path[i] == 9)
			rrotate_both(heads);
		if (path[i] == 10)
			push_a(heads);
		if (path[i] == 11)
			push_b(heads);
		i++;
	}
}

void	unload(t_manager *heads)
{
	int	all_size;
	int	midpoint;

	all_size = heads->size_a;
	midpoint = all_size / 2;
	while (heads->size_a > 7)
	{
		if (heads->head_a->index == 1)
		{
			rotate(&(heads)->head_a, heads, 'a');
			continue ;
		}
		post_station(heads, 'b');
		if (heads->head_b->index < midpoint)
			rotate(&(heads->head_b), heads, 'b');
	}
}
