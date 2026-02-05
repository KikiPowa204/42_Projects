/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:03:39 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/05 07:34:50 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	no_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9') && ((arg[i] != '-' || arg[i] != '+')
				&& arg[i] != ' '))
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
			return (valid_address(-1, 's') -1);
	}
	return (spaces);
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

int	handle_list(t_manager *heads, char ***list, char **argv, int amount)
{
	int	how_many;

	if ((amount == 2 && (!no_num(argv[1])))
		|| amount == 1)
		return (-1);
	if ((amount == 2 && ft_strchr(argv[1], ' ')))
	{
		heads->is_split = 1;
		*list = ft_split(argv[1], ' ');
		if (!*list)
			return (0);
		how_many = new_argc(argv[1]);
	}
	else
	{
		how_many = amount - 2;
		*list = argv + 1;
	}
	if (check_valid(*list, how_many) == -1)
		return (purge(*list, heads->is_split), write(2, "Error\n", 6), 0);
	return (how_many);
}

int	main(int argc, char **argv)
{
	static t_manager	heads;
	char				**list;
	int					how_many;
	int					result;

	if ((argc > 1 && !no_num(argv[1])))
		return (write(2, "Error\n", 6), 0);
	how_many = handle_list(&heads, &list, argv, argc);
	if (how_many < 0)
		return (purge(list, heads.is_split), 0);
	result = check_mate(&heads, list);
	purge(list, heads.is_split);
	if (result == 1)
		return (ft_lstclear(&(heads.head_a)), ft_printf("OK\n"), 1);
	else if (result < 0)
		return (ft_lstclear(&(heads.head_a)), write(2, "Error\n", 6), 0);
	return (ft_lstclear(&(heads.head_a)), ft_printf("KO\n"), 0);
}
