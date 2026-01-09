/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_hq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:48:48 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/08 14:20:36 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arr_size(int *nums)
{
    int i;

    i = 0;
    while (nums[i])
        i++;
    return (i);
}

int *swap_array(int *nums)
{
    int    tmp;

    tmp = nums[0];
    nums[0] = nums[1];
    nums[1] = tmp;
    return (nums);
}

int    *rr_array(int *nums, int size)
{
	int first;
	int i;

	first = nums[0];
	i = 0;
	while (i < size)
	{
		nums[i] = nums[i + 1];
		i++;
	}
	nums[size] = first;
	return (nums);
}

int    *r_array(int *nums, int size)
{
    int last;

    last = nums[size];
    while (size)
    {
        nums[size] = nums[size - 1];
        size--;
    }
    nums[0] = last;
    //ft_printf("%d", nums[0]);
    return (nums);
}