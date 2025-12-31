/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:35:58 by knajmech          #+#    #+#             */
/*   Updated: 2025/12/31 08:25:41 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int         how_many;
    int         valid;
    int         i;
    t_stack     *stack_a;
    t_manager   heads;

    how_many = argc - 1;
    valid = check_valid(argv, how_many);
    if (valid == 1)
        valid = stack_manager(&heads, argv, how_many);
    if (valid <= 0)
    {
        ft_printf("ERROR");
        return (0);
    }
    i = 1;
    stack_a = heads.head_a;
    while (i <= how_many)
    {
        ft_printf("%d ", ft_atoi(argv[i], &valid));
        ft_printf("%d,", stack_a->index);
        i++;
        stack_a = stack_a->next;
    }
    return 0;
}
