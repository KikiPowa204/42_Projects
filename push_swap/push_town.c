/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_town.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 08:45:54 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/09 08:57:14 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_manager *heads)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	
}

void push_b(t_manager *heads)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *prev_b;
	t_stack *next_b;
	t_stack *prev_a;
	t_stack *next_a;

	stack_a = heads->head_a;
	stack_b = heads->head_b;
	prev_b = stack_b->prev;
	next_b = stack_b->next;
	prev_a = stack_a->prev;
	next_a = stack_a->next;
	stack_a->next = next_b;
	stack_a->prev = prev_b;
	next_a->prev = prev_a;
	prev_a->next = next_a;
}
