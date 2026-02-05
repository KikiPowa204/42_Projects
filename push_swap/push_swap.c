/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:35:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/05 10:33:57 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_num(char *arg)
{
	int	i;

	i = 0;
	if ((arg[0] != '-' || arg[0] != '+') && (arg[1] != 0))
		i++;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != ' ')
		{
			write(2, "Error\n", 6);
			return (valid_address(-1, 's'), 0);
		}
		i++;
	}
	return (1);
}

int	new_argc(char *argv)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	while (argv[i])
	{
		while (argv[i] && argv[i] == ' ')
			i++;
		if (argv[i])
		{
			spaces++;
			while (argv[i] && argv[i] != ' ')
				i++;
		}
		if (spaces == 0)
			return (valid_address(-1, 's'), -1);
	}
	return (spaces);
}

void	final_rotation(t_manager *heads)
{
	t_stack	*first;

	first = heads->first_pos;
	while (heads->head_a != first)
	{
		cost_to_top(heads->head_a, heads->size_a, 0);
		to_r_or_rr(heads, heads->head_a, first, 'a');
	}
}

int	handle_data(t_manager *heads, char **list, int how_many)
{
	int	valid;
	int	sorted;

	sorted = 1;
	valid = check_valid(list, how_many);
	if (valid <= 0)
		return (write(2, "Error\n", 6), 0);
	if (valid == 1)
		sorted = stack_manager(heads, list, 0);
	if (sorted == 2)
		return (2);
	if (valid <= 0 || !valid_address(1, 'l'))
		return (ft_lstclear(&(heads)->head_a), write(2, "Error\n", 6), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	int					how_many;
	int					sorted;
	char				**list;
	static t_manager	heads;

	if ((argc == 2 && (!no_num(argv[1]) || !ft_strchr(argv[1], ' ')))
		|| argc == 1)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		heads.is_split = 1;
		list = ft_split(argv[1], ' ');
		how_many = new_argc(argv[1]);
	}
	else
	{
		how_many = argc - 2;
		list = argv + 1;
	}
	sorted = handle_data(&heads, list, how_many);
	purge(list, heads.is_split);
	if (!sorted || sorted == 2)
		return (0);
	return (final_rotation(&heads), ft_lstclear(&(heads).head_a), 1);
}
