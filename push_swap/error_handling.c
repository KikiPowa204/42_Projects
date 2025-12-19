/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:42:58 by knajmech          #+#    #+#             */
/*   Updated: 2025/12/19 09:02:11 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_valid(char **list, int amount)
{
    int i;
    int num;
    int valid;

    valid = 1;
    i = 0;
    while (i < amount)
    {
        num = ft_atoi(list[i], &valid);
        if (valid == -1)
            return (-1);
        i++;
    }
    return (1);
}