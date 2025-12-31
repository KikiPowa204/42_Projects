/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:17:31 by knajmech          #+#    #+#             */
/*   Updated: 2025/12/31 09:15:51 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    spin_rev(t_stack *stack)
{
    t_stack     *prev_node;

    prev_node;
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

int make_list(t_manager *heads, char **argv, int amount)
{
    int     i;
    int     check;
    t_stack *stack_a;

    stack_a = ft_lstnew(ft_atoi(argv[1], &i));
    if (!stack_a || i < 1)
        return (0);
    heads->head_a = stack_a;
    stack_a->next = stack_a;
    i = 2;
    check = 1;
    while (i <= amount)
    {
        stack_a->next = ft_lstnew(ft_atoi(argv[i], &check));
        if (!stack_a->next || check < 0)
            return (ft_lstclear(&heads->head_a), 0);
        i++;
        stack_a = stack_a->next;
    }
    stack_a->next = heads->head_a;
    return (1);
}

int stack_manager(t_manager *heads, char **argv, int amount)
{
    int check;

    if (!(make_list(heads, argv, amount)))
        return (-1);
    heads->size_a = ft_lstsize(heads->head_a);
    spin_rev(heads->head_a);
    check = index_list(heads->head_a, heads, 0);
    if (!check)
        return (0);
    sort_five(heads);
    return (1);
}
