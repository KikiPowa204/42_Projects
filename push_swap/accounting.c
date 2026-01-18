/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accounting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:55:17 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/18 11:53:41 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void cost_to_top(t_stack *node, int size, int i)
{
	t_stack	*head;

	head = node;
	i = 0;
	while (node->next != node)
	{
		while (i <= size/2)
		{
			node->cost_to_top = i; 
			node = node->next;
			i++;
		}
		i = -1;
		node = head->prev;
		while (i >= (size/2) * -1)
		{
			node->cost_to_top = i; 
			node =  node->prev;
			i--;
		}
		break ;
	}
}

void form_categories(t_stack *b_nodes, t_stack *a_nodes, t_manager *heads)
{
	int		i;
	int		start;
	t_stack	*largest_node;

	heads->curr_category = 0;
	largest_node = a_nodes->prev;
	i = 1;
	while (i <=  7)
	{
		start = 0;
		while (b_nodes != heads->head_b || !(start)++)
		{
			if (b_nodes->num > largest_node->num)
			{
				b_nodes->category = 6;
			}
			else if (b_nodes->num > a_nodes->num && b_nodes->num < a_nodes->next->num)
			{
				b_nodes->category = i;
			}
			b_nodes = b_nodes->next;
		}
		a_nodes = a_nodes->next;
		i++;
	}
}

int it_is_cheap(t_manager *heads, t_stack *stack_1, t_stack *stack_2)
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

// int calculate_total_cost(t_stack *a, t_stack *b)
// {
// 	int cost_a;
// 	int cost_b;
// 	int abs_a;
// 	int abs_b;

// 	cost_a = a->cost_to_top;
// 	cost_b = b->cost_to_top;
// 	if (cost_a >= 0 && cost_b >= 0)
// 		return (cost_a > cost_b ? cost_a : cost_b);
// 	if (cost_a < 0 && cost_b < 0)
// 	{
// 		abs_a = cost_a * -1;
// 		abs_b = cost_b * -1;
// 		if (abs_a > abs_b)
// 			return (abs_a);
// 		else
// 			return (abs_b);
// 	}
// 	return (abs(cost_a) + abs(cost_b));
// }

// void find_target(t_manager *heads, t_stack *node_b)
// {
// 	t_stack *a;
// 	int i;

// 	a = heads->head_a;
// 	i = 0;
// 	while (i < heads->size_a)
// 	{
// 		// Check if node_b fits between a and a->next
// 		if (node_b->index > a->index && node_b->index < a->next->index)
// 		{
// 			if (calculate_total_cost(a->next, node_b) < heads->cost)
// 			{
// 				heads->cost = calculate_total_cost(a->next, node_b);
// 				heads->target_in_a = a->next;
// 				heads->target_in_b = node_b;
// 			}
// 		}
// 		a = a->next;
// 		i++;
// 	}
// }

void prioritise_category(t_stack *stack_b, t_manager *heads, int section)
{
	while (stack_b != heads->head_b || !section)
	{
		heads->count = 0;
		section = stack_b->category;
		if (stack_b->category == section)
		{
			while (stack_b->category == section && heads->count < heads->max)
			{
				heads->count++;
				stack_b = stack_b->next;
			}
			if (heads->count > heads->max)
			{
				heads->max = heads->count;
				heads->curr_category = stack_b->category;
				heads->category_add = stack_b;
			}
		}
		else
			stack_b = stack_b->next;
	}
}

void calculator(t_manager *heads, t_stack *stack_b)
{
	while (stack_b != heads->head_b)
	{
		find_ft(heads, heads->first_pos, stack_b);
		stack_b = stack_b->next;
	}
	if (heads->size_b)
	{
		if (!(heads->target_in_a->cost_to_top - heads->target_in_b->cost_to_top))
		{
			check_rotation(heads, heads->target_in_a->cost_to_top);
			push_a(heads);
			return ;
		}
		else
			switcheroo(heads);
	}
	if (stack_b->category != heads->curr_category)
		heads->curr_category = 0;
	return ;
}
