/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_department.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:13:39 by knajmech          #+#    #+#             */
/*   Updated: 2025/12/31 08:38:20 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_five(t_manager *heads)
{
    t_stack *stack_a;
    t_stack *tmp;
    int     start;
    int     smallest;

    stack_a = heads->head_a;
    smallest = stack_a->index;
    //stack_a = stack_a->next;
    start = 0;
    while (stack_a->next != heads->head_a || !(start++))
    {
        tmp = stack_a->next;
        if (stack_a->index > tmp->index)
            ft_putstr_fd("ra", 1);
        stack_a = stack_a->next;
        //tmp = tmp->next;
    }
}