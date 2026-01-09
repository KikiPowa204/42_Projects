/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:24:38 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 08:05:29 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void order_stack_b(t_manager *heads, int *path)
{
	int		i;

	i = 0;
	while ((path[i]))
	{
		if (path[i] == 7)
			you_spin_me_round(&(heads)->head_b);
		if (path[i] == 4)
			like_a_record_baby(&(heads)->head_b);
		if (path[i] == 1)
			freaky_friday(&(heads)->head_b);
		i++;
	}
}

void order_stack_a(t_manager *heads, int *path)
{
	int		i;

	i = 0;
	while ((path[i]))
	{
		if (path[i] == 7)
			you_spin_me_round(&(heads)->head_a);
		if (path[i] == 4)
			like_a_record_baby(&(heads)->head_a);
		if (path[i] == 1)
			freaky_friday(&(heads)->head_a);
		i++;
	}
}