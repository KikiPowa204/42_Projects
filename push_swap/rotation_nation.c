/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_nation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 08:59:26 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 16:58:31 by knajmech         ###   ########.fr       */
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
	if (a_or_b == 'a')
		ft_printf("ra\n");
	else if (a_or_b == 'b')
		ft_printf("rb\n");
}

void	you_spin_me_round(t_stack **stack, t_manager *heads, char a_or_b)
{
	*stack = (*stack)->prev;
	if (a_or_b == 'b')
		heads->head_b = *stack;
	else if (a_or_b == 'a')
		heads->head_a = *stack;
	if (a_or_b == 'a')
		ft_printf("rra\n");
	else if (a_or_b == 'b')
		ft_printf("rrb\n");
}

void	rrotate_both(t_manager *heads)
{
	heads->head_b = heads->head_b->prev;
	heads->head_a = heads->head_a->prev;
	ft_printf("rrr\n");
}

void	rotate_both(t_manager *heads)
{
	heads->head_b = heads->head_b->next;
	heads->head_a = heads->head_a->next;
	ft_printf("rr\n");
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
