/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_town.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 08:45:54 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 10:59:35 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_manager *heads)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *prev_b;
	t_stack *next_b;
	t_stack *prev_a;

	stack_a = heads->head_a;
	stack_b = heads->head_b;
	prev_b = stack_b->prev;
	prev_a = stack_a->prev;
	next_b = stack_b->next;
	prev_b->next = next_b;
	next_b->prev = prev_b;
	stack_b->prev = prev_a;
	stack_b->next = stack_a;
	prev_a->next = stack_b;
	heads->head_a = stack_b;
	heads->head_b = next_b;
	heads->size_a = ft_lstsize(heads->head_a);
	heads->size_b = ft_lstsize(heads->head_b);
}

void push_b(t_manager *heads)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *prev_b;
	t_stack *prev_a;
	t_stack *next_a;

	stack_a = heads->head_a;
	stack_b = heads->head_b;
	prev_b = stack_b->prev;
	prev_a = stack_a->prev;
	next_a = stack_a->next;
	stack_a->next = stack_b;
	stack_a->prev = prev_b;
	stack_b->prev = stack_a;
	next_a->prev = prev_a;
	prev_a->next = next_a;
	heads->head_a = next_a;
	heads->head_b = stack_a;
	heads->size_a = ft_lstsize(heads->head_a);
	heads->size_b = ft_lstsize(heads->head_b);
}

void post_station(t_manager *heads, char instruction)
{
	t_stack	*holder;
	t_stack	*prev;

	if (instruction == 'b' && heads->size_b > 0)
		push_b(heads);
	else if (instruction == 'b')
	{
		heads->head_b = heads->head_a;
		holder = heads->head_a;
		prev = holder->prev;
		prev->next = holder->next;
		heads->head_a = holder->next;
		heads->head_a->prev = prev;
		holder->next = holder;
		heads->size_a = ft_lstsize(heads->head_a);
		heads->size_b = ft_lstsize(heads->head_b);
	}
	else if (instruction == 'a')
		push_a(heads);
}
