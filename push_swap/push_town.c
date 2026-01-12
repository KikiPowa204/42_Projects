/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_town.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 08:45:54 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 11:54:58 by knajmech         ###   ########.fr       */
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
    t_stack *node = heads->head_a;

    if (!node)
		return ;
    if (heads->size_a == 1)
        heads->head_a = NULL;
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        heads->head_a = node->next;
    }
    if (heads->size_b == 0)
    {
        node->next = node;
        node->prev = node;
    }
    else
    {
        t_stack *head_b = heads->head_b;
        node->next = head_b;
        node->prev = head_b->prev;
        head_b->prev->next = node;
        head_b->prev = node;
    }
    heads->head_b = node;
    heads->size_a--;
    heads->size_b++;
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
		holder->prev = holder;
		heads->size_a = ft_lstsize(heads->head_a);
		heads->size_b = ft_lstsize(heads->head_b);
	}
	else if (instruction == 'a')
		push_a(heads);
}
