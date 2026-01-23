/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snorting_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:47:34 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/22 10:14:49 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rotation(t_manager *heads, int cost_to_top)
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

void	to_r_or_rr(t_manager *heads, t_stack *head, t_stack *target, char stack)
{
	while (target != head)
	{
		if (target->cost_to_top > 0)
		{
			rotate(&head, heads, stack);
		}
		else if (target->cost_to_top < 0)
		{
			rrotate(&head, heads, stack);
		}
	}
}

void	fix_diff(t_manager *heads, int ctt_a, int ctt_b)
{
	while (ctt_a - ctt_b > 0)
	{
		rotate(&(heads)->head_a, heads, 'a');
		ctt_a--;
	}
	while (ctt_b - ctt_a < 0)
	{
		rotate(&(heads)->head_b, heads, 'b');
		ctt_b--;
	}
}

void	move_to_position(t_manager *heads, int ctt_a, int ctt_b)
{
	if (ctt_a < 0 && ctt_b < 0 && (ctt_a - ctt_b < 0 || ctt_b - ctt_a < 0))
	{
		while (ctt_a - ctt_b < 0)
		{
			rrotate(&(heads)->head_a, heads, 'a');
			ctt_a++;
		}
		while (ctt_b - ctt_a < 0)
		{
			rrotate(&(heads)->head_b, heads, 'b');
			ctt_b++;
		}
	}
	else if (ctt_a > 0 && ctt_b > 0 && (ctt_a - ctt_b > 0 || ctt_b - ctt_a > 0))
	{
		fix_diff(heads, ctt_a, ctt_b);
	}
}

void	switcheroo(t_manager *heads)
{
	int	i;

	if (heads->head_a->next == heads->head_a || !(heads->size_b))
		return ;
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
