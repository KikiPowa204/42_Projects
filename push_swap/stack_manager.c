/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:17:31 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/16 08:29:24 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    spin_rev(t_stack *stack, t_stack *head)
{
    t_stack     *prev_node;

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

int index_list(t_stack *stack_a, t_manager *heads, int start)
{
    t_stack *tmp;

    while (stack_a->next != heads->head_a || !(start)++)
    {
        stack_a->index = heads->size_a;
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

int make_list(t_manager *heads, char **argv)
{
	int		i;
	t_stack *stack_a;

	i = 1;
	stack_a = ft_lstnew(ft_atoi(argv[0]));
	heads->head_a = stack_a;
	if (!stack_a || g_valid < 1)
		return (0);
	while ((argv[i]) != 0)
	{
		stack_a->next = ft_lstnew(ft_atoi(argv[i]));
		if (!stack_a->next || g_valid < 0)
			return (ft_lstclear(&heads->head_a), 0);
		i++;
		stack_a = stack_a->next;
		if (!argv[i])
			stack_a->next = heads->head_a;
	}
	return (1);
}

int stack_manager(t_manager *heads, char **argv)
{
	int 	check;

	if (!(make_list(heads, argv)))
		return (-1);
	heads->size_a = ft_lstsize(heads->head_a);
	spin_rev(heads->head_a, heads->head_a);
	check = index_list(heads->head_a, heads, 0);
	if (!check)
		return (0);
	unload(heads);
	sort_seven(heads);
	while (heads->size_b > 0)
		calculator(heads);
	return (1);
}
