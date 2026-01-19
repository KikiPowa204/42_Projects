/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:42:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 10:13:33 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_valid(char **list, int amount)
{
    int index;
    int num;
	int	valid;

    index = 0;
	valid = 1;
    while (index < amount)
    {
		num = ft_atoi(list[index]);
        if (valid == -1)
            return (-1);
        index++;
    }
    return (1);
}
