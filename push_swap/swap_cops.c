/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:39:31 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/20 08:07:32 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freaky_friday(t_stack **head, char a_o_b)
{
	t_stack	*node_1;
	t_stack	*node_2;
	t_stack	*last_node;

	node_1 = *head;
	node_2 = node_1->next;
	last_node = node_1->prev;
	last_node->next = node_2;
	node_2->next->prev = node_1;
	node_2->prev = last_node;
	node_1->next = node_2->next;
	node_2->next = *head;
	node_1->prev = node_2;
	*head = node_2;
	if (a_o_b == 'a')
		ft_printf("sa\n");
	if (a_o_b == 'b')
		ft_printf("sb\n");
}

void	parent_trap(t_manager *heads)
{
	freaky_friday(&(heads)->head_a, 'c');
	freaky_friday(&(heads)->head_b, 'c');
	ft_printf("ss\n");
}

void	pick_path(t_manager *heads, int num)
{
	if (num == 1)
		freaky_friday(&(heads)->head_a, 'a');
	if (num == 2)
		freaky_friday(&(heads)->head_b, 'b');
	if (num == 3)
		parent_trap(heads);
}
