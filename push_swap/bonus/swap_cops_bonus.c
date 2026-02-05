/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:39:31 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/05 10:50:51 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freaky_friday_b(t_stack **head, int size)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*tail;

	if (!head || !(*head) || (*head)->next == *head)
		return ;
	old_head = *head;
	new_head = (*head)->next;
	tail = (*head)->prev;
	if (size > 2)
	{
		tail->next = new_head;
		new_head->next->prev = old_head;
		new_head->prev = tail;
		old_head->next = new_head->next;
		new_head->next = *head;
		old_head->prev = new_head;
		*head = new_head;
	}
	else if (size == 2)
		*head = (*head)->next;
}

void	parent_trap(t_manager *heads)
{
	freaky_friday_b(&(heads)->head_a, heads->size_a);
	freaky_friday_b(&(heads)->head_b, heads->size_b);
}

void	pick_path_b(t_manager *heads, int num)
{
	if (num == 1)
		freaky_friday_b(&(heads)->head_a, heads->size_a);
	if (num == 2)
		freaky_friday_b(&(heads)->head_b, heads->size_b);
	if (num == 3)
		parent_trap(heads);
}
