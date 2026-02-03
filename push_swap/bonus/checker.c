/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:03:39 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/02 12:07:32 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	}
	return (spaces);
}

int	check_mate(t_manager *heads, char **argv)
{
	int		command;
	char	*instruction;

	if (!(make_list_b(heads, argv)))
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

	if ((amount == 2 && ft_strchr(argv[1], ' ')) || amount == 1)
	{
		heads->is_split = 1;
		*list = ft_split(argv[1], ' ');
		if (!list)
			return (0);
		how_many = new_argc(argv[1]);
	}
	else
	{
		how_many = amount - 2;
		*list = argv + 1;
	}
	return (how_many);
}

int	main(int argc, char **argv)
{
	static t_manager	heads;
	char				**list;
	int					how_many;
	int					result;

	how_many = handle_list(&heads, &list, argv, argc);
	result = check_mate(&heads, list);
	purge(list, heads.is_split);
	if (result == 1)
		return (ft_lstclear(&(heads.head_a)), ft_printf("OK\n"), 1);
	else if (result < 0)
		return (ft_lstclear(&(heads.head_a)), write(2, "Error\n", 6), 0);
	return (ft_lstclear(&(heads.head_a)), ft_printf("KO\n"), 0);
}
