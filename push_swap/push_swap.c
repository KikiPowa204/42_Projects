/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:35:58 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 07:36:32 by knajmech         ###   ########.fr       */
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

#include "unistd.h"
int main(int argc, char **argv)
{
	int					how_many;
	int					i;
	char				**list;
	t_stack				*stack_a;
	t_stack				*stack_b;
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
	final_rotation(&heads);
	stack_a = heads.head_a;
	stack_b = heads.head_b;
	int start = 0;
	while (stack_a != heads.head_a || !(start)++)
	{
		ft_printf("stack a: %d\n", stack_a->index);
		//ft_printf("stack b: %d \n", stack_b->num);
		i++;
		stack_a = stack_a->next;
//		stack_b = stack_b->next;
	}
	ft_printf("%d - %d", ft_lstsize(heads.head_a), ft_lstsize(heads.head_b));
	ft_lstclear(&(heads).head_a);
	//ft_printf("%d", heads.size_b);
	return 0;
}
