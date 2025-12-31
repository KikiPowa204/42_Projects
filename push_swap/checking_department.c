/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 08:39:33 by knajmech          #+#    #+#             */
/*   Updated: 2025/12/31 08:48:03 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checker(t_stack *stack, t_manager *heads)
{
    int prev_index;

    prev_index = stack->index;
    stack = stack->next;
    while (stack != heads->head_a)
    {
        if (stack->index < prev_index)
            return (0);
        prev_index = stack->index;
        stack = stack->next;
    }
    return (1);
}