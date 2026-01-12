/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:35:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/12 10:36:35 by knajmech         ###   ########.fr       */
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
#include "unistd.h"
int main(int argc, char **argv)
{
	int					how_many;
	int					i;
	char				**list;
	t_stack				*stack_a;
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
	g_valid = check_valid(list, how_many);
	if (g_valid == 1)
		g_valid = stack_manager(&heads, list);
	if (g_valid <= 0)
		return (ft_printf("ERROR"), 0);
	i = 0;
	stack_a = heads.head_a;
	while (i < 9)
	{
		ft_printf("%d \n", stack_a->num);
		i++;
		stack_a = stack_a->next;
	}
	ft_printf("%d", heads.size_b);
	return 0;
}
