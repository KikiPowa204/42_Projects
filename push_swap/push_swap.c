/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:35:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 11:55:56 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int new_argc(char *argv)
{
	int i;
	int spaces;

	i = 0;
	spaces = 0;
	while (argv[i])
	{
		while (argv[i] && argv[i] == ' ')
			i++;
		if (argv[i])
		{
			spaces++;
			while(argv[i] && argv[i] != ' ')
				i++;
		}
	}
	return (spaces);
}
void final_rotation(t_manager *heads)
{
	t_stack	*first;

	first = heads->first_pos;
	while (heads->head_a != first)
	{
		cost_to_top(heads->head_a, heads->size_a, 0);
		to_r_or_rr(heads, heads->head_a, first, 'a');
	}
}
int handle_data(t_manager *heads, char **list, int how_many)
{
	int valid;

	valid = check_valid(list, how_many);
	if (valid == 1)
		valid = stack_manager(heads, list);
	if (valid <= 0)
		return (ft_printf("ERROR"), 0);
	return 1;
}

int main(int argc, char **argv)
{
	int					how_many;
	char				**list;
	static t_manager	heads;

	list = 0;
	if (argc == 2 && !ft_strchr(argv[1], ' '))
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		list = ft_split(argv[1], ' ');
		how_many =  new_argc(argv[1]);
	}
	else
	{
		how_many = argc - 2;
		list = argv + 1;
	}
	if (!(handle_data(&heads, list, how_many)))
		return (0);	
	final_rotation(&heads);
	ft_lstclear(&(heads).head_a);
	return (0);
}
