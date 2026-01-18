/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snorting_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:47:34 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/18 13:04:37 by knajmech         ###   ########.fr       */
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
			//(target->cost_to_top)--;
			//ft_printf("r");
		}
		else if (target->cost_to_top < 0)
		{
			you_spin_me_round(&head, heads, stack);
			//(target->cost_to_top)++;
			//ft_printf("rr");
		}
		// if (stack == 'a')
		// 	//ft_printf("a\n");
		// else if (stack == 'b')
		// 	ft_printf("b\n");
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
}

void switcheroo(t_manager *head)
{
	int	i;

 	if (head->head_a->next == head->head_a || !(head->size_b))
 		return ;
	i = 0;
	move_to_position(head, head->target_in_a->cost_to_top, 
		head->target_in_b->cost_to_top);
	while (!(head->target_in_a->cost_to_top - head->target_in_b->cost_to_top))
	{
		if (head->target_in_b != head->head_b)
			to_r_or_rr(head, head->head_b, head->target_in_b, 'b');
		if (head->target_in_a != head->head_a)
			to_r_or_rr(head, head->head_a, head->target_in_a, 'a');
	}
	push_a(head);
}

void unload(t_manager *heads)
{
	while (heads->size_a > 7)
	{
		if (heads->head_a->index == 1)
		{
			like_a_record_baby(&(heads)->head_a, heads, 'a');
			//ft_printf("ra\n");
		}
		else
		{
			ft_printf("pb\n");
			post_station(heads, 'b');
		}
	}
}