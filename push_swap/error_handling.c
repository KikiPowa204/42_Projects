/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:42:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/05 09:00:00 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_address(int compare, char s_or_l)
{
	static int	check;

	if (s_or_l == 's' && compare < 0)
		check = -1;
	else if (s_or_l == 'l' && check == -1)
		return (0);
	return (1);
}

int	check_length(char **list, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (ft_strlen(list[i]) > 10 && list[i][0] != '-')
			return (-1);
		i++;
	}
	return (1);
}

int	check_input(char **list, int amount)
{
	int	i;
	int	j;
	int	has_num;

	i = 0;
	while (i < amount)
	{
		has_num = 0;
		j = 0;
		if (list[i][0] == '-')
			j++;
		while (list[i][j])
		{
			if (list[i][j] <= '9' && list[i][j] >= '0')
				has_num = 1;
			if (list[i][j] < '0' || list[i][j] > '9')
				return (-1);
			j++;
		}
		if (!has_num)
			return (ft_printf("culprit\n"), -1);
		i++;
	}
	return (1);
}

int	check_valid(char **list, int amount)
{
	int		index;
	long	num;

	index = 0;
	if (!valid_address(1, 'l'))
		return (0);
	if (check_length(list, amount) == -1 || check_input(list, amount) == -1)
		return (valid_address(-1, 's'), 0);
	while (index < amount)
	{
		num = ft_atoi(list[index]);
		if ((num > INT_MAX || num < INT_MIN) || !valid_address(1, 'l'))
			return (-1);
		index++;
	}
	return (1);
}
