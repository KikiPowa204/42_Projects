/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accounting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:55:17 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/21 16:59:42 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_to_top(t_stack *node, int size, int i)
{
	t_stack	*head;

	head = node;
	i = 0;
	while (node->next != node)
	{
		while (i <= size / 2)
		{
			node->cost_to_top = i;
			node = node->next;
			i++;
		}
		i = -1;
		node = head->prev;
		while (i >= (size / 2) * -1)
		{
			node->cost_to_top = i;
			node = node->prev;
			i--;
		}
		break ;
	}
}

int	it_is_cheap(t_manager *heads, t_stack *stack_1, t_stack *stack_2)
{
	int	diff;
	int	ctt_a;
	int	ctt_b;

	if (stack_1->cost_to_top < 0)
		ctt_a = stack_1->cost_to_top * -1;
	else
		ctt_a = stack_1->cost_to_top;
	if (stack_2->cost_to_top < 0)
		ctt_b = stack_2->cost_to_top * -1;
	else
		ctt_b = stack_2->cost_to_top;
	diff = stack_1->cost_to_top - stack_2->cost_to_top;
	if (diff == 0 && heads->cost > ctt_a)
		return (heads->cost = stack_1->cost_to_top, 2);
	if (heads->cost > (ctt_a + ctt_b))
		return (heads->cost = ctt_a + ctt_b, 1);
	return (0);
}

void	calculator(t_manager *heads)
{
	t_stack	*stack_b;

	stack_b = heads->head_b->next;
	while (stack_b != heads->head_b)
	{
		find_ft(heads, heads->first_pos, stack_b);
		stack_b = stack_b->next;
	}
	move_to_position(heads, heads->target_in_a->cost_to_top,
		heads->target_in_b->cost_to_top);
	cost_to_top(heads->head_a, heads->size_a, 0);
	cost_to_top(heads->head_b, heads->size_b, 0);
	if (heads->size_b)
	{
		if (!(heads->target_in_a->cost_to_top
				- heads->target_in_b->cost_to_top))
		{
			check_rotation(heads, heads->target_in_a->cost_to_top);
			push_a(heads);
			return ;
		}
		else
			switcheroo(heads);
	}
	return ;
}
