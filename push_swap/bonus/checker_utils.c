/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:20:54 by knajmech          #+#    #+#             */
/*   Updated: 2026/02/05 09:31:35 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checker_b(t_stack *stack, t_manager *heads)
{
	int	prev_index;

	//ft_printf("%d %d %d\n",stack->index, stack->next->index, stack->next->next->index);
	prev_index = stack->index;
	stack = stack->next;;
	while (stack != heads->head_a)
	{
		if (stack->index < prev_index)
			return (0);
		prev_index = stack->index;
		stack = stack->next;
	}
	return (1);
}

void	spin_rev_b(t_stack *stack, t_stack *head)
{
	t_stack	*prev_node;

	prev_node = stack;
	stack = stack->next;
	while (stack != head)
	{
		stack->prev = prev_node;
		prev_node = stack;
		stack = stack->next;
	}
	stack->prev = prev_node;
}

int	index_list_b(t_stack *stack_a, t_manager *heads, int start)
{
	t_stack	*tmp;

	while (stack_a != heads->head_a || !(start)++)
	{
		stack_a->index = heads->size_a;
		tmp = stack_a->next;
		while (tmp != stack_a)
		{
			if (stack_a->num == tmp->num)
			{
				valid_address(-1, 's');
				return (0);
			}
			else if (stack_a->num < tmp->num)
				stack_a->index--;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	make_list_b(t_manager *heads, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	stack_a = ft_lstnew(ft_atoi_b(argv[0]));
	if (!stack_a || !check_valid(argv, heads->size_a))
		return (free(stack_a), -1);
	stack_a->next = stack_a;
	heads->head_a = stack_a;
	while ((argv[i]) != 0)
	{
		stack_a->next = ft_lstnew(ft_atoi_b(argv[i]));
		if (!stack_a->next)
			return (ft_lstclear(&heads->head_a), 0);
		i++;
		stack_a = stack_a->next;
		if (!argv[i])
			stack_a->next = heads->head_a;
	}
	heads->size_a = ft_lstsize(heads->head_a);
	return (1);
}
// int	valid_address(int compare, char s_or_l)
// {
// 	static int	check;

// 	if (s_or_l == 's' && compare < 0)
// 		check = -1;
// 	else if (s_or_l == 'l' && check == -1)
// 		return (0);
// 	return (1);
// }