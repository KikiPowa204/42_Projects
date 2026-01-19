/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_seven.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:13:39 by knajmech          #+#    #+#             */
/*   Updated: 2026/01/19 12:46:58 by knajmech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *make_array (t_stack *stack_a, int size)
{
	int *nums;
	int i;

	nums = malloc((size + 2) * sizeof(int));
	if (!nums)
		return (0);
	i = 0;
	while (i < size)
	{
		nums[i] = stack_a->index;
		i++;
		stack_a = stack_a->next;
	}
	nums[i] = 0;
	return (nums);
}

int check_array(int *nums)
{
	int i;

	i = 0;
	while (nums[i])
	{
		if (nums[i] > nums[i + 1] && nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void best_timeline(int *nums, int depth, int *min_moves, t_manager *heads)
{
	if (depth >= *min_moves)
		return ;
	if (check_array(nums))
	{
		if (depth < *min_moves)
		{
			ft_bzero(&(heads)->inst[depth + 1], (20 - depth) * sizeof(int));
			*min_moves = depth;
			ft_bzero(heads->win_inst, 20 * sizeof(int));
			ft_memcpy(heads->win_inst, heads->inst, (depth) * (sizeof(int)));
		}
		return ;
	}
	heads->inst[depth] = 1;
	nums = swap_array(nums);
	best_timeline(nums, depth + 1, min_moves, heads);
	nums = swap_array(nums);
	heads->inst[depth] = 4;
	nums = rr_array(nums, arr_size(nums) - 1);
	best_timeline(nums, depth + 1, min_moves, heads);
	nums = r_array(nums, arr_size(nums) - 1);
	heads->inst[depth] = 7;
	nums = r_array(nums, arr_size(nums) - 1);
	best_timeline(nums, depth + 1, min_moves, heads);
	nums = rr_array(nums, arr_size(nums) - 1);
}

int sort_seven(t_manager *heads)
{
	int 	*nums;
	int		size;
	int		min_moves;

	min_moves = 20;
	if (checker(heads->head_a, heads))
		return (1);
	size = ft_lstsize(heads->head_a);
	nums = make_array(heads->head_a, size);
	if (!nums)
		return (ft_lstclear(&(heads->head_a)), 0);
	ft_memset(heads->inst, 0, (20 * sizeof(int)));
	ft_memset(heads->win_inst, 0, (20 * sizeof(int)));
	best_timeline(nums, 0, &min_moves, heads);
	order_stacks(heads, heads->win_inst);
	heads->size_a = ft_lstsize(heads->head_a);
	free(nums);
	return (1);
}
