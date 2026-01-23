/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:03:39 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/23 09:10:49 by knajmech         ###   ########.fr       */
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

void	execute_rule(t_manager *heads, int rule)
{
	if (!rule)
		return ;
	if (rule <= 3 && rule >= 1)
		pick_path(heads, rule);
	if (rule >= 4 && rule <= 6)
		crack_safe(heads, rule);
	if (rule == 7)
		rrotate(&(heads)->head_a, heads, 'A');
	if (rule == 8)
		rrotate(&(heads)->head_b, heads, 'B');
	if (rule == 9)
		rrotate_both(heads);
	if (rule == 10)
		push_a(heads);
	if (rule == 11)
		push_b(heads);
}

int	assign_val(char *instruction, int move)
{
	if (!instruction)
		return (0);
	if (!(ft_memcmp(instruction, &("sa\n"), 3)))
		move = 1;
	else if (!(ft_memcmp(instruction, &("sb\n"), 3)))
		move = 2;
	else if (!(ft_memcmp(instruction, &("ss\n"), 3)))
		move = 3;
	else if (!(ft_memcmp(instruction, &("ra\n"), 3)))
		move = 4;
	else if (!(ft_memcmp(instruction, &("rb\n"), 3)))
		move = 5;
	else if (!(ft_memcmp(instruction, &("rr\n"), 4)))
		move = 6;
	else if (!(ft_memcmp(instruction, &("rra\n"), 4)))
		move = 7;
	else if (!(ft_memcmp(instruction, &("rrb\n"), 3)))
		move = 8;
	else if (!(ft_memcmp(instruction, &("rrr\n"), 4)))
		move = 9;
	else if (!(ft_memcmp(instruction, &("pa\n"), 3)))
		move = 10;
	else if (!(ft_memcmp(instruction, &("pb\n"), 3)))
		move = 11;
	return (move);
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

int	main(int argc, char **argv)
{
	static t_manager	heads;
	char				**list;
	int					how_many;
	int					result;

	if ((argc == 2 && ft_strchr(argv[1], ' ')) || argc == 1)
	{
		heads.is_split = 1;
		list = ft_split(argv[1], ' ');
		if (!list)
			return (0);
		how_many = new_argc(argv[1]);
	}
	else
	{
		how_many = argc - 2;
		list = argv + 1;
	}
	result = check_mate(&heads, list);
	purge(list, heads.is_split);
	if (result == 1)
		return (ft_lstclear(&(heads.head_a)), ft_printf("OK\n"), 1);
	else if (result < 0)
		return (ft_lstclear(&(heads.head_a)), ft_printf("Error\n"), 0);
	return (ft_lstclear(&(heads.head_a)), ft_printf("KO\n"), 0);
}
