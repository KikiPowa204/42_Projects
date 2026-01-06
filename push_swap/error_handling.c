/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:42:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/06 10:44:38 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_valid(char **list, int amount)
{
    int index;
    int num;
    int valid;

    valid = 1;
    index = 1;
    if (amount < 2 && ft_strchr(list[1], ' '))
        list = ft_split(list[1], ' ');
    while (index <= amount)
    {
		//ft_printf("%s, %s", list[i], list[1]);
        num = ft_atoi(list[index]);
        if (g_valid == -1)
            return (-1);
        index++;
    }
    return (1);
}
