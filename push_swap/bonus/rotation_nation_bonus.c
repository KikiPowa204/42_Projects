/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_nation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 08:59:26 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/22 10:14:49 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack, t_manager *heads, char a_or_b)
{
	*stack = (*stack)->next;
	if (a_or_b == 'b')
		heads->head_b = *stack;
	else if (a_or_b == 'a')
		heads->head_a = *stack;
}

void	rrotate(t_stack **stack, t_manager *heads, char a_or_b)
{
	*stack = (*stack)->prev;
	if (a_or_b == 'b')
		heads->head_b = *stack;
	else if (a_or_b == 'a')
		heads->head_a = *stack;
}

void	rrotate_both(t_manager *heads)
{
	heads->head_b = heads->head_b->prev;
	heads->head_a = heads->head_a->prev;
}

void	rotate_both(t_manager *heads)
{
	heads->head_b = heads->head_b->next;
	heads->head_a = heads->head_a->next;
}

void	crack_safe(t_manager *heads, int num)
{
	if (num == 4)
		rotate(&(heads)->head_a, heads, 'a');
	if (num == 5)
		rotate(&(heads)->head_b, heads, 'b');
	if (num == 6)
		rotate_both(heads);
}
