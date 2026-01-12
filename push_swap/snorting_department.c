/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snorting_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:47:34 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/12 10:53:29 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void unload(t_manager *heads)
{
	while (heads->size_a > 7)
	{
		if (heads->head_a->index == 1)
		{
			like_a_record_baby(&(heads)->head_a);
			ft_printf("ra\n");
		}
		else
		{
			ft_printf("pb\n");
			post_station(heads, 'b');
		}
	}
}