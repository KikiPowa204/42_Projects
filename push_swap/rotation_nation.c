/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_nation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 08:59:26 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/16 22:10:41 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	like_a_record_baby(t_stack **stack, t_manager *heads, char a_or_b)
{
	*stack = (*stack)->next;
	if (a_or_b == 'b')
		heads->head_b = *stack;
	else if (a_or_b == 'a')
		heads->head_a = *stack;
}

void	you_spin_me_round(t_stack **stack, t_manager *heads, char a_or_b)
{
	*stack = (*stack)->prev;
	if (a_or_b == 'b')
		heads->head_b = *stack;
	else if (a_or_b == 'a')
		heads->head_a = *stack;
}

void	rrotate_both(t_manager *heads)
{
	you_spin_me_round(&(heads)->head_a, heads, 'a');
	you_spin_me_round(&(heads)->head_b, heads, 'b');
}

void	rotate_both(t_manager *heads)
{
	like_a_record_baby(&(heads)->head_a, heads, 'a');
	like_a_record_baby(&(heads)->head_b, heads, 'b');
}

void	crack_safe(t_manager *heads, int num)
{
	if (num == 4)
		like_a_record_baby(&(heads)->head_a, heads, 'a');
	if (num == 5)
		like_a_record_baby(&(heads)->head_b, heads, 'b');
	if (num == 6)
		rotate_both(heads);
}