/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_town.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 08:45:54 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 09:41:34 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_manager *heads)
{
	t_stack	*node;
	t_stack	*head_a;

	node = heads->head_b;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if (heads->size_b > 0)
		heads->head_b = node->next;
	head_a = heads->head_a;
	node->next = head_a;
	node->prev = head_a->prev;
	head_a->prev->next = node;
	head_a->prev = node;
	heads->head_a = node;
	heads->size_a++;
	heads->size_b--;
	if (heads->size_b == 0)
		heads->head_b = NULL;
	ft_printf("pa\n");
}
void push_b(t_manager *heads)
{
	t_stack *node;
	t_stack *head_b;

	node = heads->head_a;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if (heads->size_a > 0)
		heads->head_a = node->next;
	if (heads->size_b == 0)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		head_b = heads->head_b;
		node->next = head_b;
		node->prev = head_b->prev;
		head_b->prev->next = node;
		head_b->prev = node;
	}
	heads->head_b = node;
	heads->size_a--;
	heads->size_b++;
	ft_printf("pb\n");
}

void post_station(t_manager *heads, char instruction)
{
	if (instruction == 'b')
		push_b(heads);
	else if (instruction == 'a')
		push_a(heads);
}
