/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:17:31 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/20 09:38:51 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spin_rev(t_stack *stack, t_stack *head)
{
	t_stack	*prev_node;

	prev_node = stack;
	stack = stack->next;
	while (stack != head)
	{
		stack->prev = prev_node;
		prev_node = stack;
		stack = stack->next;
	}
	stack->prev = prev_node;
}

int	index_list(t_stack *stack_a, t_manager *heads, int start)
{
	t_stack	*tmp;

	while (stack_a != heads->head_a || !(start)++)
	{
		stack_a->index = heads->size_a;
		if (heads->size_a > 450)
			stack_a->index--;
		tmp = stack_a->next;
		while (tmp != stack_a)
		{
			if (stack_a->num == tmp->num)
				return (ft_lstclear(&heads->head_a), 0);
			else if (stack_a->num < tmp->num)
				stack_a->index--;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	make_list(t_manager *heads, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	stack_a = ft_lstnew(ft_atoi(argv[0]));
	heads->head_a = stack_a;
	if (!stack_a)
		return (0);
	while ((argv[i]) != 0)
	{
		stack_a->next = ft_lstnew(ft_atoi(argv[i]));
		if (!stack_a->next)
			return (ft_lstclear(&heads->head_a), 0);
		i++;
		stack_a = stack_a->next;
		if (!argv[i])
			stack_a->next = heads->head_a;
	}
	return (1);
}

void	find_ft(t_manager *heads, t_stack *starting, t_stack *stack_b)
{
	int		start;

	start = 0;
	while (start < heads->size_a)
	{
		if (starting->index > stack_b->index)
		{
			if (it_is_cheap(heads, starting, stack_b))
			{
				heads->target_in_b = stack_b;
				heads->target_in_a = starting;
			}
			return ;
		}
		starting = starting->next;
		start++;
	}
	if (start == heads->size_a
		&& it_is_cheap(heads, heads->first_pos, stack_b))
	{
		heads->target_in_a = starting;
		heads->target_in_b = stack_b;
	}
}

int	stack_manager(t_manager *heads, char **argv, int check)
{
	if (!(make_list(heads, argv)))
		return (-1);
	heads->size_a = ft_lstsize(heads->head_a);
	spin_rev(heads->head_a, heads->head_a);
	check = index_list(heads->head_a, heads, 0);
	if (!check)
		return (0);
	if (checker(heads->head_a, heads))
		return (ft_lstclear(&(heads)->head_a), 1);
	// if (heads->size_a >= 450)
	// 	return (radix(heads), 1);
	unload(heads);
	if (!sort_seven(heads))
		return (0);
	heads->first_pos = heads->head_a;
	while (heads->size_b > 0)
	{
		heads->cost = INT_MAX;
		cost_to_top(heads->head_b, heads->size_b, 0);
		cost_to_top(heads->head_a, heads->size_a, 0);
		find_ft(heads, heads->first_pos, heads->head_b);
		calculator(heads);
	}
	return (1);
}
