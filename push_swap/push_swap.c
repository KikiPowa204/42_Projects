/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:35:58 by knajmech          #+#    #+#             */
/*   Updated: 2025/12/19 09:08:44 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
    int how_many;
    int valid;

    how_many = argc - 1;
    valid = check_valid(argv, how_many);
    if (valid == 1)
        create_stacks();
    else if (valid == -1)
    {
        ft_printf("ERROR");
        return (0);
    }
}