/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:39:31 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/05 10:26:42 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freaky_friday_b(t_stack **head)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*tail;

	if (!head || !(*head) || (*head)->next == *head)
		return ;
/*
	tail->next = new_head;//relinking tail next
	new_head->next->prev = *head;//for tail or 3rd element
	new_head->prev = tail;//relinking new_head->prev
	//new_head->next->prev = *head;
	old_head->next = new_head->next;
	new_head->next = *head;
	old_head->prev = head->next->prev;
*/
	old_head = *head;
	new_head = (*head)->next;
	tail = (*head)->prev;
	
	tail->next = new_head;
	new_head->next->prev = old_head;
	new_head->prev = tail;
	old_head->next = new_head->next;
	new_head->next = *head;
	old_head->prev = new_head;

	// tail->next = (*head)->next;//relinking tail next
	// new_head->next->prev = *head;
	// new_head->next = (*head);
	// new_head->prev = tail;
	*head = new_head;
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
