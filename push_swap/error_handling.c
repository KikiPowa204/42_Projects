/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:42:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 11:19:10 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int valid_address(int compare, char s_or_l)
{
	static int	check;

	if (s_or_l == 's' && compare < 0)
		check = -1;
	else if (s_or_l == 'l' && check == -1)
		return (0);
	return 1;
}

int check_length(char **list, int amount)
{
	int i;

	i = 0;
	while (i < amount)
	{
		if (ft_strlen(list[i]) > 10 && list[i][0] != '-')
			return (-1);
		i++;
	}
	return (1);
}

int check_valid(char **list, int amount)
{
	int index;
	int num;
	int	valid;	

	index = 0;
	valid = 1;
	valid_address(check_length(list, amount), 's');
	while (index < amount)
	{
		num = ft_atoi(list[index]);
		index++;
	}
	if (!valid_address(valid, 'l'))
		return (0);
	return (1);
}
