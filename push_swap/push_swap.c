/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:35:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/06 11:53:54 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int new_argc(char *argv)
{
    int i;
    int spaces;

    i = 0;
    spaces = 0;
    while (argv[i + spaces])
    {
        while (argv[i] != ' ' && argv[i])
        {
            i++;
        }
        spaces++;
    }
    return (spaces);
}

int main(int argc, char **argv)
{
    int         how_many;
    int         i;
    t_stack     *stack_a;
    t_manager   heads;

    if (argc == 2 && ft_strchr(argv[1], ' '))
    {
        argv = ft_split(argv[1], ' ');
        how_many =  new_argc(argv[1]);
    }
    else
    {
        how_many = argc - 1;
        *argv = *argv + 1;
    }
    g_valid = check_valid(argv, how_many);
    if (g_valid == 1)
        g_valid = stack_manager(&heads, argv, how_many);
    if (g_valid <= 0)
        return (ft_printf("ERROR"), 0);
    i = 1;
    stack_a = heads.head_a;
    while (i <= how_many)
    {
        //ft_printf("%d ", ft_atoi(*argv));
        //ft_printf("%d,", stack_a->index);
        i++;
        stack_a = stack_a->next;
    }
    return 0;
}
