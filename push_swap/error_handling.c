/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:42:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/06 14:18:01 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_valid(char **list, int amount)
{
    int index;
    int num;

    index = 0;
    while (index < amount)
    {
		//ft_printf("%s, %s", list[i], list[1]);
        num = ft_atoi(list[index]);
        if (g_valid == -1)
            return (-1);
        index++;
    }
    return (1);
}
