/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_department.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 08:39:33 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 16:50:10 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_map(char **map)
{
	int	i;

	i = 0;
	map = malloc(sizeof(char *) * 13);
	map[12] = 0;
	while (i < 12)
	{
		map[i] = malloc(sizeof(char) * 9);
		if (!map[i])
			return (free(map), NULL);
		i++;
	}
	ft_strlcpy(map[0], "nothing", 8);
	ft_strlcpy(map[1], "sa", 3);
	ft_strlcpy(map[2], "sb", 3);
	ft_strlcpy(map[3], "ss", 3);
	ft_strlcpy(map[4], "ra", 3);
	ft_strlcpy(map[5], "rb", 3);
	ft_strlcpy(map[6], "rr", 3);
	ft_strlcpy(map[7], "rra", 4);
	ft_strlcpy(map[8], "rrb", 4);
	ft_strlcpy(map[9], "rrr", 4);
	ft_strlcpy(map[10], "pa", 3);
	ft_strlcpy(map[11], "pb", 3);
	return (map);
}

char	*read_map(int path)
{
	char	**map;

	map = 0;
	map = create_map(map);
	return (map[path]);
}

int	checker(t_stack *stack, t_manager *heads)
{
	int	prev_index;

	prev_index = stack->index;
	stack = stack->next;
	while (stack != heads->head_a)
	{
		if (stack->index < prev_index)
			return (0);
		prev_index = stack->index;
		stack = stack->next;
	}
	return (1);
}
