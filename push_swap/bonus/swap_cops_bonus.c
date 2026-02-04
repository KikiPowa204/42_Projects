/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:39:31 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/03 14:54:22 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freaky_friday_b(t_stack **head)
{
	t_stack	*n1;
	t_stack	*n2;

	if (!head || !(*head) || (*head)->next == *head)
		return ;
	n1 = *head;
	n2 = n1->next;
	n1->prev->next = n2;
	n2->next->prev = n1;
	n1->next = n2->next;
	n2->prev = n1->prev;
	n2->next = n1;
	n1->prev = n2;
	*head = n2;
}

void	parent_trap(t_manager *heads)
{
	freaky_friday_b(&(heads)->head_a);
	freaky_friday_b(&(heads)->head_b);
}

void	pick_path(t_manager *heads, int num)
{
	if (num == 1)
		freaky_friday_b(&(heads)->head_a);
	if (num == 2)
		freaky_friday_b(&(heads)->head_b);
	if (num == 3)
		parent_trap(heads);
}
