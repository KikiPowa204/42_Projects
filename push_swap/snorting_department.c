/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snorting_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:47:34 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 12:00:09 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_rotation(t_manager *heads, int cost_to_top)
{
	int	i;

	i = 0;
	if (cost_to_top < 0)
	{
		cost_to_top *= -1;
		while (i < cost_to_top)
		{
			rrotate_both(heads);
			i++;
		}
	}
	else if (cost_to_top > 0)
	{
		while (i < cost_to_top)
		{
			rotate_both(heads);
			i++;
		}
	}
}

void to_r_or_rr(t_manager *heads, t_stack *head, t_stack *target, char stack)
{
	while (target != head)
	{
		if (target->cost_to_top > 0)
		{
			like_a_record_baby(&head, heads, stack);
		}
		else if (target->cost_to_top < 0)
		{
			you_spin_me_round(&head, heads, stack);
		}
	}
}
void fix_diff(t_manager *heads, int CTT_A, int CTT_B)
{
	while (CTT_A - CTT_B > 0)
	{
		like_a_record_baby(&(heads)->head_a, heads, 'a');
		CTT_A--;
	}
	while (CTT_B - CTT_A < 0)
	{
		like_a_record_baby(&(heads)->head_b, heads, 'b');
		CTT_B--;
	}
}

void move_to_position(t_manager *heads, int CTT_A, int CTT_B)
{
	if (CTT_A < 0 && CTT_B < 0 && (CTT_A - CTT_B < 0 || CTT_B - CTT_A < 0))
	{
		while (CTT_A - CTT_B < 0)
		{
			you_spin_me_round(&(heads)->head_a, heads, 'a');
			CTT_A++;
		}
		while (CTT_B - CTT_A < 0)
		{
			you_spin_me_round(&(heads)->head_b, heads, 'b');
			CTT_B++;
		}
	}
	else if (CTT_A > 0 && CTT_B > 0 && (CTT_A - CTT_B > 0 || CTT_B - CTT_A > 0))
	{
		fix_diff(heads, CTT_A, CTT_B);
	}
}

void switcheroo(t_manager *heads)
{
	int	i;

 	if (heads->head_a->next == heads->head_a || !(heads->size_b))
 		return;
	i = 0;
	while (heads->target_in_a != heads->head_a)
	{
		to_r_or_rr(heads, heads->head_a, heads->target_in_a, 'a');
	}
	while (heads->target_in_b != heads->head_b)
	{
		to_r_or_rr(heads, heads->head_b, heads->target_in_b, 'b');
	}
	push_a(heads);
}
