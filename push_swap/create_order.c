/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:24:38 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/12 10:31:24 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			you_spin_me_round(&(heads)->head_a);
		if (path[i] == 8)
			you_spin_me_round(&(heads)->head_b);
		if (path[i] == 9)
			rrotate_both(heads);
		if (path[i] == 10)
			push_a(heads);
		if (path[i] == 11)
			push_b(heads);
		i++;
	}
}
