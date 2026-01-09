/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:39:31 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 10:13:18 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freaky_friday(t_stack **head)
{
	t_stack	*node_3;
	t_stack *node_1;
	t_stack *node_2;
	t_stack *last_node;

	node_1 = *head;
	last_node = node_1->prev;
	node_2 = node_1->next;
	node_3 = node_2->next;
	node_1 = node_2;
	node_2 = *head;
	last_node->next = node_1;
	node_1->prev = last_node;
	node_1->next = node_2;
	node_2->next = node_3;
	node_3->prev = node_2;
	node_2->prev = node_1;
	*head = node_1;
}

void parent_trap(t_manager *heads) //ss
{
	freaky_friday(&(heads)->head_a);
	freaky_friday(&(heads)->head_b);
}

void pick_path(t_manager *heads, int num)
{
	if (num == 1)
		freaky_friday(&(heads)->head_a);
	if (num == 2)
		freaky_friday(&(heads)->head_b);
	if (num == 3)
		parent_trap(heads);
}