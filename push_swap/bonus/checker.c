/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:03:39 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/10 14:52:23 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	new_argc(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

int	check_mate(t_manager *heads, char **argv)
{
	int		command;
	char	*instruction;

	if ((make_list_b(heads, argv)) <= 0)
		return (-1);
	spin_rev_b(heads->head_a, heads->head_a);
	if (!(index_list_b(heads->head_a, heads, 0)))
		return (-1);
	instruction = 0;
	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		command = assign_val(instruction, 0);
		if (command == 0)
			return (close(0), free(instruction), -1);
		execute_rule(heads, command);
		free(instruction);
	}
	if (checker_b(heads->head_a, heads) && heads->size_b == 0)
		return (close(0), 1);
	return (close(0), 0);
}

// int	handle_list(t_manager *heads, char ***list, char **argv, int amount)
// {
// 	int	how_many;

// 	if (amount == 1)
// 		return (-1);
// 	else if ((amount == 2 && ft_strchr(argv[1], ' ')))
// 	{
// 		*list = ft_split(argv[1], ' ');
// 		if (!*list)
// 			return (-1);
// 		heads->is_split = 1;
// 		how_many = new_argc(argv[1]);
// 	}
// 	else
// 	{
// 		how_many = amount - 2;
// 		*list = argv + 1;
// 	}
// 	if (how_many == -1 || list == 0)
// 		return (write(2, "Error\n", 6), -1);
// 	if (check_valid(*list, how_many) == -1)
// 		return (write(2, "Error\n", 6), 0);
// 	return (how_many);
// }

int	handle_list(t_manager *heads, char **list, int how_many)
{
	int	valid;
	int	sorted;

	valid = check_valid(list, how_many);
	if (valid != -1 && how_many == 1)
		sorted = 1;
	if (valid == -1)
		sorted = -1;
	if (valid == 1)
		sorted = check_mate(heads, list);
	purge(list, heads->is_split);
	if (sorted == -1 || valid < 0 || !valid_address(1, 'l'))
		return (write(2, "Error\n", 6), -1);
	if (sorted == 0)
		return (ft_printf("KO\n"), 0);
	if (sorted == 1)
		return (ft_printf("OK\n"), 1);
	return (1);
}

int	main(int argc, char **argv)
{
	static t_manager	heads;
	int					how_many;
	char				**list;

	if (argc == 1)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			return (0);
		heads.is_split = 1;
		how_many = new_argc(list);
	}
	else
	{
		how_many = argc - 1;
		list = argv + 1;
	}
	handle_list(&heads, list, how_many);
	if (heads.size_a)
		ft_lstclear(&(heads.head_a));
	if (heads.size_b)
		ft_lstclear(&(heads.head_b));
}
