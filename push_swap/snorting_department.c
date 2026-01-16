/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snorting_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:47:34 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/16 08:30:01 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_rotation(t_manager *heads, int cost_to_top)
{
	int	i;

	i = 0;
	if (cost_to_top < 0)
	{
		while (i < cost_to_top)
		{
			rrotate_both(heads);
			ft_printf("rrr\n");
			i++;
		}
	}
	else
	{
		while (i < cost_to_top)
		{
			rotate_both(heads);
			ft_printf("rr\n");
			i++;
		}
	}
}

void to_r_or_rr(t_stack *head, t_stack *target)
{
	while (target != head)
	{
		if (target->cost_to_top > 0)
		{
			like_a_record_baby(&head);
			ft_printf("r");
		}
		else if (target->cost_to_top < 0)
		{
			you_spin_me_round(&head);
			ft_printf("rr");
		}
	}
}

void switcheroo(t_manager *heads)
{
	if (heads->target_in_a != heads->head_a)
	{
		to_r_or_rr(heads->head_a, heads->target_in_a);
		if (heads->target_in_a->cost_to_top != 0)
			ft_printf("a\n");
	}
	if (heads->target_in_b != heads->head_b)
	{
		to_r_or_rr(heads->head_b, heads->target_in_b);
		if (heads->target_in_b->cost_to_top != 0)
			ft_printf("b\n");
	}
	ft_printf("pa\n");
	push_a(heads);
}

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